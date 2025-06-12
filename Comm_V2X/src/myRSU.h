
#pragma once

#include "veins/base/modules/BaseApplLayer.h"
#include "veins/base/modules/BaseMobility.h"
#include "veins/modules/world/annotations/AnnotationManager.h"
#include "veins/modules/mobility/traci/TraCICoordinateTransformation.h"


class myRSU : public veins::BaseApplLayer {

public:
    ~myRSU() override;
     void initialize(int stage) override;
     void finish() override;
     virtual int numInitStages() const override
     {
         return 4;
     }

protected:
    /** @brief handle messages from below and calls the onWSM, onBSM, and onWSA functions accordingly */
    void handleLowerMsg(cMessage* msg) override;

    /**
     * @brief Handle control messages from lower layer
     **/
    void handleLowerControl(cMessage* msg) override;

    /** @brief handle self messages */
    void handleSelfMsg(cMessage* msg) override;

    //void populateAndSendPacket(veins::RSUMessage* pkt, int messageKind);
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

    cMessage* statsMsg;
};
