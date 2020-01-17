/**
 * @file vector.h
 * @brief Vector implementation.
 */

#pragma once

namespace sead
{
    template<typename T>
    class Vector2
    {
    public:

        T mX;
        T mY;

        static Vector2<T> zero;
        static Vector2<T> ex;
    };

    template<typename T>
    class Vector3
    {
    public:
        
        T mX;
        T mY;
        T mZ;

        static Vector3<T> zero;
    };

    template<typename T>
    class Vector4
    {
    public:
        
        T mX;
        T mY;
        T mZ;
        T mH;
    };
};