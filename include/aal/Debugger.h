#pragma once

#include "sead/drawcontext.h"
#include "sead/textwriter.h"

namespace aal{
    class Debugger {
        public:
        Debugger();
        void drawInformation(sead::DrawContext *a2, sead::TextWriter *a3) const;
    };
};