#pragma once

#include "types.h"

namespace Cmn
{
    namespace Def {
        enum class Mode{
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
    };
};