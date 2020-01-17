#pragma once

#include "types.h"
#include "Cmn/Def/WeaponClassType.h"
#include "Cmn/Def/CustomPartsMaterial.h"

namespace Cmn {
    class WeaponData
    {
        public:
        enum class DoubleType
        {
            None = 0x0,
            Each = 0x1,
            Same = 0x2,
            Mirror = 0x3,
        };
        enum class ParamLevel
        {
            Low = 0x0,
            Middle = 0x1,
            High = 0x2,
        };
        enum class LockType
        {
            None = 0x0,
            Bcat = 0x1,
            NotForSale = 0x2,
            Mission = 0x3,
            MissionBcat = 0x4,
            Other = 0x5
        };

        struct ParamEntry //unofficial name
        {
            sead::BufferedSafeStringBase<char> mParamName;
            char mParamNameData[64];
            int mParamValue;
            int padd;
        };

    public:
        int mId;
        Cmn::Def::WeaponKind mWeaponKind;
        sead::BufferedSafeStringBase<char> mName;
        char mNameData[64];
        sead::BufferedSafeStringBase<char> mModelName;
        char mModelNameData[64];
        sead::BufferedSafeStringBase<char> mArcName;
        char mArcNameData[64];
        Cmn::Def::CustomPartsMaterial mCustomPartsMaterial;
        Cmn::Def::WeaponClassType mWeaponClassType;
        int WeaponData_x118;
        int WeaponData_x11C;
        DoubleType mDoubleType;
        ParamLevel mInkSaverLv;
        ParamLevel mMoveVelLv;
        int WeaponData_x12C;
        sead::BufferedSafeStringBase<char> mSub;
        char mSubData[64];
        sead::BufferedSafeStringBase<char> mSpecial;
        char mSpecialData[64];
        int mSpecialCost;
        int mPrice;
        int mRank;
        LockType mLockType;
        int mCoopAddition;
        int mUIRefId;
        bool mIsPressRelease;
        int WeaponData_x1FC;
        ParamEntry mParams[3];
        int CL;
        int CM;
        int CS;
    };

};