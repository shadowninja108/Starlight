#include "svc.h"
#include "types.h"
#include "agl/lyr/renderinfo.h"
#include "agl/utl/devtools.h"
#include "sead/textwriter.h"
#include "sead/string.h"
#include "sead/heap.h"
#include "sead/matrix.h"
#include "Cmn/StaticMem.h"
#include "Cmn/PlayerInfoUtil.h"
#include "Cmn/PlayerCtrl.h"
#include "Cmn/Mush/MushDataHolder.h"
#include "Cmn/Def/util.h"
#include "Lp/Utl.h"
#include "Lp/Sys/ctrl.h"
#include "Game/Utl.h"
#include "Game/PlayerGamePadData/FrameInput.h"
#include "Game/Player/PlayerMotion.h"
#include "Game/Player/Player.h"
#include "Game/PlayerMgr.h"
#include "Game/MainMgr.h"
#include "ModuleObject.hpp"

enum Modes {
    NONE, FLY, EVENT_VIEWER, INPUT_VIEWER,  PLAYER_SWITCHER, END
};

void render(agl::DrawContext *drawContext, sead::TextWriter *textWriter);
bool isTriggered(Lp::Sys::Ctrl *controller, unsigned long id);

void drawBackground();
void handleStaticMem(Cmn::StaticMem *staticMem);
void handlePlayerMgr(Game::PlayerMgr* playerMgr);
void handlePlayerControl(Cmn::PlayerCtrl* playerCtrl);
void handleMushDataHolder(Cmn::MushDataHolder* mushDataHolder);
void handleMainMgr(Game::MainMgr* mainMgr);

char const* modeToText(Modes);

enum Buttons {
    B = 1 << 0,
    A = 1 << 1,
    ZL = 1 << 2,
    Y = 1 << 3,
    X = 1 << 4,
    ZR = 1 << 5,
    RStick = 1 << 6,
    LStick = 1 << 7,

    Unk1 = 1 << 8,
    Minus1 = 1 << 9,
    Plus1 = 1 << 10,
    Plus2 = 1 << 11,
    Minus2 = 1 << 12,
    L = 1 << 13,
    R = 1 << 14,
    Unk2 = 1 << 15,

    UpDpad = 1 << 16,
    DownDpad = 1 << 17,
    LeftDpad = 1 << 18,
    RightDpad = 1 << 19,
    UpLStickOrdinal = 1 << 20,
    DownLStickOrdinal = 1 << 21,
    LeftLStickOrdinal = 1 << 22,
    RightLStickOrdinal = 1 << 23,
    
    UpRStickOrdinal = 1 << 24,
    DownRStickOrdinal = 1 << 25,
    LeftRStickOrdinal = 1 << 26,
    RightRStickOrdinal = 1 << 27,
};

