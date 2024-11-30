#include "global.h"
#include "text.h"
#include "main.h"
#include "menu.h"
#include "sprite.h"
#include "pokepulse.h"
#include "palette.h"
#include "scanline_effect.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "task.h"
#include "bg.h"
#include "gpu_regs.h"
#include "decompress.h"
#include "graphics.h"
#include "strings.h"
#include "international_string_util.h"
#include "sprite.h"
#include "fieldmap.h"
#include "sound.h"
#include "quests.h"
#include "script.h"
#include "constants/songs.h"

static const struct BgTemplate sBgTemplates_PokePulse[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 23,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
};

enum 
{
    PULSE_WIN_APP_NAMES1,
    PULSE_WIN_APP_NAMES2,
    PULSE_WIN_DESCBOX
};

static const struct WindowTemplate sPokePulseWindowTemplates[] =
{
    [PULSE_WIN_APP_NAMES1] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 8,
        .width = 27,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 54
    },
    [PULSE_WIN_APP_NAMES2] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 14,
        .width = 27,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 108
    },
    [PULSE_WIN_DESCBOX] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 17,
        .width = 24,
        .height = 2,
        .paletteNum = 14,
        .baseBlock = 162
    }
};

static const u8 sPokePulseDescTextColors[]  = { TEXT_COLOR_GREEN, TEXT_COLOR_BLUE, TEXT_COLOR_LIGHT_GREEN };
static const u8 sPokePulseAppNameTextColors[]  = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY };

static EWRAM_DATA struct PokePulse sPokePulse;

static const u32 sPokepulseTilemap[] = INCBIN_U32("graphics/pokepulse/pokepulse.bin.lz");
static const u32 sPokepulseTiles[] = INCBIN_U32("graphics/pokepulse/pokepulse.4bpp.lz");
static const u16 sPokepulsePalette[] = INCBIN_U16("graphics/pokepulse/pokepulse.gbapal");

static const u16 sPokepulseMessageBoxPal[] = INCBIN_U16("graphics/pokepulse/message.gbapal");
static const u32 sPokepulseMessageBoxGfx[] = INCBIN_U32("graphics/pokepulse/message.4bpp");

static const u32 sPokepulseIconsGfx[] = INCBIN_U32("graphics/pokepulse/icons.4bpp.lz");
static const u16 sPokepulseIconsPal[] = INCBIN_U16("graphics/pokepulse/icons.gbapal");

static const u32 sPokepulseCircleGfx[] = INCBIN_U32("graphics/pokepulse/selection_box.4bpp.lz");
static const u16 sPokepulseCirclePal[] = INCBIN_U16("graphics/pokepulse/selection_box.gbapal");

#define TAG_ICON_GFX 1234
#define TAG_ICON_PAL 0x4654

#define TAG_CIRCLE_GFX 12345
#define TAG_CIRCLE_PAL 0x4655

static const struct SpritePalette sSpritePalette_PokePulseIcons[] =
{
    { sPokepulseIconsPal, TAG_ICON_PAL },
    { NULL }
};

static const struct CompressedSpriteSheet sSpriteSheet_PokePulseIcons[] = 
{
    { sPokepulseIconsGfx, 32 * 320 / 2 , TAG_ICON_GFX },
    { NULL }
};

static const struct SpritePalette sSpritePalette_PokePulseCircle[] =
{
    { sPokepulseCirclePal, TAG_CIRCLE_PAL },
    { NULL }
};

static const struct CompressedSpriteSheet sSpriteSheet_PokePulseCircle[] = 
{
    { sPokepulseCircleGfx, 32 * 32 / 2 , TAG_CIRCLE_GFX },
    { NULL }
};

static const struct OamData sPokePulseIcon_Oam = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const struct OamData sPokePulseCircle_Oam = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 1,
};

#define POKEPULSE_APP_SPRITE(name, x) \
static const union AnimCmd gAnimCmd_##name##_Selected[] = { \
    ANIMCMD_FRAME(x * 16, 0), \
    ANIMCMD_JUMP(0), \
}; \
static const union AnimCmd gAnimCmd_##name##_NotSelected[] = { \
    ANIMCMD_FRAME((5 + x) * 16, 0), \
    ANIMCMD_JUMP(0), \
}; \
static const union AnimCmd *const gIcon##name##Anim[] = {\
    gAnimCmd_##name##_Selected,\
    gAnimCmd_##name##_NotSelected,\
};\
static const struct SpriteTemplate gSpriteIcon##name = { \
    .tileTag = TAG_ICON_GFX, \
    .paletteTag = TAG_ICON_PAL, \
    .oam = &sPokePulseIcon_Oam, \
    .anims = gIcon##name##Anim, \
    .images = NULL, \
    .affineAnims = gDummySpriteAffineAnimTable, \
    .callback = SpriteCallbackDummy, \
}; \

POKEPULSE_APP_SPRITE(Map, 0)
POKEPULSE_APP_SPRITE(Condition, 1)
POKEPULSE_APP_SPRITE(Quests, 2)
POKEPULSE_APP_SPRITE(Ribbons, 3)
POKEPULSE_APP_SPRITE(Seeker, 4)

const struct SpriteTemplate sSelectionCircleSpriteTemplate =
{
    .tileTag = TAG_CIRCLE_GFX,
    .paletteTag = TAG_CIRCLE_PAL,
    .oam = &sPokePulseCircle_Oam,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u8 sText_Map[] = _("Map");
static const u8 sText_Seeker[] = _("Seeker");
static const u8 sText_Quests[] = _("Quests");
static const u8 sText_Ribbons[] = _("Ribbons");
static const u8 sText_Condition[] = _("Condition");

static void CB2_OpenTownMapFromPokePulse(void);
static void CB2_OpenQuestMenuFromPokePulse(void);
static void PokePulse_MoveSelection(s8 delta);

static const u8 sText_QuestMenu[] = _("Check your current quests.");
static const u8 sText_VSSeeker[] = _("Arrange a rematch with Trainers.");

static const struct PokePulseApplicaton sApplications[] = 
{
    { sText_Map, gText_CheckMapOfHoenn, &gSpriteIconMap, CB2_OpenTownMapFromPokePulse },
    { sText_Quests, sText_QuestMenu, &gSpriteIconQuests, CB2_OpenQuestMenuFromPokePulse },
    { sText_Seeker, sText_VSSeeker, &gSpriteIconSeeker, NULL },
    { sText_Ribbons, gText_CheckObtainedRibbons, &gSpriteIconRibbons, NULL },
    { sText_Condition, gText_CheckPokemonInDetail, &gSpriteIconCondition, NULL },
};

void CB2_StartPokePulseFromField(void)
{
    GoToPokePulse(CB2_ReturnToFieldWithOpenMenu);
}

static void PokePulse_InitBgs(void)
{
    ResetVramOamAndBgCntRegs();
    memset(sPokePulse.bg2TilemapBuffer, 0, sizeof(sPokePulse.bg2TilemapBuffer));
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_PokePulse, ARRAY_COUNT(sBgTemplates_PokePulse));
    SetBgTilemapBuffer(2, sPokePulse.bg2TilemapBuffer);
    ResetAllBgsCoordinates();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(2);
}

static bool8 LoadPokePulseGraphics(void)
{
    switch (sPokePulse.graphicsLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, sPokepulseTiles, 0, 0, 0);
        sPokePulse.graphicsLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sPokepulseTilemap, sPokePulse.bg2TilemapBuffer);
            sPokePulse.graphicsLoadState++;
        }
        break;
    case 2:
        LoadPalette(sPokepulsePalette, 0, 0x40);
        sPokePulse.graphicsLoadState++;
        break;
    case 3:
        LoadSpritePalette(sSpritePalette_PokePulseIcons);
        LoadCompressedSpriteSheet(sSpriteSheet_PokePulseIcons);
        sPokePulse.graphicsLoadState++;
        break;
    case 4:
        LoadSpritePalette(sSpritePalette_PokePulseCircle);
        LoadCompressedSpriteSheet(sSpriteSheet_PokePulseCircle);
        sPokePulse.graphicsLoadState++;
        break;
    default:
        CopyBgTilemapBufferToVram(2);
        sPokePulse.graphicsLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void VBlankCB_PokePulseRun(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_PokePulseRun(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void PokePulse_InitWindows(void)
{
    InitWindows(sPokePulseWindowTemplates);

    PutWindowTilemap(PULSE_WIN_APP_NAMES1);
    FillWindowPixelBuffer(PULSE_WIN_APP_NAMES1, PIXEL_FILL(0));
    CopyWindowToVram(PULSE_WIN_APP_NAMES1, COPYWIN_FULL);

    PutWindowTilemap(PULSE_WIN_APP_NAMES2);
    FillWindowPixelBuffer(PULSE_WIN_APP_NAMES2, PIXEL_FILL(0));
    CopyWindowToVram(PULSE_WIN_APP_NAMES2, COPYWIN_FULL);

    LoadBgTiles(GetWindowAttribute(PULSE_WIN_DESCBOX, WINDOW_BG), sPokepulseMessageBoxGfx, 0x120, 210);
    LoadPalette(sPokepulseMessageBoxPal, 0x10 * 14, 32);

    PutWindowTilemap(PULSE_WIN_DESCBOX);
    FillWindowPixelBuffer(PULSE_WIN_DESCBOX, PIXEL_FILL(6));
    CopyWindowToVram(PULSE_WIN_DESCBOX, COPYWIN_FULL);

    DrawStdFrameWithCustomTileAndPalette(PULSE_WIN_DESCBOX, TRUE, 210, 14);
}

static void PrintPokePulseDescription(const u8 *str)
{
    u32 width = GetStringWidth(FONT_NORMAL, str, -1);
    FillWindowPixelBuffer(PULSE_WIN_DESCBOX, PIXEL_FILL(6));
    AddTextPrinterParameterized3(PULSE_WIN_DESCBOX, FONT_NORMAL, (192 - width) / 2, 1, sPokePulseDescTextColors, 0, str);
}

static void PokePulse_PrintAppName(u8 i)
{
    const u8 *str = sApplications[i].name;
    u32 x = 54 * (i % 4) + GetStringCenterAlignXOffset(FONT_NORMAL, str, 48);
    AddTextPrinterParameterized3(i / 4, FONT_NORMAL, x, 0, sPokePulseAppNameTextColors, 0, str);
}

static void PokePulse_CreateIcons(void)
{
    u32 i, x, y;
    for (i = 0; i < ARRAY_COUNT(sApplications); ++i)
    {
        const struct SpriteTemplate *iconTemplate = sApplications[i].iconTemplate;
        x = 40 + 54 * (i % 4);
        y = 48 + 48 * (i / 4);

        sPokePulse.iconSpriteIds[i] = CreateSprite(iconTemplate, x, y, 0);
        PokePulse_PrintAppName(i);

        StartSpriteAnim(&gSprites[sPokePulse.iconSpriteIds[i]], i == sPokePulse.selectionIdx ? 0 : 1);
    }

    x = 40 + 54 * (sPokePulse.selectionIdx % 4);
    y = 48 + 48 * (sPokePulse.selectionIdx / 4);
    sPokePulse.selectionBoxSpriteId = CreateSprite(&sSelectionCircleSpriteTemplate, x, y, 0);
}

static void PokePulse_FreeResources(void)
{
    u32 i;
    for (i = 0; i < 5; ++i)
    {
        struct Sprite *iconSprite = &gSprites[sPokePulse.iconSpriteIds[i]];
        DestroySpriteAndFreeResources(iconSprite);
    }
    FreeAllWindowBuffers();
}

#define tState data[0]

static void Task_ClosePokePulse(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
        tState++;
        break;
    case 1:
        if (!gPaletteFade.active)
            tState++;
        break;
    case 2:
        tState++;
        break;
    default:
        if (sPokePulse.newScreenCallback)
            SetMainCallback2(sPokePulse.newScreenCallback);
        else
            SetMainCallback2(sPokePulse.exitCallback);
        
        PokePulse_FreeResources();
        DestroyTask(taskId);
        break;
    }
}

static void Task_PokePulseHandleInput(u8 taskId)
{
    if (gPaletteFade.active) return;
    
    if (gMain.newKeys & DPAD_LEFT)
    {
        PokePulse_MoveSelection(-1);
    } 
    else if (gMain.newKeys & DPAD_RIGHT)
    {
        PokePulse_MoveSelection(1);
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        PokePulse_MoveSelection(-4);
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        PokePulse_MoveSelection(4);
    }
    else if (gMain.newKeys & A_BUTTON)
    {
        sPokePulse.newScreenCallback = sApplications[sPokePulse.selectionIdx].openCallback;
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_ClosePokePulse;
        PlaySE(SE_SELECT);
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_ClosePokePulse;
        PlaySE(SE_SELECT);
    }
}

#undef tState

static void PokePulse_MoveSelection(s8 delta)
{
    u32 i;
    struct Sprite *selectionBoxSprite;
    u8 lastSelected = sPokePulse.selectionIdx;

    if (sPokePulse.selectionIdx + delta < 0) 
        sPokePulse.selectionIdx = 4;
    else if (sPokePulse.selectionIdx + delta > 4) 
        sPokePulse.selectionIdx = 0;
    else 
        sPokePulse.selectionIdx += delta;

    if (lastSelected != sPokePulse.selectionIdx)
    {
        PlaySE(SE_SELECT);
        selectionBoxSprite = &gSprites[sPokePulse.selectionBoxSpriteId];
        selectionBoxSprite->x = 40 + 54 * (sPokePulse.selectionIdx % 4);
        selectionBoxSprite->y = 48 + 48 * (sPokePulse.selectionIdx / 4);

        PrintPokePulseDescription(sApplications[sPokePulse.selectionIdx].desc);

        for (i = 0; i < ARRAY_COUNT(sApplications); ++i)
        {
            u8 spriteId = sPokePulse.iconSpriteIds[i];
            StartSpriteAnim(&gSprites[spriteId], i == sPokePulse.selectionIdx ? 0 : 1);
        }
    }
}

static bool8 SetupPokePulse(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = TRUE;
        gMain.state++;
        break;
    case 4:
        ResetSpriteData();
        gMain.state++;
        break;
    case 5:
        gMain.state++;
        break;
    case 6:
        if (!MenuHelpers_IsLinkActive())
            ResetTasks();
        gMain.state++;
        break;
    case 7:
        PokePulse_InitBgs();
        sPokePulse.graphicsLoadState = 0;
        gMain.state++;
        break;
    case 8:
        if (!LoadPokePulseGraphics())
            break;
        gMain.state++;
        break;
    case 9:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            PokePulse_InitWindows();
            PrintPokePulseDescription(sApplications[sPokePulse.selectionIdx].desc);
            gMain.state++;
        }
        break;
    case 10:
        PokePulse_CreateIcons();
        gMain.state++;
        break;
    case 11:
        BlendPalettes(PALETTES_ALL, 16, 0);
        gMain.state++;
        break;
    case 12:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, 0);
        gPaletteFade.bufferTransferDisabled = FALSE;
        gMain.state++;
        break;
    default:
        sPokePulse.inputTaskId = CreateTask(Task_PokePulseHandleInput, 0x80);
        SetVBlankCallback(VBlankCB_PokePulseRun);
        SetMainCallback2(CB2_PokePulseRun);
        return TRUE;
    }
    return TRUE;
}

void CB2_PokePulse(void)
{
    while (SetupPokePulse() != TRUE)
    {}
}

void GoToPokePulse(MainCallback cb)
{
    sPokePulse.newScreenCallback = NULL;
    sPokePulse.exitCallback = cb;
    SetMainCallback2(CB2_PokePulse);
}

static void CB2_OpenTownMapFromPokePulse(void)
{
    FieldInitRegionMap(CB2_StartPokePulseFromField);
}

static void CB2_OpenQuestMenuFromPokePulse(void)
{
    QuestMenu_Init(0, CB2_StartPokePulseFromField);
    ScriptContext_Stop();
}