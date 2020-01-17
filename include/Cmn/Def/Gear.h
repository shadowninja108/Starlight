#pragma once

#include "types.h"

namespace Cmn
{
    namespace Def
    {
        enum GearKind {
            GearKind_cNone = 0,
            GearKind_cShoes = 1,
            GearKind_cClothes = 2,
            GearKind_cHead = 3 
        };

        class Gear
        {
        public:
            Gear();

            void resetExpAndExSkillAll();

            u32 mId;
            u32 mUnlockedSlotCount;
            u32 _8;
            u32 mMainSkill;
            u32 mSkills[3];
            u32 _1C;
        };
    };
};
