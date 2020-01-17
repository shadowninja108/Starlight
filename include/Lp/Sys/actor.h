#include "types.h"

#include "sead/tree.h"
#include "sead/string.h"

#pragma once

namespace Lp {

  namespace Sys {

      class Actor{
        public:
          Actor();
          virtual ~Actor();

          u64 LpActor_x8;
          sead::TreeNode mTreeNodes[2];
          char LpActor_x60[0xB8];
          u64 LpActor_x118;
          u64 LpActor_x120;
          u64 LpActor_x128;
          u64 LpActor_x130;
          u64 LpActor_x138;
          u64 LpActor_x140;
          u64 LpActor_x148;
          u64 LpActor_x150[16];
          char LpActor_x1D0[136];
          u32 LpActor_x258;
          u32 LpActor_x25C;
          u64 mSystemTick; // _260
          _QWORD LpActor_x268;
          sead::BufferedSafeStringBase<char> mLpActorStr;
          char LpActor_x288[64];
          u64 LpActor_x2C8;
          u64 LpActor_x2D0;
          u64 LpActor_x2D8;
          u64 LpActor_x2E0;
      };

      class ActorClassIterNodeBase {
        public:
        Lp::Sys::Actor* derivedFrontActor();
        Lp::Sys::Actor* derivedNextActor(Lp::Sys::Actor*);
      };
  };
};