#pragma once

#include <array>

#include "def/Gear.h"
#include "def/Weapon.h"
#include "lp/Sys/iusehionode.h"
#include "sead/time.h"
#include "types.h"

#ifndef CONCATENATE
#define _CONCATENATE(x1, x2) x1##x2
#define CONCATENATE(x1, x2) _CONCATENATE(x1, x2)
#endif
#define INSERT_PADDING_BYTES(num_bytes) u8 CONCATENATE(pad, __LINE__)[(num_bytes)];

namespace Cmn {

    class SaveDataCmn : Lp::Sys::IUseHioNode {
       public:
        class HaveWeapon {
           public:
            Def::Weapon weapon;
            sead::DateTime lastEquippedTime;
            u32 freshness;
            u32 flagColor;
            using WeaponFlags = std::array<u32, 66>;
            WeaponFlags weaponFlags;
            u32 isNew;
            INSERT_PADDING_BYTES(4);
        };
        static_assert(sizeof(HaveWeapon) == 0x130, "SaveDataCmn::HaveWeapon must be 0x130 bytes long");

        class HaveGear {
           public:
            Def::Gear gear;
            sead::DateTime lastEquippedTime;
            u32 isNew;
            INSERT_PADDING_BYTES(4);
        };
        static_assert(sizeof(HaveGear) == 0x30, "SaveDataCmn::HaveGear must be 0x30 bytes long");

        class HaveSkillChip {
           public:
            s32 id;
            u32 amount;
        };
        static_assert(sizeof(HaveSkillChip) == 8, "SaveDataCmn::HaveSkillChip must be 8 bytes long");

        class HaveBoostTicket {
           public:
            s32 id;
            s32 boostedId;
            u32 amount;
        };
        static_assert(sizeof(HaveBoostTicket) == 0xC, "SaveDataCmn::HaveBoostTicket must be 0xC bytes long");

        struct SaveDataCmnData {
            // inkling customizations
            s32 inklingPlayerModelType;
            s32 inklingPlayerHairId;
            s32 inklingPlayerBottomId;
            s32 inklingPlayerSkinColorId;
            s32 inklingPlayerEyeColorId;

            Def::Weapon equippedWeapon;
            INSERT_PADDING_BYTES(4);

            using WeaponInventory = std::array<HaveWeapon, 0x100>;
            WeaponInventory weaponInventory;

            s32 equippedShoesId;
            s32 equippedClothesId;
            s32 equippedHeadGearId;
            INSERT_PADDING_BYTES(4);

            using GearKindInventory = std::array<HaveGear, 0x200>;
            GearKindInventory shoeInventory;
            GearKindInventory clothesInventory;
            GearKindInventory headGearInventory;

            using SkillChipInventory = std::array<HaveSkillChip, 0x40>;
            SkillChipInventory skillChipInventory;

            using BoostTicketInventory = std::array<HaveBoostTicket, 0x40>;
            BoostTicketInventory ticketInventory;

            u32 hasSeenTutorial;

            // control options
            float handheldStickSensitivity;
            float handheldMotionSensitivity;
            u8 handheldMotionEnabled;
            u8 handheldMotionInvertY;
            u8 handheldMotionInvertX;
            INSERT_PADDING_BYTES(0x41);
            float detachedStickSensitivity;
            float detachedMotionSensitivity;
            u8 detachedMotionEnabled;
            u8 detachedMotionInvertY;
            u8 detachedMotionInvertX;
            INSERT_PADDING_BYTES(0x41);

            u32 onlinePlayPenalty[4];  // TODO: Look into this
            sead::DateTime penaltyEndTime;

            INSERT_PADDING_BYTES(0x188);

            u32 money;
            u32 seaSnails;

            INSERT_PADDING_BYTES(0x108);

            sead::DateTime saveTime;

            INSERT_PADDING_BYTES(0x54);

            u8 colorLock;
            u8 showPlazaPosts;

            INSERT_PADDING_BYTES(0x2BEA);

            // octoling customizations
            s32 octolingPlayerModelType;
            s32 octolingPlayerHairId;
            s32 octolingPlayerBottomId;
            s32 octolingPlayerSkinColorId;
            s32 octolingPlayerEyeColorId;
            s32 IsOctoling;

            INSERT_PADDING_BYTES(0x2D24);
        };
        static_assert(sizeof(SaveDataCmnData) == 0x2B210, "SaveDataCmnData must be 0x2B210 bytes long");

        virtual ~SaveDataCmn();

        u64 unk0;
        SaveDataCmnData* pData;
    };

    class SaveData : Lp::Sys::IUseHioNode {
       public:
        virtual ~SaveData();

        u64 unk0;
        void* pSaveDataBuffer;
        SaveDataCmn* pSaveDataCmn;
        void* pSaveDataVss;
        void* pSaveDataLocal;
        void* pSaveDataMsn;
        void* pSaveDataShop;
        void* pSaveDataCoop;
        void* pSaveDataFest;
        void* pSaveDataStats;
        void* pSaveDataMsnOcta;

        void fullOpen();
    };

    SaveData* GetSaveWrite();

};  // namespace Cmn
