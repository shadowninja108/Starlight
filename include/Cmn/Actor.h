#pragma once

#include "types.h"

#include "Lp/Sys/actor.h"
#include "Lp/Sys/xlinkiuser.h"

namespace  Cmn
{
  class Actor {
      public:
        Lp::Sys::Actor lpActor;
        Lp::Sys::XLinkIUser xlinkUser;
        _QWORD qword320;
        _DWORD dword328;
        _QWORD qword330;
        _QWORD qword338;
        _QWORD qword340;
  };
};
