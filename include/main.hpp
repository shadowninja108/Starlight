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
#include <list>
#include "ModuleObject.hpp"

void render(agl::DrawContext *drawContext, sead::TextWriter *textWriter);
bool isTriggered(Lp::Sys::Ctrl *controller, unsigned long id);

enum
{
    LS = 1 << 0,
    RS = 1 << 1,
    ZR = 1 << 2,
    X = 1 << 3,
    Y = 1 << 4,
    ZL = 1 << 5,
    A = 1 << 6,
    B = 1 << 7,
    Unk1 = 1 << 8,
    Minus1 = 1 << 9,
    Plus1 = 1 << 10,
    Plus2 = 1 << 11,
    Minus2 = 1 << 12,
    L = 1 << 13,
    R = 1 << 14,
    Unk2 = 1 << 15,
} Buttons;