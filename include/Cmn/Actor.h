#pragma once

#include "types.h"

#include "Lp/Sys/actor.h"
#include "Lp/Sys/xlinkiuser.h"

namespace Cmn
{
  class Actor : public Lp::Sys::Actor, Lp::Sys::XLinkIUser
  {
      public:
        u64* _320; // Lp::Sys::XLink*
        u64 _328;
        u64* _330; // Cmn::ComponentHolder*
        u64 _338;
        u64* _340; // Lp::Utl::StateMachine*
  };
};