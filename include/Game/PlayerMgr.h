#pragma once

#include "types.h"

#include "Game/Player/Player.h"

#ifndef GAME_PLAYERMGR_H
#define GAME_PLAYERMGR_H

namespace Game {
    class Player;

    class PlayerMgr : public Cmn::Actor, public sead::IDisposer {
        public:
        
        static Game::PlayerMgr *sInstance;
        __int64 *mModelResource; // Game::PlayerModelResource *
        char field_370[72];
        __int32 field_3B8;
        char field_3BC[4];
        __int64 *halfModelArcs;
        char field_3C8[64];
        __int32 squidModelArcCount;
        char field_40C[4];
        __int64 *squidModelArcs;
        char field_418[224];
        __int32 squidAnimArcCount;
        char field_4FC[4];
        __int64 *squidAnimArcs;
        char field_508[192];
        signed int currentPlayerIndex;
        __int32 field_5CC[10];
        __int32 field_5F4[2];
        __int32 field_5FC[10];
        _DWORD validInfoNum;
        _BYTE gap628[8];
        unsigned int validAmountOfPlayers;
        _BYTE gap634[4];
        Game::Player **someOtherPlayerArray;

        Game::Player* getControlledPerformer() const;
        Game::Player* getPerformerAt(unsigned int) const;
        Game::Player* getAllKindPlayerAt(unsigned int) const;
        void updateAllControlledPlayer_(int);
        void onChangeControlledPlayer();
    };
};

#endif