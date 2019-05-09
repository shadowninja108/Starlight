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

            s32 mGearID; // _0
            u32 _4;
            u32 _8;
            u32 _C;
            u32 _10; // ExSkillID
            u32 _14; // ^^
            u32 _18; // ^^
            u32 _1C;
        };
    };
};