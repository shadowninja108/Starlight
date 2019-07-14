#pragma once

#include "types.h"

#include "Game/Player/Player.h"
#include "gsys/model.h"

#ifndef GAME_PLAYERMODEL_H
#define GAME_PLAYERMODEL_H

namespace Game {

    class Player;
    class PlayerMgr;

    class PlayerModel {
        public:
        Game::Player* mPlayer;
        Game::PlayerMgr* mPlayerMgr;
        __int64 mPlayerCustomMgr; // Cmn::PlayerCustomMgr *
        gsys::Model **mFullModel;
        gsys::Model *mHalfModel;
        gsys::Model *mSquidModel;
    };
};

#endif