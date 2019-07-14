#pragma once

#include "types.h"
#include "sead/string.h"
#include "Lp/Sys/params.h"

namespace Cmn {
    class TeamColorParam : Lp::Sys::Params {
        public:
        Lp::Sys::Param<sead::Color4f> mAlphaNode;
        Lp::Sys::Param<sead::Color4f> mBravoNode;
        Lp::Sys::Param<sead::Color4f> mNeutralNode;
        Lp::Sys::Param<sead::Color4f> mExNode;
        sead::BufferedSafeStringBase<char> mPath;
        char mPathData[64];

        void pathName(sead::BufferedSafeStringBase<char>*) const;
    };
};