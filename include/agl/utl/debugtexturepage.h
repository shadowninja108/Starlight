#include "types.h"

#pragma once
namespace agl {
  namespace utl {

    class DebugTexturePage {
      public:
        ::sead::IDisposer disposer;
        _QWORD qword20;
        _QWORD qword28;
        _QWORD qword30;
        _QWORD qword38;
        _QWORD qword40;
        _QWORD qword48;
        _QWORD qword50;
        signed int signed58;
        _BYTE gap5C[132];
        _QWORD qwordE0;
        _QWORD qwordE8;
        _DWORD dwordF0;
        _BYTE gapF4[132];
        _QWORD qword178;
        _QWORD qword180;
        _DWORD dword188;
        _BYTE gap18C[132];
        _BYTE byte210;
        _DWORD dword214;
        _DWORD dword218;
        _QWORD qword220;
        _BYTE byte228;
        _BYTE byte229;
        _BYTE byte22A;
        _DWORD dword22C;
        _DWORD dword230;
        _QWORD qword238;
    };
  };
};