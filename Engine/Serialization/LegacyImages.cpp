#include "Engine/Engine.h"
#include "Engine/LOD.h"
#include "Engine/Time.h"
#include "Engine/Party.h"
#include "Engine/Tables/IconFrameTable.h"
#include "Engine/Objects/NPC.h"
#include "Engine/Graphics/Overlays.h"
#include "Engine/Serialization/LegacyImages.h"

NPCData_Image_MM7::NPCData_Image_MM7()
{
    Assert(sizeof(*this) == 0x4C);
    memset(this, 0, sizeof(*this));
}

ItemGen_Image_MM7::ItemGen_Image_MM7()
{
    Assert(sizeof(*this) == 0x24);
    memset(this, 0, sizeof(*this));
}

SpellBuff_Image_MM7::SpellBuff_Image_MM7()
{
    Assert(sizeof(*this) == 0x10);
    memset(this, 0, sizeof(*this));
}

PlayerSpellbookChapter_Image_MM7::PlayerSpellbookChapter_Image_MM7()
{
    Assert(sizeof(*this) == 0xB);
    memset(this, 0, sizeof(*this));
}

PlayerSpells_Image_MM7::PlayerSpells_Image_MM7()
{
    Assert(sizeof(*this) == 0x64);
    memset(this, 0, sizeof(*this));
}

PlayerEquipment_Image_MM7::PlayerEquipment_Image_MM7()
{
    Assert(sizeof(*this) == 0x40);
    memset(this, 0, sizeof(*this));
}

LloydBeacon_Image_MM7::LloydBeacon_Image_MM7()
{
    Assert(sizeof(*this) == 0x1C);
    memset(this, 0, sizeof(*this));
}

Player_Image_MM7::Player_Image_MM7()
{
    Assert(sizeof(*this) == 0x1B3C);
    memset(this, 0, sizeof(*this));
}

PartyTimeStruct_Image_MM7::PartyTimeStruct_Image_MM7()
{
    Assert(sizeof(*this) == 0x678);
    memset(this, 0, sizeof(*this));
}

Party_Image_MM7::Party_Image_MM7()
{
    Assert(sizeof(*this) == 0x16238);
    memset(this, 0, sizeof(*this));
}

Timer_Image_MM7::Timer_Image_MM7()
{
    Assert(sizeof(*this) == 0x28);
    memset(this, 0, sizeof(*this));
}

OtherOverlay_Image_MM7::OtherOverlay_Image_MM7()
{
    Assert(sizeof(*this) == 0x14);
    memset(this, 0, sizeof(*this));
}

OtherOverlayList_Image_MM7::OtherOverlayList_Image_MM7()
{
    Assert(sizeof(*this) == 0x3F0);
    memset(this, 0, sizeof(*this));
}

IconFrame_MM7::IconFrame_MM7()
{
    Assert(sizeof(*this) == 0x20);
    memset(this, 0, sizeof(*this));
}

UIAnimation_MM7::UIAnimation_MM7()
{
    Assert(sizeof(*this) == 0xD);
    memset(this, 0, sizeof(*this));
}





void Timer_Image_MM7::Serialize(Timer *timer)
{
    memset(this, 0, sizeof(*this));

    this->bReady = timer->bReady;
    this->bPaused = timer->bPaused;
    this->bTackGameTime = timer->bTackGameTime;
    this->uStartTime = timer->uStartTime;
    this->uStopTime = timer->uStopTime;
    this->uGameTimeStart = timer->uGameTimeStart;
    this->field_18 = timer->field_18;
    this->uTimeElapsed = timer->uTimeElapsed;
    this->dt_in_some_format = timer->dt_in_some_format;
    this->uTotalGameTimeElapsed = timer->uTotalGameTimeElapsed;
}

void Timer_Image_MM7::Deserialize(Timer *timer)
{
    timer->bReady = this->bReady;
    timer->bPaused = this->bPaused;
    timer->bTackGameTime = this->bTackGameTime;
    timer->uStartTime = this->uStartTime;
    timer->uStopTime = this->uStopTime;
    timer->uGameTimeStart = this->uGameTimeStart;
    timer->field_18 = this->field_18;
    timer->uTimeElapsed = this->uTimeElapsed;
    timer->dt_in_some_format = this->dt_in_some_format;
    timer->uTotalGameTimeElapsed = this->uTotalGameTimeElapsed;
}

void NPCData_Image_MM7::Serialize(NPCData *npc)
{
    memset(this, 0, sizeof(*this));

    this->pName = npc->pName;
    this->uPortraitID = npc->uPortraitID;
    this->uFlags = npc->uFlags;
    this->fame = npc->fame;
    this->rep = npc->rep;
    this->Location2D = npc->Location2D;
    this->uProfession = npc->uProfession;
    this->greet = npc->greet;
    this->joins = npc->joins;
    this->field_24 = npc->field_24;
    this->evt_A = npc->evt_A;
    this->evt_B = npc->evt_B;
    this->evt_C = npc->evt_C;
    this->evt_D = npc->evt_D;
    this->evt_E = npc->evt_E;
    this->evt_F = npc->evt_F;
    this->uSex = npc->uSex;
    this->bHasUsedTheAbility = npc->bHasUsedTheAbility;
    this->news_topic = npc->news_topic;
}

void NPCData_Image_MM7::Deserialize(NPCData *npc)
{
    npc->pName = this->pName;
    npc->uPortraitID = this->uPortraitID;
    npc->uFlags = this->uFlags;
    npc->fame = this->fame;
    npc->rep = this->rep;
    npc->Location2D = this->Location2D;
    npc->uProfession = this->uProfession;
    npc->greet = this->greet;
    npc->joins = this->joins;
    npc->field_24 = this->field_24;
    npc->evt_A = this->evt_A;
    npc->evt_B = this->evt_B;
    npc->evt_C = this->evt_C;
    npc->evt_D = this->evt_D;
    npc->evt_E = this->evt_E;
    npc->evt_F = this->evt_F;
    npc->uSex = this->uSex;
    npc->bHasUsedTheAbility = this->bHasUsedTheAbility;
    npc->news_topic = this->news_topic;
}


void OtherOverlayList_Image_MM7::Serialize(OtherOverlayList *list)
{
    memset(this, 0, sizeof(*this));

    this->bRedraw = list->bRedraw;
    this->field_3E8 = list->field_3E8;

    for (unsigned int i = 0; i < 50; ++i)
    {
        memset(&this->pOverlays[i], 0, sizeof(this->pOverlays[i]));

        this->pOverlays[i].field_0 = list->pOverlays[i].field_0;
        this->pOverlays[i].field_2 = list->pOverlays[i].field_2;
        this->pOverlays[i].field_4 = list->pOverlays[i].field_4;
        this->pOverlays[i].field_6 = list->pOverlays[i].field_6;
        this->pOverlays[i].field_8 = list->pOverlays[i].field_8;
        this->pOverlays[i].field_A = list->pOverlays[i].field_A;
        this->pOverlays[i].field_C = list->pOverlays[i].field_C;
        this->pOverlays[i].field_E = list->pOverlays[i].field_E;
        this->pOverlays[i].field_10 = list->pOverlays[i].field_10;
    }
}


void OtherOverlayList_Image_MM7::Deserialize(OtherOverlayList *list)
{
    list->bRedraw = this->bRedraw;
    list->field_3E8 = this->field_3E8;

    for (unsigned int i = 0; i < 50; ++i)
    {
        memset(&list->pOverlays[i], 0, sizeof(list->pOverlays[i]));

        list->pOverlays[i].field_0 = this->pOverlays[i].field_0;
        list->pOverlays[i].field_2 = this->pOverlays[i].field_2;
        list->pOverlays[i].field_4 = this->pOverlays[i].field_4;
        list->pOverlays[i].field_6 = this->pOverlays[i].field_6;
        list->pOverlays[i].field_8 = this->pOverlays[i].field_8;
        list->pOverlays[i].field_A = this->pOverlays[i].field_A;
        list->pOverlays[i].field_C = this->pOverlays[i].field_C;
        list->pOverlays[i].field_E = this->pOverlays[i].field_E;
        list->pOverlays[i].field_10 = this->pOverlays[i].field_10;
    }
}



void SpellBuff_Image_MM7::Serialize(SpellBuff *buff)
{
    memset(this, 0, sizeof(*this));

    this->uExpireTime = buff->expire_time.value;
    this->uPower = buff->uPower;
    this->uSkill = buff->uSkill;
    this->uOverlayID = buff->uOverlayID;
    this->uCaster = buff->uCaster;
    this->uFlags = buff->uFlags;
}

void SpellBuff_Image_MM7::Deserialize(SpellBuff *buff)
{
    buff->expire_time.value = this->uExpireTime;
    buff->uPower = this->uPower;
    buff->uSkill = this->uSkill;
    buff->uOverlayID = this->uOverlayID;
    buff->uCaster = this->uCaster;
    buff->uFlags = this->uFlags;
}



void ItemGen_Image_MM7::Serialize(ItemGen *item)
{
    memset(this, 0, sizeof(*this));

    this->uItemID = item->uItemID;
    this->uEnchantmentType = item->uEnchantmentType;
    this->m_enchantmentStrength = item->m_enchantmentStrength;
    this->special_enchantment = item->special_enchantment;
    this->uNumCharges = item->uNumCharges;
    this->uAttributes = item->uAttributes;
    this->uBodyAnchor = item->uBodyAnchor;
    this->uMaxCharges = item->uMaxCharges;
    this->uHolderPlayer = item->uHolderPlayer;
    this->field_1B = item->field_1B;
    this->uExpireTime = item->expirte_time.value;
}

void ItemGen_Image_MM7::Deserialize(ItemGen *item)
{
    item->uItemID = this->uItemID;
    item->uEnchantmentType = this->uEnchantmentType;
    item->m_enchantmentStrength = this->m_enchantmentStrength;
    item->special_enchantment = (ITEM_ENCHANTMENT)this->special_enchantment;
    item->uNumCharges = this->uNumCharges;
    item->uAttributes = this->uAttributes;
    item->uBodyAnchor = this->uBodyAnchor;
    item->uMaxCharges = this->uMaxCharges;
    item->uHolderPlayer = this->uHolderPlayer;
    item->field_1B = this->field_1B;
    item->expirte_time.value = this->uExpireTime;
}


void Party_Image_MM7::Serialize(Party *party)
{
    memset(this, 0, sizeof(*this));

    this->field_0 = party->field_0;
    this->uPartyHeight = party->uPartyHeight;
    this->uDefaultPartyHeight = party->uDefaultPartyHeight;
    this->sEyelevel = party->sEyelevel;
    this->uDefaultEyelevel = party->uDefaultEyelevel;
    this->field_14_radius = party->field_14_radius;
    this->y_rotation_granularity = party->y_rotation_granularity;
    this->uWalkSpeed = party->uWalkSpeed;
    this->y_rotation_speed = party->y_rotation_speed;
    this->field_24 = party->field_24;
    this->field_28 = party->field_28;
    this->uTimePlayed = party->playing_time.value;
    this->uLastRegenerationTime = party->last_regenerated.value;

    for (unsigned int i = 0; i < 10; ++i)
        this->PartyTimes.bountyHunting_next_generation_time[i] = party->PartyTimes.bountyHunting_next_generation_time[i];
    for (unsigned int i = 0; i < 85; ++i)
        this->PartyTimes.Shops_next_generation_time[i] = party->PartyTimes.Shops_next_generation_time[i];
    for (unsigned int i = 0; i < 53; ++i)
        this->PartyTimes._shop_ban_times[i] = party->PartyTimes._shop_ban_times[i];
    for (unsigned int i = 0; i < 10; ++i)
        this->PartyTimes.CounterEventValues[i] = party->PartyTimes.CounterEventValues[i];
    for (unsigned int i = 0; i < 29; ++i)
        this->PartyTimes.HistoryEventTimes[i] = party->PartyTimes.HistoryEventTimes[i];
    for (unsigned int i = 0; i < 20; ++i)
        this->PartyTimes._s_times[i] = party->PartyTimes._s_times[i];

    this->vPosition.x = party->vPosition.x;
    this->vPosition.y = party->vPosition.y;
    this->vPosition.z = party->vPosition.z;
    this->sRotationY = party->sRotationY;
    this->sRotationX = party->sRotationX;
    this->vPrevPosition.x = party->vPrevPosition.x;
    this->vPrevPosition.y = party->vPrevPosition.y;
    this->vPrevPosition.z = party->vPrevPosition.z;
    this->sPrevRotationY = party->sPrevRotationY;
    this->sPrevRotationX = party->sPrevRotationX;
    this->sPrevEyelevel = party->sPrevEyelevel;
    this->field_6E0 = party->field_6E0;
    this->field_6E4 = party->field_6E4;
    this->uFallSpeed = party->uFallSpeed;
    this->field_6EC = party->field_6EC;
    this->field_6F0 = party->field_6F0;
    this->floor_face_pid = party->floor_face_pid;
    this->walk_sound_timer = party->walk_sound_timer;
    this->_6FC_water_lava_timer = party->_6FC_water_lava_timer;
    this->uFallStartY = party->uFallStartY;
    this->bFlying = party->bFlying;
    this->field_708 = party->field_708;
    this->hirelingScrollPosition = party->hirelingScrollPosition;
    this->field_70A = party->field_70A;
    this->field_70B = party->field_70B;
    this->uCurrentYear = party->uCurrentYear;
    this->uCurrentMonth = party->uCurrentMonth;
    this->uCurrentMonthWeek = party->uCurrentMonthWeek;
    this->uCurrentDayOfMonth = party->uCurrentDayOfMonth;
    this->uCurrentHour = party->uCurrentHour;
    this->uCurrentMinute = party->uCurrentMinute;
    this->uCurrentTimeSecond = party->uCurrentTimeSecond;
    this->uNumFoodRations = party->uNumFoodRations;
    this->field_72C = party->field_72C;
    this->field_730 = party->field_730;
    this->uNumGold = party->uNumGold;
    this->uNumGoldInBank = party->uNumGoldInBank;
    this->uNumDeaths = party->uNumDeaths;
    this->field_740 = party->field_740;
    this->uNumPrisonTerms = party->uNumPrisonTerms;
    this->uNumBountiesCollected = party->uNumBountiesCollected;
    this->field_74C = party->field_74C;

    for (unsigned int i = 0; i < 5; ++i)
        this->monster_id_for_hunting[i] = party->monster_id_for_hunting[i];
    for (unsigned int i = 0; i < 5; ++i)
        this->monster_for_hunting_killed[i] = party->monster_for_hunting_killed[i];

    this->days_played_without_rest = party->days_played_without_rest;

    for (unsigned int i = 0; i < 64; ++i)
        this->_quest_bits[i] = party->_quest_bits[i];
    for (unsigned int i = 0; i < 16; ++i)
        this->pArcomageWins[i] = party->pArcomageWins[i];

    this->field_7B5_in_arena_quest = party->field_7B5_in_arena_quest;
    this->uNumArenaPageWins = party->uNumArenaPageWins;
    this->uNumArenaSquireWins = party->uNumArenaSquireWins;
    this->uNumArenaKnightWins = party->uNumArenaKnightWins;
    this->uNumArenaLordWins = party->uNumArenaLordWins;

    for (unsigned int i = 0; i < 29; ++i)
        this->pIsArtifactFound[i] = party->pIsArtifactFound[i];
    for (unsigned int i = 0; i < 39; ++i)
        this->field_7d7[i] = party->field_7d7[i];
    for (unsigned int i = 0; i < 26; ++i)
        this->_autonote_bits[i] = party->_autonote_bits[i];
    for (unsigned int i = 0; i < 60; ++i)
        this->field_818[i] = party->field_818[i];
    for (unsigned int i = 0; i < 32; ++i)
        this->field_854[i] = party->field_854[i];

    this->uNumArcomageWins = party->uNumArcomageWins;
    this->uNumArcomageLoses = party->uNumArcomageLoses;
    this->bTurnBasedModeOn = party->bTurnBasedModeOn;
    this->field_880 = party->field_880;
    this->uFlags2 = party->uFlags2;
    this->alignment = party->alignment;

    for (unsigned int i = 0; i < 20; ++i)
        this->pPartyBuffs[i].Serialize(&party->pPartyBuffs[i]);
    for (unsigned int i = 0; i < 4; ++i)
        this->pPlayers[i].Serialize(&party->pPlayers[i]);
    for (unsigned int i = 0; i < 2; ++i)
        this->pHirelings[i].Serialize(&party->pHirelings[i]);

    this->pPickedItem.Serialize(&party->pPickedItem);

    this->uFlags = party->uFlags;

    for (unsigned int i = 0; i < 53; ++i)
        for (unsigned int j = 0; j < 12; ++j)
            this->StandartItemsInShops[i][j].Serialize(&party->StandartItemsInShops[i][j]);

    for (unsigned int i = 0; i < 53; ++i)
        for (unsigned int j = 0; j < 12; ++j)
            this->SpecialItemsInShops[i][j].Serialize(&party->SpecialItemsInShops[i][j]);

    for (unsigned int i = 0; i < 32; ++i)
        for (unsigned int j = 0; j < 12; ++j)
            this->SpellBooksInGuilds[i][j].Serialize(&party->SpellBooksInGuilds[i][j]);

    for (unsigned int i = 0; i < 24; ++i)
        this->field_1605C[i] = party->field_1605C[i];

    strcpy(this->pHireling1Name, party->pHireling1Name);
    strcpy(this->pHireling2Name, party->pHireling2Name);

    this->armageddon_timer = party->armageddon_timer;
    this->armageddonDamage = party->armageddonDamage;

    for (unsigned int i = 0; i < 4; ++i)
        this->pTurnBasedPlayerRecoveryTimes[i] = party->pTurnBasedPlayerRecoveryTimes[i];

    for (unsigned int i = 0; i < 53; ++i)
        this->InTheShopFlags[i] = party->InTheShopFlags[i];

    this->uFine = party->uFine;
    this->flt_TorchlightColorR = party->flt_TorchlightColorR;
    this->flt_TorchlightColorG = party->flt_TorchlightColorG;
    this->flt_TorchlightColorB = party->flt_TorchlightColorB;
}


void Party_Image_MM7::Deserialize(Party *party)
{
    party->field_0 = this->field_0;
    party->uPartyHeight = this->uPartyHeight;
    party->uDefaultPartyHeight = this->uDefaultPartyHeight;
    party->sEyelevel = this->sEyelevel;
    party->uDefaultEyelevel = this->uDefaultEyelevel;
    party->field_14_radius = this->field_14_radius;
    party->y_rotation_granularity = this->y_rotation_granularity;
    party->uWalkSpeed = this->uWalkSpeed;
    party->y_rotation_speed = this->y_rotation_speed;
    party->field_24 = this->field_24;
    party->field_28 = this->field_28;
    party->playing_time.value = this->uTimePlayed;
    party->last_regenerated.value = this->uLastRegenerationTime;

    for (unsigned int i = 0; i < 10; ++i)
        party->PartyTimes.bountyHunting_next_generation_time[i] = this->PartyTimes.bountyHunting_next_generation_time[i];
    for (unsigned int i = 0; i < 85; ++i)
        party->PartyTimes.Shops_next_generation_time[i] = this->PartyTimes.Shops_next_generation_time[i];
    for (unsigned int i = 0; i < 53; ++i)
        party->PartyTimes._shop_ban_times[i] = this->PartyTimes._shop_ban_times[i];
    for (unsigned int i = 0; i < 10; ++i)
        party->PartyTimes.CounterEventValues[i] = this->PartyTimes.CounterEventValues[i];
    for (unsigned int i = 0; i < 29; ++i)
        party->PartyTimes.HistoryEventTimes[i] = this->PartyTimes.HistoryEventTimes[i];
    for (unsigned int i = 0; i < 20; ++i)
        party->PartyTimes._s_times[i] = this->PartyTimes._s_times[i];

    party->vPosition.x = this->vPosition.x;
    party->vPosition.y = this->vPosition.y;
    party->vPosition.z = this->vPosition.z;
    party->sRotationY = this->sRotationY;
    party->sRotationX = this->sRotationX;
    party->vPrevPosition.x = this->vPrevPosition.x;
    party->vPrevPosition.y = this->vPrevPosition.y;
    party->vPrevPosition.z = this->vPrevPosition.z;
    party->sPrevRotationY = this->sPrevRotationY;
    party->sPrevRotationX = this->sPrevRotationX;
    party->sPrevEyelevel = this->sPrevEyelevel;
    party->field_6E0 = this->field_6E0;
    party->field_6E4 = this->field_6E4;
    party->uFallSpeed = this->uFallSpeed;
    party->field_6EC = this->field_6EC;
    party->field_6F0 = this->field_6F0;
    party->floor_face_pid = this->floor_face_pid;
    party->walk_sound_timer = this->walk_sound_timer;
    party->_6FC_water_lava_timer = this->_6FC_water_lava_timer;
    party->uFallStartY = this->uFallStartY;
    party->bFlying = this->bFlying;
    party->field_708 = this->field_708;
    party->hirelingScrollPosition = this->hirelingScrollPosition;
    party->field_70A = this->field_70A;
    party->field_70B = this->field_70B;
    party->uCurrentYear = this->uCurrentYear;
    party->uCurrentMonth = this->uCurrentMonth;
    party->uCurrentMonthWeek = this->uCurrentMonthWeek;
    party->uCurrentDayOfMonth = this->uCurrentDayOfMonth;
    party->uCurrentHour = this->uCurrentHour;
    party->uCurrentMinute = this->uCurrentMinute;
    party->uCurrentTimeSecond = this->uCurrentTimeSecond;
    party->uNumFoodRations = this->uNumFoodRations;
    party->field_72C = this->field_72C;
    party->field_730 = this->field_730;
    party->uNumGold = this->uNumGold;
    party->uNumGoldInBank = this->uNumGoldInBank;
    party->uNumDeaths = this->uNumDeaths;
    party->field_740 = this->field_740;
    party->uNumPrisonTerms = this->uNumPrisonTerms;
    party->uNumBountiesCollected = this->uNumBountiesCollected;
    party->field_74C = this->field_74C;

    for (unsigned int i = 0; i < 5; ++i)
        party->monster_id_for_hunting[i] = this->monster_id_for_hunting[i];
    for (unsigned int i = 0; i < 5; ++i)
        party->monster_for_hunting_killed[i] = this->monster_for_hunting_killed[i];

    party->days_played_without_rest = this->days_played_without_rest;

    for (unsigned int i = 0; i < 64; ++i)
        party->_quest_bits[i] = this->_quest_bits[i];
    for (unsigned int i = 0; i < 16; ++i)
        party->pArcomageWins[i] = this->pArcomageWins[i];

    party->field_7B5_in_arena_quest = this->field_7B5_in_arena_quest;
    party->uNumArenaPageWins = this->uNumArenaPageWins;
    party->uNumArenaSquireWins = this->uNumArenaSquireWins;
    party->uNumArenaKnightWins = this->uNumArenaKnightWins;
    party->uNumArenaLordWins = this->uNumArenaLordWins;

    for (unsigned int i = 0; i < 29; ++i)
        party->pIsArtifactFound[i] = this->pIsArtifactFound[i];
    for (unsigned int i = 0; i < 39; ++i)
        party->field_7d7[i] = this->field_7d7[i];
    for (unsigned int i = 0; i < 26; ++i)
        party->_autonote_bits[i] = this->_autonote_bits[i];
    for (unsigned int i = 0; i < 60; ++i)
        party->field_818[i] = this->field_818[i];
    for (unsigned int i = 0; i < 32; ++i)
        party->field_854[i] = this->field_854[i];

    party->uNumArcomageWins = this->uNumArcomageWins;
    party->uNumArcomageLoses = this->uNumArcomageLoses;
    party->bTurnBasedModeOn = this->bTurnBasedModeOn;
    party->field_880 = this->field_880;
    party->uFlags2 = this->uFlags2;

    switch (this->alignment)
    {
        case 0: party->alignment = PartyAlignment_Good; break;
        case 1: party->alignment = PartyAlignment_Neutral; break;
        case 2: party->alignment = PartyAlignment_Evil; break;
        default:
            Assert(false);
    }

    for (unsigned int i = 0; i < 20; ++i)
        this->pPartyBuffs[i].Deserialize(&party->pPartyBuffs[i]);
    for (unsigned int i = 0; i < 4; ++i)
        this->pPlayers[i].Deserialize(&party->pPlayers[i]);
    for (unsigned int i = 0; i < 2; ++i)
        this->pHirelings[i].Deserialize(&party->pHirelings[i]);

    this->pPickedItem.Deserialize(&party->pPickedItem);

    party->uFlags = this->uFlags;

    for (unsigned int i = 0; i < 53; ++i)
        for (unsigned int j = 0; j < 12; ++j)
            this->StandartItemsInShops[i][j].Deserialize(&party->StandartItemsInShops[i][j]);

    for (unsigned int i = 0; i < 53; ++i)
        for (unsigned int j = 0; j < 12; ++j)
            this->SpecialItemsInShops[i][j].Deserialize(&party->SpecialItemsInShops[i][j]);

    for (unsigned int i = 0; i < 32; ++i)
        for (unsigned int j = 0; j < 12; ++j)
            this->SpellBooksInGuilds[i][j].Deserialize(&party->SpellBooksInGuilds[i][j]);

    for (unsigned int i = 0; i < 24; ++i)
        party->field_1605C[i] = this->field_1605C[i];

    strcpy(party->pHireling1Name, this->pHireling1Name);
    strcpy(party->pHireling2Name, this->pHireling2Name);

    party->armageddon_timer = this->armageddon_timer;
    party->armageddonDamage = this->armageddonDamage;

    for (unsigned int i = 0; i < 4; ++i)
        party->pTurnBasedPlayerRecoveryTimes[i] = this->pTurnBasedPlayerRecoveryTimes[i];

    for (unsigned int i = 0; i < 53; ++i)
        party->InTheShopFlags[i] = this->InTheShopFlags[i];

    party->uFine = this->uFine;
    party->flt_TorchlightColorR = this->flt_TorchlightColorR;
    party->flt_TorchlightColorG = this->flt_TorchlightColorG;
    party->flt_TorchlightColorB = this->flt_TorchlightColorB;
}


void Player_Image_MM7::Serialize(Player *player)
{
    memset(this, 0, sizeof(*this));

    for (unsigned int i = 0; i < 20; ++i)
        this->pConditions[i] = player->conditions_times[i].value;

    this->uExperience = player->uExperience;

    strcpy(this->pName, player->pName);

    this->uSex = player->uSex;
    this->classType = player->classType;
    this->uCurrentFace = player->uCurrentFace;
    this->field_BB = player->field_BB;
    this->uMight = player->uMight;
    this->uMightBonus = player->uMightBonus;
    this->uIntelligence = player->uIntelligence;
    this->uIntelligenceBonus = player->uIntelligenceBonus;
    this->uWillpower = player->uWillpower;
    this->uWillpowerBonus = player->uWillpowerBonus;
    this->uEndurance = player->uEndurance;
    this->uEnduranceBonus = player->uEnduranceBonus;
    this->uSpeed = player->uSpeed;
    this->uSpeedBonus = player->uSpeedBonus;
    this->uAccuracy = player->uAccuracy;
    this->uAccuracyBonus = player->uAccuracyBonus;
    this->uLuck = player->uLuck;
    this->uLuckBonus = player->uLuckBonus;
    this->sACModifier = player->sACModifier;
    this->uLevel = player->uLevel;
    this->sLevelModifier = player->sLevelModifier;
    this->sAgeModifier = player->sAgeModifier;
    this->field_E0 = player->field_E0;
    this->field_E4 = player->field_E4;
    this->field_E8 = player->field_E8;
    this->field_EC = player->field_EC;
    this->field_F0 = player->field_F0;
    this->field_F4 = player->field_F4;
    this->field_F8 = player->field_F8;
    this->field_FC = player->field_FC;
    this->field_100 = player->field_100;
    this->field_104 = player->field_104;

    for (unsigned int i = 0; i < 37; ++i)
        this->pActiveSkills[i] = player->pActiveSkills[i];

    for (unsigned int i = 0; i < 64; ++i)
        this->_achieved_awards_bits[i] = player->_achieved_awards_bits[i];

    for (unsigned int i = 0; i < 99; ++i)
        this->spellbook.bHaveSpell[i] = player->spellbook.bHaveSpell[i];

    this->pure_luck_used = player->pure_luck_used;
    this->pure_speed_used = player->pure_speed_used;
    this->pure_intellect_used = player->pure_intellect_used;
    this->pure_endurance_used = player->pure_endurance_used;
    this->pure_willpower_used = player->pure_willpower_used;
    this->pure_accuracy_used = player->pure_accuracy_used;
    this->pure_might_used = player->pure_might_used;

    for (unsigned int i = 0; i < 138; ++i)
        this->pOwnItems[i].Serialize(&player->pOwnItems[i]);

    for (unsigned int i = 0; i < 126; ++i)
        this->pInventoryMatrix[i] = player->pInventoryMatrix[i];

    this->sResFireBase = player->sResFireBase;
    this->sResAirBase = player->sResAirBase;
    this->sResWaterBase = player->sResWaterBase;
    this->sResEarthBase = player->sResEarthBase;
    this->field_177C = player->field_177C;
    this->sResMagicBase = player->sResMagicBase;
    this->sResSpiritBase = player->sResSpiritBase;
    this->sResMindBase = player->sResMindBase;
    this->sResBodyBase = player->sResBodyBase;
    this->sResLightBase = player->sResLightBase;
    this->sResDarkBase = player->sResDarkBase;
    this->sResFireBonus = player->sResFireBonus;
    this->sResAirBonus = player->sResAirBonus;
    this->sResWaterBonus = player->sResWaterBonus;
    this->sResEarthBonus = player->sResEarthBonus;
    this->field_1792 = player->field_1792;
    this->sResMagicBonus = player->sResMagicBonus;
    this->sResSpiritBonus = player->sResSpiritBonus;
    this->sResMindBonus = player->sResMindBonus;
    this->sResBodyBonus = player->sResBodyBonus;
    this->sResLightBonus = player->sResLightBonus;
    this->sResDarkBonus = player->sResDarkBonus;

    for (unsigned int i = 0; i < 24; ++i)
        this->pPlayerBuffs[i].Serialize(&player->pPlayerBuffs[i]);

    this->uVoiceID = player->uVoiceID;
    this->uPrevVoiceID = player->uPrevVoiceID;
    this->uPrevFace = player->uPrevFace;
    this->field_192C = player->field_192C;
    this->field_1930 = player->field_1930;
    this->uTimeToRecovery = player->uTimeToRecovery;
    this->field_1936 = player->field_1936;
    this->field_1937 = player->field_1937;
    this->uSkillPoints = player->uSkillPoints;
    this->sHealth = player->sHealth;
    this->sMana = player->sMana;
    this->uBirthYear = player->uBirthYear;

    for (unsigned int i = 0; i < 16; ++i)
        this->pEquipment.pIndices[i] = player->pEquipment.pIndices[i];

    for (unsigned int i = 0; i < 49; ++i)
        this->field_1988[i] = player->field_1988[i];

    this->field_1A4C = player->field_1A4C;
    this->field_1A4D = player->field_1A4D;
    this->lastOpenedSpellbookPage = player->lastOpenedSpellbookPage;
    this->uQuickSpell = player->uQuickSpell;

    for (unsigned int i = 0; i < 49; ++i)
        this->playerEventBits[i] = player->playerEventBits[i];

    this->_some_attack_bonus = player->_some_attack_bonus;
    this->field_1A91 = player->field_1A91;
    this->_melee_dmg_bonus = player->_melee_dmg_bonus;
    this->field_1A93 = player->field_1A93;
    this->_ranged_atk_bonus = player->_ranged_atk_bonus;
    this->field_1A95 = player->field_1A95;
    this->_ranged_dmg_bonus = player->_ranged_dmg_bonus;
    this->field_1A97 = player->field_1A97;
    this->uFullHealthBonus = player->uFullHealthBonus;
    this->_health_related = player->_health_related;
    this->uFullManaBonus = player->uFullManaBonus;
    this->_mana_related = player->_mana_related;
    this->expression = player->expression;
    this->uExpressionTimePassed = player->uExpressionTimePassed;
    this->uExpressionTimeLength = player->uExpressionTimeLength;
    this->field_1AA2 = player->field_1AA2;
    this->_expression21_animtime = player->_expression21_animtime;
    this->_expression21_frameset = player->_expression21_frameset;

    for (unsigned int i = 0; i < 5; ++i)
    {
        this->pInstalledBeacons[i].uBeaconTime = player->pInstalledBeacons[i].uBeaconTime;
        this->pInstalledBeacons[i].PartyPos_X = player->pInstalledBeacons[i].PartyPos_X;
        this->pInstalledBeacons[i].PartyPos_Y = player->pInstalledBeacons[i].PartyPos_Y;
        this->pInstalledBeacons[i].PartyPos_Z = player->pInstalledBeacons[i].PartyPos_Z;
        this->pInstalledBeacons[i].PartyRot_X = player->pInstalledBeacons[i].PartyRot_X;
        this->pInstalledBeacons[i].PartyRot_Y = player->pInstalledBeacons[i].PartyRot_Y;
        this->pInstalledBeacons[i].SaveFileID = player->pInstalledBeacons[i].SaveFileID;
    }

    this->uNumDivineInterventionCastsThisDay = player->uNumDivineInterventionCastsThisDay;
    this->uNumArmageddonCasts = player->uNumArmageddonCasts;
    this->uNumFireSpikeCasts = player->uNumFireSpikeCasts;
    this->field_1B3B = player->field_1B3B;
}

void Player_Image_MM7::Deserialize(Player *player)
{
    for (unsigned int i = 0; i < 20; ++i)
        player->conditions_times[i].value = this->pConditions[i];

    player->uExperience = this->uExperience;

    strcpy(player->pName, this->pName);

    switch (this->uSex)
    {
        case 0: player->uSex = SEX_MALE; break;
        case 1: player->uSex = SEX_FEMALE; break;
        default:
            Assert(false);
    }

    switch (this->classType)
    {
        case  0: classType = PLAYER_CLASS_KNIGHT; break;
        case  1: classType = PLAYER_CLASS_CHEVALIER; break;
        case  2: classType = PLAYER_CLASS_CHAMPION; break;
        case  3: classType = PLAYER_CLASS_BLACK_KNIGHT; break;
        case  4: classType = PLAYER_CLASS_THEIF; break;
        case  5: classType = PLAYER_CLASS_ROGUE; break;
        case  6: classType = PLAYER_CLASS_SPY; break;
        case  7: classType = PLAYER_CLASS_ASSASSIN; break;
        case  8: classType = PLAYER_CLASS_MONK; break;
        case  9: classType = PLAYER_CLASS_INITIATE; break;
        case 10: classType = PLAYER_CLASS_MASTER; break;
        case 11: classType = PLAYER_CLASS_NINJA; break;
        case 12: classType = PLAYER_CLASS_PALADIN; break;
        case 13: classType = PLAYER_CLASS_CRUSADER; break;
        case 14: classType = PLAYER_CLASS_HERO; break;
        case 15: classType = PLAYER_CLASS_VILLIAN; break;
        case 16: classType = PLAYER_CLASS_ARCHER; break;
        case 17: classType = PLAYER_CLASS_WARRIOR_MAGE; break;
        case 18: classType = PLAYER_CLASS_MASTER_ARCHER; break;
        case 19: classType = PLAYER_CLASS_SNIPER; break;
        case 20: classType = PLAYER_CLASS_RANGER; break;
        case 21: classType = PLAYER_CLASS_HUNTER; break;
        case 22: classType = PLAYER_CLASS_RANGER_LORD; break;
        case 23: classType = PLAYER_CLASS_BOUNTY_HUNTER; break;
        case 24: classType = PLAYER_CLASS_CLERIC; break;
        case 25: classType = PLAYER_CLASS_PRIEST; break;
        case 26: classType = PLAYER_CLASS_PRIEST_OF_SUN; break;
        case 27: classType = PLAYER_CLASS_PRIEST_OF_MOON; break;
        case 28: classType = PLAYER_CLASS_DRUID; break;
        case 29: classType = PLAYER_CLASS_GREAT_DRUID; break;
        case 30: classType = PLAYER_CLASS_ARCH_DRUID; break;
        case 31: classType = PLAYER_CLASS_WARLOCK; break;
        case 32: classType = PLAYER_CLASS_SORCERER; break;
        case 33: classType = PLAYER_CLASS_WIZARD; break;
        case 34: classType = PLAYER_CLASS_ARCHMAGE; break;
        case 35: classType = PLAYER_CLASS_LICH; break;
        default:
            Assert(false);
    }

    player->uCurrentFace = this->uCurrentFace;
    player->field_BB = this->field_BB;
    player->uMight = this->uMight;
    player->uMightBonus = this->uMightBonus;
    player->uIntelligence = this->uIntelligence;
    player->uIntelligenceBonus = this->uIntelligenceBonus;
    player->uWillpower = this->uWillpower;
    player->uWillpowerBonus = this->uWillpowerBonus;
    player->uEndurance = this->uEndurance;
    player->uEnduranceBonus = this->uEnduranceBonus;
    player->uSpeed = this->uSpeed;
    player->uSpeedBonus = this->uSpeedBonus;
    player->uAccuracy = this->uAccuracy;
    player->uAccuracyBonus = this->uAccuracyBonus;
    player->uLuck = this->uLuck;
    player->uLuckBonus = this->uLuckBonus;
    player->sACModifier = this->sACModifier;
    player->uLevel = this->uLevel;
    player->sLevelModifier = this->sLevelModifier;
    player->sAgeModifier = this->sAgeModifier;
    player->field_E0 = this->field_E0;
    player->field_E4 = this->field_E4;
    player->field_E8 = this->field_E8;
    player->field_EC = this->field_EC;
    player->field_F0 = this->field_F0;
    player->field_F4 = this->field_F4;
    player->field_F8 = this->field_F8;
    player->field_FC = this->field_FC;
    player->field_100 = this->field_100;
    player->field_104 = this->field_104;

    for (unsigned int i = 0; i < 37; ++i)
        player->pActiveSkills[i] = this->pActiveSkills[i];

    for (unsigned int i = 0; i < 64; ++i)
        player->_achieved_awards_bits[i] = this->_achieved_awards_bits[i];

    for (unsigned int i = 0; i < 99; ++i)
        player->spellbook.bHaveSpell[i] = this->spellbook.bHaveSpell[i];

    player->pure_luck_used = this->pure_luck_used;
    player->pure_speed_used = this->pure_speed_used;
    player->pure_intellect_used = this->pure_intellect_used;
    player->pure_endurance_used = this->pure_endurance_used;
    player->pure_willpower_used = this->pure_willpower_used;
    player->pure_accuracy_used = this->pure_accuracy_used;
    player->pure_might_used = this->pure_might_used;

    for (unsigned int i = 0; i < 138; ++i)
        this->pOwnItems[i].Deserialize(&player->pOwnItems[i]);

    for (unsigned int i = 0; i < 126; ++i)
        player->pInventoryMatrix[i] = this->pInventoryMatrix[i];

    player->sResFireBase = this->sResFireBase;
    player->sResAirBase = this->sResAirBase;
    player->sResWaterBase = this->sResWaterBase;
    player->sResEarthBase = this->sResEarthBase;
    player->field_177C = this->field_177C;
    player->sResMagicBase = this->sResMagicBase;
    player->sResSpiritBase = this->sResSpiritBase;
    player->sResMindBase = this->sResMindBase;
    player->sResBodyBase = this->sResBodyBase;
    player->sResLightBase = this->sResLightBase;
    player->sResDarkBase = this->sResDarkBase;
    player->sResFireBonus = this->sResFireBonus;
    player->sResAirBonus = this->sResAirBonus;
    player->sResWaterBonus = this->sResWaterBonus;
    player->sResEarthBonus = this->sResEarthBonus;
    player->field_1792 = this->field_1792;
    player->sResMagicBonus = this->sResMagicBonus;
    player->sResSpiritBonus = this->sResSpiritBonus;
    player->sResMindBonus = this->sResMindBonus;
    player->sResBodyBonus = this->sResBodyBonus;
    player->sResLightBonus = this->sResLightBonus;
    player->sResDarkBonus = this->sResDarkBonus;

    for (unsigned int i = 0; i < 24; ++i)
        this->pPlayerBuffs[i].Deserialize(&player->pPlayerBuffs[i]);

    player->uVoiceID = this->uVoiceID;
    player->uPrevVoiceID = this->uPrevVoiceID;
    player->uPrevFace = this->uPrevFace;
    player->field_192C = this->field_192C;
    player->field_1930 = this->field_1930;
    player->uTimeToRecovery = this->uTimeToRecovery;
    player->field_1936 = this->field_1936;
    player->field_1937 = this->field_1937;
    player->uSkillPoints = this->uSkillPoints;
    player->sHealth = this->sHealth;
    player->sMana = this->sMana;
    player->uBirthYear = this->uBirthYear;

    for (unsigned int i = 0; i < 16; ++i)
        player->pEquipment.pIndices[i] = this->pEquipment.pIndices[i];

    for (unsigned int i = 0; i < 49; ++i)
        player->field_1988[i] = this->field_1988[i];

    player->field_1A4C = this->field_1A4C;
    player->field_1A4D = this->field_1A4D;
    player->lastOpenedSpellbookPage = this->lastOpenedSpellbookPage;
    player->uQuickSpell = this->uQuickSpell;

    for (unsigned int i = 0; i < 49; ++i)
        player->playerEventBits[i] = this->playerEventBits[i];

    player->_some_attack_bonus = this->_some_attack_bonus;
    player->field_1A91 = this->field_1A91;
    player->_melee_dmg_bonus = this->_melee_dmg_bonus;
    player->field_1A93 = this->field_1A93;
    player->_ranged_atk_bonus = this->_ranged_atk_bonus;
    player->field_1A95 = this->field_1A95;
    player->_ranged_dmg_bonus = this->_ranged_dmg_bonus;
    player->field_1A97 = this->field_1A97;
    player->uFullHealthBonus = this->uFullHealthBonus;
    player->_health_related = this->_health_related;
    player->uFullManaBonus = this->uFullManaBonus;
    player->_mana_related = this->_mana_related;
    player->expression = (CHARACTER_EXPRESSION_ID)this->expression;
    player->uExpressionTimePassed = this->uExpressionTimePassed;
    player->uExpressionTimeLength = this->uExpressionTimeLength;
    player->field_1AA2 = this->field_1AA2;
    player->_expression21_animtime = this->_expression21_animtime;
    player->_expression21_frameset = this->_expression21_frameset;

    for (unsigned int i = 0; i < 5; ++i)
    {
        player->pInstalledBeacons[i].uBeaconTime = this->pInstalledBeacons[i].uBeaconTime;
        player->pInstalledBeacons[i].PartyPos_X = this->pInstalledBeacons[i].PartyPos_X;
        player->pInstalledBeacons[i].PartyPos_Y = this->pInstalledBeacons[i].PartyPos_Y;
        player->pInstalledBeacons[i].PartyPos_Z = this->pInstalledBeacons[i].PartyPos_Z;
        player->pInstalledBeacons[i].PartyRot_X = this->pInstalledBeacons[i].PartyRot_X;
        player->pInstalledBeacons[i].PartyRot_Y = this->pInstalledBeacons[i].PartyRot_Y;
        player->pInstalledBeacons[i].SaveFileID = this->pInstalledBeacons[i].SaveFileID;
    }

    player->uNumDivineInterventionCastsThisDay = this->uNumDivineInterventionCastsThisDay;
    player->uNumArmageddonCasts = this->uNumArmageddonCasts;
    player->uNumFireSpikeCasts = this->uNumFireSpikeCasts;
    player->field_1B3B = this->field_1B3B;
}



void IconFrame_MM7::Serialize(Icon *icon)
{
    strcpy(pAnimationName, icon->GetAnimationName());
    uAnimLength = icon->GetAnimLength();

    strcpy(pTextureName, icon->pTextureName);
    uAnimTime = icon->GetAnimTime();
    uFlags = icon->uFlags;
}

void IconFrame_MM7::Deserialize(Icon *icon)
{
    icon->SetAnimationName(this->pAnimationName);
    icon->SetAnimLength(8 * this->uAnimLength);

    strcpy(icon->pTextureName, pTextureName);
    icon->SetAnimTime(uAnimTime);
    icon->uFlags = uFlags;
}



void UIAnimation_MM7::Serialize(UIAnimation *anim)
{
    /* 000 */ uIconID = anim->icon->id;
    /* 002 */ field_2 = anim->field_2;
    /* 004 */ uAnimTime = anim->uAnimTime;
    /* 006 */ uAnimLength = anim->uAnimLength;
    /* 008 */ x = anim->x;
    /* 00A */ y = anim->y;
    /* 00C */ field_C = anim->field_C;
}

void UIAnimation_MM7::Deserialize(UIAnimation *anim)
{
    anim->icon = pIconsFrameTable->GetIcon(uIconID);
    ///* 000 */ anim->uIconID = uIconID;
    /* 002 */ anim->field_2 = field_2;
    /* 004 */ anim->uAnimTime = uAnimTime;
    /* 006 */ anim->uAnimLength = uAnimLength;
    /* 008 */ anim->x = x;
    /* 00A */ anim->y = y;
    /* 00C */ anim->field_C = field_C;
}