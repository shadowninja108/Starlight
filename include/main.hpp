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
bool isHold(Cmn::PlayerCtrl *playerCtrl, unsigned long id);