#pragma once

#include "types.h"

namespace Cmn
{
    class MushMapInfo
    {
    public:
        class Data
        {
        public:
            int Id;
            int Data_x4;
            int Data_x8;
            int mMsnAreaNo;
            int mMsnStageNo;
            int mMsnMainWeaponId;
            sead::BufferedSafeStringBase<char> mStr1;
            char mStr1Data[64];
            sead::BufferedSafeStringBase<char> Str2;
            char mStr2Data[64];
            int mEnvHour;
            float mMiniMapScale;
            float mMiniMapYaw;
            float mMiniMapPitch;
            int mMiniMapTrans;
            float Data_xDC;
            int mData_xE0;
            int mMiniMapBravoInvType;
            sead::BufferedSafeStringBase<char> mFixTeamColor;
            char mFixTeamColorData[64];
            sead::BufferedSafeStringBase<char> mBGMType;
            char mBGMTypeData[64];
            sead::BufferedSafeStringBase<char> mSndSceneEnv;
            char mSndSceneEnvData[64];
            bool mBakeLightForceEnable;
            bool mOnlyObjPaint;
            u64 padd;
            float mAbnormalYPos;
            int mCoopAddition;
            int mPrivateMatchOrder;
            int mMsnLyr_Shooter;
            int mMsnLyr_Roller;
            int mMsnLyr_Charger;
            int mMsnLyr_Twins;
            int mMsnLyr_Umbrella;
            int mMsnLyr_Spinner;
            int mMsnLyr_Blaster;
            int mMsnLyr_Slosher;
            int mMsnLyr_Brush;
            int Data_x224;
        };
        Cmn::MushMapInfo::Data* getByMushOrder(int) const;
        
        
        const char* getDevName(void)
    
        int MushMapInfo_x8;
        int MushMapInfo_xC;
        Data *mMapInfoArray;
        u32 mMapInfoArrayCount;
        int MushMapInfo_x1C;
        int MushMapInfo_x20;
        int MushMapInfo_x24;
        Data mDefaultData;
    };
};
