#include "types.h"
#include "agl/utl/parameter.h"

#pragma once

namespace agl {
  namespace utl {
      class MultiFilterUnit {
          public:
        _QWORD qword8;
        _QWORD qword10;
        _QWORD qword18;
        _QWORD qword20;
        IParameterList parameterList;
        IParameterObj parameterObj;
        _QWORD qwordA0;
        _QWORD qwordA8;
        _DWORD dwordB0;
        _DWORD dwordB4;
        ParameterBase paramBases[4];
      };
  }; 
};