#pragma once

#include "types.h"

#include "Game/Player/Player.h"
#include "PlayerModelResource.h"

namespace Game {
    class Player;

    class PlayerMgr : public Cmn::Actor, public sead::IDisposer {
        public:
        
        static Game::PlayerMgr *sInstance;

        Game::PlayerModelResource mModelResource; // Game::PlayerModelResource
        unsigned int mCurrentPlayerIndex;
        signed int mControlledArray[10];
        int PlayerMgr_x5F4[2];
        int mPlayerIndexes[10];
        int mTotalPlayers;
        u32 mValidInfo;
        sead::PtrArrayImpl mAllKindPlayerArry;
        sead::PtrArrayImpl mCustomMgrArry;
        sead::PtrArrayImpl mPerformerArry;
        sead::PtrArrayImpl mTotalPlayerArry;
        
        __int64 cmnCamera; // Game::PlayerCmnCamera *

        Game::Player* getControlledPerformer() const;
        Game::Player* getPerformerAt(unsigned int) const;
        Game::Player* getAllKindPlayerAt(unsigned int) const;
        void updateAllControlledPlayer_(int);
        void onChangeControlledPlayer();
    };
};