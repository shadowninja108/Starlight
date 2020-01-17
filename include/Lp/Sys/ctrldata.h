#pragma once

#include "types.h"

namespace Lp {
    namespace Sys {
        enum Key {
            KEY_A = 1 << 0,
            KEY_B = 1 << 1,
            KEY_ZL = 1 << 2,
            KEY_Y = 1 << 3,
            KEY_X = 1 << 4,
            KEY_ZR = 1 << 5,
            KEY_RSTICK = 1 << 6,
            KEY_LSTICK = 1 << 7,

            KEY_UNK1 = 1 << 8,
            KEY_MINUS = 1 << 9,
            KEY_PLUS = 1 << 10,
            KEY_PLUS_ALT = 1 << 11,
            KEY_MINUS_ALT = 1 << 12,
            KEY_L = 1 << 13,
            KEY_R = 1 << 14,
            KEY_UNK2 = 1 << 15,

            KEY_DUP = 1 << 16,
            KEY_DDOWN = 1 << 17,
            KEY_DLEFT = 1 << 18,
            KEY_DRIGHT = 1 << 19,
            KEY_LSTICK_UP = 1 << 20,
            KEY_LSTICK_DOWN = 1 << 21,
            KEY_LSTICK_LEFT = 1 << 22,
            KEY_LSTICK_RIGHT = 1 << 23,

            KEY_RSTICK_UP = 1 << 24,
            KEY_RSTICK_DOWN = 1 << 25,
            KEY_RSTICK_LEFT = 1 << 26,
            KEY_RSTICK_RIGHT = 1 << 27,
        };

        class CtrlData {
            public:
            Key mButtons;
            u32 CtrlData_x4[32];
            u32 CtrlData_x84;
            u32 CtrlData_x88;
            u32 CtrlData_x8C;
            sead::Vector2<float> mLeftStick;
            sead::Vector2<float> mRightStick;
        };

        class __attribute__ ((packed)) CtrlData200Hz {
            public:
            u64 CtrlData200Hz_x0;
            u32 CtrlData200Hz_x8;
            u64 CtrlData200Hz_xC;
            u32 CtrlData200Hz_x14;
            u128 CtrlData200Hz_x18[6];
            u64 CtrlData200Hz_x78;
            u32 CtrlData200Hz_x80;
            u64 CtrlData200Hz_x84;
            u32 CtrlData200Hz_x8C;
            u64 CtrlData200Hz_x90;
            u32 CtrlData200Hz_x98;
            u64 CtrlData200Hz_x9C;
            u32 CtrlData200Hz_xA4;
        };
    };
};