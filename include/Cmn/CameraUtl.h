#pragma once

#include "types.h"
#include "sead/vector.h"
#include "sead/camera.h"

namespace Cmn {

    enum CameraUtl_Layer : s32 {
        Layer1 = -999,
        Layer2 = -998
    };

    template<CameraUtl_Layer T>
    class CameraUtl {
        public:
        static sead::Vector3<float> worldToScreenPos(sead::Vector3<float> const&);
        static sead::Camera* getRenderCamera();
        static sead::Viewport* getRenderViewport();
        static sead::Projection* getRenderProjection();
    };
};