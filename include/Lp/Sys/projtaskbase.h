#pragma once

#include "types.h"

#include "sead/task.h"
#include "agl/lyr/drawmethod.h"

namespace Lp {
    namespace Sys {
        class ProjTaskBase : public sead::CalculateTask {
            public:
            agl::lyr::DrawMethod mDrawMethod1;
            agl::lyr::DrawMethod mDrawMethod2;
        };
    };
};