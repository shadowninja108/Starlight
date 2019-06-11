#pragma once

#include "types.h"
#include "sead/heap.h"
#include "TeamColorMgr.h"

namespace Cmn
{
    class GfxSetting :sead::IDisposer {
        public:
        static Cmn::GfxSetting* sInstance;

        Cmn::TeamColorMgr* mTeamColorMgr;

        void load();
        void updateInkParams(float);
        virtual ~GfxSetting();        
    };
}