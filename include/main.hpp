#pragma once

#include <string.h>
#include <vector>
#include <math.h>
#include "svc.h"
#include "types.h"
#include "operator.h"
#include "agl/lyr/renderinfo.h"
#include "agl/lyr/renderer.h"
#include "agl/utl/devtools.h"
#include "sead/textwriter.h"
#include "sead/string.h"
#include "sead/drawer.h"
#include "sead/heap.h"
#include "sead/matrix.h"
#include "sead/arena.h"
#include "sead/system.h"
#include "Cmn/StaticMem.h"
#include "Cmn/CameraUtl.h"
#include "Cmn/PlayerInfoUtil.h"
#include "Cmn/PlayerCtrl.h"
#include "Cmn/Mush/MushDataHolder.h"
#include "Cmn/GfxSetting.h"
#include "Cmn/AppUBOMgr.h"
#include "Cmn/Def/util.h"
#include "Cmn/GfxUtl.h"
#include "Lp/Utl.h"
#include "Lp/Sys/ctrl.h"
#include "Lp/Sys/heapgroup.h"
#include "Game/Utl.h"
#include "Game/PlayerGamePadData/FrameInput.h"
#include "Game/Player/PlayerMotion.h"
#include "Game/Player/Player.h"
#include "Game/PlayerMgr.h"
#include "Game/MainMgr.h"
#include "Game/PaintUtl.h"
#include "MiniGame/gfx.h"
#include "aal/debugdrawer.h"
#include "ModuleObject.hpp"
#include "starlight/collector.hpp"
#include "starlight/view.hpp"
#include "starlight/menu/simplemenu.hpp"
#include "starlight/menu/popmenuentry.hpp"

enum Modes {
    NONE, FLY, EVENT_VIEWER, INPUT_VIEWER,  PLAYER_SWITCHER, PAINT_ALL, END
};

void renderEntrypoint(agl::DrawContext *drawContext, sead::TextWriter *textWriter);

void allocHeap();

void drawBackground();
void handleStaticMem(Cmn::StaticMem *staticMem);
void handlePlayerMgr(Game::PlayerMgr* playerMgr);
void handlePlayerControl(Cmn::PlayerCtrl* playerCtrl);
void handleMushDataHolder(Cmn::MushDataHolder* mushDataHolder);
void handleMainMgr(Game::MainMgr* mainMgr);
void handleGfxSetting(Cmn::GfxSetting*);

char const* modeToText(Modes);



char const* modeToText(Modes);