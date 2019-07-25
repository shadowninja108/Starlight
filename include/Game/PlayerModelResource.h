#pragma once

#include "types.h"
#include "sead/array.h"
#include "Lp/Sys/model.h"

namespace Game {
    class PlayerModelResource {
        public:
        sead::PtrArrayImpl mHumanArcs;
        Lp::Sys::ModelArc *mHumanArcBuffer[8];
        sead::PtrArrayImpl mHalfArcs;
        Lp::Sys::ModelArc *mHalfArcBuffer[8];
        sead::PtrArrayImpl mSquidArcs;
        Lp::Sys::ModelArc *mSquidArcBuffer[8];
        sead::PtrArrayImpl mHumanAnimArcs;
        Lp::Sys::ModelArc *mHumanAnimArcBuffer[8];
        sead::PtrArrayImpl mHumanExAnimArcs;
        Lp::Sys::ModelArc *mHumanExAnimArcBuffer[8];
        sead::PtrArrayImpl mSquidAnimArcs;
        Lp::Sys::ModelArc *mSquidAnimArcBuffer[8];
        sead::PtrArrayImpl mHairArcs[8];
    };
};