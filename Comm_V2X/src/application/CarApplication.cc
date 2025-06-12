#include "CarApplication.h"

#include "veins/modules/utility/Consts80211p.h"
#include "veins/base/utils/SimpleAddress.h"
#include <fstream>
#include "util/base64.h"


Define_Module(CarApplication);

CarApplication::~CarApplication() {
    // TODO Auto-generated destructor stub
}

void CarApplication::initialize(int stage) {
    veins::BaseApplLayer::initialize(stage);

    if (stage == 0) {

        manager = veins::TraCIScenarioManagerAccess().get();
        ASSERT(manager);

        if (veins::FindModule<veins::TraCIMobility*>::findSubModule(getParentModule())) {
            carMobility = veins::TraCIMobilityAccess().get(getParentModule());
            carTraci = carMobility->getVehicleCommandInterface();
        }
        else {
            carMobility = nullptr;
            carTraci = nullptr;
        }

        annotationManager = veins::AnnotationManagerAccess().getIfExists();
        ASSERT(annotationManager);

        headerLength = par("headerLength");
        packetLength = par("packetLength");
        beaconingInterval = par("beaconingInterval");

    }
    if (stage == 3){
        myOmnetPosition = carMobility->getPositionAt(simTime());
        sumoId = carMobility->getExternalId();
        omnetId = this->getId();

        // create my neighbor table
        //myTable = new NeighborTable(omnetId);
        // schedule an event for removing outdated information from the neighbor table
        //updateNeighborTableTrigger = new cMessage("updateNT", UPDATE_NEIGHBOR_TABLE_EVT);
        //scheduleAt(simTime() + 1, updateNeighborTableTrigger);

        beaconingTrigger = new cMessage("beacon", SEND_PKT_BEACON_EVT);
        scheduleAt(simTime() + uniform(0, beaconingInterval), beaconingTrigger);


        // use these helper functions wherever required
        carMobility->getHeading().getRad();     // to get the heading of the car in radian angles
        myOmnetPosition.distance(veins::Coord(0,0));   // to get the distance to an arbitrary coordinate: Coord(0,0)
        manager->getManagedHosts().size();      // to get total number of SUMO nodes in the scenario
        /*
         * Draw a white line from myOmnetPosition to Coord(0,0) and schedule its erase in 0.1 second.
         * Can be used to visualize the path of a packet, drawing a line when it is received at the receiver.
         * Might be useful to see how the packet travels from hop to hop.
         * Change the erase timer according to your needs.
         * Frequent drawing in the GUI will slow down simulations.
         */
        annotationManager->scheduleErase(0.1,
                annotationManager->drawLine(myOmnetPosition, veins::Coord(0,0), "white")
                );

    }
}

void CarApplication::handleSelfMsg(cMessage* msg) {
    switch (msg->getKind()) {
    case SEND_PKT_BEACON_EVT: {
        veins::CarMessage* pkt = new veins::CarMessage("Beacon");
        pkt->setKind(BEACON);
        std::ifstream file("gettyimages-1282679063-612x612.jpg", std::ios::binary);
        std::ostringstream oss;
        oss << file.rdbuf();
        std::string base64_img = base64_encode(reinterpret_cast<const unsigned char*>(oss.str().c_str()), oss.str().length(), false);

        pkt->setImageData(base64_img.c_str());
        pkt->addBitLength(base64_img.length()*8);

        populateAndSendPacket(pkt);
        std::cout << "CarId: " << sumoId << "Car message - Object Detection" << std::endl;

        scheduleAt(simTime() + beaconingInterval, beaconingTrigger);
        break;
    }
    case RECORD_STATS_EVT: {
        // can be used for periodic statistics recording, if needed. You have to schedule an event for this to work
        break;
    }
    case UPDATE_NEIGHBOR_TABLE_EVT: {
        // remove all entries in neighbor table which are older than (beaconInterval X 2)
        myTable->purgeNodes(beaconingInterval * 2);
        // schedule next event to update neighbor table cleanup
        scheduleAt(simTime() + beaconingInterval, updateNeighborTableTrigger);
        break;
    }
    default: {
        throw new cRuntimeError("unknown self message type");
        break;
    }
    }
}


void CarApplication::handleLowerMsg(cMessage *msg) {
    veins::RSUMessage* pkt = dynamic_cast<veins::RSUMessage*>(msg);
    if (pkt) {
        std::cout << "CarId: " << sumoId << " -- It is a RSU message" << std::endl;
        switch (pkt->getKind()) {
        case AWARENESS: {
            if (simTime() - pkt->getTimestamp() > 10) {
                std::cout << "This awareness message has expired, time to discard it!" << std::endl;
            }
            else{
                // if needed, do something
            }
            break;
        }
        case EMERGENCY: {
            // if needed, do something
            break;
        }
        default:
            throw new cRuntimeError("unknown user priority of received packet!");
            break;
        }
    }
    else{
        veins::CarMessage* pkt = dynamic_cast<veins::CarMessage*>(msg);
        if (pkt) {
            std::cout << "CarId: " << sumoId << " -- It is a Car message" << std::endl;

            // if needed, do something
        }

    }
    delete msg;
}

void CarApplication::populateAndSendPacket(veins::CarMessage* pkt) {
    // populate the packet
    pkt->setRecipientAddress(veins::LAddress::L2BROADCAST());
    pkt->setBitLength(headerLength);
    pkt->addBitLength(packetLength);

    pkt->setPsid(-1);
    pkt->setChannelNumber(static_cast<int>(veins::Channel::cch));

    // send the packet to mac
    sendDown(pkt);
}

void CarApplication::sendDown(cMessage* msg) {
    veins::BaseApplLayer::sendDown(msg);
}

void CarApplication::handleLowerControl(cMessage *msg) {
    delete msg;
}

void CarApplication::finish() {
    cancelAndDelete(statsMsg);
    cancelAndDelete(beaconingTrigger);
    cancelAndDelete(updateNeighborTableTrigger);
}
