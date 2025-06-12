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

#ifndef APPLICATION_INTERSECTIONSAFETYAPP_H_
#define APPLICATION_INTERSECTIONSAFETYAPP_H_

#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"
#include "message/ObjectDetectionMessage_m.h"

namespace veins{

class VEINS_API IntersectionSafetyApp :public DemoBaseApplLayer{

protected:
        // For vehicle1
        bool detectionSent;
        int currentImagePacket;
        static const int PACKET_SIZE = 1000;
        std::vector<std::string> imageChunks;

        // For RSU
        std::map<std::string, std::map<int, ImagePacketMessage>> packetBuffers;

        virtual void initialize(int stage);
        virtual void handlePositionUpdate(cObject* obj);
        virtual void handleSelfMsg(cMessage* msg);
        virtual void onWSM(BaseFrame1609_4* frame);

        void sendObjectDetection();
        void sendImagePackets();
        void processImagePackets(ImagePacketMessage* imgMsg);
        void forwardProcessedData(std::string vehicleId);
};
}
#endif /* APPLICATION_INTERSECTIONSAFETYAPP_H_ */
