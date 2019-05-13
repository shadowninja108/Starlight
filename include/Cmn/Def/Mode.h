#pragma once

#include "sead/string.h"
#include "types.h"

namespace Cmn {
    namespace Def {
        class Mode {
            enum {
                cNone,
                cVersus,
                cCoop,
                cMission,
                cPlaza,
                cWorld,
                cTutorial,
                cShootingRange,
                cWalkThrough,
                cTwoShot,
                cStaffRoll, 
                cLobby,
                cMatch, 
                cShop, 
                cCustomize, 
                cPlayerMake, 
                cMissionOcta, 
                cBaseCampOcta, 
                cDepartureOcta, 
                cCentralOcta, 
                cStaffRollOcta, 
                cBoot, 
                cOther, 
                cFreeTest, 
                cDbgSetting, 
                cDevOther
            };

            static sead::SafeStringBase<char>* text_();
        };
    };
};