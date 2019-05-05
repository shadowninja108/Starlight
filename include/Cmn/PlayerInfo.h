#pragma once

#include "types.h"
#include "Cmn/Def/MMR.h"
#include "Cmn/Def/Gear.h"
#include "Cmn/Def/Weapon.h"

namespace Cmn
{
    class PlayerInfo {
        public:
        int vtable;
        _BYTE gap4[16];
        _BYTE field_14;
        _BYTE field_15;
        __attribute__((packed)) __attribute__((aligned(1))) char *name;
        _BYTE gap1E[26];
        __int64 modelType;
        __int32 hairId;
        __int32 skinColor;
        __int32 eyeColor;
        __attribute__((packed)) __attribute__((aligned(1))) Cmn::Def::Weapon weapon;
        _WORD word5C;
        _BYTE gap5E[6];
        Cmn::Def::Gear gear[3];
        __int32 tankId;
        __int32 bottomInfo;
        _DWORD dwordCC;
        _DWORD dwordD0;
        _DWORD dwordD4;
        float dwordD8;
        __int32 rank;
        __int32 starRank;
        __int32 udemaeGrade[6];
        _DWORD dwordFC;
        Cmn::Def::MMR mmr1;
        Cmn::Def::MMR mmr2;
        _BYTE gap120[4];
        __attribute__((packed)) __attribute__((aligned(1))) _QWORD qword124;
        __attribute__((packed)) __attribute__((aligned(1))) _QWORD qword12C;
        _BYTE gap134[28];
        _DWORD dword150;
        __attribute__((aligned(8))) _DWORD dword158;
        __attribute__((aligned(8))) Cmn::Def::MMR mmr3;
    };
};