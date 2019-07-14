#pragma once

#include "types.h"
#include "Cmn/Actor.h"
#include "sead/string.h"

namespace Game {
    class Field : public Cmn::Actor {
    public:
        sead::BufferedSafeStringBase<char> mStr1;
        char mStr1Data[64];
        sead::BufferedSafeStringBase<char> mStr2;
        char mStr2Data[64];
        sead::BufferedSafeStringBase<char> mStr3;
        char mStr3Data[64];
        sead::BufferedSafeStringBase<char> xLinkName;
        char xLinkNameData[64];
    };
};