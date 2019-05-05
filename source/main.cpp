#include "main.hpp"
__attribute__((section(".bss"))) rtld::ModuleObject __nx_module_runtime; // to appease rtld

// hook for gsys::SystemTask::invokeDrawTV_
void render(agl::DrawContext *drawContext, sead::TextWriter *textWriter)
{
    sead::Vector3<float> p1;
    p1.mX = -1;
    p1.mY = 1;
    p1.mZ = 0.0;
    sead::Vector3<float> p2;
    p2.mX = -1;
    p2.mY = 0.3;
    p2.mZ = 0.0;
    sead::Vector3<float> p3;
    p3.mX = 0.5;
    p3.mY = 1;
    p3.mZ = 0.0;

    sead::Color4f c;
    c.r = 255.0;
    c.g = 255.0;
    c.b = 255.0;
    c.a = 0.5;

    agl::utl::DevTools::drawTriangleImm(drawContext, p1, p2, p3, c);
    textWriter->printf("Welcome to Starlight!\n");
    textWriter->printf("This is a demonstration of C/C++ code running in the context of a Switch game!\n");
    textWriter->printf("Credit to shiboleet, Khangaroo, Dax, Retr0id, and the libnx maintainers!\n");
    
    Cmn::StaticMem *staticMem = Cmn::StaticMem::sInstance;

    if(staticMem != NULL){
        sead::SafeStringBase<char> *stageName = &staticMem->stageName;
        if(stageName->mCharPtr != NULL){
            textWriter->printf("Loaded stage: %s\n", stageName->mCharPtr);
        }
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