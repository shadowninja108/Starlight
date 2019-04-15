#include "types.h"
#include "agl/renderbuffer.h"
#include "agl/lyr/layer.h"
#include "agl/drawcontext.h"
#include "Lp/Sys/dbgtextwriter.h"
#include "sead/viewport.h"
#include "sead/projection.h"

#pragma once

namespace agl {

  namespace lyr {

      class RenderInfo {
        public:
        RenderInfo(agl::DrawContext *a2, char a3, agl::RenderBuffer *a4);
        RenderInfo(agl::DrawContext *drawContext, char a3, int a4, agl::RenderBuffer *renderBuffer, char a6, agl::lyr::Layer *layer);

        _BYTE byte8;
        agl::RenderBuffer *renderBuffer;
        agl::lyr::Layer *layer;
        Lp::Sys::DbgTextWriter::Info *dword20;
        _QWORD camera;
        sead::Projection *renderProjection;
        sead::Viewport *qword38;
        _BYTE byte40;
        agl::DrawContext *drawContext;
      };
  };
  
};