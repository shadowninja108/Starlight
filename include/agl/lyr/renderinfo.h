#include "types.h"
#include "agl/RenderBuffer.h"
#include "agl/lyr/layer.h"
#include "agl/DrawContext.h"
#include "Lp/Sys/dbgtextwriter.h"
#include "sead/viewport.h"
#include "sead/projection.h"

#pragma once

namespace agl {

  namespace lyr {

      class RenderInfo {
        public:
        RenderInfo(agl::DrawContext *drawContext, char a2, agl::RenderBuffer *renderBuffer);
        RenderInfo(agl::DrawContext *drawContext, char a2, int a3, agl::RenderBuffer *renderBuffer, char a5, agl::lyr::Layer *layer);

        virtual agl::RenderBuffer* getFrameBuffer();
        virtual void bindFrameBufferAndApplyViewport(agl::DrawContext *drawContext);
        virtual void setUpPrimitiveRenderer();

        _BYTE byte8;
        agl::RenderBuffer *renderBuffer;
        agl::lyr::Layer *layer;
        Lp::Sys::DbgTextWriter::Info *dbgInfo;
        sead::Camera *camera;
        sead::Projection *renderProjection;
        sead::Viewport *viewport;
        _BYTE byte40;
        agl::DrawContext *drawContext;
      };
  };
  
};