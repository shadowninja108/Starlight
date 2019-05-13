#pragma once

#include "types.h"

#include "Cmn/Actor.h"

namespace Cmn {
    class MainMgr : Cmn::Actor{
        public:
        __int64 scene; //Lp::Sys::Scene *scene;
        _QWORD gfxLayer3d;
        _QWORD qword378;
        _QWORD plazaGfxLayer3d;
        __int64 mudata; //Cmn::MuData *mudata;
        __int64 seqMgr; //Game::SeqMgrCoop *seqMgr;
        __int64 field; //Game::Field *field;
        Lp::Sys::Actor *managers[20];
        __int64 cloneObjMgr; //Game::CloneObjMgr *cloneObjMgr;
        __int64 gfxMgr; //Game::GfxMgr *gfxMgr;
        signed __int32 gap408;
        _BYTE gap454[12];
        _QWORD twoShotParamsHolder;
        _BYTE qword420;
        _QWORD qword428;
        _QWORD qword430;
        _QWORD qword438;
        _QWORD qword440;
        _QWORD qword448;
        _QWORD qword450;
        _DWORD dword458;
        _BYTE gap45C[4];
        _QWORD qword460;
        _BYTE byte468;

        unsigned int getPaintGameFrame();
    };
};