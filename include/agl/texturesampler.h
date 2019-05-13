#include "types.h"
#include "agl/detail/samplerobj.h"
#include "agl/driver/NVNsampler.h"
#include "agl/TextureData.h"

#pragma once

namespace agl {
    class TextureSampler {
        public:
            driver::NVNsampler_ nvnSampler;
            TextureData textureData;
            detail::SamplerObject samplerObj;
            _DWORD compSel;
            unsigned int unsigned160;
            _BYTE byte164;
            _QWORD string;
    };
};