#pragma once

#include "types.h"
#include "Cmn/Def/MMR.h"
#include "Cmn/Def/Gear.h"
#include "Cmn/Def/Weapon.h"

namespace Cmn
{
    class PlayerInfo {
        public:
        int PlayerInfo_x0;
        int PlayerInfo_x4;
        int PlayerInfo_x8;
        int PlayerInfo_xC;
        u32 mPlayerIndex;
        u16 unk; //Always 1
        char16_t mPlayerName[17];
        int mTeam;
        int mModelType;
        int mModelId;
        int mSkinColorId;
        int mEyeColorId;
        Cmn::Def::Weapon mWeapon;
        int PlayerInfo_x5C;
        int PlayerInfo_x60;
        Cmn::Def::Gear mGears[3];
        int PlayerInfo_xC4;
        u32 mBottomId;
        sead::Color4f mColor; //Only used for the plaza NPCs ?
        u32 mPlayerRank;
        u32 mStarRank;
        u32 mUdemaeGrades[5];
        int PlayerInfo_xF8;
        int PlayerInfo_xFC;
        Cmn::Def::MMR mMMR1;
        Cmn::Def::MMR mMMR2;
        char gap_x120[0x80];

        void setPlayerRank(int);
        void dbgSetPlayerName(sead::SafeStringBase<char> const&);
    };
};
