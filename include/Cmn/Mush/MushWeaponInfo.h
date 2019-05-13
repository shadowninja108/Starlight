#pragma once

#include "types.h"
#include "sead/string.h"
#include "MushInfoKindBase.h"
#include "Cmn/WeaponData.h"
#include "Cmn/Def/WeaponKind.h"

namespace Cmn {

    class MushWeaponInfo : public MushInfoWithKindBase<Cmn::WeaponData,Cmn::Def::WeaponKind>
    {
        public:
        Cmn::WeaponData* searchByName(Cmn::Def::WeaponKind, sead::SafeStringBase<char> const&) const; 
    };
};
