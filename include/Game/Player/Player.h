#pragma once

#include "types.h"

#include "sead/vector.h"
#include "Cmn/Actor.h"
#include "PlayerMotion.h"
#include "PlayerModel.h"
#include "Game/PlayerMgr.h"
#include "Cmn/PlayerInfo.h"


#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

namespace Game {
    class Player : public Cmn::Actor {
        public:
        enum ResultAnim{
            Win, Lose, CoopWin, CoopLose
        };

        void start_MissionAppear();
        void change_DemoPlaceAnim(Game::Player::ResultAnim, int);
        void replaceTeamColor(sead::Color4f const&);

        _BYTE somestuff[0x138];
        u32 mIndex;
        Cmn::PlayerInfo *mPlayerInfo;
        Game::PlayerMgr *mPlayerMgr;
        _BYTE moarstuff[0x2B0];
        sead::Vector3<float> position;
        _BYTE morestuff[0x81C];
        Game::PlayerModel *model;
        __int64 silhouette; // Game::PlayerSilhouette *
        Game::PlayerMotion *motion;
    };
};
#endif