#pragma once

#include "types.h"

namespace Cmn {
    class WeaponData {
        public:
        _DWORD id;
        _DWORD index;
        sead::BufferedSafeStringBase<char> name;
        _BYTE gap20[64];
        sead::BufferedSafeStringBase<char> modelName;
        _BYTE gap78[64];
        sead::BufferedSafeStringBase<char> arcName;
        _BYTE gapD0[64];
        _QWORD qword110;
        signed __int64 signed118;
        _QWORD qword120;
        _DWORD dword128;
        _BYTE gap12C[4];
        sead::BufferedSafeStringBase<char> sub;
        _BYTE gap148[64];
        sead::BufferedSafeStringBase<char> special;
        _BYTE gap1A0[64];
        _DWORD specialCost;
        _DWORD price;
        _DWORD rank;
        _DWORD lock;
        _DWORD coopAddition;
        _DWORD uiRefId;
        _BYTE isPressRelease;
        _BYTE gap1F9[7];
        sead::BufferedSafeStringBase<char> unkStr200;
        _BYTE gap218[64];
        _DWORD dword258;
        _BYTE gap25C[4];
        sead::BufferedSafeStringBase<char> unkStr260;
        _BYTE gap278[64];
        _DWORD dword2B8;
        _BYTE gap2BC[4];
        sead::BufferedSafeStringBase<char> unkStr2C0;
        _BYTE gap2D8[64];
        _DWORD dword318;
        _BYTE gap31C[4];
        _DWORD cl;
        int cm;
        int cs;
    };
};