#pragma once

#include "types.h"
#include "context.h"
#include "matrix.h"
#include "camera.h"
#include "projection.h"
#include "color.h"

namespace sead {
    class PrimitiveDrawer {
        public:
        virtual ~PrimitiveDrawer();

        PrimitiveDrawer(sead::DrawContext*);

        sead::Matrix34<float>* mModelMatrix;
        sead::Matrix34<float>* mCameraMatrix;
        sead::Matrix44<float>* mProjectionMatrix;
        sead::DrawContext* mDrawContext;

        void begin();
        void end();
        void setCamera(sead::Camera const*);
        void setProjection(sead::Projection const*);
        void drawLine(sead::Vector3<float> const&,sead::Vector3<float> const&,sead::Color4f const&);

    };
}