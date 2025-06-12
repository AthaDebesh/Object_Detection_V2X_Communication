
#include "myRSU.h"

#include "veins/modules/utility/Consts80211p.h"
#include "veins/base/utils/SimpleAddress.h"
#include "util/base64.h"

#include "NumVehicleMsg_m.h"

Define_Module(myRSU);
/*
void myRSU::initialize(int stage)
{
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        currentOfferedServiceId = 17; // whatever number you'd like
    }
    else if (stage == 1){
        //startService(Channel::sch2, currentOfferedServiceId, "NumVehicle Service");
        // Let‘s not use the SCH for now
    }
}

void myRSU::onWSA(DemoServiceAdvertisment* wsa)
{
    // if this RSU receives a WSA for service 42, it will tune to the chan
    if (wsa->getPsid() == 42) {
        mac->changeServiceChannel(static_cast<Channel>(wsa->getTargetChannel()));
    }
}

void myRSU::onWSM(BaseFrame1609_4* frame)
{
    if(NumVehicleMsg* wsm = check_and_cast<NumVehicleMsg*>(frame)){
        Coord senderPos = wsm->getSenderPos();
        double distance = (senderPos - curPosition).length();
        std::cout << "CarId: " << wsm->getSenderAddress() << " Distance: " << distance << "\n";
    }

    // this rsu repeats the received traffic update in 2 seconds plus some random delay
    //sendDelayedDown(wsm->dup(), 2 + uniform(0.01, 0.2));
}
*/
myRSU::~myRSU() {
}

void myRSU::initialize(int stage) {
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

            //cMessage *drawPosition = new cMessage("drawMessage", DRAW);
            //scheduleAt(simTime() + 1.0, drawPosition);

            std::cout << "I am SourceRSU with ID: " << rsuId << " and omnet position: " << myOmnetPosition << std::endl;

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

void myRSU::finish() {
}

void myRSU::handleLowerMsg(cMessage *msg) {
}

void myRSU::handleLowerControl(cMessage *msg) {
}

void myRSU::handleSelfMsg(cMessage *msg) {
}

//void myRSU::populateAndSendPacket(veins::RSUMessage *pkt, int messageKind) {
//}

void myRSU::sendDown(cMessage *msg) {
}
