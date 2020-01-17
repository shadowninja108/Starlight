/**
 * @file stream.h
 * @brief Binary/Text I/O Streaming
 */

#pragma once

#include "types.h"

namespace sead
{

    class StreamSrc {
        virtual uint read(void*, uint);
        virtual uint write(void const*, uint);
        virtual uint skip(int);
        virtual void rewind();
        virtual bool isEOF();
        virtual void flush();
    };

    class Endian
    {
    public:
        enum Types
        {
            BIG = 0,
            LITTLE = 1
        };
    };

    class StreamFormat {
        virtual uchar readU8(sead::StreamSrc*, sead::Endian::Types);
        virtual ushort readU16(sead::StreamSrc*, sead::Endian::Types);
        virtual uint readU32(sead::StreamSrc*, sead::Endian::Types);
        virtual ulong readU64(sead::StreamSrc*, sead::Endian::Types);
        virtual signed char readS8(sead::StreamSrc*, sead::Endian::Types);
        virtual short readS16(sead::StreamSrc*, sead::Endian::Types);
        virtual int readS32(sead::StreamSrc*, sead::Endian::Types);
        virtual long readS64(sead::StreamSrc*, sead::Endian::Types);
        virtual float readF32(sead::StreamSrc*, sead::Endian::Types);

        virtual void readBit(sead::StreamSrc*, void*, uint);
        virtual void readString(sead::StreamSrc*, sead::BufferedSafeStringBase<char>*, uint);
        virtual void readMemBlock(sead::StreamSrc*, void*, uint);
        
        virtual void writeU8(sead::StreamSrc*, sead::Endian::Types, uchar);
        virtual void writeU16(sead::StreamSrc*, sead::Endian::Types, ushort);
        virtual void writeU32(sead::StreamSrc*, sead::Endian::Types, uint);
        virtual void writeU64(sead::StreamSrc*, sead::Endian::Types, ulong);
        virtual void writeS8(sead::StreamSrc*, sead::Endian::Types, signed char);
        virtual void writeS16(sead::StreamSrc*, sead::Endian::Types, short);
        virtual void writeS32(sead::StreamSrc*, sead::Endian::Types, int);
        virtual void writeS64(sead::StreamSrc*, sead::Endian::Types, long);
        virtual void writeF32(sead::StreamSrc*, sead::Endian::Types, float);

        virtual void writeBit(sead::StreamSrc *,void const*,uint);
        virtual void writeString(sead::StreamSrc *,sead::SafeStringBase<char> const&,uint);
        virtual void writeMemBlock(sead::StreamSrc *,void const*,uint);
        virtual void writeDecorationText(sead::StreamSrc *,sead::SafeStringBase<char> const&);
        virtual void writeNullChar(sead::StreamSrc *);

        // TODO: finish this vtable 
    };

    class Stream
    {
    public:
        enum Modes
        {
            BINARY = 0,
            TEXT = 1
        };

        Stream();
        Stream(sead::StreamSrc *, sead::Stream::Modes);
        Stream(sead::StreamSrc *, sead::StreamFormat *);
        virtual ~Stream();

        void setMode(sead::Stream::Modes);
        void setUserFormat(sead::StreamFormat *);
        void setBinaryEndian(sead::Endian::Types);
        void skip(u32 howMany);
        void skip(u32, u32);
        void rewind();
        bool isEOF();

        sead::StreamFormat* mStreamFormat; // _8
        sead::StreamSrc* mSrc; // _10
        sead::Endian::Types mEndianess; // _18
    };

    class ReadStream { };

    class WriteStream { };
};