#ifndef C2XAPPLICATION_H_
#define C2XAPPLICATION_H_

#include "veins/base/modules/BaseApplLayer.h"
#include "veins/base/modules/BaseMobility.h"
#include "veins/modules/world/annotations/AnnotationManager.h"
#include "veins/modules/mobility/traci/TraCICoordinateTransformation.h"
#include "../message/RSUMessage_m.h"
#include "../message/CarMessage_m.h"


class RSUApplication : public veins::BaseApplLayer{
public:
    ~RSUApplication() override;
    void initialize(int stage) override;
    void finish() override;
    virtual int numInitStages() const override
    {
        return 4;
    }

    enum RSUEventKinds {
        SEND_PKT_AWARENESS_EVT = LAST_BASE_APPL_MESSAGE_KIND + 1,
        SEND_PKT_EMERGENCY_EVT = LAST_BASE_APPL_MESSAGE_KIND + 2,
        RECORD_STATS_EVT = LAST_BASE_APPL_MESSAGE_KIND + 3
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

    void populateAndSendPacket(veins::RSUMessage* pkt, int messageKind);
    /**
     * @brief overloaded for error handling and stats recording purposes
     *
     * @param msg the message to be sent. Must be a WSM/BSM/WSA
     */
    virtual void sendDown(cMessage* msg);

protected:

    //bool source;
    int rsuId;
    int packetLength;
    veins::Coord myOmnetPosition;
    veins::TraCICoord myTraciPosition;
    veins::BaseMobility* rsuMobility;
    veins::AnnotationManager* annotationManager;
    veins::TraCICoordinateTransformation* coordTransformer;

    cMessage* awarenessTrafficTrigger;
    cMessage* emergencyTrafficTrigger;
    cMessage* statsMsg;
};

#endif /* C2XAPPLICATION_H_ */
