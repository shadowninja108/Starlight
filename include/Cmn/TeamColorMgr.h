#pragma once

#include "types.h"
#include "sead/color.h"
#include "sead/string.h"
#include "sead/array.h"
#include "Cmn/Def/Team.h"
#include "Cmn/TeamColorSet.h"
//#include "Cmn/TeamColorParam.h"

namespace Cmn {
    class TeamColorMgr {
        public:
        enum ColorVariation {
            COLOR_0,
            COLOR_1,
            COLOR_2,
            COLOR_3,
            COLOR_4,
            COLOR_5,
            COLOR_6,
            COLOR_7,
            COLOR_8,
            COLOR_9,
            COLOR_A,
            COLOR_B,
        };

        /*struct TeamColorParamArry {
            u64 length;
            Cmn::TeamColorParam params[0x20];
        };*/

        struct TeamColorParamEntry
        {
            #pragma pack(push, 1)
            Cmn::TeamColorParam *mParamLookup;
            u32 mStart;
            s32 mBeginningOfLookup;
            s32 mLengthOfLookup;
            u32 unk;
            #pragma pack(pop)
        };

    
        char somethin[0x10];
        TeamColorParamEntry entries[10];
        _BYTE gap100[24];
        float gap118[12];
        _QWORD qword148;
        _QWORD qword150;
        _DWORD dword158;
        _QWORD qword160;
        _QWORD qword168;
        _DWORD dword170;
        Cmn::TeamColorSet teamColorSet;


        //static void calcSubColorSet(sead::SafeArray<sead::SafeArray<sead::Color4f, 12>, 4>&, Cmn::TeamColorSet const&);
        void updateInkColor(float);
        sead::Color4f* getCurColor(Cmn::Def::Team, Cmn::TeamColorMgr::ColorVariation) const;
    };
};