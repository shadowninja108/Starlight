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

      enum FrameworkType : u32 {
        FRAMEWORK_DEFAULT = 0
      };

      class RenderInfo {
        public:

        RenderInfo(agl::DrawContext*, int, agl::RenderBuffer const*);
        RenderInfo(agl::DrawContext*, int, FrameworkType, agl::RenderBuffer const*, bool, agl::lyr::Layer const*);

        agl::RenderBuffer* getFrameBuffer();
        void bindFrameBufferAndApplyViewport(agl::DrawContext *drawContext);
        void setUpPrimitiveRenderer();

        u32 RenderInfo_x0;
        agl::lyr::FrameworkType mFrameworkType;
        bool RenderInfo_x8;
        agl::RenderBuffer *mRenderBuffer;
        agl::lyr::Layer *mLayer;
        Lp::Sys::DbgTextWriter::Info *mDbgInfo;
        sead::Camera *mCamera;
        sead::Projection *mRenderProjection;
        sead::Viewport *mViewport;
        char RenderInfo_x40;
        agl::DrawContext *mDrawContext;
      };
  };
  
};