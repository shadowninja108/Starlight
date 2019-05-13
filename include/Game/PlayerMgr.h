#pragma once

#include "types.h"

#include "Player/Player.h"

namespace Game {
    class PlayerMgr {
        public:
        
        static Game::PlayerMgr *sInstance;
        void *actor;
        char field_8[864];
        __int64 *field_368;
        char field_370[72];
        __int32 field_3B8;
        char field_3BC[4];
        __int64 *field_3C0;
        char field_3C8[64];
        __int32 field_408;
        char field_40C[4];
        __int64 *field_410;
        char field_418[224];
        __int32 field_4F8;
        char field_4FC[4];
        __int64 *field_500;
        char field_508[192];
        signed int currentPlayerIndex;
        _DWORD gap5CC[10];
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