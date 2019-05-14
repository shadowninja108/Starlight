#pragma once

#include "types.h"

namespace Cmn {
    namespace Def {
        class AmiiboData {
            public:
            int mVersion;
            char gap_x4[0x1C];
            int mModelType;
            char gap_x24[0xB4];
        };
    };
};