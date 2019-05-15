#pragma once

#include "types.h"
#include "Cmn/Def/Team.h"

namespace Game {
    class PaintUtl {
        void requestAllPaintFloor(unsigned int, Cmn::Def::Team);
        void requestAllPaintWall(unsigned int, Cmn::Def::Team);
    };
};