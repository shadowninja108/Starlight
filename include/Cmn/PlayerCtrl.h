#pragma once

#include "types.h"
#include "sead/vector.h"
#include "Lp/Sys/ctrl.h"

namespace Cmn {
    class PlayerCtrl {
        public:
        static Cmn::PlayerCtrl* sInstance;

        float getAngleVel();
        sead::Vector3<float>* getPostureX(void);
        sead::Vector3<float>* getPostureY(void);
        sead::Vector3<float>* getPostureZ(void);
        sead::Vector2<float>* getRightStick(void) const;
        bool isHold(unsigned long) const;
        bool isHoldAllAndTrigAny(unsigned long) const;
        bool isHoldContinue(unsigned long, int) const;
        bool isRelease(unsigned long) const;
        bool isTrig(unsigned long) const;
        bool isTrigWithRepeat(unsigned long) const;
        bool isTrigWithRepeat(unsigned long, int, int) const;

        Lp::Sys::Ctrl *lpController;
    };
};