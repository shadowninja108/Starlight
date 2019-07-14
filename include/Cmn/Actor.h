#pragma once

#include "types.h"

#include "Lp/Sys/actor.h"
#include "Lp/Sys/xlinkiuser.h"
#include "Cmn/Def/Team.h"

namespace Cmn
{
  class Actor : public Lp::Sys::Actor, public Lp::Sys::XLinkIUser
  {
      public:
        u64* mXLink; // Lp::Sys::XLink*
        Cmn::Def::Team mTeam;
        u32 CmnActor_32C;
        u64* CmnActor_330; // Cmn::ComponentHolder*
        gsys::Model *mActorFullModel;
        u64* CmnActor_340; // Lp::Utl::StateMachine*
  };
};