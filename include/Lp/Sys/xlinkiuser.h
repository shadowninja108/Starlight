#pragma once

#include "types.h"

#include "gsys/model.h"
#include "sead/string.h"

namespace Lp {

  namespace Sys {


      class XLinkIUser {
        public:
          XLinkIUser();
          virtual char* getLinkName();
          
          u64 XLinkIUser_ModelCount;
          gsys::Model **XLinkIUser_ModelArryPtr;
          u64 XLinkIUser_ActionSlotCount;
          sead::SafeStringBase<char> **XLinkIUser_ActionSlotArryPtr;
          u64 XLinkIUser_LocalPropertiesCount;
          u64 XLinkIUser_LocalPropertiesArryPtr;
      };
  };
};