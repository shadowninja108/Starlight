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

    class PlayerGamePad {
        public:
        Game::Player* mPlayer;
    };

    class Player : public Cmn::Actor {
        public:
        enum ResultAnim{
            Win, Lose, CoopWin, CoopLose
        };


        static Lp::Sys::ActorClassIterNodeBase* getClassIterNodeStatic();

        void start_MissionAppear();
        void change_DemoPlaceAnim(Game::Player::ResultAnim, int);
        void replaceTeamColor(sead::Color4f const&);
        void calcDraw_In4thCalc();

        u64 mMinimapTarget;
        u32 Player_x350;
        u32 Player_x354;
        u32 Player_x358;
        u32 mModelType;
        char somestuff[0x120];
        u32 mIndex;
        Cmn::PlayerInfo *mPlayerInfo;
        Game::PlayerMgr *mPlayerMgr;
        _BYTE moarstuff[0x78];
        sead::Vector3<float> mAngleVel;
        sead::Vector3<float> mPostureX;
        sead::Vector3<float> mPostureY;
        sead::Vector3<float> mPostureZ;
        bool Player_x540;
        bool Player_x541;
        bool Player_x542;
        bool Player_x543;
        bool Player_x544;
        bool Player_x546;
        bool Player_x547;
        char Player_x548[0x1F8];
        sead::Vector3<float> mPosition;
        _BYTE morestuff[0x784];
        Game::PlayerGamePad* mPlayerGamePad;
        _BYTE evenmoarstuff[0x98];
        Game::PlayerModel *mPlayerModel;
        __int64 silhouette; // Game::PlayerSilhouette *
        Game::PlayerMotion *mPlayerMotion;
        _BYTE stufff[0x120];
        u32 mUsingAi;
        u32 Player_x10AC;
    };
};
#endif