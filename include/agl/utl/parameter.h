#include "types.h"

#include "sead/string.h"

#pragma once
namespace agl {
  namespace utl {

      class IParameterList {
        _QWORD qword8;
        _QWORD qword10;
        _QWORD qword18;
        _QWORD qword20;
        _DWORD hash;
        _QWORD qword30;
        _QWORD qword38;
        _QWORD qword40;
      };

      class ParameterBase {
        _DWORD hash;
        _QWORD qword10;
        _QWORD data;
      };

      class IParameterObj {
        _QWORD qword8;
        _QWORD qword10;
        _QWORD qword18;
        _QWORD qword20;
        _QWORD qword28;
      };

      
      class IParameterIO {
        IParameterList parameterList;
        ::sead::BufferedSafeStringBase<char> string1[3];
        _BYTE gap90[16];
        _DWORD dwordA0;
        _QWORD qwordA8;
        ::sead::BufferedSafeStringBase<char> string2[11];
        _BYTE gap1B8[16];
        _QWORD qword1C8;
      };
  };
};