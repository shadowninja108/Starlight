#pragma once

#include "types.h"
#include "sead/vector.h"

namespace Game {
    namespace PlayerGamePadData {
        class FrameInput {
            public:
            void record();

            _BYTE buttons[10];
            sead::Vector2<float> leftStick;
            sead::Vector2<float> rightStick;
            sead::Vector3<float> angleVel;
            sead::Vector3<float> postureX;
            sead::Vector3<float> postureY;
            sead::Vector3<float> postureZ;
        };
    };
};