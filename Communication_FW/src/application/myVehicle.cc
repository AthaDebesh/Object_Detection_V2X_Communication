//
// Copyright (C) 2006-2011 Christoph Sommer <christoph.sommer@uibk.ac.at>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "myVehicle.h"

#include "message/NumVehicleMsg_m.h"
#include "message/CarMessage_m.h"
#include "util/base64.h"

using namespace veins;

Define_Module(veins::myVehicle);

void myVehicle::initialize(int stage)
{
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        currentSubscribedServiceId = -1;
        sendPeriod = 0.5;
        wsmSendEvt = new cMessage("wsm send task", BEACON);
        detectionEvent = new cMessage("objectDetected");
    }
    else if (stage == 1){
        scheduleAt(simTime()+sendPeriod, wsmSendEvt);
        simtime_t triggerTime = 20.0;  // Send object detection at t=20s
        scheduleAt(triggerTime, detectionEvent);
    }
}

void myVehicle::onWSA(DemoServiceAdvertisment* wsa)
{
    if (currentSubscribedServiceId == -1) {
        mac->changeServiceChannel(static_cast<Channel>(wsa->getTargetChannel()));
        currentSubscribedServiceId = wsa->getPsid();
        if (currentOfferedServiceId != wsa->getPsid()) {
            stopService();
            startService(static_cast<Channel>(wsa->getTargetChannel()), wsa->getPsid(), "Mirrored Traffic Service");
        }
    }
}

void myVehicle::onWSM(BaseFrame1609_4* frame)
{
    /*
    NumVehicleMsg* wsm = check_and_cast<NumVehicleMsg*>(frame);

    findHost()->getDisplayString().setTagArg("i", 1, "green");

    if (mobility->getRoadId()[0] != ':') traciVehicle->changeRoute(wsm->getDemoData(), 9999);
    if (!sentMessage) {
        sentMessage = true;
        // repeat the received traffic update once in 2 seconds plus some random delay
        wsm->setSenderAddress(myId);
        wsm->setSerial(3);
        scheduleAt(simTime() + 2 + uniform(0.01, 0.2), wsm->dup());
    }*/
}

void myVehicle::handleSelfMsg(cMessage* msg)
{
    /*if (NumVehicleMsg* wsm = dynamic_cast<NumVehicleMsg*>(msg)) {
        // send this message on the service channel until the counter is 3 or higher.
        // this code only runs when channel switching is enabled
        sendDown(wsm->dup());
        wsm->setSerial(wsm->getSerial() + 1);
        if (wsm->getSerial() >= 3) {
            // stop service advertisements
            stopService();
            delete (wsm);
        }
        else {
            scheduleAt(simTime() + 1, wsm);
        }
    }
    else {
        DemoBaseApplLayer::handleSelfMsg(msg);
    }*/

    if(msg->getKind() == BEACON){

        /*CarMessage* pkt = new CarMessage();
        std::ifstream file("gettyimages-1282679063-612x612.jpg", std::ios::binary);
        std::ostringstream oss;
        oss << file.rdbuf();
        std::string base64_img = base64_encode(reinterpret_cast<const unsigned char*>(oss.str().c_str()), oss.str().length(), false);
        pkt->setSenderAddress(myId);
        pkt->setSenderPos(curPosition);
        pkt->setTimeStampP(simTime());
        pkt->setChannelNumber(static_cast<int>(Channel::cch));
        pkt->setBitLength(headerLength);
        pkt->setImageData(base64_img.c_str());
        pkt->addBitLength(base64_img.length()*8);
        sendDown(pkt->dup());
        std::cout<<"Car data sent!";
        delete pkt;
        */

        NumVehicleMsg* nvm = new NumVehicleMsg();
        nvm->setSenderAddress(myId);
        nvm->setSenderPos(curPosition);
        nvm->setTimeStampP(simTime());
        nvm->setChannelNumber(static_cast<int>(Channel::cch));
        sendDown(nvm->dup());
        delete nvm;
        scheduleAt(simTime() + sendPeriod, wsmSendEvt);
    }
    else if (msg == detectionEvent) {
        std::cout << "Received object detection event. Sending WSM to RSU.\n";

        CarMessage* pkt = new CarMessage();
        std::ifstream file("gettyimages-1282679063-612x612.jpg", std::ios::binary);
        std::ostringstream oss;
        oss << file.rdbuf();

        if(RSU_inference)
        {
            std::string base64_img = base64_encode(reinterpret_cast<const unsigned char*>(oss.str().c_str()), oss.str().length(), false);
            pkt->setChannelNumber(static_cast<int>(Channel::cch));
            pkt->setBitLength(headerLength);
            pkt->setImageData(base64_img.c_str());
            pkt->addBitLength(base64_img.length()*8);
            sendDown(pkt->dup());
            std::cout<<"Car data sent!";
            delete pkt;
        }
        else if (on_board_inference)
        {
            std::string resultJson = runInferenceAndGetResult(oss.str().c_str());


            auto result = json::parse(resultJson);

            std::ostringstream cpmPayload;
            cpmPayload << "CPM_START\n";

            for (const auto& det : result["detections"]) {
                std::string cls = det["class"];
                float conf = det["confidence"];
                auto bbox = det["bbox"];

                cpmPayload << cls << "," << conf << ",["
                           << bbox[0] << "," << bbox[1] << "," << bbox[2] << "," << bbox[3] << "]\n";
            }

            cpmPayload << "CPM_END";

            auto cpmMsg = new WaveShortMessage();
            cpmMsg->setWsmData(cpmPayload.str().c_str());
            cpmMsg->setChannelNumber(CCH1);
            cpmMsg->setRecipientAddress(-1);  // Broadcast
            sendDown(cpmMsg);
        }


        //scheduleAt(simTime(), detectionEvent);
    }
    else
    {
        DemoBaseApplLayer::handleSelfMsg(msg);
    }

}

std::string RSUApplication::runInferenceAndGetResult(const std::string& imagePath) {
    std::string cmd = "curl -X 'POST' 'http://127.0.0.1:8000/predict/' -F 'file=@" + imagePath + "'";
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return "{}";

    char buffer[256];
    std::string result;
    while (fgets(buffer, sizeof(buffer), pipe)) {
        result += buffer;
    }
    pclose(pipe);
    return result;
}

/*
void myVehicle::handlePositionUpdate(cObject* obj)
{
    DemoBaseApplLayer::handlePositionUpdate(obj);

    // stopped for for at least 10s?
    if (mobility->getSpeed() < 1) {
        if (simTime() - lastDroveAt >= 10 && sentMessage == false) {
            findHost()->getDisplayString().setTagArg("i", 1, "red");
            sentMessage = true;

            NumVehicleMsg* wsm = new NumVehicleMsg();
            populateWSM(wsm);
            wsm->setDemoData(mobility->getRoadId().c_str());

            // host is standing still due to crash
            if (dataOnSch) {
                startService(Channel::sch2, 42, "Traffic Information Service");
                // started service and server advertising, schedule message to self to send later
                scheduleAt(computeAsynchronousSendingTime(1, ChannelType::service), wsm);
            }
            else {
                // send right away on CCH, because channel switching is disabled
                sendDown(wsm);
            }
        }
    }
    else {
        lastDroveAt = simTime();
    }
}
*/
