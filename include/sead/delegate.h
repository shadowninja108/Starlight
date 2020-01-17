/**
 * @file delegate.h
 * @brief Delegate classes.
 */

#pragma once

#include "list.h"

namespace sead
{
    class Heap;

    template<typename T>
    class Delegate
    {
    public:
        virtual void invoke();
        virtual void clone(sead::Heap *) const;

        T* mInstance;
        void (*mCallback)(T);
        u64 mUnk;
    };

    
    template<typename T>
    class IDelegate1
    {
    public:
        virtual void invoke(T);
        virtual void clone(sead::Heap *) const;
        virtual bool isNoDummy();

        T* mInstance;
        void (*mCallback)(T);
        u64 mUnk;
    };

    template<typename T, typename T2>
    class IDelegate2
    {
        public:
        virtual void invoke(T, T2) = 0;
        virtual void clone(sead::Heap *) const = 0;
        virtual bool isNoDummy();

        T* mInstance;
        void (*mCallback)(T, T2);
        u64 mUnk;
    };

    template<typename T, typename T2>
    class Delegate1 : public IDelegate1<T>
    {
    public:
        virtual void invoke(T2);
        virtual void clone(sead::Heap *) const;
        virtual bool isNoDummy();
    };

    template<typename T, typename T2, typename T3>
    class Delegate2 : public IDelegate2<T2, T3>
    {
    public:
        virtual void invoke(T2, T3);
        virtual void clone(sead::Heap *) const;
        virtual bool isNoDummy();
    };


    template<typename T>
    class DelegateEvent
    {
    public:

        class Slot
        {
        public:
            virtual ~Slot();

            u64 _0;
            u64 _8;
            u64 _10;
            u64 _18;
            sead::ListNode mNode; // _20
            u64 _30;
            u64 _38;
            u8 _40[0x6C-0x40];
        };

        virtual ~DelegateEvent();
    };

    template<typename T>
    class AnyDelegate1Const { };
};