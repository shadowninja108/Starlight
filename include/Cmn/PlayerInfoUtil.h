#pragma once

#include "types.h"
#include "PlayerInfo.h"
#include "Def/Team.h"
#include "Def/Mode.h"
#include "Cnet/PacketPlayerInfo.h"

namespace Cmn
{
    class PlayerInfoUtil {
        public:
        static void setPlayerInfoAgentThree(Cmn::PlayerInfo*, Cmn::Def::Team);
        static void setPlayerInfoByDummy(Cmn::PlayerInfo*, Cmn::Def::Mode);
        
        static void setNetPacketByPlayerInfo(Cnet::PacketPlayerInfo*, Cmn::PlayerInfo const*);
    };
};