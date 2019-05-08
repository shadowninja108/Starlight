#pragma once

#include "types.h"

namespace Game {
    class Player {
        public:
        enum ResultAnim{
            Win, Lose, CoopWin, CoopLose
        };

        void start_MissionAppear();
        void change_DemoPlaceAnim(Game::Player::ResultAnim, int);

        _BYTE somestuff[0xF80];
        Game::PlayerMotion *motion;
    };
};