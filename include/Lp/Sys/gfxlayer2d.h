#include "types.h"

#include "gsys/layer.h"
#include "sead/heap.h"
#include "agl/texturesampler.h"
#include "agl/renderbuffer.h"

#pragma once

namespace Lp {

  namespace Sys {

    class GfxLayer2D : public gsys::Layer {
    _QWORD qwordE78;
    _QWORD qwordE80;
    _QWORD qwordE88;
    _QWORD qwordE90;
    _QWORD qwordE98;
    _QWORD qwordEA0;
    _BYTE byteEA8;
    _BYTE gapEA9[15];
    agl::TextureSampler textureSampler;
    agl::RenderTargetColor renderTargetColor;
    _BYTE gap1180[32];
    agl::RenderBuffer renderBuffer;
    agl::TextureSampler texturesampler1208;
    sead::IDisposer disposer;
    _QWORD qword1398;
    _QWORD qword13A0;
    _QWORD qword13A8;
    _DWORD dword13B0;
    _QWORD qword13B4;
    _QWORD qword13BC;
    _QWORD qword13C4;
    _QWORD qword13CC;
    _BYTE gap13D4[4];
    sead::IDisposer disposer1;
    _QWORD qword13F8;
    _QWORD qword1400;
    _QWORD qword1408;
    _DWORD dword1410;
    _QWORD qword1414;
    _QWORD qword141C;
    _QWORD qword1424;
    _QWORD qword142C;
    _BYTE gap1434[4];
    sead::IDisposer disposer2;
    _QWORD qword1458;
    _QWORD qword1460;
    _QWORD qword1468;
    _DWORD dword1470;
    _QWORD qword1474;
    _QWORD qword147C;
    _QWORD qword1484;
    _QWORD qword148C;
    _BYTE gap1494[4];
    sead::IDisposer disposer3;
    _QWORD qword14B8;
    _QWORD qword14C0;
    _QWORD qword14C8;
    _DWORD dword14D0;
    _QWORD qword14D4;
    _QWORD qword14DC;
    _QWORD qword14E4;
    _QWORD qword14EC;
    _BYTE gap14F4[4];
    sead::IDisposer disposer4;
    _QWORD qword1518;
    _QWORD qword1520;
    _QWORD qword1528;
    _DWORD dword1530;
    _QWORD qword1534;
    _QWORD qword153C;
    _QWORD qword1544;
    _QWORD qword154C;
    __int32 end;
    };
  };
};