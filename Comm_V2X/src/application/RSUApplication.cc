#include "RSUApplication.h"

#include "veins/modules/utility/Consts80211p.h"
#include "veins/base/utils/SimpleAddress.h"
#include "util/base64.h"

Define_Module(RSUApplication);

RSUApplication::~RSUApplication() {
    // TODO Auto-generated destructor stub
}

void RSUApplication::initialize(int stage) {
    veins::BaseApplLayer::initialize(stage);

    if (stage == 0) {

        cModule* tmpMobility = getParentModule()->getSubmodule("mobility");
        rsuMobility = dynamic_cast<veins::BaseMobility*>(tmpMobility);
        ASSERT(rsuMobility);

        annotationManager = veins::AnnotationManagerAccess().getIfExists();
        ASSERT(annotationManager);

        headerLength = par("headerLength");
        packetLength = par("packetLength");
        //source = par("source");

    }
    if (stage == 3){

        myOmnetPosition = rsuMobility->getPositionAt(simTime());
        rsuId = this->getId();

        cMessage *drawPosition = new cMessage("drawMessage", DRAW);
        scheduleAt(simTime() + 1.0, drawPosition);

        //if (source){
            std::cout << "I am RSU with ID: " << rsuId << " and omnet position: " << myOmnetPosition << std::endl;

            // generating awareness and emergency traffic
            //awarenessTrafficTrigger  = new cMessage("awareness", SEND_PKT_AWARENESS_EVT);
            //scheduleAt(simTime() + par("awarenessInterval"), awarenessTrafficTrigger);

            //emergencyTrafficTrigger  = new cMessage("emergency", SEND_PKT_EMERGENCY_EVT);
            //scheduleAt(simTime() + par("emergencyInterval"), emergencyTrafficTrigger);
        //}
        //else{
        //    std::cout << "I am SinkRSU with ID: " << rsuId << " and omnet position: " << myOmnetPosition << std::endl;

            // sink does not transmit
            return;
        //}
    }
}

void RSUApplication::handleSelfMsg(cMessage* msg) {
    switch (msg->getKind()) {
    case DRAW: {
        //if (source){
            annotationManager->drawPoint(myOmnetPosition, "red", "SRC");
            annotationManager->drawLine(myOmnetPosition, veins::Coord(145,145), "white");
        //}
        //else{
        //    annotationManager->drawPoint(myOmnetPosition, "green", "SINK");
        //}
        break;
    }
    case SEND_PKT_AWARENESS_EVT: {
        veins::RSUMessage* pkt = new veins::RSUMessage("RSUMessage");
        populateAndSendPacket(pkt, AWARENESS);
        std::cout << "RSU with ID: " << rsuId << " transmitted Awareness message!" << std::endl;
        scheduleAt(simTime() + par("awarenessInterval"), awarenessTrafficTrigger);
        break;
    }
    case SEND_PKT_EMERGENCY_EVT: {
        veins::RSUMessage* pkt = new veins::RSUMessage("RSUMessage");
        populateAndSendPacket(pkt, EMERGENCY);
        std::cout << "RSU with ID: " << rsuId << " transmitted Emergency message!" << std::endl;
        scheduleAt(simTime() + par("emergencyInterval"), emergencyTrafficTrigger);
        break;
    }
    case RECORD_STATS_EVT: {
        // TODO: can be used for statistics recording, you have to schedule an event for this to work
        break;
    }
    default: {
        throw new cRuntimeError("unknown self message type");
        break;
    }
    }
}

void RSUApplication::handleLowerMsg(cMessage *msg) {
    //if (source){
        // do nothing
    //}
    //else{
        /*veins::RSUMessage* pkt = dynamic_cast<veins::RSUMessage*>(msg);
        if (pkt) {
            // check if SinkRSU is the destination
            if (pkt->getDestination() == rsuId){
                switch (pkt->getKind()) {
                // TODO: can record statistics here
                case AWARENESS: {

                break;
                }
                case EMERGENCY: {

                break;
                }
                default:
                    throw new cRuntimeError("unknown user priority of received packet!");
                    break;
                }
            }
        }*/
        //{
            veins::CarMessage* pkt = dynamic_cast<veins::CarMessage*>(msg);
            if (pkt) {
                switch (pkt->getKind()) {
                // TODO: can record statistics here
                case BEACON: {
                    std::cout << "RSU received image message from vehicle.\n";

                    std::string b64img = pkt->getImageData();
                    std::string decoded_img = base64_decode(b64img);

                    std::cout << "decoded_img:" << decoded_img;

                    // Call Python application (pseudo code)
                    // std::string response = callPythonApp(decoded_img);

                    // After receiving results (response), broadcast it via RSUMessage or CarMessage

                    break;
                }
                default:
                    throw new cRuntimeError("unknown user priority of received packet!");
                    break;
            }
        }
    //}
    delete msg;
    //}
}

void RSUApplication::populateAndSendPacket(veins::RSUMessage* pkt, int messageKind) {
    // populate the packet
    pkt->setRecipientAddress(veins::LAddress::L2BROADCAST());
    pkt->setBitLength(headerLength);
    pkt->addBitLength(packetLength);

    pkt->setPsid(-1);
    pkt->setChannelNumber(static_cast<int>(veins::Channel::cch));

    //pkt->setSource(rsuId);
    pkt->setDestination(14);        // omnet id of the sink rsu
    pkt->setKind(messageKind);
    pkt->setTimestamp(simTime());

    // send the packet to mac
    sendDown(pkt);
}

void RSUApplication::sendDown(cMessage* msg) {
    veins::BaseApplLayer::sendDown(msg);
}

void RSUApplication::finish() {
}

void RSUApplication::handleLowerControl(cMessage *msg) {
    delete msg;
}
