#pragma once

#include "types.h"
#include "MushWeaponInfo.h"
#include "MushMapInfo.h"
#include "sead/heap.h"

namespace Cmn {
    class MushDataHolder {
        public:
        static Cmn::MushDataHolder* sInstance;

        _BYTE gap0[32];
        sead::Heap *heap;
         Cmn::MushMapInfo* mushMapInfo;
        __int64 mushHairInfo;// Cmn::MushHairInfo *
        __int64 mushGearInfo;// Cmn::MushGearInfo *
        __int64 mushTankInfo;// Cmn::MushTankInfo *
        __int64 mushBottomInfo;// Cmn::MushBottomInfo *
        Cmn::MushWeaponInfo *mushWeaponInfo;
    };
}