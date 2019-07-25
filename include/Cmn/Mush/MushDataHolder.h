#pragma once

#include "types.h"
#include "MushWeaponInfo.h"
#include "MushMapInfo.h"
#include "sead/heap.h"

namespace Cmn {
    class MushDataHolder {
        public:
        static Cmn::MushDataHolder* sInstance;

        sead::IDisposer mDisposer;
        sead::Heap *mHeap;
        Cmn::MushMapInfo* mMushMapInfo;
        __int64 mMushHairInfo;// Cmn::MushHairInfo *
        __int64 mMushGearInfo;// Cmn::MushGearInfo *
        __int64 mMushTankInfo;// Cmn::MushTankInfo *
        __int64 mMushBottomInfo;// Cmn::MushBottomInfo *
        Cmn::MushWeaponInfo *mMushWeaponInfo;
    };
}