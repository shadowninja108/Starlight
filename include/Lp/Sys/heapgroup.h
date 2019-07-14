#pragma once

#include "types.h"

#include "sead/heap.h"
#include "sead/mutex.h"

namespace Lp {
    namespace Sys {
        class HeapGroup {
            public:
            static Lp::Sys::HeapGroup *sInstance;

            _QWORD qword8;
            sead::CriticalSection *mutex;
            __int64 lock; //sead::ReadWriteLock *
            sead::IDisposer disposer;
            sead::Heap *heaps[7];

            virtual ~HeapGroup();

            enum Group {
                cSys, cGfx, cRes, cSnd, cScene, cDbg, cOthers
            };
        };
    };
};