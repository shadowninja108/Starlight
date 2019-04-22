#include "main.hpp"
__attribute__((section(".bss"))) rtld::ModuleObject __nx_module_runtime; // to appease rtld

// hook for Lp::Sys::GfxLayer2D::drawUser
void render(agl::lyr::Layer *layer, agl::lyr::RenderInfo *renderInfo)
{
    agl::DrawContext* drawContext = renderInfo->drawContext;

    sead::Vector3<float> p1;
    p1.mX = 0.0;
    p1.mY = 0.0;
    p1.mZ = 0.0;
    sead::Vector3<float> p2;
    p2.mX = 0.0;
    p2.mY = 127.0;
    p2.mZ = 0.0;
    sead::Vector3<float> p3;
    p3.mX = 127.0;
    p3.mY = 0.0;
    p3.mZ = 0.0;

    sead::Color4f c;
    c.r = 255.0;
    c.g = 255.0;
    c.b = 255.0;
    c.a = 255.0;

    //agl::utl::DevTools::drawTriangleImm(drawContext, p1, p2, p3, c);
}

int main(int argc, char **argv) 
{
    // this is to ensure that this isn't being ran by the HBL
    if (svcGetSystemTick() > 0) 
    {
        return 0;
    }
}
