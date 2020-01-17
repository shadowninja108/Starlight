#pragma once

#include "input.hpp"

#include "Game/MainMgr.h"
#include "Game/PlayerMgr.h"
#include "Game/Player/Player.h"
#include "Cmn/Player/PlayerCtrl.h"
#include "Cmn/StaticMem.h"
#include "Cmn/GfxSetting.h"
#include "Cmn/Mush/MushDataHolder.h"
#include "Cmn/Mush/MushWeaponInfo.h"
#include "Cmn/Mush/MushMapInfo.h"
#include "Lp/Utl.h"
#include "sead/heap.h"

namespace starlight
{
    class Collector {
        public:
        static Controller mController;

        // Managers
        static Game::MainMgr* mMainMgrInstance;
        static Game::PlayerMgr* mPlayerMgrInstance;
        static sead::HeapMgr* mHeapMgr;

        // Utils
        static Cmn::StaticMem* mStaticMemInstance;
        static Cmn::GfxSetting* mGfxSettingInstance;

        // Player Information
        static Game::Player* mControlledPlayer;
        static Cmn::PlayerInfo* mControlledPlayerInfo;
        static Cmn::PlayerCtrl* mPlayerCtrlInstance;
        static Cmn::PlayerInfoAry* mPlayerInfoAry;

        // Mush
        static Cmn::MushDataHolder* mMushDataHolder;
        static Cmn::MushWeaponInfo* mMushWeaponInfo;
        static Cmn::MushMapInfo* mMushMapInfo;

        static void init();
        static void collect();
        static void clear();
    };
}


