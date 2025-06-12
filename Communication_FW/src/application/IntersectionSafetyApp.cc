//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "IntersectionSafetyApp.h"

#include "veins/modules/utility/Consts80211p.h"
#include "util/base64.h"

Define_Module(veins::IntersectionSafetyApp);

void veins::IntersectionSafetyApp::initialize(int stage) {
    DemoBaseApplLayer::initialize(stage);
        if (stage == 0) {
            detectionSent = false;
            currentImagePacket = 0;

            // Simulate image data (split into chunks)
            std::string fakeImageData(10000, 'X');
            for (size_t i = 0; i < fakeImageData.size(); i += PACKET_SIZE) {
                imageChunks.push_back(fakeImageData.substr(i, PACKET_SIZE));
            }
        }
}

void veins::IntersectionSafetyApp::handlePositionUpdate(cObject *obj) {

    // Get current position
    Coord pos = mobility->getPositionAt(simTime());
    std::string vehicleId = "0";

    Coord rsuPosition(145, 145, 3);
    double distance = pos.distance(rsuPosition);

    if (vehicleId == "0" && !detectionSent && distance <= 20) {
            sendObjectDetection();
            detectionSent = true;
            scheduleAt(simTime() + 0.1, new cMessage("sendImage"));
        }

}

void veins::IntersectionSafetyApp::handleSelfMsg(cMessage *msg) {

    if (msg->isName("sendImage")) {
            sendImagePackets();
            delete msg;
        }
        else {
            DemoBaseApplLayer::handleSelfMsg(msg);
        }

}

void veins::IntersectionSafetyApp::onWSM(BaseFrame1609_4 *frame) {

    if (ObjectDetectionMessage* odMsg = dynamic_cast<ObjectDetectionMessage*>(frame)) {
            // RSU logic for handling detection
            if (std::string(odMsg->getVehicleId()) == "0") {
                EV << "RSU received object detection from veh0" << endl;
                scheduleAt(simTime() + 0.5, new cMessage("processDetection"));
            }
        }
        else if (ImagePacketMessage* imgMsg = dynamic_cast<ImagePacketMessage*>(frame)) {
            processImagePackets(imgMsg);
        }

}

void veins::IntersectionSafetyApp::sendObjectDetection() {
    ObjectDetectionMessage* odMsg = new ObjectDetectionMessage();
        populateWSM(odMsg);
        odMsg->setVehicleId(mobility->getExternalId().c_str());
        odMsg->setPosition(mobility->getPositionAt(simTime()));
        odMsg->setDetectionTime(simTime().dbl());
        odMsg->setDistanceToIntersection(20);
        sendDown(odMsg);
}

void veins::IntersectionSafetyApp::sendImagePackets() {

    if (currentImagePacket < imageChunks.size()) {
            ImagePacketMessage* imgMsg = new ImagePacketMessage();
            populateWSM(imgMsg);
            imgMsg->setOriginalSender(mobility->getExternalId().c_str());
            imgMsg->setPacketNumber(currentImagePacket);
            imgMsg->setTotalPackets(imageChunks.size());
            imgMsg->setImageDataChunk(imageChunks[currentImagePacket].c_str());

            // Simple checksum
            int checksum = 0;
            for (char c : imageChunks[currentImagePacket]) {
                checksum += c;
            }
            imgMsg->setChecksum(checksum);

            sendDown(imgMsg);
            currentImagePacket++;
            scheduleAt(simTime() + 0.01, new cMessage("sendImage"));
        }
}

void veins::IntersectionSafetyApp::processImagePackets(
        ImagePacketMessage *imgMsg) {

    std::string sender = imgMsg->getOriginalSender();
        int pktNum = imgMsg->getPacketNumber();

        // Verify checksum
        int calculatedChecksum = 0;
        for (char c : std::string(imgMsg->getImageDataChunk())) {
            calculatedChecksum += c;
        }

        if (calculatedChecksum != imgMsg->getChecksum()) {
            EV << "Checksum mismatch for packet " << pktNum << endl;
            return;
        }

        // Store in buffer
        packetBuffers[sender][pktNum] = *imgMsg;

        // Check if all packets received
        if (packetBuffers[sender].size() == imgMsg->getTotalPackets()) {
            std::cout << "RSU received all image packets from " << sender << endl;
            //forwardProcessedData(sender);
        }
}

void veins::IntersectionSafetyApp::forwardProcessedData(std::string vehicleId) {

    /*
    auto* manager = TraCIScenarioManagerAccess().get();
        auto* commandInterface = manager->getCommandInterface();
        auto* vehicle2 = commandInterface->vehicle("1");

        if (vehicle2) {
            // Create processed data message
            BaseFrame1609_4* procMsg = new BaseFrame1609_4();
            populateWSM(procMsg);
            procMsg->setRecipientAddress(vehicle2->getId().c_str());
            procMsg->setSenderAddress("rsu");
            procMsg->setTimestamp(simTime());
            procMsg->setWsmData("Processed data from vehicle1");
            sendDown(procMsg);
        }
    */
}
