#pragma once

#include "types.h"
#include "Lp/Utl.h"

namespace Cmn {
    class PlayerCtrl {        
        public:
        static Cmn::PlayerCtrl* sInstance;

        sead::Vector3<float>* getAngleVel() const;
        sead::Vector3<float>* getPostureX(void) const;
        sead::Vector3<float>* getPostureY(void) const;
        sead::Vector3<float>* getPostureZ(void) const;
        sead::Vector2<float>* getRightStick(void) const;
        bool isHold(unsigned long) const;
        bool isHoldAllAndTrigAny(unsigned long) const;
        bool isHoldContinue(unsigned long, int) const;
        bool isRelease(unsigned long) const;
        bool isTrig(unsigned long) const;
        bool isTrigWithRepeat(unsigned long) const;
        bool isTrigWithRepeat(unsigned long, int, int) const;

        Lp::Utl::CtrlMaskConvert mMaskConverter;
        char PlaterCtrl_x108[0x20];
    };
};