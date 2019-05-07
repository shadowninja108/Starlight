#pragma once

#include "types.h"

#include "Player.h"

namespace Game {
    class PlayerMgr {
        public:
        
        static Game::PlayerMgr *sInstance;
        void *actor;
        _BYTE gap8[864];
        __int64 *field_368;
        _BYTE gap370[72];
        __int32 field_3B8;
        _BYTE gap3BC[4];
        __int64 *field_3C0;
        _BYTE gap3C8[64];
        __int32 field_408;
        _BYTE gap40C[4];
        __int64 *field_410;
        _BYTE gap418[224];
        __int32 field_4F8;
        _BYTE gap4FC[4];
        __int64 *field_500;
        _BYTE gap508[192];
        _DWORD currentPlayerIndex;
        unsigned int field_5CC;
        _BYTE gap5D0[4];
        char field_5D4[8];
        char field_5DC[8];
        char field_5E4[8];
        char field_5EC[8];
        __int32 *qword5F4;
        __int32 *qword5FC;
        _QWORD qword604;
        _QWORD qword60C;
        _QWORD qword614;
        _QWORD qword61C;
        __int32 maxPlayers;
        _BYTE field_628;
        _BYTE gap629[7];
        _DWORD totalPlayers;
        _BYTE gap634[4];
        Game::Player *players[8];
        _QWORD qword678;
        _QWORD qword680;
        _QWORD qword688;
        _BYTE byte690;
        _BYTE gap691[7];
        _QWORD qword698;
        _QWORD qword6A0;
        _QWORD qword6A8;
        _QWORD qword6B0;
        _BYTE word6B8;
        _BYTE field_6B9;
        _BYTE byte6BA;
    };
};