#pragma once

#include "types.h"
#include "Sys/ctrl.h"

namespace Lp
{
    class Utl {
        public:
        static Sys::Ctrl* getCtrl(int);
    };
};
