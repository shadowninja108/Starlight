#pragma once

#include "types.h"

#include "sead/heap.h"

namespace Cmn{
    class GfxMgr : sead::Disposer {
        public:
        gsys::ModelScene *modelScene;
        sead::BufferedSafeStringBase qword38;
        _BYTE gap50[32];
        _QWORD qword70;
        char *pchar78;
        _DWORD dword80;
        _BYTE gap84[36];
        unsigned int hour;
        _BYTE gapAC[4];
        _QWORD qwordB0;
        _QWORD qwordB8;
        Cmn::GPUPerfController *gpuPerfController;
        _QWORD qwordC8;
        agl::utl::DebugTexturePage debugTexturePage;
        _BYTE byte310;
    };
};