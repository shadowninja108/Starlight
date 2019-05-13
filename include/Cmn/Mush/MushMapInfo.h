#pragma once

#include "types.h"

namespace Cmn {
    class MushMapInfo {
        public:
        class Data {
            public:
            _DWORD dword0;
            _QWORD qword4;
            _DWORD msnAreaNo;
            _DWORD msnStageNo;
            _DWORD msnMainWeaponId;
            _QWORD qword18;
            void *pvoid20;
            signed int signed28;
            _BYTE gap2C[68];
            _QWORD qword70;
            void *pvoid78;
            signed int signed80;
            _BYTE gap84[68];
            _QWORD envHour;
            _DWORD effectFakePointLight;
            float miniMapScale;
            float miniMapYaw;
            _DWORD miniMapPitch;
            _DWORD miniMapTrans;
            _DWORD dwordE4;
            _DWORD qwordE8;
            int miniMapBravoInvType;
            _QWORD qwordF0;
            void *fixTeamColor;
            signed int signed100;
            _BYTE gap104[68];
            _QWORD qword148;
            void *bgmType;
            signed int signed158;
            _BYTE gap15C[68];
            _QWORD qword1A0;
            void *pvoid1A8;
            signed int signed1B0;
            _BYTE gap1B4[68];
            _WORD word1F8;
            __attribute__((aligned(4))) _QWORD qword1FC;
            _BYTE gap204[4];
            _QWORD qword208;
            _QWORD qword210;
            _QWORD qword218;
            _QWORD qword220;
            _DWORD dword228;
            _DWORD dword230;
        };

        Cmn::MushMapInfo::Data* getByMushOrder(int) const;
    };
};