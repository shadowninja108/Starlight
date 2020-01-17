#pragma once

#include "types.h"
#include "sead/textwriter.h"
#include "starlight/collector.hpp"

namespace starlight {
    
    namespace mush {
        
        class Entry {
            public:
            s64 Entry_x0;
            u64* Entry_x8;
            u64* Entry_x10;
            u32 Entry_x18;
            u32 Entry_x1C;
            u64* Entry_x20;
            u64* Entry_x28;
            u64 Entry_x30[5];
        };

        class MushView {
            public:
            virtual int getSize() = 0;
            virtual void render(sead::TextWriter*, int) = 0;
        };

        class MapMushView : public MushView {
            public:
            virtual int getSize();
            virtual void render(sead::TextWriter*, int);
        };

        class WeaponMushView : public MushView {
            public:
            virtual int getSize();
            virtual void render(sead::TextWriter*, int);
        };
    };
};