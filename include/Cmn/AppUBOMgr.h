#pragma once

#include "types.h"
#include "sead/heap.h"
#include "agl/util.h"


namespace Cmn {
    class AppUBOMgr : sead::IDisposer {
        public:
        static Cmn::AppUBOMgr *sInstance;

        /*
        agl::UniformBlock agl::uniformblock20;
        agl::UniformBlock agl::uniformblock98;
        _BYTE byte110;
        sead::Color4f colors[18];
        */

        void updateUBO(bool);
    };
};