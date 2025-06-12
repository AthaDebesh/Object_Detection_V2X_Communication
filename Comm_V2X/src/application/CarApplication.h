#ifndef C2XAPPLICATION_H_
#define C2XAPPLICATION_H_

#include "veins/base/modules/BaseApplLayer.h"
#include "veins/modules/mobility/traci/TraCIMobility.h"
#include "../util/NeighborTable.h"
#include "../message/RSUMessage_m.h"
#include "../message/CarMessage_m.h"

class CarApplication : public veins::BaseApplLayer{
public:
    ~CarApplication() override;
    void initialize(int stage) override;
    void finish() override;
    virtual int numInitStages() const override
    {
        return 4;
    }

    enum CarEventKinds {
        SEND_PKT_BEACON_EVT = LAST_BASE_APPL_MESSAGE_KIND + 1,
        RECORD_STATS_EVT = LAST_BASE_APPL_MESSAGE_KIND + 2,
        UPDATE_NEIGHBOR_TABLE_EVT = LAST_BASE_APPL_MESSAGE_KIND + 3
    };

protected:
    /** @brief handle messages from below and calls the onWSM, onBSM, and onWSA functions accordingly */
    void handleLowerMsg(cMessage* msg) override;

    /**
     * @brief Handle control messages from lower layer
     **/
    void handleLowerControl(cMessage* msg) override;

    /** @brief handle self messages */
    void handleSelfMsg(cMessage* msg) override;

    void populateAndSendPacket(veins::CarMessage* pkt);
    /**
     * @brief overloaded for error handling and stats recording purposes
     *
     * @param msg the message to be sent. Must be a WSM/BSM/WSA
     */
    virtual void sendDown(cMessage* msg);

protected:
    veins::TraCIScenarioManager* manager;
    veins::TraCIMobility* carMobility;
    veins::TraCICommandInterface::Vehicle* carTraci;
    veins::Coord myOmnetPosition;
    veins::AnnotationManager* annotationManager;
    NeighborTable* myTable;

    int omnetId;
    std::string sumoId;

    int packetLength;
    double beaconingInterval;

    cMessage* statsMsg;
    cMessage* beaconingTrigger;
    cMessage* updateNeighborTableTrigger;

};

#endif /* C2XAPPLICATION_H_ */
