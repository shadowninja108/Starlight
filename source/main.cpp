#include "main.hpp"
__attribute__((section(".bss"))) rtld::ModuleObject __nx_module_runtime; // to appease rtld

static __int64 lastInputs = 0x200;
static bool showMenu;
static agl::DrawContext *mDrawContext;
static sead::TextWriter *mTextWriter;
static Lp::Sys::Ctrl *mController;
static Game::Player* mCurrentPlayer;
static int mode;

// hook for gsys::SystemTask::invokeDrawTV_
void render(agl::DrawContext *drawContext, sead::TextWriter *textWriter)
{
    mDrawContext = drawContext;
    mTextWriter = textWriter;
    mController =  Lp::Utl::getCtrl(0);

    if(isTriggered(mController, Minus1Button))
        showMenu = !showMenu;

    if(showMenu){
        drawBackground();
        
        textWriter->setScaleFromFontHeight(20);
        sead::TextWriter::setupGraphics(drawContext); // re-setup context

        textWriter->printf("Welcome to Starlight!\n");
        textWriter->printf("This is a demonstration of C/C++ code running in the context of a Switch game!\n");
        textWriter->printf("Credit to shibboleet, Khangaroo, Thog, Retr0id, and the libnx maintainers!\n");

        if(isTriggered(mController, Buttons::RSButton))
            mode++;
        if(mode > 2)
            mode = 0;
        textWriter->printf("Current mode: %s", modeToText(mode));

        Cmn::StaticMem *staticMem = Cmn::StaticMem::sInstance;
        if(staticMem != NULL)
            handleStaticMem(staticMem);

        Game::PlayerMgr *playerMgr = Game::PlayerMgr::sInstance;
        if(playerMgr != NULL)
            handlePlayerMgr(playerMgr);
            
        Cmn::PlayerCtrl *playerCtrl = Cmn::PlayerCtrl::sInstance;
        if(playerCtrl != NULL)
            handlePlayerControl(playerCtrl);
    }
    lastInputs = mController->data;
}

void drawBackground(){
    float fullWidth = 1280;
    float fullHeight = 720;
    float width = fullWidth/2;
    float height = fullHeight;

    sead::Vector3<float> p1; // top left
    p1.mX = -1.0;
    p1.mY = 1.0;
    p1.mZ = 0.0;
    sead::Vector3<float> p2; // top right
    p2.mX = 0.0;
    p2.mY = 1.0;
    p2.mZ = 0.0;
    sead::Vector3<float> p3; // bottom left
    p3.mX = -1.0;
    p3.mY = -1.0;
    p3.mZ = 0.0;
    sead::Vector3<float> p4; // bottom right
    p4.mX = 0.0;
    p4.mY = -1.0;
    p4.mZ = 0.0;

    sead::Color4f c;
    c.r = 1.0;
    c.g = 1.0;
    c.b = 1.0;
    c.a = 0.5;

    agl::utl::DevTools::beginDrawImm(mDrawContext, sead::Matrix34<float>::ident, sead::Matrix44<float>::ident);
    agl::utl::DevTools::drawTriangleImm(mDrawContext, p1, p2, p3, c);
    agl::utl::DevTools::drawTriangleImm(mDrawContext, p3, p4, p2, c);
}

void handleStaticMem(Cmn::StaticMem *staticMem){
    mTextWriter->printf("StaticMem ptr: 0x%x\n", staticMem);
    sead::SafeStringBase<char> *stageName = &staticMem->stageName;
    if(stageName->mCharPtr != NULL){
        mTextWriter->printf("Loaded stage: %s\n", stageName->mCharPtr);
    }
    
    Cmn::PlayerInfoAry *playerInfoAry = staticMem->playerInfoArray;
    if(playerInfoAry != NULL){
        mTextWriter->printf("PlayerInfoAry ptr: 0x%x\n", playerInfoAry);
        Cmn::PlayerInfo* playerInfo = playerInfoAry->infos[0];
        if(playerInfo != NULL){
            mTextWriter->printf("PlayerInfo[0] ptr: 0x%x\n", playerInfo);
            mTextWriter->printf("PlayerInfo[0] weapon ID: 0x%x\n", playerInfo->weapon.id);
            mTextWriter->printf("PlayerInfo[0] weapon turf inked: 0x%x\n", playerInfo->weapon.turfInked);

            mTextWriter->printf("PlayerInfo[0] unk FC: 0x%x\n", playerInfo->dwordFC);
        }
    }
}

void handlePlayerMgr(Game::PlayerMgr* playerMgr){
    Game::Player *player = playerMgr->getControlledPerformer();
    mCurrentPlayer = player;
    if(player != NULL)
    {
        mTextWriter->printf("Controlled player ptr: 0x%x\n", player);
        Game::PlayerMotion *playerMotion = player->motion;

        mTextWriter->printf("PlayerMotion ptr: 0x%x\n", playerMotion);

        if(mode == 2) {
            static long scroll = 0;

            if(isTriggered(mController, UpDpadButton))
                scroll++;
            if(isTriggered(mController, DownDpadButton))
                scroll--;

            if(isTriggered(mController, LeftDpadButton))
                scroll-=0x10;
            if(isTriggered(mController, RightDpadButton))
                scroll+=0x10;

            if(scroll < 0)
                scroll = 0;

            mTextWriter->printf("Animation ID: 0x%x\n", scroll);

            if(isTriggered(mController, LSButton))
                playerMotion->startEventAnim((Game::PlayerMotion::AnimID) scroll, 0, 1.0);
        }
    }
}

<<<<<<< HEAD
void handlePlayerControl(Cmn::PlayerCtrl* playerCtrl){
    Game::PlayerGamePadData::FrameInput input;
    input.record(); // grab input data
=======
                sead::Vector3<float> *playerPos = &player->position;
                textWriter->printf("Player position | x: %f | y: %f | z: %f", playerPos->mX, playerPos->mY, playerPos->mZ);

                if(isTriggered(controller, UpDpadButton))
                    scroll++;
                if(isTriggered(controller, DownDpadButton))
                    scroll--;
>>>>>>> 4b31b391927a5420eec207037e50de236447aea2

    static bool showInputs = false;

    if(isTriggered(mController, Plus1Button))
        showInputs = !showInputs;

    if(showInputs){
        mTextWriter->printf("Left stick | x: %f | y: %f\n", input.leftStick.mX, input.leftStick.mY);
        mTextWriter->printf("Right stick | x: %f | y: %f\n", input.rightStick.mX, input.rightStick.mY);
        mTextWriter->printf("Angle vel | x: %f | y: %f | z: %f\n", input.angleVel.mX, input.angleVel.mY, input.angleVel.mZ);
        mTextWriter->printf("Posture x | x: %f | y: %f | z: %f\n", input.postureX.mX, input.postureX.mY, input.postureX.mZ);
        mTextWriter->printf("Posture y | x: %f | y: %f | z: %f\n", input.postureY.mX, input.postureY.mY, input.postureY.mZ);
        mTextWriter->printf("Posture z | x: %f | y: %f | z: %f\n", input.postureZ.mX, input.postureZ.mY, input.postureZ.mZ);
    }

    static bool enteredFly;
    if(mode == 1 && mCurrentPlayer != NULL){
        static float x, y, z;
        if(!enteredFly){
            x = mCurrentPlayer->
        }

        enteredFly = true;

    } else {
        enteredFly = false;
    }
}

bool isTriggered(Lp::Sys::Ctrl *controller, unsigned long id){
    bool buttonHeld = controller->data & id;
    return buttonHeld & !(controller->data & lastInputs & id);
}

char* modeToText(int mode){
    switch(mode){
        case 0:
            return "None";
        case 1:
            return "Fly";
        case 2:
            return "Event viewer";
        default:
            return "None";
    }
}

int main(int argc, char **argv) 
{
    // this is to ensure that this isn't being ran by the HBL
    if (svcGetSystemTick() > 0) 
    {
        return 0;
    }
}