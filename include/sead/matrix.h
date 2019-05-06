/**
 * @file matrix.h
 * @brief Matrix implementation.
 */

#pragma once

#include "types.h"

namespace sead
{
    template<typename T>
    class Matrix34
    {
        public:
        static Matrix34<float> ident; 
        T matrix[3][4];
    };

    template<typename T>
    class Matrix44
    {
        public:
        static Matrix44<float> ident; 
        T matrix[4][4];
    };
};