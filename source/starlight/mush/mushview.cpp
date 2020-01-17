#include "starlight/mush/mushview.hpp"

namespace starlight {

    namespace mush {

        int MapMushView::getSize(){
            return Collector::mMushMapInfo->mMapInfoCount;
        }

        void MapMushView::render(sead::TextWriter* textWriter, int index){
            Cmn::MushMapInfo* mushMapInfo = Collector::mMushMapInfo;

            Cmn::MushMapInfo::Data* info = mushMapInfo->getByMushOrder(index);

            textWriter->printf("Id: 0x%x\n", info->Id);
            textWriter->printf("Str1: %s\n", info->mStr1.mCharPtr);
            textWriter->printf("EnvHour: %i\n", info->mEnvHour);
        }

        int WeaponMushView::getSize(){
            return 0xB0 / sizeof(u64);
        }

        void WeaponMushView::render(sead::TextWriter *textWriter, int index){
            Cmn::MushWeaponInfo* mushWeaponInfo = Collector::mMushWeaponInfo;
            Cmn::WeaponData* weapon = mushWeaponInfo->getById(Cmn::Def::WeaponKind::cMain, index);
            textWriter->printf("Id: 0x%x\n", weapon->mId);
            textWriter->printf("Name: %s\n", weapon->mNameData);
            textWriter->printf("Model name: %s\n", weapon->mModelNameData);
            textWriter->printf("Arc name: %s\n", weapon->mArcNameData);
            textWriter->printf("Custom parts matrial: 0x%x\n", weapon->mCustomPartsMaterial);
            textWriter->printf("Class type: 0x%x\n", weapon->mWeaponClassType);
            textWriter->printf("Sub: 0x%x\n", weapon->mSubData);
            textWriter->printf("Special: 0x%x\n", weapon->mSpecialData);
            for(int i = 0; i < 3; i++){
                textWriter->printf("Param[%i] name: %s\n", i, weapon->mParams[i].mParamNameData);
                textWriter->printf("Param[%i] value: 0x%x\n", i, weapon->mParams[i].mParamValue);
            }
        }
    };
};