#pragma once

#include "types.h"
#include "Cmn/PlayerInfo.h"

namespace Cmn
{
    class PlayerInfoAry {
        public:
        __int64 vtable;
        Cmn::PlayerInfo *infos[10];
    };
};