#pragma once

#include "Mode.h"
#include "nn/nn.h"
#include "RomType.h"
#include "sead/string.h"
#include "types.h"

namespace Cmn
{
    namespace Def
    {
        class Instance
        {
            public:
            class SingletonDisposer
            {
            public:
                virtual ~SingletonDisposer();
            };

            Instance();

            virtual ~Instance();

            Cmn::Def::Mode sceneIdToMode(s32) const;

            u8 _0[0x30];
            s32 mAppVersion; // _30 (0x1D means has octo expansion)

            static Cmn::Def::Instance* sInstance;
        };

        s32 getAppVersion();
        sead::SafeStringBase<char> getAppVersionString();
        bool isAbleReferToOcta();
        Cmn::Def::RomType getRomType();
        void setRomType(Cmn::Def::RomType);
        nn::ApplicationId getApplicationId(Cmn::Def::RomType);
        bool isDevelopSeq();
        Cmn::Def::Mode sceneIdToMode(s32);
        Cmn::Def::Mode getCurMode();
        Cmn::Def::Mode getLastMode();
        Cmn::Def::Mode getNextMode();
        bool isMissionOrWorld(Cmn::Def::Mode);
        bool isMissionOrOcta(Cmn::Def::Mode);
        bool isCurModeMissionOrOcta();
        bool isOctaMode(Cmn::Def::Mode);
        bool isHaveFreeCommunicationPermission(bool);

        static Cmn::Def::RomType sRomType;
    };
};