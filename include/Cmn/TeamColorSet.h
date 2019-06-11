#pragma once

#include "types.h"
#include "sead/color.h"

namespace Cmn {
    class TeamColorSet {
        public:
        sead::Color4f alpha;
        sead::Color4f bravo;
        sead::Color4f neutral;
        sead::Color4f unk;
    };
};