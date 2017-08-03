#include "global.h"
#include "main.h"
#include "task.h"
#include "palette.h"
#include "sound.h"
#include "pokemon.h"
#include "text.h"
#include "strings.h"
#include "string_util.h"
#include "menu.h"
#include "save.h"
#include "species.h"
#include "rom4.h"
#include "m4a.h"
#include "data2.h"
#include "decompress.h"

extern u32 gUnknown_0203931C;
extern bool8 gUnknown_02039324; // has hall of fame records
extern void (*gGameContinueCallback)(void);
extern struct MusicPlayerInfo gMPlay_BGM;
extern u8 gReservedSpritePaletteCount;
extern struct SpriteTemplate gUnknown_02024E8C;

extern const s16 gUnknown_0840B534[][4];
extern const s16 gUnknown_0840B564[][4];

struct HallofFameMon
{
    u32 tid;
    u32 personality;
    u16 species : 9;
    u16 lvl : 7;
    u8 nick[10];
};

struct HallofFameMons
{
    struct HallofFameMon mons[6];
};

#define HALL_OF_FAME_MAX_TEAMS 50

extern u8 ewram[];

static void sub_8141FF8(u8 taskID);
static void sub_81422E8(u8 taskID);
static void sub_814217C(u8 taskID);
static void sub_8142274(u8 taskID);
static void sub_81422B8(u8 taskID);
static void sub_8142320(u8 taskID);
static void sub_8142404(u8 taskID);
static void sub_8142484(u8 taskID);
static void sub_8142570(u8 taskID);
static void sub_8142618(u8 taskID);
static void sub_81426F8(u8 taskID);
static void sub_8142738(u8 taskID);
static void sub_8142794(u8 taskID);
static void sub_8142818(u8 taskID);
static void sub_8142850(u8 taskID);
static void sub_81428A0(u8 taskID);
static void sub_8142A28(u8 taskID);
static void sub_8142FEC(u8 taskID);
static void sub_8142B04(u8 taskID);
static void sub_8142CC8(u8 taskID);
static void sub_8142DF4(u8 taskID);
static void sub_8142F78(u8 taskID);
static void sub_8142FCC(u8 taskID);
static void sub_814302C(u8 taskID);

static void sub_81435DC(struct Sprite* sprite);
void SpriteCB_HallOfFame_Dummy(struct Sprite* sprite);

static void sub_8143068(u8 a0, u8 a1);
static void HallOfFame_PrintMonInfo(struct HallofFameMon* currMon, u8 a1, u8 a2);
static void HallOfFame_PrintPlayerInfo(u8 a0, u8 a1);
static void sub_81433E0(void);
static void sub_8143570(void);
static void sub_81435B8(void);
static u32 sub_81436BC(u16 species, s16 posX, s16 posY, u16 pokeID, u32 tid, u32 pid);

// functions from different files
void sub_81438C4(void);
u32 sub_81437A4(u16 gender, u16 a1, u16 a2, u16 a3);
void sub_81439D0(void);
void sub_80C5CD4(void*); // ?
void sub_80C5E38(void*); // ?
bool8 sub_80C5DCC(void);
bool8 sub_80C5F98(void);
void ReturnFromHallOfFamePC(void);
u16 SpeciesToPokedexNum(u16 species);
void remove_some_task(void);

#define tDisplayedPoke      data[1]
#define tPokesNumber        data[2]
#define tFrameCount         data[3]
#define tPlayerSpriteID     data[4]
#define tMonSpriteID(i)     data[i + 5]

static void VBlankCB_HallOfFame(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_HallOfFame(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static bool8 sub_8141E64(void)
{
    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        sub_81433E0();
        gMain.state = 1;
        break;
    case 1:
        sub_8143570();
        gMain.state++;
        break;
    case 2:
        {
            u16 saved_IME;

            BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
            SetVBlankCallback(VBlankCB_HallOfFame);
            saved_IME = REG_IME;
            REG_IME = 0;
            REG_IE |= 1;
            REG_IME = saved_IME;
            REG_DISPSTAT |= 8;
            gMain.state++;
        }
        break;
    case 3:
        REG_BLDCNT = 0x3F42;
        REG_BLDALPHA = 0x710;
        REG_BLDY = 0;
        sub_81435B8();
        gMain.state++;
        break;
    case 4:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            SetMainCallback2(CB2_HallOfFame);
            PlayBGM(436);
            return 0;
        }
        break;
    }
    return 1;
}

void sub_8141F90(void)
{
    if (sub_8141E64() == 0)
    {
        u8 taskID = CreateTask(sub_8141FF8, 0);
        gTasks[taskID].data[0] = 0;
    }
}

static void sub_8141FC4(void)
{
    if (sub_8141E64() == 0)
    {
        u8 taskID = CreateTask(sub_8141FF8, 0);
        gTasks[taskID].data[0] = 1;
    }
}

static void sub_8141FF8(u8 taskID)
{
    u16 i, j;
    struct HallofFameMons* fameMons = (struct HallofFameMons*)(&ewram[0x1C000]);

    gTasks[taskID].tPokesNumber = 0; // valid pokes
    for (i = 0; i < 6; i++)
    {
        u8 nick[12];
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
        {
            fameMons->mons[i].species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
            fameMons->mons[i].tid = GetMonData(&gPlayerParty[i], MON_DATA_OT_ID);
            fameMons->mons[i].personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
            fameMons->mons[i].lvl = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
            GetMonData(&gPlayerParty[i], MON_DATA_NICKNAME, nick);
            for (j = 0; j < 10; j++)
            {
                fameMons->mons[i].nick[j] = nick[j];
            }
            gTasks[taskID].tPokesNumber++;
        }
        else
        {
            fameMons->mons[i].species = 0;
            fameMons->mons[i].tid = 0;
            fameMons->mons[i].personality = 0;
            fameMons->mons[i].lvl = 0;
            fameMons->mons[i].nick[0] = EOS;
        }
    }
    gUnknown_0203931C = 0;
    gTasks[taskID].tDisplayedPoke = 0;
    gTasks[taskID].data[4] = 0xFF;
    for (i = 0; i < 6; i++)
    {
        gTasks[taskID].tMonSpriteID(i) = 0xFF;
    }
    if (gTasks[taskID].data[0])
        gTasks[taskID].func = sub_81422E8;
    else
        gTasks[taskID].func = sub_814217C;
}

static void sub_814217C(u8 taskID)
{
    u16 i;
    struct HallofFameMons* fameMons = (struct HallofFameMons*)(&ewram[0x1C000]);
    struct HallofFameMons* lastSavedTeam = (struct HallofFameMons*)(&ewram[0x1E000]);

    if (gUnknown_02039324 == FALSE)
    {
        for (i = 0; i < 0x2000; i++)
            ewram[i + 0x1E000] = 0;
    }
    else
        sub_8125EC8(3);

    for (i = 0; i < 50; i++, lastSavedTeam++)
    {
        if (lastSavedTeam->mons[0].species == 0)
            break;
    }
    if (i >= 50)
    {
        struct HallofFameMons* r5 = (struct HallofFameMons*)(&ewram[0x1E000]);
        struct HallofFameMons* r6 = (struct HallofFameMons*)(&ewram[0x1E000]);
        r5++;
        for (i = 0; i < 49; i++, r6++, r5++)
        {
            *r6 = *r5;
        }
        lastSavedTeam--;
    }
    *lastSavedTeam = *fameMons;
    MenuDrawTextWindow(2, 14, 27, 19);
    MenuPrint(gMenuText_HOFSaving, 3, 15);
    gTasks[taskID].func = sub_8142274;
}

static void sub_8142274(u8 taskID)
{
    gGameContinueCallback = sub_8141FC4;
    TrySavingData(3);
    PlaySE(55);
    gTasks[taskID].func = sub_81422B8;
    gTasks[taskID].tFrameCount = 32;
}

static void sub_81422B8(u8 taskID)
{
    if (gTasks[taskID].tFrameCount)
        gTasks[taskID].tFrameCount--;
    else
        gTasks[taskID].func = sub_81422E8;
}

static void sub_81422E8(u8 taskID)
{
    SetUpWindowConfig(&gWindowConfig_81E7198);
    InitMenuWindow(&gWindowConfig_81E7198);
    gTasks[taskID].func = sub_8142320;
}

static void sub_8142320(u8 taskID)
{
    u8 spriteID;
    s16 xPos, yPos, field4, field6;

    struct HallofFameMons* fameMons = (struct HallofFameMons*)(&ewram[0x1C000]);
    u16 currPokeID = gTasks[taskID].tDisplayedPoke;
    struct HallofFameMon* currMon = &fameMons->mons[currPokeID];

    if (gTasks[taskID].tPokesNumber > 3)
    {
        xPos = gUnknown_0840B534[currPokeID][0];
        yPos = gUnknown_0840B534[currPokeID][1];
        field4 = gUnknown_0840B534[currPokeID][2];
        field6 = gUnknown_0840B534[currPokeID][3];
    }
    else
    {
        xPos = gUnknown_0840B564[currPokeID][0];
        yPos = gUnknown_0840B564[currPokeID][1];
        field4 = gUnknown_0840B564[currPokeID][2];
        field6 = gUnknown_0840B564[currPokeID][3];
    }

    spriteID = sub_81436BC(currMon->species, xPos, yPos, currPokeID, currMon->tid, currMon->personality);
    gSprites[spriteID].data1 = field4;
    gSprites[spriteID].data2 = field6;
    gSprites[spriteID].data0 = 0;
    gSprites[spriteID].callback = sub_81435DC;
    gTasks[taskID].tMonSpriteID(currPokeID) = spriteID;
    MenuZeroFillWindowRect(0, 14, 29, 19);
    gTasks[taskID].func = sub_8142404;
}

static void sub_8142404(u8 taskID)
{
    struct HallofFameMons* fameMons = (struct HallofFameMons*)(&ewram[0x1C000]);
    u16 currPokeID = gTasks[taskID].tDisplayedPoke;
    struct HallofFameMon* currMon = &fameMons->mons[currPokeID];

    if (gSprites[gTasks[taskID].tMonSpriteID(currPokeID)].data0 != 0)
    {
        if (currMon->species != SPECIES_EGG)
            PlayCry1(currMon->species, 0);
        HallOfFame_PrintMonInfo(currMon, 0, 14);
        gTasks[taskID].tFrameCount = 120;
        gTasks[taskID].func = sub_8142484;
    }
}

static void sub_8142484(u8 taskID)
{
    struct HallofFameMons* fameMons = (struct HallofFameMons*)(&ewram[0x1C000]);
    u16 currPokeID = gTasks[taskID].tDisplayedPoke;
    struct HallofFameMon* currMon = &fameMons->mons[currPokeID];

    if (gTasks[taskID].tFrameCount != 0)
        gTasks[taskID].tFrameCount--;
    else
    {
        gUnknown_0203931C |= (0x10000 << gSprites[gTasks[taskID].tMonSpriteID(currPokeID)].oam.paletteNum);
        if (gTasks[taskID].tDisplayedPoke <= 4 && currMon[1].species != 0) // there is another pokemon to display
        {
            gTasks[taskID].tDisplayedPoke++;
            BeginNormalPaletteFade(gUnknown_0203931C, 0, 12, 12, 0x735F);
            gSprites[gTasks[taskID].tMonSpriteID(currPokeID)].oam.priority = 1;
            gTasks[taskID].func = sub_8142320;
        }
        else
            gTasks[taskID].func = sub_8142570;
    }
}

static void sub_8142570(u8 taskID)
{
    u16 i;

    BeginNormalPaletteFade(0xFFFF0000, 0, 0, 0, 0);
    for (i = 0; i < 6; i++)
    {
        if (gTasks[taskID].tMonSpriteID(i) != 0xFF)
            gSprites[gTasks[taskID].tMonSpriteID(i)].oam.priority = 0;
    }
    MenuZeroFillWindowRect(0, 14, 29, 19);
    sub_8143068(0, 15);
    PlaySE(105);
    gTasks[taskID].tFrameCount = 400;
    gTasks[taskID].func = sub_8142618;
}

static void sub_8142618(u8 taskID)
{
    if (gTasks[taskID].tFrameCount != 0)
    {
        gTasks[taskID].tFrameCount--;
        if ((gTasks[taskID].tFrameCount & 3) == 0 && gTasks[taskID].tFrameCount > 110)
            sub_81438C4();
    }
    else
    {
        u16 i;
        for (i = 0; i < 6; i++)
        {
            if (gTasks[taskID].tMonSpriteID(i) != 0xFF)
                gSprites[gTasks[taskID].tMonSpriteID(i)].oam.priority = 1;
        }
        BeginNormalPaletteFade(gUnknown_0203931C, 0, 12, 12, 0x735F);
        MenuZeroFillWindowRect(0, 14, 29, 19);
        gTasks[taskID].tFrameCount = 7;
        gTasks[taskID].func = sub_81426F8;
    }
}

static void sub_81426F8(u8 taskID)
{
    if (gTasks[taskID].tFrameCount >= 16)
        gTasks[taskID].func = sub_8142738;
    else
    {
        gTasks[taskID].tFrameCount++;
        REG_BLDALPHA = gTasks[taskID].tFrameCount * 256;
    }
}

static void sub_8142738(u8 taskID)
{
    REG_DISPCNT = 0x1940;
    SetUpWindowConfig(&gWindowConfig_81E71B4);
    InitMenuWindow(&gWindowConfig_81E71B4);

    gTasks[taskID].tPlayerSpriteID = sub_81437A4(gSaveBlock2.playerGender, 120, 72, 6);
    gTasks[taskID].tFrameCount = 120;
    gTasks[taskID].func = sub_8142794;
}

static void sub_8142794(u8 taskID)
{
    if (gTasks[taskID].tFrameCount != 0)
        gTasks[taskID].tFrameCount--;
    else
    {
        if (gSprites[gTasks[taskID].tPlayerSpriteID].pos1.x != 160)
            gSprites[gTasks[taskID].tPlayerSpriteID].pos1.x++;
        else
        {
            MenuDrawTextWindow(1, 2, 15, 9);
            HallOfFame_PrintPlayerInfo(1, 2);
            MenuDrawTextWindow(2, 14, 27, 19);
            MenuPrint(gMenuText_HOFCongratulations, 4, 15);
            gTasks[taskID].func = sub_8142818;
        }
    }
}

static void sub_8142818(u8 taskID)
{
    if (gMain.newKeys & A_BUTTON)
    {
        FadeOutBGM(4);
        gTasks[taskID].func = sub_8142850;
    }
}

static void sub_8142850(u8 taskID)
{
    CpuSet(gPlttBufferFaded, gPlttBufferUnfaded, 0x200);
    BeginNormalPaletteFade(-1, 8, 0, 0x10, 0);
    gTasks[taskID].func = sub_81428A0;
}

static void sub_81428A0(u8 taskID)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskID);
        SetMainCallback2(sub_81439D0);
    }
}

#undef tDisplayedPoke
#undef tPokesNumber
#undef tFrameCount
#undef tPlayerSpriteID
#undef tMonSpriteID

extern const struct HallofFameMon sDummyFameMon;

void sub_81428CC(void)
{
    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        sub_81433E0();
        gMain.state = 1;
        break;
    case 1:
        sub_8143570();
        gMain.state++;
        break;
    case 2:
        {
            u16 savedIme;

            SetVBlankCallback(VBlankCB_HallOfFame);
            savedIme = REG_IME;
            REG_IME = 0;
            REG_IE |= 1;
            REG_IME = savedIme;
            REG_DISPSTAT |= 8;
            gMain.state++;
        }
        break;
    case 3:
        {
            struct HallofFameMons* fameMons;

            REG_BLDCNT = 0;
            REG_BLDALPHA = 0;
            REG_BLDY = 0;
            sub_81435B8();

            fameMons = (struct HallofFameMons*)(&ewram[0x1C000]);
            fameMons->mons[0] = sDummyFameMon;

            sub_80C5CD4(fameMons);
            gMain.state++;
        }
        break;
    case 4:
        AnimateSprites();
        BuildOamBuffer();
        UpdatePaletteFade();
        if (sub_80C5DCC())
            gMain.state++;
        break;
    case 5:
        REG_BLDCNT = 0x3F42;
        REG_BLDALPHA = 0x710;
        REG_BLDY = 0;
        CreateTask(sub_8142A28, 0);
        SetMainCallback2(CB2_HallOfFame);
        break;
    }
}

#define tCurrTeamNo     data[0]     //0x8
#define tCurrPageNo     data[1]     //0xA
#define tCurrPokeID     data[2]     //0xC
#define tPokesNo        data[4]     //0x10
#define tMonSpriteID(i) data[i + 5]

static void sub_8142A28(u8 taskID)
{
    if (sub_8125EC8(3) != 1)
        gTasks[taskID].func = sub_8142FEC;
    else
    {
        u16 *vram1, *vram2;

        u16 i;
        struct HallofFameMons* savedTeams = (struct HallofFameMons*)(&ewram[0x1E000]);
        for (i = 0; i < 50; i++, savedTeams++)
        {
            if (savedTeams->mons[0].species == 0)
                break;
        }
        if (i < 50)
            gTasks[taskID].tCurrTeamNo = i - 1;
        else
            gTasks[taskID].tCurrTeamNo = 49;
        gTasks[taskID].tCurrPageNo = GetGameStat(10);

        for (i = 0, vram1 = (u16*)(VRAM + 0x381A), vram2 = (u16*)(VRAM + 0x385A); i <= 16; i++)
        {
            *(vram1 + i) = i + 3;
            *(vram2 + i) = i + 20;
        }
        SetUpWindowConfig(&gWindowConfig_81E7198);
        InitMenuWindow(&gWindowConfig_81E7198);
        gTasks[taskID].func = sub_8142B04;
    }
}

static void sub_8142B04(u8 taskID)
{
    struct HallofFameMons* savedTeams = (struct HallofFameMons*)(&ewram[0x1E000]);
    struct HallofFameMon* currMon;
    u16 i;
    u8* stringPtr;

    for (i = 0; i < gTasks[taskID].tCurrTeamNo; i++)
        savedTeams++;

    currMon = &savedTeams->mons[0];
    gUnknown_0203931C = 0;
    gTasks[taskID].tCurrPokeID = 0;
    gTasks[taskID].tPokesNo = 0;

    for (i = 0; i < 6; i++, currMon++)
    {
        if (currMon->species != 0)
            gTasks[taskID].tPokesNo++;
    }

    currMon = &savedTeams->mons[0];

    for (i = 0; i < 6; i++, currMon++)
    {
        if (currMon->species != 0)
        {
            u16 spriteID;
            s16 posX, posY;
            if (gTasks[taskID].tPokesNo > 3)
            {
                posX = gUnknown_0840B534[i][2];
                posY = gUnknown_0840B534[i][3];
            }
            else
            {
                posX = gUnknown_0840B564[i][2];
                posY = gUnknown_0840B564[i][3];
            }
            spriteID = sub_81436BC(currMon->species, posX, posY, i, currMon->tid, currMon->personality);
            gSprites[spriteID].oam.priority = 1;
            gTasks[taskID].tMonSpriteID(i) = spriteID;
        }
        else
            gTasks[taskID].tMonSpriteID(i) = 0xFF;
    }

    BlendPalettes(0xFFFF0000, 0xC, 0x735F);

    stringPtr = gStringVar1;
    stringPtr = StringCopy(stringPtr, gMenuText_HOFNumber);
    stringPtr[0] = 0xFC;
    stringPtr[1] = 0x14;
    stringPtr[2] = 0x6;
    stringPtr += 3;
    stringPtr = ConvertIntToDecimalString(stringPtr, gTasks[taskID].tCurrPageNo);
    stringPtr[0] = 0xFC;
    stringPtr[1] = 0x13;
    stringPtr[2] = 0xF0;
    stringPtr[3] = EOS;
    MenuPrint(gStringVar1, 0, 0);

    gTasks[taskID].func = sub_8142CC8;
}

static void sub_8142CC8(u8 taskID)
{
    struct HallofFameMons* savedTeams = (struct HallofFameMons*)(&ewram[0x1E000]);
    struct HallofFameMon* currMon;
    u16 i;
    u16 currMonID;

    for (i = 0; i < gTasks[taskID].tCurrTeamNo; i++)
        savedTeams++;

    for (i = 0; i < 6; i++)
    {
        u16 spriteID = gTasks[taskID].tMonSpriteID(i);
        if (spriteID != 0xFF)
            gSprites[spriteID].oam.priority = 1;
    }

    currMonID = gTasks[taskID].tMonSpriteID(gTasks[taskID].tCurrPokeID);
    gSprites[currMonID].oam.priority = 0;
    gUnknown_0203931C = (0x10000 << gSprites[currMonID].oam.paletteNum) ^ 0xFFFF0000;
    BlendPalettesUnfaded(gUnknown_0203931C, 0xC, 0x735F);

    currMon = &savedTeams->mons[gTasks[taskID].tCurrPokeID];
    if (currMon->species != SPECIES_EGG)
    {
        StopCryAndClearCrySongs();
        PlayCry1(currMon->species, 0);
    }
    HallOfFame_PrintMonInfo(currMon, 0, 14);

    gTasks[taskID].func = sub_8142DF4;
}

static void sub_8142DF4(u8 taskID)
{
    u16 i;
    if (gMain.newKeys & A_BUTTON)
    {
        if (gTasks[taskID].tCurrTeamNo != 0) // prepare another team to view
        {
            gTasks[taskID].tCurrTeamNo--;
            for (i = 0; i < 6; i++)
            {
                u8 spriteID = gTasks[taskID].tMonSpriteID(i);
                if (spriteID != 0xFF)
                {
                    FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(gSprites[spriteID].oam.paletteNum));
                    DestroySprite(&gSprites[spriteID]);
                }
            }
            if (gTasks[taskID].tCurrPageNo != 0)
                gTasks[taskID].tCurrPageNo--;
            gTasks[taskID].func = sub_8142B04;
        }
        else // no more teams to view, turn off hall of fame PC
        {
            if (IsCryPlayingOrClearCrySongs())
            {
                StopCryAndClearCrySongs();
                m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
            }
            gTasks[taskID].func = sub_8142F78;
        }
    }
    else if (gMain.newKeys & B_BUTTON) // turn off hall of fame PC
    {
        if (IsCryPlayingOrClearCrySongs())
        {
            StopCryAndClearCrySongs();
            m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
        }
        gTasks[taskID].func = sub_8142F78;
    }
    else if (gMain.newKeys & DPAD_UP && gTasks[taskID].tCurrPokeID != 0) // change poke -1
    {
        gTasks[taskID].tCurrPokeID--;
        gTasks[taskID].func = sub_8142CC8;
    }
    else if (gMain.newKeys & DPAD_DOWN && gTasks[taskID].tCurrPokeID < gTasks[taskID].tPokesNo - 1) // change poke +1
    {
        gTasks[taskID].tCurrPokeID++;
        gTasks[taskID].func = sub_8142CC8;
    }
}

static void sub_8142F78(u8 taskID)
{
    struct HallofFameMons* fameMons;

    CpuSet(gPlttBufferFaded, gPlttBufferUnfaded, 0x200);
    fameMons = (struct HallofFameMons*)(&ewram[0x1C000]);
    fameMons->mons[0] = sDummyFameMon;
    sub_80C5E38(fameMons);
    gTasks[taskID].func = sub_8142FCC;
}

static void sub_8142FCC(u8 taskID)
{
    if (sub_80C5F98())
    {
        DestroyTask(taskID);
        ReturnFromHallOfFamePC();
    }
}

static void sub_8142FEC(u8 taskID)
{
    MenuDrawTextWindow(2, 14, 27, 19);
    MenuPrintMessage(gMenuText_HOFCorrupt, 3, 15);
    gTasks[taskID].func = sub_814302C;
}

static void sub_814302C(u8 taskID)
{
    if (MenuUpdateWindowText() && gMain.newKeys & A_BUTTON)
        gTasks[taskID].func = sub_8142F78;
}

#undef tCurrTeamNo
#undef tCurrPageNo
#undef tCurrPokeID
#undef tPokesNo
#undef tMonSpriteID

static void sub_8143068(u8 a0, u8 a1)
{
    sub_8072BD8(gMenuText_WelcomeToHOFAndDexRating, 0, a1 + 1, 0xF0);
}

static void HallOfFame_PrintMonInfo(struct HallofFameMon* currMon, u8 a1, u8 a2)
{
    u8* stringPtr;
    u16 monData;
    u16 i;

    stringPtr = gStringVar1;
    stringPtr[0] = EXT_CTRL_CODE_BEGIN;
    stringPtr[1] = 0x13;
    stringPtr[2] = 0x28;
    stringPtr[3] = EOS;

    if (currMon->species != SPECIES_EGG)
    {
        monData = SpeciesToPokedexNum(currMon->species);
        if (monData != 0xFFFF)
        {
            stringPtr = StringCopy(stringPtr, gOtherText_Number2);
            ConvertIntToDecimalStringN(stringPtr, monData, 2, 3);
        }
    }

    MenuPrint(gStringVar1, a1 + 4, a2 + 1);
    stringPtr = gStringVar1;

    for (i = 0; i < 10 && currMon->nick[i] != EOS; stringPtr[i] = currMon->nick[i], i++) {}
    stringPtr += i;
    stringPtr[0] = EOS;

    if (currMon->species == SPECIES_EGG)
    {
        stringPtr[0] = EXT_CTRL_CODE_BEGIN;
        stringPtr[1] = 0x13;
        stringPtr[2] = 0xA0;
        stringPtr[3] = EOS;
        MenuPrint(gStringVar1, a1 + 9, a2 + 1);
        MenuZeroFillWindowRect(0, a2 + 3, 29, a2 + 4);
    }
    else
    {

        stringPtr[0] = EXT_CTRL_CODE_BEGIN;
        stringPtr[1] = 0x13;
        stringPtr[2] = 0x3E;
        stringPtr += 3;

        stringPtr[0] = CHAR_SLASH;
        stringPtr++;

        for (i = 0; i < 10 && gSpeciesNames[currMon->species][i] != EOS; stringPtr[i] = gSpeciesNames[currMon->species][i], i++) {}

        stringPtr += i;
        stringPtr[0] = CHAR_SPACE;
        stringPtr++;

        if (currMon->species != SPECIES_NIDORAN_M && currMon->species != SPECIES_NIDORAN_F)
        {
            switch (GetGenderFromSpeciesAndPersonality(currMon->species, currMon->personality))
            {
            case MON_MALE:
                stringPtr[0] = CHAR_MALE;
                stringPtr++;
                break;
            case MON_FEMALE:
                stringPtr[0] = CHAR_FEMALE;
                stringPtr++;
                break;
            }
        }

        stringPtr[0] = EXT_CTRL_CODE_BEGIN;
        stringPtr[1] = 0x13;
        stringPtr[2] = 0xA0;
        stringPtr[3] = EOS;

        MenuPrint(gStringVar1, a1 + 9, a2 + 1);

        monData = currMon->lvl;

        stringPtr = StringCopy(gStringVar1, gOtherText_Level3);

        stringPtr[0] = EXT_CTRL_CODE_BEGIN;
        stringPtr[1] = 0x14;
        stringPtr[2] = 6;
        stringPtr += 3;

        stringPtr = ConvertIntToDecimalStringN(stringPtr, monData, 0, 3);

        stringPtr[0] = EXT_CTRL_CODE_BEGIN;
        stringPtr[1] = 0x13;
        stringPtr[2] = 0x30;
        stringPtr[3] = EOS;

        MenuPrint(gStringVar1, a1 + 7, a2 + 3);

        monData = currMon->tid;

        stringPtr = StringCopy(gStringVar1, gOtherText_IDNumber);
        ConvertIntToDecimalStringN(stringPtr, monData, 2, 5);

        MenuPrint(gStringVar1, a1 + 13, a2 + 3);
    }
}

#define ByteRead16(ptr) ((ptr)[0] | ((ptr)[1] << 8))

static void HallOfFame_PrintPlayerInfo(u8 a0, u8 a1)
{
    u8* stringPtr;
    u16 visibleTid;

    MenuPrint(gOtherText_Name, a0 + 1, a1 + 1);
    MenuPrint_RightAligned(gSaveBlock2.playerName, a0 + 14, a1 + 1);

    MenuPrint(gOtherText_IDNumber2, a0 + 1, a1 + 3);
    visibleTid = ByteRead16(gSaveBlock2.playerTrainerId);
    ConvertIntToDecimalStringN(gStringVar1, visibleTid, 2, 5);

    MenuPrint_RightAligned(gStringVar1, a0 + 14, a1 + 3);
    MenuPrint(gMainMenuString_Time, a0 + 1, a1 + 5);

    stringPtr = ConvertIntToDecimalString(gStringVar1, gSaveBlock2.playTimeHours);
    stringPtr[0] = CHAR_SPACE;
    stringPtr[1] = CHAR_COLON;
    stringPtr[2] = CHAR_SPACE;
    stringPtr += 3;

    stringPtr = ConvertIntToDecimalStringN(stringPtr, gSaveBlock2.playTimeMinutes, 2, 2);
    stringPtr[0] = EOS;

    MenuPrint_RightAligned(gStringVar1, a0 + 14, a1 + 5);
}

extern const u8 gHallOfFame_Gfx[];
extern const u16 gHallOfFame_Pal[];

static void sub_81433E0(void)
{
    u32 offsetWrite, offsetWrite2, offsetWrite3, offsetWrite4;
    u32 size, size2, size3, size4;
    u16 i;

    REG_DISPCNT = 0;

    REG_BG0CNT = 0;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;

    REG_BG1CNT = 0;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;

    REG_BG2CNT = 0;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;

    REG_BG3CNT = 0;
    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;

    offsetWrite = (VRAM);
    size = 0x18000;
    while (TRUE)
    {
        DmaFill16(3, 0, offsetWrite, 0x1000);
        offsetWrite += 0x1000;
        size -= 0x1000;
        if (size <= 0x1000)
        {
            DmaFill16(3, 0, offsetWrite, size);
            break;
        }
    }

    offsetWrite2 = OAM;
    size2 = OAM_SIZE;
    DmaFill32(3, 0, offsetWrite2, size2);

    offsetWrite3 = PLTT;
    size3 = PLTT_SIZE;
    DmaFill16(3, 0, offsetWrite3, size3);

    LZ77UnCompVram(gHallOfFame_Gfx, (void*)(VRAM));

    for (i = 0; i < 64; i++)
    {
        *((u16*)(VRAM + 0x3800) + i) = 1;
    }
    for (i = 0; i < 192; i++)
    {
        *((u16*)(VRAM + 0x3B80) + i) = 1;
    }
    for (i = 0; i < 1024; i++)
    {
        *((u16*)(VRAM + 0x3000) + i) = 2;
    }

    offsetWrite4 = (u32)(&ewram[0]);
    size4 = 0x4000;
    while (TRUE)
    {
        DmaFill16(3, 0, offsetWrite4, 0x1000);
        offsetWrite4 += 0x1000;
        size4 -= 0x1000;
        if (size4 <= 0x1000)
        {
            DmaFill16(3, 0, offsetWrite4, size4);
            break;
        }
    }

    ResetPaletteFade();
    LoadPalette(gHallOfFame_Pal, 0, 0x20);
}

extern const struct CompressedSpriteSheet gUnknown_0840B514;
extern const struct CompressedSpritePalette gUnknown_0840B524;

static void sub_8143570(void)
{
    remove_some_task();
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 8;
    LoadCompressedObjectPic(&gUnknown_0840B514);
    LoadCompressedObjectPalette(&gUnknown_0840B524);
    SetUpWindowConfig(&gWindowConfig_81E71B4);
    InitMenuWindow(&gWindowConfig_81E71B4);
}

static void sub_81435B8(void)
{
    REG_BG1CNT = 0x700;
    REG_BG3CNT = 0x603;
    REG_DISPCNT = 0x1B40;
}

static void sub_81435DC(struct Sprite* sprite)
{
    u32 spritePos = *(u32*)(&sprite->pos1);
    u32 dataPos = *(u32*)(&sprite->data1);
    if (spritePos != dataPos)
    {
        if (sprite->pos1.x < sprite->data1)
            sprite->pos1.x += 15;
        if (sprite->pos1.x > sprite->data1)
            sprite->pos1.x -= 15;

        if (sprite->pos1.y < sprite->data2)
            sprite->pos1.y += 10;
        if (sprite->pos1.y > sprite->data2)
            sprite->pos1.y -= 10;
    }
    else
    {
        sprite->data0 = 1;
        sprite->callback = SpriteCB_HallOfFame_Dummy;
    }
}

void SpriteCB_HallOfFame_Dummy(struct Sprite* sprite)
{

}

extern const struct SpriteTemplate gUnknown_0840B6B8;
extern const struct SpriteFrameImage* gUnknown_0840B69C[];

void sub_8143648(u16 paletteTag, u8 animID)
{
    gUnknown_02024E8C = gUnknown_0840B6B8;
    gUnknown_02024E8C.paletteTag = paletteTag;
    gUnknown_02024E8C.images = gUnknown_0840B69C[animID];
    gUnknown_02024E8C.anims = gSpriteAnimTable_81E7C64;
}

void sub_8143680(u16 paletteTag, u8 animID)
{
    gUnknown_02024E8C = gUnknown_0840B6B8;
    gUnknown_02024E8C.paletteTag = paletteTag;
    gUnknown_02024E8C.images = gUnknown_0840B69C[animID];
    gUnknown_02024E8C.anims = gUnknown_081EC2A4[0];
}

extern void* gUnknown_0840B5A0[];

static u32 sub_81436BC(u16 species, s16 posX, s16 posY, u16 pokeID, u32 tid, u32 pid)
{
    u8 spriteID;
    const u8* pokePal;

    LoadSpecialPokePic(&gMonFrontPicTable[species], gMonFrontPicCoords[species].coords, gMonFrontPicCoords[species].y_offset, 0x2000000, gUnknown_0840B5A0[pokeID], species, pid, 1);

    pokePal = species_and_otid_get_pal(species, tid, pid);
    LoadCompressedPalette(pokePal, 16 * pokeID + 256, 0x20);

    sub_8143648(pokeID, pokeID);
    spriteID = CreateSprite(&gUnknown_02024E8C, posX, posY, 10 - pokeID);
    gSprites[spriteID].oam.paletteNum = pokeID;
    return spriteID;
}
