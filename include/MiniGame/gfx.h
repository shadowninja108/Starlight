#pragma once

#include "types.h"
#include "agl/lyr/renderinfo.h"
#include "sead/vector.h"
#include "sead/color.h"

namespace MiniGame {
    class Gfx {
        public:
        static void drawLine(agl::lyr::RenderInfo const&, sead::Vector2<float> const&, sead::Vector2<float> const&, float, sead::Color4f const&);
    };
};