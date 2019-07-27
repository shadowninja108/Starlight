#include "starlight/collector.hpp"

namespace starlight {
    Controller Collector::mController;

    // Managers
    Game::MainMgr* Collector::mMainMgrInstance;
    Game::PlayerMgr* Collector::mPlayerMgrInstance;
    sead::HeapMgr* Collector::mHeapMgr;

    // Utils
    Cmn::StaticMem* Collector::mStaticMemInstance;
    Cmn::GfxSetting* Collector::mGfxSettingInstance;

    // Player Information
    Game::Player* Collector::mControlledPlayer;
    Cmn::PlayerInfo* Collector::mControlledPlayerInfo;
    Cmn::PlayerCtrl* Collector::mPlayerCtrlInstance;
    Cmn::PlayerInfoAry* Collector::mPlayerInfoAry;

    // Mush
    Cmn::MushDataHolder* Collector::mMushDataHolder;
    Cmn::MushWeaponInfo* Collector::mMushWeaponInfo;
    Cmn::MushMapInfo* Collector::mMushMapInfo;

    void Collector::init() {
        
    }

    void Collector::collect(){
        mController.mController = Lp::Utl::getCtrl(0);
        mMainMgrInstance = Game::MainMgr::sInstance;
        mStaticMemInstance = Cmn::StaticMem::sInstance;
        mGfxSettingInstance = Cmn::GfxSetting::sInstance;
        mHeapMgr = sead::HeapMgr::sInstance;
        mPlayerMgrInstance = Game::PlayerMgr::sInstance;
        mPlayerCtrlInstance = Cmn::PlayerCtrl::sInstance;
        mMushDataHolder = Cmn::MushDataHolder::sInstance;

        if(mStaticMemInstance){
            mPlayerInfoAry = mStaticMemInstance->mPlayerInfoAry;
            mControlledPlayerInfo = &mStaticMemInstance->mPlayerInfo;
        } else {
            mPlayerInfoAry = NULL;
        }

        if(mPlayerMgrInstance){
            mControlledPlayer = mPlayerMgrInstance->getControlledPerformer();
        } else {
            mControlledPlayer = NULL;
        }
        
        if(mMushDataHolder){
            mMushWeaponInfo = mMushDataHolder->mMushWeaponInfo;
            mMushMapInfo = mMushDataHolder->mMushMapInfo;
        } else {
            mMushWeaponInfo = NULL;
            mMushMapInfo = NULL;
        }
    }
};