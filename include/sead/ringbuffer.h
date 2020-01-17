#pragma once

#include "types.h"

namespace sead {
    template <class T>
    class RingBuffer {
        public:
        T* mBufferPtr;
        u32 mUnk1;
        u32 mUnk2;
        u32 mUnk3;
        u32 mUnk4;
    };

    template<class T, u32 size>
    class FixedRingBuffer : public RingBuffer<T> {
        public:
        T mBuffer[size];
    };
}