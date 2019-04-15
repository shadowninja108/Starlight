#include "types.h"

#include "gsys/layertexture.h"
#include "agl/RenderBuffer.h"
#include "agl/utl/debugtexturepage.h"
#include "agl/utl/multifilter.h"

#pragma once

namespace gsys {

  class Layer {
      public:
        _BYTE gap0[496];
        _DWORD dword1F8;
        agl::utl::MultiFilter *multiFilter;
        _QWORD qword208;
        _QWORD qword210;
        _QWORD qword218;
        _QWORD qword220;
        _BYTE gap228[368];
        _BYTE gap398[8];
        _QWORD name;
        char *pchar3A8;
        _DWORD dword3B0;
        _BYTE gap3B4[36];
        _QWORD qword3D8;
        gsys::LayerTexture layerTexture;
        agl::RenderBuffer renderBuffer;
        _BYTE gap940[344];
        _BYTE gapA98[32];
        _QWORD qwordAB8;
        _BYTE gapAC0[368];
        _DWORD dwordC30;
        _WORD wordC34;
        agl::utl::DebugTexturePage debugtexturepageC38;

  };
};