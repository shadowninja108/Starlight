#pragma once

#include "types.h"
#include "Sys/ctrl.h"
#include "sead/color.h"
#include "Cmn/Def/Mode.h"

namespace Lp
{
    class Utl {
        public:
        static Sys::Ctrl* getCtrl(int);
        static sead::Color4f hsb2rgb(sead::Vector3<float> const&);
        static Cmn::Def::Mode getCurSceneId();
        static char* getCurSceneName();

        static void convertWorldToScreen(sead::Vector2<float> *,sead::Vector3<float> const&,agl::lyr::RenderInfo const&);
        static void convertWorldToScreen(sead::Vector2<float> *,sead::Vector3<float> const&,agl::lyr::Layer const*,sead::Camera const*);
        static void convertWorldToScreen(sead::Vector2<float> *,sead::Vector3<float> const&,sead::Camera const*,sead::Projection const*,sead::Viewport const*);
        
        class ByamlIter {
            
        };
        class ByamlWriter {
            
        };
         class YamlWriter {
            
        };
    };
};
