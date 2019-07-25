#pragma once

#include "types.h"

#include "sead/heap.h"
#include "sead/mutex.h"
#include "sead/critical.h"

namespace Lp {
    namespace Sys {
        class HeapGroup {
            public:
            static Lp::Sys::HeapGroup *sInstance;

            u64 HeapGroup_x8;
            sead::CriticalSection mMutex;
            char mRWLock[0xB8]; //sead::ReadWriteLock
            sead::IDisposer mDisposer;
            sead::ExpHeap *mHeaps[7];

            virtual ~HeapGroup();

            enum Group {
                cSys, cGfx, cRes, cSnd, cScene, cDbg, cOthers
            };
        };
    };
};