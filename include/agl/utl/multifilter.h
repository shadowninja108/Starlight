#include "types.h"

#include "agl/RenderBuffer.h"
#include "agl/RenderTargetColor.h"
#include "agl/texturesampler.h"
#include "agl/utl/parameter.h"
#include "agl/utl/trimming.h"
#include "agl/utl/dynamictexturecache.h"

#pragma once
namespace agl {
  namespace utl {
    class MultiFilter {
      public:
        utl::IParameterIO paramIO;
        _QWORD qword1D8;
        _QWORD qword1E0;
        _DWORD dword1E8;
        _QWORD qword1F0;
        _QWORD qword1F8;
        _DWORD dword200;
        _QWORD qword208;
        _QWORD qword210;
        _DWORD dword218;
        _QWORD qword220;
        _QWORD qword228;
        _DWORD dword230;
        _QWORD qword238;
        _QWORD qword240;
        _DWORD dword248;
        _QWORD qword250;
        _QWORD qword258;
        _DWORD dword260;
        _QWORD qword268;
        _QWORD qword270;
        _DWORD dword278;
        _QWORD qword280;
        _QWORD qword288;
        _DWORD dword290;
        utl::IParameterList paramLists[7];
        _BYTE gap490[224];
        _QWORD qword570;
        _QWORD qword578;
        _DWORD dword580;
        agl::TextureSampler textureSampler;
        ::agl::RenderBuffer renderBuffer;
        ::agl::RenderTargetColor renderTargetColor;
        _DWORD dword8D8;
        _BYTE byte8DC;
        DynamicTextureCache dynamicTextureCache;
        _DWORD dword910;
        _QWORD qword914;
        _QWORD qword91C;
        _DWORD dword924;
        _BYTE byte928;
        _BYTE byte929;
        _BYTE byte92A;
        _QWORD qword930;
        utl::IParameterObj paramObj;
        ParameterBase paramBase;
        Trimming trimming988;
    };
  };
};