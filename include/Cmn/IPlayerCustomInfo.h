#pragma once

#include "types.h"
#include "Cmn/Def/Gear.h"
#include "Cmn/Def/Team.h"
#include "Game/Player/Player.h"
#include "gsys/model.h"

namespace Cmn {
    class IPlayerCustomInfo {
        public:
        virtual bool isUseStandAlone();
        virtual u64 getCustomMgr();
        virtual bool isCreateWeapon();
        virtual void getMainWeapon(int);
        virtual bool isCreateTank();
        virtual bool isCreateAllTank();
        virtual int getCreateTankNum();
        virtual int getCreateTankDataId();
        virtual bool isCreateArmomr(); // nice job guys
        virtual bool isCreateAllBottom();
        virtual int getCreateBottomDataId();
        virtual bool isCreateMantle();
        virtual int getGearCreateActorNum(Cmn::Def::GearKind);
        virtual u64 getGearInfo(Cmn::Def::GearKind, int);
        virtual int getModelType();
        virtual Cmn::Def::Team getTeam();
        virtual int getXluZPrePassID_Offset();
        virtual Cmn::Def::Team getFestTeam();
        virtual int getFestId();
        virtual u64 getHumanBoneAccessor();
        virtual bool isUseLODModel();
        virtual void addToOcclusionQuery(gsys::Model*);
        virtual u64 getModelScene();
        virtual int getHairId();
        virtual Game::Player* getGamePlayer();
        virtual u64 getCustomizePlayer();
        virtual u64 getShopPlayerDressup();
        virtual u64 getPlayerViewerPlayer();
        virtual u64 getStaffRollOctaPlayer();
    };
};