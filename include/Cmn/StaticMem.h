#pragma once

#include "types.h"
#include "sead/string.h"
#include "Cmn/PlayerInfoAry.h"

namespace Cmn
{
    class StaticMem {
        public:
        static StaticMem* sInstance;
        _QWORD vtable;
        _QWORD qword8;
        _BYTE gap10[32];
        const char *pchar30;
        Cmn::PlayerInfoAry *playerInfoArray;
        _DWORD random;
        _BYTE gap44[4];
        sead::SafeStringBase<char> stageName;
    };
};