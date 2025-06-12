
#include "myRSU.h"

#include "veins/modules/utility/Consts80211p.h"
#include "veins/base/utils/SimpleAddress.h"
#include "util/base64.h"

#include "message/NumVehicleMsg_m.h"
#include "message/CarMessage_m.h"

Define_Module(veins::myRSU);

void veins::myRSU::initialize(int stage)
{
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        currentOfferedServiceId = 17; // whatever number you'd like

        headerLength = par("headerLength");
        packetLength = par("packetLength");
    }
    else if (stage == 1){
        startService(Channel::sch1, currentOfferedServiceId, "NumVehicle Service");
        // Let‘s not use the SCH for now
    }
}

/*void veins::MyRSU::onWSA(DemoServiceAdvertisment* wsa)
{
    // if this RSU receives a WSA for service 42, it will tune to the chan
    if (wsa->getPsid() == 42) {
        mac->changeServiceChannel(static_cast<Channel>(wsa->getTargetChannel()));
    }
}
*/
void veins::myRSU::onWSM(BaseFrame1609_4* frame)
{
    NumVehicleMsg* wsm = dynamic_cast<NumVehicleMsg*>(frame);

    if(wsm){
            Coord senderPos = wsm->getSenderPos();
            double distance = (senderPos - curPosition).length();
            std::cout << "CarId: " << wsm->getSenderAddress() << " Distance: " << distance << "\n";
        }

    else{
        CarMessage* wsm = dynamic_cast<CarMessage*>(frame);
        if(wsm)
        {
            if(RSU_inference)
            {
                std::cout << "Received Image data!!";
                std::string b64img = wsm->getImageData();
                std::string decoded_img = base64_decode(b64img);
                std::ofstream outFile("received_image.png", std::ios::binary);
                outFile.write(decoded_img.c_str(), decoded_img.size());
                outFile.close();

                std::string resultJson = runInferenceAndGetResult("received_image.png");

                auto result = json::parse(resultJson);
            }

            else if(on_board_inference)
            {
                std::cout << "Received Image data!!";

            }
        }

    }

    // this rsu repeats the received traffic update in 2 seconds plus some random delay
    //sendDelayedDown(wsm->dup(), 2 + uniform(0.01, 0.2));
}
