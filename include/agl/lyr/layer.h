#include "types.h"

#include "sead/heap.h"
#include "agl/RenderBuffer.h"
#include "agl/utl/multifilter.h"
#include "agl/utl/debugtexturepage.h"
#include "gsys/layertexture.h"

namespace agl {

  namespace lyr {
    
      class Layer {
        public:
        ::sead::IDisposer *disposer;
        _BYTE gap10[24];
        _DWORD dword28;
        _BYTE gap2C[4];
        _DWORD dword30;
        _BYTE gap34[4];
        _QWORD qword38;
        _DWORD dword40;
        _BYTE gap44[4];
        _QWORD qword48;
        _DWORD dword50;
        _BYTE gap54[4];
        _QWORD qword58;
        _DWORD dword60;
        _BYTE gap64[4];
        _QWORD qword68;
        _DWORD dword70;
        _BYTE gap74[4];
        _QWORD qword78;
        RenderBuffer renderBuffer;
        _BYTE gap84[300];
        _DWORD dword1B0;
        _DWORD dword1B4;
        _DWORD dword1B8;
        _WORD word1BC;
        _BYTE byte1BE;
        _BYTE gap1BF[41];
        int fixedSize1;
        _BYTE gap1EC[196];
        int fixedSize2;
        _BYTE gap2B4[196];
        int fixedSize3;
        _BYTE gap37C[196];
        int fixedSize4;
        _BYTE gap444[196];
        _QWORD qword508;
        _DWORD dword510;
        _BYTE gap514[4];
        ::sead::CriticalSection lock;
        _BYTE gap540[24];
        _QWORD qword558;
        _QWORD qword560;
        _DWORD dword568;
        _DWORD dword56C;
        _DWORD dword570;
        _DWORD dword574;
        _WORD word578;
        _BYTE byte57A;
        _BYTE byte57B;
        _WORD word57C;
        _BYTE byte57E;

        void setVisible(bool visible);
      };
  };
};