#include "types.h"

#include "sead/tree.h"
#include "sead/string.h"

#pragma once

namespace Lp {

  namespace Sys {

      class Actor{
        public:
          Actor();
          virtual ~Actor();

          _QWORD qword8;
          sead::TreeNode treeNodes[2];
          _BYTE data[180];
          _QWORD qword118;
          _QWORD qword120;
          _QWORD qword128;
          _QWORD qword130;
          _QWORD qword138;
          _QWORD qword140;
          _QWORD qword148;
          __int64 array[16];
          _BYTE gap1D0[136];
          _DWORD dword258;
          u64 mSystemTick; // _260
          _QWORD qword268;
          sead::BufferedSafeStringBase<char> str;
          _BYTE gap288[64];
          _QWORD qword2C8;
          _QWORD qword2D0;
          _QWORD qword2D8;
          _QWORD qword2E0;
      };
  };
};