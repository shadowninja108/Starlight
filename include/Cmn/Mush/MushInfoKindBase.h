#pragma once

#include "types.h"

namespace Cmn {
    template <class T, class K> class MushInfoWithKindBase {
        public:
            T* getById(K, int) const;    
    };
};