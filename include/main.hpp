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
#include "Lp/Utl.h"
#include "Lp/Sys/ctrl.h"
#include "Game/PlayerGamePadData/FrameInput.h"
#include "Game/Player/PlayerMotion.h"
#include "Game/Player/Player.h"
#include "Game/PlayerMgr.h"
#include "ModuleObject.hpp"

void render(agl::DrawContext *drawContext, sead::TextWriter *textWriter);
bool isTriggered(Lp::Sys::Ctrl *controller, unsigned long id);

void drawBackground();
void handleStaticMem(Cmn::StaticMem *staticMem);
void handlePlayerMgr(Game::PlayerMgr* playerMgr);
void handlePlayerControl(Cmn::PlayerCtrl* playerCtrl);

char* modeToText(int);

enum Buttons {
    BButton = 1 << 0,
    AButton = 1 << 1,
    ZLButton = 1 << 2,
    YButton = 1 << 3,
    XButton = 1 << 4,
    ZRButton = 1 << 5,
    RSButton = 1 << 6,
    LSButton = 1 << 7,

    Unk1Button = 1 << 8,
    Minus1Button = 1 << 9,
    Plus1Button = 1 << 10,
    Plus2Button = 1 << 11,
    Minus2Button = 1 << 12,
    LButton = 1 << 13,
    RButton = 1 << 14,
    Unk2Button = 1 << 15,

    UpDpadButton = 1 << 16,
    DownDpadButton = 1 << 17,
    LeftDpadButton = 1 << 18,
    RightDpadButton = 1 << 19,
    UpLStickOrdinal = 1 << 20,
    DownLStickOrdinal = 1 << 21,
    LeftLStickOrdinal = 1 << 22,
    RightLStickOrdinal = 1 << 23,
    
    UpRStickOrdinal = 1 << 24,
    DownRStickOrdinal = 1 << 25,
    LeftRStickOrdinal = 1 << 26,
    RightRStickOrdinal = 1 << 27,
};