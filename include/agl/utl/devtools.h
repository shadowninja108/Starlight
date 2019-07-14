#include "types.h"
#include "agl/DrawContext.h"
#include "sead/vector.h"
#include "sead/color.h"

#pragma once

namespace agl {
    namespace utl {
        class DevTools{
            public:
            void static beginDrawImm(agl::DrawContext *,sead::Matrix34<float> const&,sead::Matrix44<float> const&);
            void static drawTriangleImm(agl::DrawContext*, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Color4f const&);
            void static drawLineImm(agl::DrawContext*, sead::Vector3<float> const&, sead::Vector3<float> const&, sead::Color4f const&, float);
        };
    };
};