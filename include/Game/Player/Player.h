#pragma once

#include "types.h"
#include "sead/vector.h"

namespace Game {
    class Player {
        public:
        enum ResultAnim{
            Win, Lose, CoopWin, CoopLose
        };

        void start_MissionAppear();
        void change_DemoPlaceAnim(Game::Player::ResultAnim, int);

        _BYTE somestuff[0x748];
        sead::Vector3<float> position;
        _BYTE morestuff[0x82C];
        Game::PlayerMotion *motion;

    };
};