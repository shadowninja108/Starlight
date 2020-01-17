#pragma once 

#include "types.h"
#include "sead/matrix.h"
#include "sead/array.h"
#include "sead/controller.h"
#include "ctrldata.h"

namespace Lp
{
  namespace Sys {
      #pragma pack(push, 4)
      class Ctrl{
        public:

        virtual ~Ctrl();
        virtual bool checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo const*);
        virtual sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo();
        virtual void setEnableGyroDirRevise();
        virtual void setGyroDirReviseBaseMtx(sead::Matrix34<float> const&);
        virtual void setGyroDirReviseParam(float);
        virtual void updateData();
        virtual void updateData200Hz();

        bool isHoldContinue(unsigned int, int) const;
        bool isTrigWithRepeat(unsigned int, int, int) const;

        u64 Ctrl_x8;
        CtrlData mData1;
        CtrlData mData2;
        u64 Ctrl_x150;
        u32 Ctrl_x158;
        sead::SafeArray<CtrlData200Hz, 16> m200hzData;
        u32 Ctrl_xBDC;
        u16 Ctrl_xBE0;
        u16 Ctrl_xBE2; // padding?
        u32 mIndex;
        u32 Ctrl_xBE8;
        sead::BufferedSafeStringBase<char> Ctrl_xBF0;
        char Ctrl_xC04[32];
        u32 Ctrl_xC24;
        sead::NinJoyNpadDevice* mBaseDevice;
      };
      #pragma pack(pop)
  };
};
