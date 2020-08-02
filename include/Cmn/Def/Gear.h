#pragma once

#include "types.h"

namespace Cmn
{
    namespace Def
    {
        class Gear
        {
        public:
            Gear();

            void resetExpAndExSkillAll();

            s32 mGearId;
            u32 mUnlockedSkillCount;
            u32 mUnlockedSlotCount;
            s32 mMainSkillId;
            s32 mSubSkillIds[3];
            u32 mGearExp;
        };
    };
};
