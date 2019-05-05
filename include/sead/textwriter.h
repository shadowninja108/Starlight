/**
 * @file viewport.h
 * @brief Basic Viewport class.
 */

#pragma once

#include "types.h"
#include "sead/projection.h"
#include "sead/bound.h"

namespace sead
{
    class TextWriter
    {
        public:
            void printImpl_(char const*, int, bool, sead::BoundBox2<float>*);
            void printf(char const*, ...);
    };
};