#pragma once

#include "types.h"

namespace sead {
    template <class T, u64 size>
    class FixedRingBuffer {
        T* mBufferPtr;
        u64 mSize;
        u64 mUnk;
        T mBuffer[size];
    };
}