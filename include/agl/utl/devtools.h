#include "types.h"
#include "agl/DrawContext.h"
#include "sead/vector.h"
#include "sead/color.h"

#pragma once

namespace agl {
    namespace utl {
        class DevTools{
            public:
            void static drawTriangleImm(agl::DrawContext* drawContext, sead::Vector3<float>* p1, sead::Vector3<float>* p2, sead::Vector3<float>* p3, sead::Color4f* color);
        };
    };
};