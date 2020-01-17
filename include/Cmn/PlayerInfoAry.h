#pragma once

#include "types.h"
#include "Cmn/PlayerInfo.h"

namespace Cmn
{
    class PlayerInfoAry {
        public:
        Cmn::PlayerInfo *infos[10];

        int getValidInfoNum() const;

        virtual ~PlayerInfoAry();
    };
};