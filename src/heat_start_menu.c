#include "global.h"
#include "option_menu.h"
#include "heat_start_menu.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_object_lock.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "field_weather.h"
#include "field_screen_effect.h"
#include "frontier_pass.h"
#include "frontier_util.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "link.h"
#include "load_save.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "new_game.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokenav.h"
#include "safari_zone.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "sprite.h"
#include "sound.h"
#include "start_menu.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_card.h"
#include "window.h"
#include "union_room.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "rtc.h"
#include "event_object_movement.h"
#include "gba/isagbprint.h"
#include "pokepulse.h"

/* CALLBACKS */
static void SpriteCB_IconPoketch(struct Sprite *sprite);
static void SpriteCB_IconPokedex(struct Sprite *sprite);
static void SpriteCB_IconParty(struct Sprite *sprite);
static void SpriteCB_IconBag(struct Sprite *sprite);
static void SpriteCB_IconTrainerCard(struct Sprite *sprite);
static void SpriteCB_IconSave(struct Sprite *sprite);
static void SpriteCB_IconOptions(struct Sprite *sprite);
static void SpriteCB_IconFlag(struct Sprite *sprite);

/* TASKs */
static bool8 Task_HeatStartMenu_HandleMainInput(void);

/* OTHER FUNCTIONS */
static void AddHeatStartMenuAction(u8 action);
static void HeatStartMenu_LoadSprites(void);
static void HeatStartMenu_CreateSprites(void);
static void HeatStartMenu_LoadBgGfx(void);
static void HeatStartMenu_ShowTimeWindow(void);
static void HeatStartMenu_UpdateMenuName(void);
static u8 HeatStartMenu_CreateMenuNameWindow(void);

/* ENUMs */
enum
{
    MENU_ACTION_POKEDEX,
    MENU_ACTION_PARTY,
    MENU_ACTION_BAG,
    MENU_ACTION_POKEPULSE,
    MENU_ACTION_TRAINER_CARD,
    MENU_ACTION_SAVE,
    MENU_ACTION_OPTIONS,
    MENU_ACTION_RETIRE,
    MENU_ACTION_COUNT
};

/* STRUCTs */
struct HeatStartMenu
{
    MainCallback savedCallback;
    u8 sStartClockWindowId;
    u8 sMenuNameWindowId;
    u8 sSafariBallsWindowId;
    u8 iconSpriteIds[MENU_ACTION_COUNT];
    u8 currentStartMenuActions[MENU_ACTION_COUNT];
    u8 startMenuLoadStep;
    u8 numStartMenuActions;
    u8 menuCursorPos;
    bool8 (*menuCallback)(void);
};

struct HeatStartMenuAction
{
    const u8 *name;
    const struct SpriteTemplate *iconTemplate;
    bool8 (*action)(void);
    bool8 fade;
};

static EWRAM_DATA struct HeatStartMenu sHeatStartMenu;

// --BG-GFX--
static const u32 sStartMenuTiles[] = INCBIN_U32("graphics/heat_start_menu/bg.4bpp.lz");
static const u32 sStartMenuTilemap[] = INCBIN_U32("graphics/heat_start_menu/bg.bin.lz");
static const u32 sStartMenuTilemapSafari[] = INCBIN_U32("graphics/heat_start_menu/bg_safari.bin.lz");
static const u16 sStartMenuPalette[] = INCBIN_U16("graphics/heat_start_menu/bg.gbapal");
static const u16 gStandardMenuPalette2[] = INCBIN_U16("graphics/interface/std_menu.gbapal");

static const u16 sPokepulseMessageBoxPal[] = INCBIN_U16("graphics/pokepulse/message.gbapal");
static const u32 sPokepulseMessageBoxGfx[] = INCBIN_U32("graphics/pokepulse/message.4bpp");

//--SPRITE-GFX--
#define TAG_ICON_GFX 1234
#define TAG_ICON_PAL 0x4654

static const u32 sIconGfx[] = INCBIN_U32("graphics/heat_start_menu/icons.4bpp.lz");
static const u16 sIconPal[] = INCBIN_U16("graphics/heat_start_menu/icons.gbapal");

static const struct WindowTemplate sSaveInfoWindowTemplate = 
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 14,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 8
};

static const struct WindowTemplate sWindowTemplate_StartClock = 
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 10, // If you want to shorten the dates to Sat., Sun., etc., change this to 9
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x30
};

static const struct WindowTemplate sWindowTemplate_MenuName = 
{
    .bg = 0,
    .tilemapLeft = 11,
    .tilemapTop = 14,
    .width = 8,
    .height = 2,
    .paletteNum = 14,
    .baseBlock = 0x30 + (12 * 2)
};

static const struct WindowTemplate sWindowTemplate_SafariBalls = 
{
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 1,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = (0x30 + (12 * 2)) + (8 * 2)
};

static const struct SpritePalette sSpritePal_Icon[] =
{
    { sIconPal, TAG_ICON_PAL },
    { NULL },
};

static const struct CompressedSpriteSheet sSpriteSheet_Icon[] =
{
    { sIconGfx, 32 * 512 / 2, TAG_ICON_GFX },
    { NULL },
};

static const struct OamData gOamIcon = 
{
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

static const union AnimCmd gAnimCmdPoketch_NotSelected[] = {
    ANIMCMD_FRAME(112, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmdPoketch_Selected[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gIconPoketchAnim[] = {
    gAnimCmdPoketch_NotSelected,
    gAnimCmdPoketch_Selected,
};

static const union AnimCmd gAnimCmdPokedex_NotSelected[] = {
    ANIMCMD_FRAME(128, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmdPokedex_Selected[] = {
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gIconPokedexAnim[] = {
    gAnimCmdPokedex_NotSelected,
    gAnimCmdPokedex_Selected,
};

static const union AnimCmd gAnimCmdParty_NotSelected[] = {
    ANIMCMD_FRAME(144, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmdParty_Selected[] = {
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gIconPartyAnim[] = {
    gAnimCmdParty_NotSelected,
    gAnimCmdParty_Selected,
};

static const union AnimCmd gAnimCmdBag_NotSelected[] = {
    ANIMCMD_FRAME(160, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmdBag_Selected[] = {
    ANIMCMD_FRAME(48, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gIconBagAnim[] = {
    gAnimCmdBag_NotSelected,
    gAnimCmdBag_Selected,
};

static const union AnimCmd gAnimCmdTrainerCard_NotSelected[] = {
    ANIMCMD_FRAME(176, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmdTrainerCard_Selected[] = {
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gIconTrainerCardAnim[] = {
    gAnimCmdTrainerCard_NotSelected,
    gAnimCmdTrainerCard_Selected,
};

static const union AnimCmd gAnimCmdSave_NotSelected[] = {
    ANIMCMD_FRAME(192, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmdSave_Selected[] = {
    ANIMCMD_FRAME(80, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gIconSaveAnim[] = {
    gAnimCmdSave_NotSelected,
    gAnimCmdSave_Selected,
};

static const union AnimCmd gAnimCmdOptions_NotSelected[] = {
    ANIMCMD_FRAME(208, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmdOptions_Selected[] = {
    ANIMCMD_FRAME(96, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gIconOptionsAnim[] = {
    gAnimCmdOptions_NotSelected,
    gAnimCmdOptions_Selected,
};

static const union AnimCmd gAnimCmdFlag_NotSelected[] = {
    ANIMCMD_FRAME(240, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmdFlag_Selected[] = {
    ANIMCMD_FRAME(224, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gIconFlagAnim[] = {
    gAnimCmdFlag_NotSelected,
    gAnimCmdFlag_Selected,
};

static const union AffineAnimCmd sAffineAnimIcon_NoAnim[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 60),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnimIcon_Anim[] =
    {
    AFFINEANIMCMD_FRAME(20, 20, 0, 5),    // Scale big
    AFFINEANIMCMD_FRAME(-10, -10, 0, 10), // Scale smol
    AFFINEANIMCMD_FRAME(0, 0, 1, 4),      // Begin rotating

    AFFINEANIMCMD_FRAME(0, 0, -1, 4), // Loop starts from here ; Rotate/Tilt left
    AFFINEANIMCMD_FRAME(0, 0, 0, 2),
    AFFINEANIMCMD_FRAME(0, 0, -1, 4),
    AFFINEANIMCMD_FRAME(0, 0, 0, 2),
    AFFINEANIMCMD_FRAME(0, 0, -1, 4),

    AFFINEANIMCMD_FRAME(0, 0, 1, 4), // Rotate/Tilt Right
    AFFINEANIMCMD_FRAME(0, 0, 0, 2),
    AFFINEANIMCMD_FRAME(0, 0, 1, 4),
    AFFINEANIMCMD_FRAME(0, 0, 0, 2),
    AFFINEANIMCMD_FRAME(0, 0, 1, 4),

    AFFINEANIMCMD_JUMP(3),
};

static const union AffineAnimCmd *const sAffineAnimsIcon[] =
{
    sAffineAnimIcon_NoAnim,
    sAffineAnimIcon_Anim,
};

static const struct SpriteTemplate gSpriteIconPoketch = 
{
    .tileTag = TAG_ICON_GFX,
    .paletteTag = TAG_ICON_PAL,
    .oam = &gOamIcon,
    .anims = gIconPoketchAnim,
    .images = NULL,
    .affineAnims = sAffineAnimsIcon,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteIconPokedex = 
{
    .tileTag = TAG_ICON_GFX,
    .paletteTag = TAG_ICON_PAL,
    .oam = &gOamIcon,
    .anims = gIconPokedexAnim,
    .images = NULL,
    .affineAnims = sAffineAnimsIcon,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteIconParty = 
{
    .tileTag = TAG_ICON_GFX,
    .paletteTag = TAG_ICON_PAL,
    .oam = &gOamIcon,
    .anims = gIconPartyAnim,
    .images = NULL,
    .affineAnims = sAffineAnimsIcon,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteIconBag = 
{
    .tileTag = TAG_ICON_GFX,
    .paletteTag = TAG_ICON_PAL,
    .oam = &gOamIcon,
    .anims = gIconBagAnim,
    .images = NULL,
    .affineAnims = sAffineAnimsIcon,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteIconTrainerCard = 
{
    .tileTag = TAG_ICON_GFX,
    .paletteTag = TAG_ICON_PAL,
    .oam = &gOamIcon,
    .anims = gIconTrainerCardAnim,
    .images = NULL,
    .affineAnims = sAffineAnimsIcon,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteIconSave = 
{
    .tileTag = TAG_ICON_GFX,
    .paletteTag = TAG_ICON_PAL,
    .oam = &gOamIcon,
    .anims = gIconSaveAnim,
    .images = NULL,
    .affineAnims = sAffineAnimsIcon,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteIconOptions = 
{
    .tileTag = TAG_ICON_GFX,
    .paletteTag = TAG_ICON_PAL,
    .oam = &gOamIcon,
    .anims = gIconOptionsAnim,
    .images = NULL,
    .affineAnims = sAffineAnimsIcon,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteIconFlag = 
{
    .tileTag = TAG_ICON_GFX,
    .paletteTag = TAG_ICON_PAL,
    .oam = &gOamIcon,
    .anims = gIconFlagAnim,
    .images = NULL,
    .affineAnims = sAffineAnimsIcon,
    .callback = SpriteCallbackDummy,
};

static const u8 gText_Pokepulse[] = _("PokePulse");
static const u8 gText_Pokedex[] = _("Pokédex");
static const u8 gText_Party[] = _("Party");
static const u8 gText_Bag[] = _("Bag");
static const u8 gText_Trainer[] = _("Trainer");
static const u8 gText_Save[] = _("Save");
static const u8 gText_Options[] = _("Options");

static bool8 StartMenuPokedexCallback(void)
{
    if (!gPaletteFade.active)
    {
        IncrementGameStat(GAME_STAT_CHECKED_POKEDEX);
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_OpenPokedex);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokemonCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_PartyMenuFromStartMenu); // Display party menu

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuBagCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_BagMenuFromStartMenu); // Display bag menu

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokepulseCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_StartPokePulseFromField);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();

        if (IsOverworldLinkActive() || InUnionRoom())
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card
        else if (FlagGet(FLAG_SYS_FRONTIER_PASS))
            ShowFrontierPass(CB2_ReturnToFieldWithOpenMenu); // Display frontier pass
        else
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuOptionCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitOptionMenu); // Display option menu
        gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuSaveCallback(void);

static const struct HeatStartMenuAction sHeatStartMenuActions[] =
{
    [MENU_ACTION_POKEDEX] = { gText_Pokedex, &gSpriteIconPokedex, StartMenuPokedexCallback, TRUE },
    [MENU_ACTION_PARTY] = { gText_Party, &gSpriteIconParty, StartMenuPokemonCallback, TRUE },
    [MENU_ACTION_BAG] = { gText_Bag, &gSpriteIconBag, StartMenuBagCallback, TRUE },
    [MENU_ACTION_POKEPULSE] = { gText_Pokepulse, &gSpriteIconPoketch, StartMenuPokepulseCallback, TRUE },
    [MENU_ACTION_TRAINER_CARD] = { gText_Trainer, &gSpriteIconTrainerCard, StartMenuPlayerNameCallback, TRUE },
    [MENU_ACTION_SAVE] = { gText_Save, &gSpriteIconSave, StartMenuSaveCallback, FALSE },
    [MENU_ACTION_OPTIONS] = { gText_Options, &gSpriteIconOptions, StartMenuOptionCallback, TRUE },
    [MENU_ACTION_RETIRE] = { gText_Retire, &gSpriteIconFlag, NULL, FALSE },
};

// If you want to shorten the dates to Sat., Sun., etc., change this to 70
#define CLOCK_WINDOW_WIDTH 100

static const u8 gText_Friday[] = _("Fri,");
static const u8 gText_Saturday[] = _("Sat,");
static const u8 gText_Sunday[] = _("Sun,");
static const u8 gText_Monday[] = _("Mon,");
static const u8 gText_Tuesday[] = _("Tue,");
static const u8 gText_Wednesday[] = _("Wed,");
static const u8 gText_Thursday[] = _("Thu,");

static const u8 *const gDayNameStringsTable[] =
{
    gText_Friday,
    gText_Saturday,
    gText_Sunday,
    gText_Monday,
    gText_Tuesday,
    gText_Wednesday,
    gText_Thursday
};

static const u8 gText_CurrentTime[] = _("  {STR_VAR_3} {STR_VAR_1}:{STR_VAR_2}");
static const u8 gText_CurrentTimeOff[] = _("  {STR_VAR_3} {CLEAR_TO 64}{STR_VAR_1} {STR_VAR_2}");
static const u8 gText_CurrentTimeAM[] = _("  {STR_VAR_3} {STR_VAR_1}:{STR_VAR_2} AM");
static const u8 gText_CurrentTimeAMOff[] = _("  {STR_VAR_3} {CLEAR_TO 51}{STR_VAR_1} {STR_VAR_2} AM");
static const u8 gText_CurrentTimePM[] = _("  {STR_VAR_3} {STR_VAR_1}:{STR_VAR_2} PM");
static const u8 gText_CurrentTimePMOff[] = _("  {STR_VAR_3} {CLEAR_TO 51}{STR_VAR_1} {STR_VAR_2} PM");

static void ShowSafariBallsWindow(void)
{
    sHeatStartMenu.sSafariBallsWindowId = AddWindow(&sWindowTemplate_SafariBalls);
    FillWindowPixelBuffer(sHeatStartMenu.sSafariBallsWindowId, PIXEL_FILL(TEXT_COLOR_WHITE));
    PutWindowTilemap(sHeatStartMenu.sSafariBallsWindowId);
    ConvertIntToDecimalStringN(gStringVar1, gNumSafariBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar4, gText_SafariBallStock);
    AddTextPrinterParameterized(sHeatStartMenu.sSafariBallsWindowId, FONT_NARROW, gStringVar4, 0, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sHeatStartMenu.sSafariBallsWindowId, COPYWIN_GFX);
}

static void BuildNormalStartMenu(void)
{    
    if (GetSafariZoneFlag() == TRUE)
        AddHeatStartMenuAction(MENU_ACTION_RETIRE);

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
        AddHeatStartMenuAction(MENU_ACTION_POKEDEX);
    
    if (FlagGet(FLAG_SYS_POKEMON_GET) == TRUE)
        AddHeatStartMenuAction(MENU_ACTION_PARTY);

    AddHeatStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddHeatStartMenuAction(MENU_ACTION_POKEPULSE);

    AddHeatStartMenuAction(MENU_ACTION_TRAINER_CARD);
    
    if (GetSafariZoneFlag() != TRUE)
        AddHeatStartMenuAction(MENU_ACTION_SAVE);
    AddHeatStartMenuAction(MENU_ACTION_OPTIONS);
}

static void AddHeatStartMenuAction(u8 action)
{
    sHeatStartMenu.currentStartMenuActions[sHeatStartMenu.numStartMenuActions] = action;
    ++sHeatStartMenu.numStartMenuActions;
}

static void Task_HeatStartMenu_LoadStartMenu(u8 taskId);

void Task_HeatStartMenu_Loop(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (data[0])
    {
    case 0:
        sHeatStartMenu.menuCallback = Task_HeatStartMenu_HandleMainInput;
        data[0]++;
        break;
    case 1:
        if (sHeatStartMenu.menuCallback() == TRUE)
            DestroyTask(taskId);
        break;
    }
}

void HeatStartMenu_Init(void)
{
    if (!IsOverworldLinkActive())
    {
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
    }

    LockPlayerFieldControls();

    sHeatStartMenu.startMenuLoadStep = 0;
    sHeatStartMenu.savedCallback = CB2_ReturnToFieldWithOpenMenu;

    SetTaskFuncWithFollowupFunc(CreateTask(Task_HeatStartMenu_LoadStartMenu, 0), Task_HeatStartMenu_LoadStartMenu, Task_HeatStartMenu_Loop);
}

static void HeatStartMenu_QuickInit(void)
{
    if (!IsOverworldLinkActive())
    {
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
    }

    LockPlayerFieldControls();

    sHeatStartMenu.startMenuLoadStep = 0;
    sHeatStartMenu.savedCallback = CB2_ReturnToFieldWithOpenMenu;

    while (!HeatStartMenu_LoadStartMenu())
        ;

    CreateTask(Task_HeatStartMenu_Loop, 0);
}

bool8 HeatStartMenu_LoadStartMenu(void)
{
    switch (sHeatStartMenu.startMenuLoadStep)
    {
    case 0:
        BuildNormalStartMenu();
        sHeatStartMenu.startMenuLoadStep++;
        break;
    case 1:
        HeatStartMenu_LoadSprites();
        HeatStartMenu_CreateSprites();
        sHeatStartMenu.startMenuLoadStep++;
        break;
    case 2:
        HeatStartMenu_LoadBgGfx();
        sHeatStartMenu.startMenuLoadStep++;
        break;
    case 3:
        HeatStartMenu_ShowTimeWindow();
        if (GetSafariZoneFlag() == TRUE)
            ShowSafariBallsWindow();
        sHeatStartMenu.sMenuNameWindowId = HeatStartMenu_CreateMenuNameWindow();
        HeatStartMenu_UpdateMenuName();
        sHeatStartMenu.startMenuLoadStep++;
        break;
    case 4:
        sHeatStartMenu.startMenuLoadStep = 0;
        return TRUE;
    }

    return FALSE;
}

static void Task_HeatStartMenu_LoadStartMenu(u8 taskId)
{
    if (HeatStartMenu_LoadStartMenu() == TRUE)
        SwitchTaskToFollowupFunc(taskId);
}

static void HeatStartMenu_LoadSprites(void)
{
    u32 index;
    LoadSpritePalette(sSpritePal_Icon);
    // index = IndexOfSpritePaletteTag(TAG_ICON_PAL);
    // LoadPalette(sIconPal, OBJ_PLTT_ID(index), PLTT_SIZE_4BPP);
    LoadCompressedSpriteSheet(sSpriteSheet_Icon);
}

static void HeatStartMenu_SetIconAnimation(u8 spriteId, bool8 animate)
{
    StartSpriteAnim(&gSprites[spriteId], animate);
    StartSpriteAffineAnim(&gSprites[spriteId], animate);
}

static void HeatStartMenu_CreateSprites(void)
{
    u8 action;
    u32 i, spacing, start;

    spacing = (240 - ((sHeatStartMenu.numStartMenuActions - 1) * 24)) / (sHeatStartMenu.numStartMenuActions * 2);
    start = (240 - ((sHeatStartMenu.numStartMenuActions - 1) * (24 + spacing))) / 2;

    for (i = 0; i < sHeatStartMenu.numStartMenuActions; ++i)
    {
        action = sHeatStartMenu.currentStartMenuActions[i];
        sHeatStartMenu.iconSpriteIds[action] = CreateSprite(sHeatStartMenuActions[action].iconTemplate, start + (24 + spacing) * i, 144, 0);
        
        if (sHeatStartMenu.menuCursorPos == i)
            HeatStartMenu_SetIconAnimation(sHeatStartMenu.iconSpriteIds[action], TRUE);
        else
            HeatStartMenu_SetIconAnimation(sHeatStartMenu.iconSpriteIds[action], FALSE);
    }
}

static void HeatStartMenu_LoadBgGfx(void)
{
    u8 *buf = GetBgTilemapBuffer(0);
    LoadBgTilemap(0, 0, 0, 0);
    // DecompressAndCopyTileDataToVram(0, sStartMenuTiles, 0, 0, 0);
    // if (GetSafariZoneFlag() == FALSE) {
    //   LZDecompressWram(sStartMenuTilemap, buf);
    // } else {
    //   LZDecompressWram(sStartMenuTilemapSafari, buf);
    // }
    LoadPalette(gStandardMenuPalette2, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    // LoadPalette(sStartMenuPalette, BG_PLTT_ID(14), PLTT_SIZE_4BPP);

    LoadBgTiles(0, sPokepulseMessageBoxGfx, 0x120, 0x223);
    LoadPalette(sPokepulseMessageBoxPal, BG_PLTT_ID(14), PLTT_SIZE_4BPP);

    ScheduleBgCopyTilemapToVram(0);
}

static const u8 sPokePulseDescTextColors[]  = { TEXT_COLOR_GREEN, TEXT_COLOR_BLUE, TEXT_COLOR_LIGHT_GREEN };

static void HeatStartMenu_ShowTimeWindow(void)
{
    u8 analogHour;

    RtcCalcLocalTime();
    // print window
    sHeatStartMenu.sStartClockWindowId = AddWindow(&sWindowTemplate_StartClock);
    PutWindowTilemap(sHeatStartMenu.sStartClockWindowId);
    CopyWindowToVram(sHeatStartMenu.sStartClockWindowId, COPYWIN_FULL);

    analogHour = (gLocalTime.hours >= 13 && gLocalTime.hours <= 24) ? gLocalTime.hours - 12 : gLocalTime.hours;

    StringCopy(gStringVar3, gDayNameStringsTable[(gLocalTime.days % 7)]);
    ConvertIntToDecimalStringN(gStringVar1, gLocalTime.hours, STR_CONV_MODE_LEADING_ZEROS, 2);
    ConvertIntToDecimalStringN(gStringVar2, gLocalTime.minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    ConvertIntToDecimalStringN(gStringVar1, analogHour, STR_CONV_MODE_LEADING_ZEROS, 2);

    // StringExpandPlaceholders(gStringVar4, gText_CurrentTime);
    if (gLocalTime.hours >= 13 && gLocalTime.hours <= 24)
        StringExpandPlaceholders(gStringVar4, gText_CurrentTimePM);
    else
        StringExpandPlaceholders(gStringVar4, gText_CurrentTimeAM);

    // DrawStdFrameWithCustomTileAndPalette(sHeatStartMenu.sStartClockWindowId, FALSE, 0x223, 14);
    FillWindowPixelBuffer(sHeatStartMenu.sStartClockWindowId, PIXEL_FILL(0));
    AddTextPrinterParameterized2(sHeatStartMenu.sStartClockWindowId, FONT_NORMAL, gStringVar4, 0, NULL, TEXT_COLOR_WHITE, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_TRANSPARENT);

    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(8, 88));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(8, 24));
    SetGpuReg(REG_OFFSET_BLDCNT, GetGpuReg(REG_OFFSET_BLDCNT) | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDY, 7);
}

static u8 HeatStartMenu_CreateMenuNameWindow(void)
{
    u8 windowId = AddWindow(&sWindowTemplate_MenuName);

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);

    DrawStdFrameWithCustomTileAndPalette(windowId, FALSE, 0x223, 14);

    return windowId;
}

static void HeatStartMenu_UpdateMenuName(void)
{
    const u8 *str = sHeatStartMenuActions[sHeatStartMenu.currentStartMenuActions[sHeatStartMenu.menuCursorPos]].name;
    u32 x = GetStringCenterAlignXOffset(FONT_NORMAL, str, 64);

    FillWindowPixelBuffer(sHeatStartMenu.sMenuNameWindowId, PIXEL_FILL(6));
    AddTextPrinterParameterized3(sHeatStartMenu.sMenuNameWindowId, FONT_NORMAL, x, 0, sPokePulseDescTextColors, 0, str);
    // AddTextPrinterParameterized(sHeatStartMenu.sMenuNameWindowId, 1, str, x, 0, 0xFF, NULL);
    // CopyWindowToVram(sHeatStartMenu.sMenuNameWindowId, COPYWIN_GFX);
}

static void HeatStartMenu_FreeResources(void)
{
    u32 i;
    u8 *buf = GetBgTilemapBuffer(0);

    ClearStdWindowAndFrame(sHeatStartMenu.sStartClockWindowId, TRUE);
    ClearStdWindowAndFrame(sHeatStartMenu.sMenuNameWindowId, TRUE);
    RemoveWindow(sHeatStartMenu.sStartClockWindowId);
    RemoveWindow(sHeatStartMenu.sMenuNameWindowId);

    memset(buf, 0, BG_SCREEN_SIZE);
    ScheduleBgCopyTilemapToVram(0);

    for (i = 0; i < sHeatStartMenu.numStartMenuActions; ++i)
    {
        DestroySpriteAndFreeResources(&gSprites[sHeatStartMenu.iconSpriteIds[sHeatStartMenu.currentStartMenuActions[i]]]);
    }

    sHeatStartMenu.numStartMenuActions = 0;

    FreeSpriteTilesByTag(TAG_ICON_GFX);

    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
}

static void HeatStartMenu_MoveSelection(s8 delta)
{
    s8 newPos = sHeatStartMenu.menuCursorPos + delta;
    if (newPos >= sHeatStartMenu.numStartMenuActions) newPos = 0;
    else if (newPos < 0) newPos = sHeatStartMenu.numStartMenuActions - 1;

    if (newPos != sHeatStartMenu.menuCursorPos)
    {
        u32 i;
        sHeatStartMenu.menuCursorPos = newPos;

        for (i = 0; i < sHeatStartMenu.numStartMenuActions; ++i)
            HeatStartMenu_SetIconAnimation(sHeatStartMenu.iconSpriteIds[sHeatStartMenu.currentStartMenuActions[i]], newPos == i);

        HeatStartMenu_UpdateMenuName();
    }
}

static void Task_HeatStartMenu_EraseAfterFade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        HeatStartMenu_FreeResources();
        DestroyTask(taskId);
    }
}

static bool8 Task_HeatStartMenu_HandleMainInput(void)
{
    if (JOY_NEW(B_BUTTON | START_BUTTON))
    {
        PlaySE(SE_SELECT);
        HeatStartMenu_FreeResources();
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        return TRUE;
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        PlaySE(SE_SELECT);
        HeatStartMenu_MoveSelection(-1);
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        PlaySE(SE_SELECT);
        HeatStartMenu_MoveSelection(1);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        sHeatStartMenu.menuCallback = sHeatStartMenuActions[sHeatStartMenu.currentStartMenuActions[sHeatStartMenu.menuCursorPos]].action;
        if (sHeatStartMenuActions[sHeatStartMenu.currentStartMenuActions[sHeatStartMenu.menuCursorPos]].fade)
        {
            FadeScreen(FADE_TO_BLACK, 0);
            CreateTask(Task_HeatStartMenu_EraseAfterFade, 0);
        }
        else
        {
            HeatStartMenu_FreeResources();
        }
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
    }

    return FALSE;
}

// Save porting
enum
{
    SAVE_IN_PROGRESS,
    SAVE_SUCCESS,
    SAVE_CANCELED,
    SAVE_ERROR
};

static EWRAM_DATA u8 (*sSaveDialogCallback)(void) = NULL;
static EWRAM_DATA u8 sSaveDialogTimer = 0;
static EWRAM_DATA u8 sSaveInfoWindowId = 0;

static u8 RunSaveCallback(void);
static u8 SaveDoSaveCallback(void);
static void HideSaveInfoWindow(void);
static void HideSaveMessageWindow(void);
static u8 SaveOverwriteInputCallback(void);
static u8 SaveConfirmOverwriteDefaultNoCallback(void);
static u8 SaveConfirmOverwriteCallback(void);
static void ShowSaveMessage(const u8 *message, u8 (*saveCallback)(void));
static u8 SaveFileExistsCallback(void);
static u8 SaveSavingMessageCallback(void);
static u8 SaveConfirmInputCallback(void);
static u8 SaveYesNoCallback(void);
static void ShowSaveInfoWindow(void);
static u8 SaveConfirmSaveCallback(void);
static void InitSave(void);

static u8 RunSaveCallback(void)
{
    // True if text is still printing
    if (RunTextPrintersAndIsPrinter0Active() == TRUE)
    {
        return SAVE_IN_PROGRESS;
    }

    return sSaveDialogCallback();
}

static void SaveStartTimer(void)
{
    sSaveDialogTimer = 60;
}

static bool8 SaveSuccesTimer(void)
{
    sSaveDialogTimer--;


    if (JOY_HELD(A_BUTTON) || JOY_HELD(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        return TRUE;
    }
    if (sSaveDialogTimer == 0)
    {
        return TRUE;
    }

    return FALSE;
}

static bool8 SaveErrorTimer(void)
{
    if (sSaveDialogTimer != 0)
    {
        sSaveDialogTimer--;
    }
    else if (JOY_HELD(A_BUTTON))
    {
        return TRUE;
    }

    return FALSE;
}

static u8 SaveReturnSuccessCallback(void)
{
    if (!IsSEPlaying() && SaveSuccesTimer())
    {
        HideSaveInfoWindow();
        return SAVE_SUCCESS;
    }
    else
    {
        return SAVE_IN_PROGRESS;
    }
}

static u8 SaveSuccessCallback(void)
{
    if (!IsTextPrinterActive(0))
    {
        PlaySE(SE_SAVE);
        sSaveDialogCallback = SaveReturnSuccessCallback;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveReturnErrorCallback(void)
{
    if (!SaveErrorTimer())
    {
        return SAVE_IN_PROGRESS;
    }
    else
    {
        HideSaveInfoWindow();
        return SAVE_ERROR;
    }
}

static u8 SaveErrorCallback(void)
{
    if (!IsTextPrinterActive(0))
    {
        PlaySE(SE_BOO);
        sSaveDialogCallback = SaveReturnErrorCallback;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveDoSaveCallback(void)
{
    u8 saveStatus;

    IncrementGameStat(GAME_STAT_SAVED_GAME);
    PausePyramidChallenge();

    if (gDifferentSaveFile == TRUE)
    {
        saveStatus = TrySavingData(SAVE_OVERWRITE_DIFFERENT_FILE);
        gDifferentSaveFile = FALSE;
    }
    else
    {
        saveStatus = TrySavingData(SAVE_NORMAL);
    }

    if (saveStatus == SAVE_STATUS_OK)
        ShowSaveMessage(gText_PlayerSavedGame, SaveSuccessCallback);
    else
        ShowSaveMessage(gText_SaveError, SaveErrorCallback);

    SaveStartTimer();
    return SAVE_IN_PROGRESS;
}

static void HideSaveInfoWindow(void) {
  ClearStdWindowAndFrame(sSaveInfoWindowId, FALSE);
  RemoveWindow(sSaveInfoWindowId);
}

static void HideSaveMessageWindow(void) {
  ClearDialogWindowAndFrame(0, TRUE);
}

static u8 SaveOverwriteInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        sSaveDialogCallback = SaveSavingMessageCallback;
        return SAVE_IN_PROGRESS;
    case MENU_B_PRESSED:
    case 1: // No
        HideSaveInfoWindow();
        HideSaveMessageWindow();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmOverwriteDefaultNoCallback(void)
{
    DisplayYesNoMenuWithDefault(1); // Show Yes/No menu (No selected as default)
    sSaveDialogCallback = SaveOverwriteInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmOverwriteCallback(void)
{
    DisplayYesNoMenuDefaultYes(); // Show Yes/No menu
    sSaveDialogCallback = SaveOverwriteInputCallback;
    return SAVE_IN_PROGRESS;
}

static void ShowSaveMessage(const u8 *message, u8 (*saveCallback)(void)) {
    StringExpandPlaceholders(gStringVar4, message);
    LoadMessageBoxAndFrameGfx(0, TRUE);
    AddTextPrinterForMessage_2(TRUE);
    sSaveDialogCallback = saveCallback;
}

static u8 SaveFileExistsCallback(void)
{
    if (gDifferentSaveFile == TRUE)
    {
        ShowSaveMessage(gText_DifferentSaveFile, SaveConfirmOverwriteDefaultNoCallback);
    }
    else
    {
        sSaveDialogCallback = SaveSavingMessageCallback;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveSavingMessageCallback(void) 
{
    ShowSaveMessage(gText_SavingDontTurnOff, SaveDoSaveCallback);
    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        switch (gSaveFileStatus)
        {
        case SAVE_STATUS_EMPTY:
        case SAVE_STATUS_CORRUPT:
            if (gDifferentSaveFile == FALSE)
            {
                sSaveDialogCallback = SaveFileExistsCallback;
                return SAVE_IN_PROGRESS;
            }

            sSaveDialogCallback = SaveSavingMessageCallback;
            return SAVE_IN_PROGRESS;
        default:
            sSaveDialogCallback = SaveFileExistsCallback;
            return SAVE_IN_PROGRESS;
        }
    case MENU_B_PRESSED: // No break, thats smart 
    case 1: // No
        HideSaveInfoWindow();
        HideSaveMessageWindow();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveYesNoCallback(void) 
{
    DisplayYesNoMenuDefaultYes(); // Show Yes/No menu
    sSaveDialogCallback = SaveConfirmInputCallback;
    return SAVE_IN_PROGRESS;
}


static void ShowSaveInfoWindow(void) 
{
    struct WindowTemplate saveInfoWindow = sSaveInfoWindowTemplate;
    u8 gender;
    u8 color;
    u32 xOffset;
    u32 yOffset;
    const u8 *suffix;
    u8 *alignedSuffix = gStringVar3;

    if (!FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        saveInfoWindow.height -= 2;
    }
    
    sSaveInfoWindowId = AddWindow(&saveInfoWindow);
    DrawStdWindowFrame(sSaveInfoWindowId, FALSE);

    gender = gSaveBlock2Ptr->playerGender;
    color = TEXT_COLOR_RED;  // Red when female, blue when male.

    if (gender == MALE)
    {
        color = TEXT_COLOR_BLUE;
    }

    // Print region name
    yOffset = 1;
    BufferSaveMenuText(SAVE_MENU_LOCATION, gStringVar4, TEXT_COLOR_GREEN);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, 0, yOffset, TEXT_SKIP_DRAW, NULL);

    // Print player name
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingPlayer, 0, yOffset, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_NAME, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0x70);
    PrintPlayerNameOnWindow(sSaveInfoWindowId, gStringVar4, xOffset, yOffset);

    // Print badge count
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingBadges, 0, yOffset, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_BADGES, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0x70);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, xOffset, yOffset, TEXT_SKIP_DRAW, NULL);

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
    {
        // Print pokedex count
        yOffset += 16;
        AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingPokedex, 0, yOffset, TEXT_SKIP_DRAW, NULL);
        BufferSaveMenuText(SAVE_MENU_CAUGHT, gStringVar4, color);
        xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0x70);
        AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, xOffset, yOffset, TEXT_SKIP_DRAW, NULL);
    }

    // Print play time
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingTime, 0, yOffset, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_PLAY_TIME, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0x70);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, xOffset, yOffset, TEXT_SKIP_DRAW, NULL);

    CopyWindowToVram(sSaveInfoWindowId, COPYWIN_GFX);
}

static u8 SaveConfirmSaveCallback(void) 
{
    ShowSaveInfoWindow();

    if (InBattlePyramid()) 
        ShowSaveMessage(gText_BattlePyramidConfirmRest, SaveYesNoCallback);
    else 
        ShowSaveMessage(gText_ConfirmSave, SaveYesNoCallback);

    return SAVE_IN_PROGRESS;
}

static void InitSave(void)
{
    SaveMapView();
    sSaveDialogCallback = SaveConfirmSaveCallback;
}

static void Task_HandleSave(u8 taskId) {
    switch (RunSaveCallback()) 
    {
    case SAVE_IN_PROGRESS:
        break;
    case SAVE_CANCELED: // Back to start menu
        ClearDialogWindowAndFrameToTransparent(0, FALSE);
        HeatStartMenu_QuickInit();
        DestroyTask(taskId);
        break;
    case SAVE_SUCCESS:
    case SAVE_ERROR:    // Close start menu
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        SoftResetInBattlePyramid();
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        DestroyTask(taskId);
        break;
    }
}

static bool8 StartMenuSaveCallback(void) 
{
    LockPlayerFieldControls();
    FreezeObjectEvents();
    LoadUserWindowBorderGfx(sSaveInfoWindowId, 0x214, 0xE0);
    InitSave();
    CreateTask(Task_HandleSave, 0x80);
    return TRUE;
}
