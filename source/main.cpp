#include "main.hpp"
__attribute__((section(".bss"))) rtld::ModuleObject __nx_module_runtime; // to appease rtld


// hook for gsys::SystemTask::invokeDrawTV_
void render(agl::DrawContext *drawContext, sead::TextWriter *textWriter)
{
    Lp::Sys::Ctrl* controller =  Lp::Utl::getCtrl(0);

    if(controller->data[1] & 0x2){
        int fullWidth = 1280;
        int fullHeight = 720;
        int width = fullWidth/2;
        int height = fullHeight;

        sead::Vector3<float> p1;
        p1.mX = -1.0;
        p1.mY = 1.0;
        p1.mZ = 0.0;
        sead::Vector3<float> p2;
        p2.mX = (width/fullWidth);
        p2.mY = 1.0;
        p2.mZ = 0.0;
        sead::Vector3<float> p3;
        p3.mX = -1.0;
        p3.mY = 1-(height/fullHeight);
        p3.mZ = 0.0;
        sead::Vector3<float> p4;
        p4.mX = (width/fullWidth);
        p4.mY = 1-(height/fullHeight);
        p4.mZ = 0.0;

        sead::Color4f c;
        c.r = 1.0;
        c.g = 1.0;
        c.b = 1.0;
        c.a = 0.5;

        agl::utl::DevTools::beginDrawImm(drawContext, sead::Matrix34<float>::ident, sead::Matrix44<float>::ident);
        agl::utl::DevTools::drawTriangleImm(drawContext, p1, p2, p3, c);
        agl::utl::DevTools::drawTriangleImm(drawContext, p3, p4, p2, c);
        
        float size = 60;
        size /= 120;
        size *= 10;
        size += 10;

        textWriter->setScaleFromFontHeight(size);
        sead::TextWriter::setupGraphics(drawContext); // re-setup context

        textWriter->printf("Welcome to Starlight!\n");
        textWriter->printf("This is a demonstration of C/C++ code running in the context of a Switch game!\n");
        textWriter->printf("Credit to shibboleet, Khangaroo, Thog, Retr0id, and the libnx maintainers!\n");
        
        Cmn::PlayerCtrl *playerCtrl = Cmn::PlayerCtrl::sInstance;
        if(playerCtrl != NULL){
            Game::PlayerGamePadData::FrameInput input;
            input.record();
            textWriter->printf("Left stick | x: %f | y: %f\n", input.leftStick.mX, input.leftStick.mY);
            textWriter->printf("Right stick | x: %f | y: %f\n", input.rightStick.mX, input.rightStick.mY);
            textWriter->printf("Angle vel | x: %f | y: %f | z: %f\n", input.angleVel.mX, input.angleVel.mY, input.angleVel.mZ);
            textWriter->printf("Posture x | x: %f | y: %f | z: %f\n", input.postureX.mX, input.postureX.mY, input.postureX.mZ);
            textWriter->printf("Posture y | x: %f | y: %f | z: %f\n", input.postureY.mX, input.postureY.mY, input.postureY.mZ);
            textWriter->printf("Posture z | x: %f | y: %f | z: %f\n", input.postureZ.mX, input.postureZ.mY, input.postureZ.mZ);
        }

        char* data = controller->data;
        for(int i = 0; i < 4; i++){
            char j = data[i];
            for(int k = 0; k < 8; k++){
                textWriter->printf("%i", j & 1);
                j >>= 1;
            }
            textWriter->printf(" ");
        }
        textWriter->printf("\n");

        Cmn::StaticMem *staticMem = Cmn::StaticMem::sInstance;

        if(staticMem != NULL){
            textWriter->printf("StaticMem ptr: 0x%x\n", staticMem);
            sead::SafeStringBase<char> *stageName = &staticMem->stageName;
            if(stageName->mCharPtr != NULL){
                textWriter->printf("Loaded stage: %s\n", stageName->mCharPtr);
            }
            Cmn::PlayerInfoAry *playerInfoAry = staticMem->playerInfoArray;
            if(playerInfoAry != NULL){
                textWriter->printf("PlayerInfoAry ptr: 0x%x\n", playerInfoAry);
                Cmn::PlayerInfo* playerInfo = playerInfoAry->infos[0];
                if(playerInfo != NULL){
                    textWriter->printf("PlayerInfo[0] ptr: 0x%x\n", playerInfo);
                    textWriter->printf("PlayerInfo[0] weapon ID: 0x%x\n", playerInfo->weapon.id);
                    textWriter->printf("PlayerInfo[0] weapon turf inked: 0x%x\n", playerInfo->weapon.turfInked);
                    textWriter->printf("PlayerInfo[0] unk 14: 0x%x\n", playerInfo->field_14);
                    textWriter->printf("PlayerInfo[0] unk 15: 0x%x\n", playerInfo->field_15);
                    textWriter->printf("PlayerInfo[0] unk CC: 0x%x\n", playerInfo->dwordCC);
                    textWriter->printf("PlayerInfo[0] unk D0: 0x%x\n", playerInfo->dwordD0);
                    textWriter->printf("PlayerInfo[0] unk D4: 0x%x\n", playerInfo->dwordD4);
                    textWriter->printf("PlayerInfo[0] unk D8: 0x%x\n", playerInfo->dwordD8);
                    textWriter->printf("PlayerInfo[0] unk FC: 0x%x\n", playerInfo->dwordFC);
                    textWriter->printf("PlayerInfo[0] unk 150: 0x%x\n", playerInfo->dword150);
                    textWriter->printf("PlayerInfo[0] unk 154: 0x%x\n", playerInfo->dword158);
                    //sead::SafeStringBase<char> newName;
                    //newName.mCharPtr = "Gamer";
                    //playerInfo->dbgSetPlayerName(newName);
                }
            }
        }
        textWriter->printf("Font size: %f\n", size);
    }
}

bool isHold(Cmn::PlayerCtrl *playerCtrl, unsigned long id){
    unsigned long read = playerCtrl->isHold(id & 0xC0);
    read |= playerCtrl->isHold(id & 0x3F);
    return read;
}

int main(int argc, char **argv) 
{
    // this is to ensure that this isn't being ran by the HBL
    if (svcGetSystemTick() > 0) 
    {
        return 0;
    }
}