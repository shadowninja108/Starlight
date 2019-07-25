#pragma once

#include "types.h"
#include "sead/heap.h"
#include "TeamColorMgr.h"

namespace Cmn
{
    class GfxSetting {
        public:
        static Cmn::GfxSetting* sInstance;

        u64 mUnk;
        sead::IDisposer mDisposer;
        Cmn::TeamColorMgr* mTeamColorMgr;

        void load();
        void updateInkParams(float);
        virtual ~GfxSetting();        
    };
}