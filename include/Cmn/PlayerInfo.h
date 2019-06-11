#pragma once

#include "types.h"
#include "Cmn/Def/MMR.h"
#include "Cmn/Def/Gear.h"
#include "Cmn/Def/Weapon.h"

namespace Cmn
{
    class PlayerInfo {
        public:
        u32 PlayerInfo_x0;
        u32 PlayerInfo_x4;
        u32 PlayerInfo_x8;
        u32 PlayerInfo_xC;
        u32 mPlayerIndex;
        u16 unk; //Always 1
        char16_t mPlayerName[17];
        Cmn::Def::Team mTeam;
        u32 mModelType;
        u32 mModelId;
        u32 mSkinColorId;
        u32 mEyeColorId;
        Cmn::Def::Weapon mWeapon;
        u32 PlayerInfo_x5C;
        u32 PlayerInfo_x60;
        Cmn::Def::Gear mGears[3];
        u32 PlayerInfo_xC4;
        u32 mBottomId;
        sead::Color4f mColor; //Only used for the plaza NPCs ?
        u32 mPlayerRank;
        u32 mStarRank;
        u32 mUdemaeGrades[5];
        u32 PlayerInfo_xF8;
        u32 PlayerInfo_xFC;
        Cmn::Def::MMR mMMR1;
        Cmn::Def::MMR mMMR2;
        char gap_x120[0x80];

        void setPlayerRank(int);
        void dbgSetPlayerName(sead::SafeStringBase<char> const&);
    };
};
