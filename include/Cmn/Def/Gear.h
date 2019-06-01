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

            u32 mId;
            u32 _4;
            u32 _8;
            u32 mMainSkill;
            u32 mSkills[3];
            u32 _1C;
        };
    };
};
