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
        class ByamlIter {
            
        };
        class ByamlWriter {
            
        };
         class YamlWriter {
            
        };
    };
};
