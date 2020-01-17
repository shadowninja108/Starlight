#pragma once

#include "types.h"
#include "sead/heap.h"
#include "sead/string.h"
#include "sead/delegate.h"
#include "agl/lyr/renderinfo.h"

namespace agl {
    namespace lyr {
        #pragma pack(push, 1)
        class DrawMethod : public sead::IDisposer {
            public:
            sead::SafeStringBase<char> mStr;
            u64 DrawMethod_x10;
            u32 DrawMethod_x18;
            sead::Delegate1<agl::lyr::DrawMethod, agl::lyr::RenderInfo const&> mDelegate;
            u32 DrawMethod_x34;
        };
        #pragma pack(pop)
    };
};