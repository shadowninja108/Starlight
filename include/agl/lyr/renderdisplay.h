#pragma once

#include "types.h"
#include "agl/RenderBuffer.h"

namespace agl {
    namespace lyr {
        class RenderDisplay {
            public:
            virtual ~RenderDisplay();
            u16 RenderDisplay_x8;
            u16 RenderDisplay_xA;
            u16 RenderDisplay_xC;
            u16 RenderDisplay_xE;
            agl::RenderBuffer* mRenderBuffer1;
            u64 RenderDisplay_18[0x146];
            u32 RenderDisplay_A48;
            u32 RenderDisplay_A4C;
            u64 RenderDisplay_A50;
            agl::lyr::Layer** mLayers;
        };
    };
};