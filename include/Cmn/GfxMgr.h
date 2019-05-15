#pragma once

#include "types.h"

#include "sead/heap.h"
//#include "gsys/ModelScene.h"

namespace Cmn{
    class GfxMgr :  sead::IDisposer {
        public:
        __int64 modelScene; //gsys::ModelScene *
        sead::BufferedSafeStringBase<char> qword38;
        _BYTE gap50[32];
        _QWORD qword70;
        char *pchar78;
        _DWORD dword80;
        _BYTE gap84[36];
        unsigned int hour;
        _BYTE gapAC[4];
        _QWORD qwordB0;
        _QWORD qwordB8;
        __int64* gpuPerfController; //Cmn::GPUPerfController *
        _QWORD qwordC8;
        __int64 debugTexturePage; //agl::utl::DebugTexturePage *
        _BYTE byte310;
    };
};