/**
 * @file arena.h
 * @brief Arena implementation for heaps.
 */

#pragma once

#include "nn/os.h"
#include "sead/heap.h"
#include "types.h"

namespace sead
{
    class Arena
    {
    public:
        Arena();
        ~Arena();

        void initialize(u64 size);
        void destroy();

        sead::Heap* heap;
        u64 mSize; // _8
        u8 mIsNotFreed; // _10
        u8 _11; // padding?
        u8 _12; // ^^
        u8 _13; // ^^
    };
};