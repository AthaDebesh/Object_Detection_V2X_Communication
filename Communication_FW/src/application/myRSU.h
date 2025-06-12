
#pragma once

#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"


namespace veins {
/**
 * Small RSU Demo using 11p
 */
class VEINS_API myRSU : public DemoBaseApplLayer {
public:
    void initialize(int stage) override;
protected:
    void onWSM(BaseFrame1609_4* wsm) override;
};
}
