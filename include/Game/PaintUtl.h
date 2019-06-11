#pragma once

#include "types.h"
#include "Cmn/Def/Team.h"

namespace Game {
    class PaintUtl {
        public:
        static void requestAllPaintFloor(unsigned int, Cmn::Def::Team);
        static void requestAllPaintWall(unsigned int, Cmn::Def::Team);
    };
};