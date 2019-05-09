#pragma once

#include "types.h"
#include "sead/array.h"

namespace Game {
    class PlayerModelResource {
        sead::PtrArrayImpl ptrArray1;
        char char10;
        _BYTE gap11[63];
        sead::PtrArrayImpl ptrArray2;
        char char60;
        _BYTE gap61[63];
        sead::PtrArrayImpl ptrArray2;
        char charB0;
        _BYTE gapB1[63];
        char qwordF0[128];
    };
};