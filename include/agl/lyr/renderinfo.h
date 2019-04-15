#include "types.h"
#include "agl/renderbuffer.h"
#include "agl/lyr/layer.h"
#include "agl/drawcontext.h"
#include "Lp/Sys/dbgtextwriter.h"
#include "sead/viewport.h"

#pragma once

namespace agl {

  namespace lyr {

      class RenderInfo {
        public:
          _BYTE byte8;
          agl::RenderBuffer *renderBuffer;
          agl::lyr::Layer *layer;
          Lp::Sys::DbgTextWriter::Info *dword20;
          _QWORD camera;
          _QWORD renderProjection;
          sead::Viewport *qword38;
          _BYTE byte40;
          agl::DrawContext *drawContext;
      };
  };
  
};