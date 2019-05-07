#include "types.h"

#pragma once

namespace Lp {

  namespace Sys {


      class XLinkIUser {
        public:
          XLinkIUser();
          virtual char* getLinkName();
          _QWORD qword8;
          _QWORD qword10;
          _QWORD qword18;
          _QWORD qword20;
          _QWORD qword28;
          _QWORD qword30;
      };
  };
};