#pragma once

#include "types.h"
#include "sead/textwriter.h"
#include "sead/viewport.h"
#include "sead/context.h"
#include "sead/color.h"

namespace aal {
    class DebugDrawer {
        public:
        DebugDrawer(sead::TextWriter*);
        DebugDrawer(sead::Viewport*);

        void begin(sead::DrawContext*);
        void end();

        void drawLine(sead::Vector2<float> const&, sead::Vector2<float> const&, sead::Color4f const&);
    };
};