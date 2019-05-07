#pragma once 

#include "types.h"

namespace Lp
{
  namespace Sys {

      class Ctrl{
          public:
          bool isHoldContinue(unsigned int, int) const;
          bool isTrigWithRepeat(unsigned int, int, int) const;

          __int32 dword0;
          __int32 dword4;
          __int64 qword8;
          __int64 data;
      };
  };
};
