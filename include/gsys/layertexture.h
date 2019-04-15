#include "types.h"

#include "sead/heap.h"
#include "agl/RenderBuffer.h"
#include "agl/texturedata.h"
#include "agl/g3d/restexturedataex.h"

#pragma once

namespace gsys {
  class LayerTexture {

    public:
      sead::IDisposer disposer;
      agl::RenderBuffer renderBuffer;
      _BYTE gap88[344];
      _BYTE gap1E0[32];
      _QWORD qword200;
      agl::g3d::ResTextureDataEx resTextureData;
      agl::TextureData textureData;

  };
};