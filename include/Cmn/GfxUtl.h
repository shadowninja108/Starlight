#pragma once

#include "types.h"

#include "sead/color.h"
#include "gsys/model.h"

namespace Cmn {
    class GfxUtl {
        public:
        static void replaceTeamColor(gsys::Model *, sead::Color4f const&);
        static void replaceAlphaBravoColorForCalcColor_(gsys::Model*, sead::Color4f const&, sead::Color4f const&);
    };
};