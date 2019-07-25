#pragma once

#include "types.h"
#include "sead/heap.h"
#include "renderdisplay.h"

namespace agl {
    namespace lyr {
        class Renderer {
            public:
            static agl::lyr::Renderer* sInstance;
            
            sead::IDisposer mDisposer;
            u64 Renderer_x28;
            u64 mDisplayCount;
            agl::lyr::RenderDisplay** mDisplays; 

            virtual ~Renderer();
        };
    };
};