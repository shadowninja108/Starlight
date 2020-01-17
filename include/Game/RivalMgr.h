#pragma once

#include "types.h"

#include "Cmn/Def/Team.h"
#include "Cmn/PlayerInfo.h"
#include "sead/string.h"

namespace Game {
    class RivalMgr {
        public:
        static Game::RivalMgr* sInstance;

        void customizePlayerInfo(Cmn::PlayerInfo*, Cmn::Def::Team, sead::SafeStringBase<char>, sead::SafeStringBase<char>, bool);
    };
};