#include "global.h"
#include "graphics.h"
#include "palette.h"
#include "util.h"
#include "battle_transition.h"
#include "task.h"
#include "battle_transition.h"
#include "fieldmap.h"

static EWRAM_DATA struct {
    const u16 *src;
    u16 *dest;
    u16 size;
} sTilesetDMA3TransferBuffer[20] = {0};

static u8 sTilesetDMA3TransferBufferSize;
static u16 sPrimaryTilesetAnimCounter;
static u16 sPrimaryTilesetAnimCounterMax;
static u16 sSecondaryTilesetAnimCounter;
static u16 sSecondaryTilesetAnimCounterMax;
static void (*sPrimaryTilesetAnimCallback)(u16);
static void (*sSecondaryTilesetAnimCallback)(u16);

static void _InitPrimaryTilesetAnimation(void);
static void _InitSecondaryTilesetAnimation(void);
static void TilesetAnim_General(u16);
static void TilesetAnim_Building(u16);
static void TilesetAnim_Petalburg(u16);
static void TilesetAnim_Dewford(u16);
static void TilesetAnim_Slateport(u16);
static void TilesetAnim_Mauville(u16);
static void TilesetAnim_Lavaridge(u16);
static void TilesetAnim_EverGrande(u16);
static void TilesetAnim_Pacifidlog(u16);
static void TilesetAnim_Sootopolis(u16);
static void TilesetAnim_BattleFrontierOutsideWest(u16);
static void TilesetAnim_BattleFrontierOutsideEast(u16);
static void TilesetAnim_Underwater(u16);
static void TilesetAnim_SootopolisGym(u16);
static void TilesetAnim_Cave(u16);
static void TilesetAnim_EliteFour(u16);
//static void TilesetAnim_MauvilleGym(u16);
static void TilesetAnim_BikeShop(u16);
static void TilesetAnim_BattlePyramid(u16);
static void TilesetAnim_BattleDome(u16);
static void TilesetAnim_BattleTent(u16);
static void TilesetAnim_GenericBuilding(u16);
static void TilesetAnim_RustboroGym(u16);
static void TilesetAnim_Rustboro(u16);
static void TilesetAnim_PokemonCenter(u16);
static void TilesetAnim_Lilycove(u16);
static void TilesetAnim_Fallarbor(u16);
static void QueueAnimTiles_General_Flower(u16);
static void QueueAnimTiles_General_WhiteFlower(u16);
static void QueueAnimTiles_General_Water(u16);
static void QueueAnimTiles_General_MainWater(u16);
static void QueueAnimTiles_General_PondWaterEdge(u16);
static void QueueAnimTiles_General_PondWaterSide(u16);
static void QueueAnimTiles_General_PondWaterTop(u16);
static void QueueAnimTiles_General_SandWaterEdge(u16);
//static void QueueAnimTiles_General_Sea(u16);
static void QueueAnimTiles_General_Waterfall(u16);
static void QueueAnimTiles_General_WaterfallBottom(u16);
static void QueueAnimTiles_General_LandWaterEdge(u16);
static void QueueAnimTiles_General_WeedT(u16);
static void QueueAnimTiles_General_WeedNT(u16);
static void QueueAnimTiles_Building_TVTurnedOn(u16);
static void QueueAnimTiles_Dewford_Flag(u16);
static void QueueAnimTiles_Slateport_Balloons(u16);
static void QueueAnimTiles_Slateport_Water0(u16);
static void QueueAnimTiles_Slateport_Water1(u16);
static void QueueAnimTiles_Slateport_Water2(u16);
static void QueueAnimTiles_Slateport_Water3(u16);
static void QueueAnimTiles_Slateport_Water4(u16);
static void QueueAnimTiles_Slateport_Water5(u16);
static void QueueAnimTiles_Slateport_Water6(u16);
static void QueueAnimTiles_Slateport_Water7(u16);
static void QueueAnimTiles_Slateport_Water8(u16);
static void QueueAnimTiles_Slateport_Water9(u16);
static void QueueAnimTiles_Slateport_SmallRockTop(u16);
static void QueueAnimTiles_Slateport_SmallRockBottom(u16);
static void QueueAnimTiles_Mauville_Flowers(u16, u8);
static void QueueAnimTiles_BikeShop_BlinkingLights(u16);
static void QueueAnimTiles_GenericBuilding_SunBeams(u16);
static void QueueAnimTiles_GenericBuilding_Water0(u16);
static void QueueAnimTiles_GenericBuilding_Water1(u16);
static void QueueAnimTiles_GenericBuilding_Water2(u16);
static void QueueAnimTiles_GenericBuilding_Water3(u16);
static void QueueAnimTiles_GenericBuilding_Water4(u16);
static void QueueAnimTiles_GenericBuilding_Water5(u16);
static void QueueAnimTiles_GenericBuilding_Water6(u16);
static void QueueAnimTiles_GenericBuilding_Water7(u16);
static void QueueAnimTiles_GenericBuilding_Water8(u16);
static void QueueAnimTiles_GenericBuilding_Water9(u16);
static void QueueAnimTiles_GenericBuilding_BigRock(u16);
static void QueueAnimTiles_GenericBuilding_SmallRockTop(u16);
static void QueueAnimTiles_GenericBuilding_SmallRockBottom(u16);
static void QueueAnimTiles_GenericBuilding_Wood(u16);
static void QueueAnimTiles_GenericBuilding_Rapid(u16);
static void QueueAnimTiles_BattlePyramid_Torch(u16);
static void QueueAnimTiles_BattlePyramid_StatueShadow(u16);
static void QueueAnimTiles_RustboroGym_Water0(u16);
static void QueueAnimTiles_RustboroGym_Water1(u16);
static void QueueAnimTiles_RustboroGym_Water2(u16);
static void QueueAnimTiles_RustboroGym_Water3(u16);
static void QueueAnimTiles_RustboroGym_Water4(u16);
static void QueueAnimTiles_RustboroGym_Water5(u16);
static void QueueAnimTiles_RustboroGym_Water6(u16);
static void QueueAnimTiles_RustboroGym_Water7(u16);
static void QueueAnimTiles_RustboroGym_Water8(u16);
static void QueueAnimTiles_RustboroGym_Water9(u16);
static void QueueAnimTiles_RustboroGym_GreenBeams(u16);
static void QueueAnimTiles_RustboroGym_GreyBeams(u16);
static void QueueAnimTiles_RustboroGym_Weed(u16);
static void QueueAnimTiles_RustboroGym_Rapid(u16);
static void QueueAnimTiles_PokemonCenter_Map(u16);
static void QueueAnimTiles_PokemonCenter_Stripe(u16);
static void QueueAnimTiles_Lilycove_Flag(u16);
static void QueueAnimTiles_Fallarbor_Campfire(u16);
static void QueueAnimTiles_Fallarbor_Smoke(u16);
static void BlendAnimPalette_BattleDome_FloorLights(u16);
static void BlendAnimPalette_BattleDome_FloorLightsNoBlend(u16);
//static void QueueAnimTiles_Lavaridge_Steam(u8);
//static void QueueAnimTiles_Lavaridge_Lava(u16);
static void QueueAnimTiles_EverGrande_Flowers(u16, u8);
static void QueueAnimTiles_Pacifidlog_LogBridges(u8);
static void QueueAnimTiles_Pacifidlog_WaterCurrents(u8);
static void QueueAnimTiles_Petalburg_Chimney_Smoke(u16);
static void QueueAnimTiles_Rustboro_Chimney_Smoke(u16);
static void QueueAnimTiles_Petalburg_Watermill1(u16);
static void QueueAnimTiles_Petalburg_Watermill2(u16);
static void QueueAnimTiles_Petalburg_Watermill3(u16);
static void QueueAnimTiles_Petalburg_Watermill4(u16);
static void QueueAnimTiles_Petalburg_Watermill5(u16);
static void QueueAnimTiles_Petalburg_Watermill6(u16);
static void QueueAnimTiles_Petalburg_Watermill7(u16);
static void QueueAnimTiles_Petalburg_Watermill8(u16);
static void QueueAnimTiles_Petalburg_Watermill9(u16);
static void QueueAnimTiles_Petalburg_Watermill10(u16);
static void QueueAnimTiles_Dewford_Turbine1(u16);
static void QueueAnimTiles_Dewford_Turbine2(u16);
static void QueueAnimTiles_Dewford_Turbine3(u16);
static void QueueAnimTiles_Dewford_Turbine4(u16);
static void QueueAnimTiles_Dewford_Turbine5(u16);
static void QueueAnimTiles_Dewford_Turbine6(u16);
static void QueueAnimTiles_Dewford_Flower(u16);
static void QueueAnimTiles_Dewford_Sunflower1(u16);
static void QueueAnimTiles_Dewford_Sunflower2(u16);
static void QueueAnimTiles_Sootopolis_StormyWater(u16);
static void QueueAnimTiles_Underwater_Seaweed(u8);
//static void QueueAnimTiles_Cave_Lava(u16);
static void QueueAnimTiles_BattleFrontierOutsideWest_Flag(u16);
static void QueueAnimTiles_BattleFrontierOutsideEast_Flag(u16);
static void QueueAnimTiles_BattleTent_Tv_Ten(u16);
static void QueueAnimTiles_BattleTent_Tv_Poke(u16);
static void QueueAnimTiles_BattleTent_Tv_Trainer(u16);
static void QueueAnimTiles_BattleTent_Tv_Drowzee(u16);
static void QueueAnimTiles_BattleTent_Tv_Cliff(u16);
//static void QueueAnimTiles_MauvilleGym_ElectricGates(u16);
static void QueueAnimTiles_SootopolisGym_Waterfalls(u16);
static void QueueAnimTiles_EliteFour_GroundLights(u16);
static void QueueAnimTiles_EliteFour_WallLights(u16);

const u16 gTilesetAnims_General_Flower_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/0.4bpp");
const u16 gTilesetAnims_General_Flower_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/1.4bpp");
const u16 gTilesetAnims_General_Flower_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/2.4bpp");
const u16 gTilesetAnims_General_Flower_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/flower/3.4bpp");
const u16 tileset_anims_space_0[16] = {};

const u16 *const gTilesetAnims_General_Flower[] = {
    gTilesetAnims_General_Flower_Frame0,
    gTilesetAnims_General_Flower_Frame1,
    gTilesetAnims_General_Flower_Frame2,
    gTilesetAnims_General_Flower_Frame3
};

const u16 gTilesetAnims_General_WhiteFlower_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/white_flower/0.4bpp");
const u16 gTilesetAnims_General_WhiteFlower_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/white_flower/1.4bpp");

const u16 *const gTilesetAnims_General_WhiteFlower[] = {
    gTilesetAnims_General_WhiteFlower_Frame0,
    gTilesetAnims_General_WhiteFlower_Frame1
};

const u16 gTilesetAnims_General_MainWater_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/main_water/0.4bpp");
const u16 gTilesetAnims_General_MainWater_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/main_water/1.4bpp");
const u16 gTilesetAnims_General_MainWater_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/main_water/2.4bpp");
const u16 gTilesetAnims_General_MainWater_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/main_water/3.4bpp");
const u16 gTilesetAnims_General_MainWater_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/main_water/4.4bpp");
const u16 gTilesetAnims_General_MainWater_Frame5[] = INCBIN_U16("data/tilesets/primary/general/anim/main_water/5.4bpp");
const u16 gTilesetAnims_General_MainWater_Frame6[] = INCBIN_U16("data/tilesets/primary/general/anim/main_water/6.4bpp");
const u16 gTilesetAnims_General_MainWater_Frame7[] = INCBIN_U16("data/tilesets/primary/general/anim/main_water/7.4bpp");

const u16 *const gTilesetAnims_General_MainWater[] = {
    gTilesetAnims_General_MainWater_Frame0,
    gTilesetAnims_General_MainWater_Frame1,
    gTilesetAnims_General_MainWater_Frame2,
    gTilesetAnims_General_MainWater_Frame3,
    gTilesetAnims_General_MainWater_Frame4,
    gTilesetAnims_General_MainWater_Frame5,
    gTilesetAnims_General_MainWater_Frame6,
    gTilesetAnims_General_MainWater_Frame7
};

const u16 gTilesetAnims_General_Water_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/water/0.4bpp");
const u16 gTilesetAnims_General_Water_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/water/1.4bpp");
const u16 gTilesetAnims_General_Water_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/water/2.4bpp");
const u16 gTilesetAnims_General_Water_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/water/3.4bpp");

const u16 *const gTilesetAnims_General_Water[] = {
    gTilesetAnims_General_Water_Frame0,
    gTilesetAnims_General_Water_Frame1,
    gTilesetAnims_General_Water_Frame2,
    gTilesetAnims_General_Water_Frame3
};

const u16 gTilesetAnims_General_PondWaterEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_edge/0.4bpp");
const u16 gTilesetAnims_General_PondWaterEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_edge/1.4bpp");

const u16 *const gTilesetAnims_General_PondWaterEdge[] = {
    gTilesetAnims_General_PondWaterEdge_Frame0,
    gTilesetAnims_General_PondWaterEdge_Frame1
};

const u16 gTilesetAnims_General_PondWaterSide_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_side/0.4bpp");
const u16 gTilesetAnims_General_PondWaterSide_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_side/1.4bpp");
const u16 gTilesetAnims_General_PondWaterSide_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_side/2.4bpp");
const u16 gTilesetAnims_General_PondWaterSide_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_side/3.4bpp");
const u16 gTilesetAnims_General_PondWaterSide_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_side/4.4bpp");
const u16 gTilesetAnims_General_PondWaterSide_Frame5[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_side/5.4bpp");
const u16 gTilesetAnims_General_PondWaterSide_Frame6[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_side/6.4bpp");
const u16 gTilesetAnims_General_PondWaterSide_Frame7[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_side/7.4bpp");

const u16 *const gTilesetAnims_General_PondWaterSide[] = {
    gTilesetAnims_General_PondWaterSide_Frame0,
    gTilesetAnims_General_PondWaterSide_Frame1,
    gTilesetAnims_General_PondWaterSide_Frame2,
    gTilesetAnims_General_PondWaterSide_Frame3,
    gTilesetAnims_General_PondWaterSide_Frame4,
    gTilesetAnims_General_PondWaterSide_Frame5,
    gTilesetAnims_General_PondWaterSide_Frame6,
    gTilesetAnims_General_PondWaterSide_Frame7
};

const u16 gTilesetAnims_General_PondWaterTop_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_top/0.4bpp");
const u16 gTilesetAnims_General_PondWaterTop_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_top/1.4bpp");
const u16 gTilesetAnims_General_PondWaterTop_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_top/2.4bpp");
const u16 gTilesetAnims_General_PondWaterTop_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_top/3.4bpp");
const u16 gTilesetAnims_General_PondWaterTop_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_top/4.4bpp");
const u16 gTilesetAnims_General_PondWaterTop_Frame5[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_top/5.4bpp");
const u16 gTilesetAnims_General_PondWaterTop_Frame6[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_top/6.4bpp");
const u16 gTilesetAnims_General_PondWaterTop_Frame7[] = INCBIN_U16("data/tilesets/primary/general/anim/pond_water_top/7.4bpp");

const u16 *const gTilesetAnims_General_PondWaterTop[] = {
    gTilesetAnims_General_PondWaterTop_Frame0,
    gTilesetAnims_General_PondWaterTop_Frame1,
    gTilesetAnims_General_PondWaterTop_Frame2,
    gTilesetAnims_General_PondWaterTop_Frame3,
    gTilesetAnims_General_PondWaterTop_Frame4,
    gTilesetAnims_General_PondWaterTop_Frame5,
    gTilesetAnims_General_PondWaterTop_Frame6,
    gTilesetAnims_General_PondWaterTop_Frame7
};

const u16 gTilesetAnims_General_SandWaterEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/sand_water_edge/0.4bpp");
const u16 gTilesetAnims_General_SandWaterEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/sand_water_edge/1.4bpp");
const u16 gTilesetAnims_General_SandWaterEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/sand_water_edge/2.4bpp");
const u16 gTilesetAnims_General_SandWaterEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/sand_water_edge/3.4bpp");
const u16 gTilesetAnims_General_SandWaterEdge_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/sand_water_edge/4.4bpp");
const u16 gTilesetAnims_General_SandWaterEdge_Frame5[] = INCBIN_U16("data/tilesets/primary/general/anim/sand_water_edge/5.4bpp");
const u16 gTilesetAnims_General_SandWaterEdge_Frame6[] = INCBIN_U16("data/tilesets/primary/general/anim/sand_water_edge/6.4bpp");

const u16 *const gTilesetAnims_General_SandWaterEdge[] = {
    gTilesetAnims_General_SandWaterEdge_Frame0,
    gTilesetAnims_General_SandWaterEdge_Frame1,
    gTilesetAnims_General_SandWaterEdge_Frame2,
    gTilesetAnims_General_SandWaterEdge_Frame3,
    gTilesetAnims_General_SandWaterEdge_Frame4,
    gTilesetAnims_General_SandWaterEdge_Frame5,
    gTilesetAnims_General_SandWaterEdge_Frame6,
    gTilesetAnims_General_SandWaterEdge_Frame0
};

/*const u16 gTilesetAnims_General_Sea_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/sea/sea_anim_0.4bpp");
const u16 gTilesetAnims_General_Sea_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/sea/sea_anim_1.4bpp");
const u16 gTilesetAnims_General_Sea_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/sea/sea_anim_2.4bpp");
const u16 gTilesetAnims_General_Sea_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/sea/sea_anim_3.4bpp");
const u16 gTilesetAnims_General_Sea_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/sea/sea_anim_4.4bpp");
const u16 gTilesetAnims_General_Sea_Frame5[] = INCBIN_U16("data/tilesets/primary/general/anim/sea/sea_anim_5.4bpp");
const u16 gTilesetAnims_General_Sea_Frame6[] = INCBIN_U16("data/tilesets/primary/general/anim/sea/sea_anim_6.4bpp");
const u16 gTilesetAnims_General_Sea_Frame7[] = INCBIN_U16("data/tilesets/primary/general/anim/sea/sea_anim_7.4bpp");

const u16 *const gTilesetAnims_General_Sea[] = {
    gTilesetAnims_General_Sea_Frame0,
    gTilesetAnims_General_Sea_Frame1,
    gTilesetAnims_General_Sea_Frame2,
    gTilesetAnims_General_Sea_Frame3,
    gTilesetAnims_General_Sea_Frame4,
    gTilesetAnims_General_Sea_Frame5,
    gTilesetAnims_General_Sea_Frame6,
    gTilesetAnims_General_Sea_Frame7
};*/

const u16 gTilesetAnims_General_Waterfall_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/waterfall/0.4bpp");
const u16 gTilesetAnims_General_Waterfall_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/waterfall/1.4bpp");
const u16 gTilesetAnims_General_Waterfall_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/waterfall/2.4bpp");
const u16 gTilesetAnims_General_Waterfall_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/waterfall/3.4bpp");
const u16 gTilesetAnims_General_Waterfall_Frame4[] = INCBIN_U16("data/tilesets/primary/general/anim/waterfall/4.4bpp");
const u16 gTilesetAnims_General_Waterfall_Frame5[] = INCBIN_U16("data/tilesets/primary/general/anim/waterfall/5.4bpp");
const u16 gTilesetAnims_General_Waterfall_Frame6[] = INCBIN_U16("data/tilesets/primary/general/anim/waterfall/6.4bpp");
const u16 gTilesetAnims_General_Waterfall_Frame7[] = INCBIN_U16("data/tilesets/primary/general/anim/waterfall/7.4bpp");
const u16 gTilesetAnims_General_Waterfall_Frame8[] = INCBIN_U16("data/tilesets/primary/general/anim/waterfall/8.4bpp");

const u16 *const gTilesetAnims_General_Waterfall[] = {
    gTilesetAnims_General_Waterfall_Frame0,
    gTilesetAnims_General_Waterfall_Frame1,
    gTilesetAnims_General_Waterfall_Frame2,
    gTilesetAnims_General_Waterfall_Frame3,
    gTilesetAnims_General_Waterfall_Frame4,
    gTilesetAnims_General_Waterfall_Frame5,
    gTilesetAnims_General_Waterfall_Frame6,
    gTilesetAnims_General_Waterfall_Frame7,
    gTilesetAnims_General_Waterfall_Frame8
};

const u16 gTilesetAnims_General_WaterfallBottom_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/waterfall_bottom/0.4bpp");
const u16 gTilesetAnims_General_WaterfallBottom_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/waterfall_bottom/1.4bpp");
const u16 gTilesetAnims_General_WaterfallBottom_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/waterfall_bottom/2.4bpp");
const u16 gTilesetAnims_General_WaterfallBottom_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/waterfall_bottom/3.4bpp");

const u16 *const gTilesetAnims_General_WaterfallBottom[] = {
    gTilesetAnims_General_WaterfallBottom_Frame0,
    gTilesetAnims_General_WaterfallBottom_Frame1,
    gTilesetAnims_General_WaterfallBottom_Frame2,
    gTilesetAnims_General_WaterfallBottom_Frame3
};

const u16 gTilesetAnims_General_LandWaterEdge_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/land_water_edge/0.4bpp");
const u16 gTilesetAnims_General_LandWaterEdge_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/land_water_edge/1.4bpp");
const u16 gTilesetAnims_General_LandWaterEdge_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/land_water_edge/2.4bpp");
const u16 gTilesetAnims_General_LandWaterEdge_Frame3[] = INCBIN_U16("data/tilesets/primary/general/anim/land_water_edge/3.4bpp");

const u16 *const gTilesetAnims_General_LandWaterEdge[] = {
    gTilesetAnims_General_LandWaterEdge_Frame0,
    gTilesetAnims_General_LandWaterEdge_Frame1,
    gTilesetAnims_General_LandWaterEdge_Frame2,
    gTilesetAnims_General_LandWaterEdge_Frame3
};

const u16 gTilesetAnims_General_WeedT_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/weed-t/weed-frame-t-0.4bpp");
const u16 gTilesetAnims_General_WeedT_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/weed-t/weed-frame-t-1.4bpp");
const u16 gTilesetAnims_General_WeedT_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/weed-t/weed-frame-t-2.4bpp");

const u16 *const gTilesetAnims_General_WeedT[] = {
    gTilesetAnims_General_WeedT_Frame0,
    gTilesetAnims_General_WeedT_Frame1,
    gTilesetAnims_General_WeedT_Frame2,
    gTilesetAnims_General_WeedT_Frame1
};

const u16 gTilesetAnims_General_WeedNT_Frame0[] = INCBIN_U16("data/tilesets/primary/general/anim/weed-nt/weed-frame-0.4bpp");
const u16 gTilesetAnims_General_WeedNT_Frame1[] = INCBIN_U16("data/tilesets/primary/general/anim/weed-nt/weed-frame-1.4bpp");
const u16 gTilesetAnims_General_WeedNT_Frame2[] = INCBIN_U16("data/tilesets/primary/general/anim/weed-nt/weed-frame-2.4bpp");

const u16 *const gTilesetAnims_General_WeedNT[] = {
    gTilesetAnims_General_WeedNT_Frame0,
    gTilesetAnims_General_WeedNT_Frame1,
    gTilesetAnims_General_WeedNT_Frame2,
    gTilesetAnims_General_WeedNT_Frame1
};

const u16 gTilesetAnims_GenericBuilding_SunBeams_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/sun_beams/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_SunBeams_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/sun_beams/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_SunBeams_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/sun_beams/2.4bpp");
const u16 gTilesetAnims_GenericBuilding_SunBeams_Frame3[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/sun_beams/3.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_SunBeams[] = {
    gTilesetAnims_GenericBuilding_SunBeams_Frame0,
    gTilesetAnims_GenericBuilding_SunBeams_Frame1,
    gTilesetAnims_GenericBuilding_SunBeams_Frame2,
    gTilesetAnims_GenericBuilding_SunBeams_Frame3
};

const u16 gTilesetAnims_GenericBuilding_Water0_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/0/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water0_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/0/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water0_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/0/2.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_Water0[] = {
    gTilesetAnims_GenericBuilding_Water0_Frame0,
    gTilesetAnims_GenericBuilding_Water0_Frame1,
    gTilesetAnims_GenericBuilding_Water0_Frame2,
    gTilesetAnims_GenericBuilding_Water0_Frame1
};

const u16 gTilesetAnims_GenericBuilding_Water1_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/1/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water1_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/1/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water1_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/1/2.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_Water1[] = {
    gTilesetAnims_GenericBuilding_Water1_Frame0,
    gTilesetAnims_GenericBuilding_Water1_Frame1,
    gTilesetAnims_GenericBuilding_Water1_Frame2,
    gTilesetAnims_GenericBuilding_Water1_Frame1
};

const u16 gTilesetAnims_GenericBuilding_Water2_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/2/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water2_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/2/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water2_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/2/2.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_Water2[] = {
    gTilesetAnims_GenericBuilding_Water2_Frame0,
    gTilesetAnims_GenericBuilding_Water2_Frame1,
    gTilesetAnims_GenericBuilding_Water2_Frame2,
    gTilesetAnims_GenericBuilding_Water2_Frame1
};

const u16 gTilesetAnims_GenericBuilding_Water3_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/3/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water3_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/3/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water3_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/3/2.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_Water3[] = {
    gTilesetAnims_GenericBuilding_Water3_Frame0,
    gTilesetAnims_GenericBuilding_Water3_Frame1,
    gTilesetAnims_GenericBuilding_Water3_Frame2,
    gTilesetAnims_GenericBuilding_Water3_Frame1
};

const u16 gTilesetAnims_GenericBuilding_Water4_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/4/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water4_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/4/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water4_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/4/2.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_Water4[] = {
    gTilesetAnims_GenericBuilding_Water4_Frame0,
    gTilesetAnims_GenericBuilding_Water4_Frame1,
    gTilesetAnims_GenericBuilding_Water4_Frame2,
    gTilesetAnims_GenericBuilding_Water4_Frame1
};

const u16 gTilesetAnims_GenericBuilding_Water5_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/5/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water5_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/5/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water5_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/5/2.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_Water5[] = {
    gTilesetAnims_GenericBuilding_Water5_Frame0,
    gTilesetAnims_GenericBuilding_Water5_Frame1,
    gTilesetAnims_GenericBuilding_Water5_Frame2,
    gTilesetAnims_GenericBuilding_Water5_Frame1
};

const u16 gTilesetAnims_GenericBuilding_Water6_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/6/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water6_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/6/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water6_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/6/2.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_Water6[] = {
    gTilesetAnims_GenericBuilding_Water6_Frame0,
    gTilesetAnims_GenericBuilding_Water6_Frame1,
    gTilesetAnims_GenericBuilding_Water6_Frame2,
    gTilesetAnims_GenericBuilding_Water6_Frame1
};

const u16 gTilesetAnims_GenericBuilding_Water7_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/7/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water7_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/7/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water7_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/7/2.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_Water7[] = {
    gTilesetAnims_GenericBuilding_Water7_Frame0,
    gTilesetAnims_GenericBuilding_Water7_Frame1,
    gTilesetAnims_GenericBuilding_Water7_Frame2,
    gTilesetAnims_GenericBuilding_Water7_Frame1
};

const u16 gTilesetAnims_GenericBuilding_Water8_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/8/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water8_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/8/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water8_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/8/2.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_Water8[] = {
    gTilesetAnims_GenericBuilding_Water8_Frame0,
    gTilesetAnims_GenericBuilding_Water8_Frame1,
    gTilesetAnims_GenericBuilding_Water8_Frame2,
    gTilesetAnims_GenericBuilding_Water8_Frame1
};

const u16 gTilesetAnims_GenericBuilding_Water9_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/9/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water9_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/9/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_Water9_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/9/2.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_Water9[] = {
    gTilesetAnims_GenericBuilding_Water9_Frame0,
    gTilesetAnims_GenericBuilding_Water9_Frame1,
    gTilesetAnims_GenericBuilding_Water9_Frame2,
    gTilesetAnims_GenericBuilding_Water9_Frame1
};

const u16 gTilesetAnims_GenericBuilding_BigRock_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/big_rock/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_BigRock_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/big_rock/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_BigRock_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/big_rock/2.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_BigRock[] = {
    gTilesetAnims_GenericBuilding_BigRock_Frame0,
    gTilesetAnims_GenericBuilding_BigRock_Frame1,
    gTilesetAnims_GenericBuilding_BigRock_Frame2,
    gTilesetAnims_GenericBuilding_BigRock_Frame1
};

const u16 gTilesetAnims_GenericBuilding_SmallRockTop_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/small_rock_top/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_SmallRockTop_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/small_rock_top/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_SmallRockTop_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/small_rock_top/2.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_SmallRockTop[] = {
    gTilesetAnims_GenericBuilding_SmallRockTop_Frame0,
    gTilesetAnims_GenericBuilding_SmallRockTop_Frame1,
    gTilesetAnims_GenericBuilding_SmallRockTop_Frame2,
    gTilesetAnims_GenericBuilding_SmallRockTop_Frame1
};

const u16 gTilesetAnims_GenericBuilding_SmallRockBottom_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/small_rock_bottom/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_SmallRockBottom_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/small_rock_bottom/1.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_SmallRockBottom[] = {
    gTilesetAnims_GenericBuilding_SmallRockBottom_Frame0,
    gTilesetAnims_GenericBuilding_SmallRockBottom_Frame1
};

const u16 gTilesetAnims_GenericBuilding_Wood_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/wood/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_Wood_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/wood/1.4bpp");
const u16 gTilesetAnims_GenericBuilding_Wood_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/wood/2.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_Wood[] = {
    gTilesetAnims_GenericBuilding_Wood_Frame0,
    gTilesetAnims_GenericBuilding_Wood_Frame1
};

const u16 gTilesetAnims_GenericBuilding_Rapid_Frame0[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/rapid/0.4bpp");
const u16 gTilesetAnims_GenericBuilding_Rapid_Frame1[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/rapid/1.4bpp");

const u16 *const gTilesetAnims_GenericBuilding_Rapid[] = {
    gTilesetAnims_GenericBuilding_Rapid_Frame0,
    gTilesetAnims_GenericBuilding_Rapid_Frame1
};

const u16 gTilesetAnims_RustboroGym_Water0_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/0/0.4bpp");
const u16 gTilesetAnims_RustboroGym_Water0_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/0/1.4bpp");
const u16 gTilesetAnims_RustboroGym_Water0_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/0/2.4bpp");

const u16 *const gTilesetAnims_RustboroGym_Water0[] = {
    gTilesetAnims_RustboroGym_Water0_Frame0,
    gTilesetAnims_RustboroGym_Water0_Frame1,
    gTilesetAnims_RustboroGym_Water0_Frame2,
    gTilesetAnims_RustboroGym_Water0_Frame1
};

const u16 gTilesetAnims_RustboroGym_Water1_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/1/0.4bpp");
const u16 gTilesetAnims_RustboroGym_Water1_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/1/1.4bpp");
const u16 gTilesetAnims_RustboroGym_Water1_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/1/2.4bpp");

const u16 *const gTilesetAnims_RustboroGym_Water1[] = {
    gTilesetAnims_RustboroGym_Water1_Frame0,
    gTilesetAnims_RustboroGym_Water1_Frame1,
    gTilesetAnims_RustboroGym_Water1_Frame2,
    gTilesetAnims_RustboroGym_Water1_Frame1
};

const u16 gTilesetAnims_RustboroGym_Water2_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/2/0.4bpp");
const u16 gTilesetAnims_RustboroGym_Water2_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/2/1.4bpp");
const u16 gTilesetAnims_RustboroGym_Water2_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/2/2.4bpp");

const u16 *const gTilesetAnims_RustboroGym_Water2[] = {
    gTilesetAnims_RustboroGym_Water2_Frame0,
    gTilesetAnims_RustboroGym_Water2_Frame1,
    gTilesetAnims_RustboroGym_Water2_Frame2,
    gTilesetAnims_RustboroGym_Water2_Frame1
};

const u16 gTilesetAnims_RustboroGym_Water3_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/3/0.4bpp");
const u16 gTilesetAnims_RustboroGym_Water3_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/3/1.4bpp");
const u16 gTilesetAnims_RustboroGym_Water3_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/3/2.4bpp");

const u16 *const gTilesetAnims_RustboroGym_Water3[] = {
    gTilesetAnims_RustboroGym_Water3_Frame0,
    gTilesetAnims_RustboroGym_Water3_Frame1,
    gTilesetAnims_RustboroGym_Water3_Frame2,
    gTilesetAnims_RustboroGym_Water3_Frame1
};

const u16 gTilesetAnims_RustboroGym_Water4_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/4/0.4bpp");
const u16 gTilesetAnims_RustboroGym_Water4_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/4/1.4bpp");
const u16 gTilesetAnims_RustboroGym_Water4_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/4/2.4bpp");

const u16 *const gTilesetAnims_RustboroGym_Water4[] = {
    gTilesetAnims_RustboroGym_Water4_Frame0,
    gTilesetAnims_RustboroGym_Water4_Frame1,
    gTilesetAnims_RustboroGym_Water4_Frame2,
    gTilesetAnims_RustboroGym_Water4_Frame1
};

const u16 gTilesetAnims_RustboroGym_Water5_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/5/0.4bpp");
const u16 gTilesetAnims_RustboroGym_Water5_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/5/1.4bpp");
const u16 gTilesetAnims_RustboroGym_Water5_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/5/2.4bpp");

const u16 *const gTilesetAnims_RustboroGym_Water5[] = {
    gTilesetAnims_RustboroGym_Water5_Frame0,
    gTilesetAnims_RustboroGym_Water5_Frame1,
    gTilesetAnims_RustboroGym_Water5_Frame2,
    gTilesetAnims_RustboroGym_Water5_Frame1
};

const u16 gTilesetAnims_RustboroGym_Water6_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/6/0.4bpp");
const u16 gTilesetAnims_RustboroGym_Water6_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/6/1.4bpp");
const u16 gTilesetAnims_RustboroGym_Water6_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/6/2.4bpp");

const u16 *const gTilesetAnims_RustboroGym_Water6[] = {
    gTilesetAnims_RustboroGym_Water6_Frame0,
    gTilesetAnims_RustboroGym_Water6_Frame1,
    gTilesetAnims_RustboroGym_Water6_Frame2,
    gTilesetAnims_RustboroGym_Water6_Frame1
};

const u16 gTilesetAnims_RustboroGym_Water7_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/7/0.4bpp");
const u16 gTilesetAnims_RustboroGym_Water7_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/7/1.4bpp");
const u16 gTilesetAnims_RustboroGym_Water7_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/7/2.4bpp");

const u16 *const gTilesetAnims_RustboroGym_Water7[] = {
    gTilesetAnims_RustboroGym_Water7_Frame0,
    gTilesetAnims_RustboroGym_Water7_Frame1,
    gTilesetAnims_RustboroGym_Water7_Frame2,
    gTilesetAnims_RustboroGym_Water7_Frame1
};

const u16 gTilesetAnims_RustboroGym_Water8_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/8/0.4bpp");
const u16 gTilesetAnims_RustboroGym_Water8_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/8/1.4bpp");
const u16 gTilesetAnims_RustboroGym_Water8_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/8/2.4bpp");

const u16 *const gTilesetAnims_RustboroGym_Water8[] = {
    gTilesetAnims_RustboroGym_Water8_Frame0,
    gTilesetAnims_RustboroGym_Water8_Frame1,
    gTilesetAnims_RustboroGym_Water8_Frame2,
    gTilesetAnims_RustboroGym_Water8_Frame1
};

const u16 gTilesetAnims_RustboroGym_Water9_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/9/0.4bpp");
const u16 gTilesetAnims_RustboroGym_Water9_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/9/1.4bpp");
const u16 gTilesetAnims_RustboroGym_Water9_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/9/2.4bpp");

const u16 *const gTilesetAnims_RustboroGym_Water9[] = {
    gTilesetAnims_RustboroGym_Water9_Frame0,
    gTilesetAnims_RustboroGym_Water9_Frame1,
    gTilesetAnims_RustboroGym_Water9_Frame2,
    gTilesetAnims_RustboroGym_Water9_Frame1
};

const u16 gTilesetAnims_RustboroGym_GreenBeams_Frame0[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/green_beams/0.4bpp");
const u16 gTilesetAnims_RustboroGym_GreenBeams_Frame1[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/green_beams/1.4bpp");
const u16 gTilesetAnims_RustboroGym_GreenBeams_Frame2[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/green_beams/2.4bpp");
const u16 gTilesetAnims_RustboroGym_GreenBeams_Frame3[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/green_beams/3.4bpp");
const u16 gTilesetAnims_RustboroGym_GreenBeams_Frame4[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/green_beams/4.4bpp");
const u16 gTilesetAnims_RustboroGym_GreenBeams_Frame5[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/green_beams/5.4bpp");
const u16 gTilesetAnims_RustboroGym_GreenBeams_Frame6[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/green_beams/6.4bpp");

const u16 *const gTilesetAnims_RustboroGym_GreenBeams[] = {
    gTilesetAnims_RustboroGym_GreenBeams_Frame0,
    gTilesetAnims_RustboroGym_GreenBeams_Frame1,
    //gTilesetAnims_RustboroGym_GreenBeams_Frame2,
    gTilesetAnims_RustboroGym_GreenBeams_Frame3,
    gTilesetAnims_RustboroGym_GreenBeams_Frame4,
    gTilesetAnims_RustboroGym_GreenBeams_Frame5,
    gTilesetAnims_RustboroGym_GreenBeams_Frame6
};

const u16 gTilesetAnims_RustboroGym_GreyBeams_Frame0[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/grey_beams/0.4bpp");
const u16 gTilesetAnims_RustboroGym_GreyBeams_Frame1[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/grey_beams/1.4bpp");
const u16 gTilesetAnims_RustboroGym_GreyBeams_Frame2[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/grey_beams/2.4bpp");

const u16 *const gTilesetAnims_RustboroGym_GreyBeams[] = {
    gTilesetAnims_RustboroGym_GreyBeams_Frame0,
    gTilesetAnims_RustboroGym_GreyBeams_Frame1,
    gTilesetAnims_RustboroGym_GreyBeams_Frame0,
    gTilesetAnims_RustboroGym_GreyBeams_Frame2
};

const u16 gTilesetAnims_RustboroGym_Weed_Frame0[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/weed/0.4bpp");
const u16 gTilesetAnims_RustboroGym_Weed_Frame1[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/weed/1.4bpp");
const u16 gTilesetAnims_RustboroGym_Weed_Frame2[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/weed/2.4bpp");

const u16 *const gTilesetAnims_RustboroGym_Weed[] = {
    gTilesetAnims_RustboroGym_Weed_Frame0,
    gTilesetAnims_RustboroGym_Weed_Frame1,
    gTilesetAnims_RustboroGym_Weed_Frame2,
    gTilesetAnims_RustboroGym_Weed_Frame1
};

const u16 gTilesetAnims_RustboroGym_Rapid_Frame0[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/rapid/0.4bpp");
const u16 gTilesetAnims_RustboroGym_Rapid_Frame1[] = INCBIN_U16("data/tilesets/secondary/rustboro_gym/anim/rapid/1.4bpp");

const u16 *const gTilesetAnims_RustboroGym_Rapid[] = {
    gTilesetAnims_RustboroGym_Rapid_Frame0,
    gTilesetAnims_RustboroGym_Rapid_Frame1
};

const u16 gTilesetAnims_PokemonCenter_Map_Frame0[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/map/0.4bpp");
const u16 gTilesetAnims_PokemonCenter_Map_Frame1[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/map/1.4bpp");

const u16 *const gTilesetAnims_PokemonCenter_Map[] = {
    gTilesetAnims_PokemonCenter_Map_Frame0,
    gTilesetAnims_PokemonCenter_Map_Frame1
};

const u16 gTilesetAnims_PokemonCenter_Stripe_Frame0[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/0.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame1[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/1.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame2[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/2.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame3[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/3.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame4[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/4.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame5[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/5.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame6[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/6.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame7[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/7.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame8[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/8.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame9[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/9.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame10[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/10.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame11[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/11.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame12[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/12.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame13[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/13.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame14[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/14.4bpp");
const u16 gTilesetAnims_PokemonCenter_Stripe_Frame15[] = INCBIN_U16("data/tilesets/secondary/pokemon_center/anim/stripe/15.4bpp");

const u16 *const gTilesetAnims_PokemonCenter_Stripe[] = {
    gTilesetAnims_PokemonCenter_Stripe_Frame0,
    gTilesetAnims_PokemonCenter_Stripe_Frame1,
    gTilesetAnims_PokemonCenter_Stripe_Frame2,
    gTilesetAnims_PokemonCenter_Stripe_Frame3,
    gTilesetAnims_PokemonCenter_Stripe_Frame4,
    gTilesetAnims_PokemonCenter_Stripe_Frame5,
    gTilesetAnims_PokemonCenter_Stripe_Frame6,
    gTilesetAnims_PokemonCenter_Stripe_Frame7,
    gTilesetAnims_PokemonCenter_Stripe_Frame8,
    gTilesetAnims_PokemonCenter_Stripe_Frame9,
    gTilesetAnims_PokemonCenter_Stripe_Frame10,
    gTilesetAnims_PokemonCenter_Stripe_Frame11,
    gTilesetAnims_PokemonCenter_Stripe_Frame12,
    gTilesetAnims_PokemonCenter_Stripe_Frame13,
    gTilesetAnims_PokemonCenter_Stripe_Frame14,
    gTilesetAnims_PokemonCenter_Stripe_Frame15
};

const u16 gTilesetAnims_Lilycove_Flag_Frame0[] = INCBIN_U16("data/tilesets/secondary/lilycove/anim/flag/0.4bpp");
const u16 gTilesetAnims_Lilycove_Flag_Frame1[] = INCBIN_U16("data/tilesets/secondary/lilycove/anim/flag/1.4bpp");
const u16 gTilesetAnims_Lilycove_Flag_Frame2[] = INCBIN_U16("data/tilesets/secondary/lilycove/anim/flag/2.4bpp");
const u16 gTilesetAnims_Lilycove_Flag_Frame3[] = INCBIN_U16("data/tilesets/secondary/lilycove/anim/flag/3.4bpp");

const u16 *const gTilesetAnims_Lilycove_Flag[] = {
    gTilesetAnims_Lilycove_Flag_Frame0,
    gTilesetAnims_Lilycove_Flag_Frame1,
    gTilesetAnims_Lilycove_Flag_Frame2,
    gTilesetAnims_Lilycove_Flag_Frame3
};

const u16 gTilesetAnims_Fallarbor_Campfire_Frame0[] = INCBIN_U16("data/tilesets/secondary/fallarbor/anim/campfire/0.4bpp");
const u16 gTilesetAnims_Fallarbor_Campfire_Frame1[] = INCBIN_U16("data/tilesets/secondary/fallarbor/anim/campfire/1.4bpp");
const u16 gTilesetAnims_Fallarbor_Campfire_Frame2[] = INCBIN_U16("data/tilesets/secondary/fallarbor/anim/campfire/2.4bpp");

/*const u16 gTilesetAnims_Lavaridge_Steam_Frame0[] = INCBIN_U16("data/tilesets/secondary/lavaridge/anim/steam/0.4bpp");
const u16 gTilesetAnims_Lavaridge_Steam_Frame1[] = INCBIN_U16("data/tilesets/secondary/lavaridge/anim/steam/1.4bpp");
const u16 gTilesetAnims_Lavaridge_Steam_Frame2[] = INCBIN_U16("data/tilesets/secondary/lavaridge/anim/steam/2.4bpp");
const u16 gTilesetAnims_Lavaridge_Steam_Frame3[] = INCBIN_U16("data/tilesets/secondary/lavaridge/anim/steam/3.4bpp");

const u16 *const gTilesetAnims_Lavaridge_Steam[] = {
    gTilesetAnims_Lavaridge_Steam_Frame0,
    gTilesetAnims_Lavaridge_Steam_Frame1,
    gTilesetAnims_Lavaridge_Steam_Frame2,
    gTilesetAnims_Lavaridge_Steam_Frame3
};*/

const u16 gTilesetAnims_Pacifidlog_LogBridges_Frame0[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/log_bridges/0.4bpp");
const u16 gTilesetAnims_Pacifidlog_LogBridges_Frame1[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/log_bridges/1.4bpp");
const u16 gTilesetAnims_Pacifidlog_LogBridges_Frame2[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/log_bridges/2.4bpp");

const u16 *const gTilesetAnims_Pacifidlog_LogBridges[] = {
    gTilesetAnims_Pacifidlog_LogBridges_Frame0,
    gTilesetAnims_Pacifidlog_LogBridges_Frame1,
    gTilesetAnims_Pacifidlog_LogBridges_Frame2,
    gTilesetAnims_Pacifidlog_LogBridges_Frame1
};

const u16 gTilesetAnims_Petalburg_Chimney_Smoke_Frame0[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/chimney_smoke/0.4bpp");
const u16 gTilesetAnims_Petalburg_Chimney_Smoke_Frame1[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/chimney_smoke/1.4bpp");
const u16 gTilesetAnims_Petalburg_Chimney_Smoke_Frame2[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/chimney_smoke/2.4bpp");

const u16 *const gTilesetAnims_Petalburg_Chimney_Smoke[] = {
    gTilesetAnims_Petalburg_Chimney_Smoke_Frame0,
    gTilesetAnims_Petalburg_Chimney_Smoke_Frame1,
    gTilesetAnims_Petalburg_Chimney_Smoke_Frame2
};

const u16 gTilesetAnims_Rustboro_Chimney_Smoke_Frame0[] = INCBIN_U16("data/tilesets/secondary/rustboro/anim/chimney_smoke/0.4bpp");
const u16 gTilesetAnims_Rustboro_Chimney_Smoke_Frame1[] = INCBIN_U16("data/tilesets/secondary/rustboro/anim/chimney_smoke/1.4bpp");
const u16 gTilesetAnims_Rustboro_Chimney_Smoke_Frame2[] = INCBIN_U16("data/tilesets/secondary/rustboro/anim/chimney_smoke/2.4bpp");

const u16 *const gTilesetAnims_Rustboro_Chimney_Smoke[] = {
    gTilesetAnims_Rustboro_Chimney_Smoke_Frame0,
    gTilesetAnims_Rustboro_Chimney_Smoke_Frame1,
    gTilesetAnims_Rustboro_Chimney_Smoke_Frame2
};

const u16 *const gTilesetAnims_Fallarbor_Campfire[] = {
    gTilesetAnims_Fallarbor_Campfire_Frame0,
    gTilesetAnims_Fallarbor_Campfire_Frame1,
    gTilesetAnims_Fallarbor_Campfire_Frame2
};

const u16 gTilesetAnims_Fallarbor_Smoke_Frame0[] = INCBIN_U16("data/tilesets/secondary/fallarbor/anim/smoke/0.4bpp");
const u16 gTilesetAnims_Fallarbor_Smoke_Frame1[] = INCBIN_U16("data/tilesets/secondary/fallarbor/anim/smoke/1.4bpp");
const u16 gTilesetAnims_Fallarbor_Smoke_Frame2[] = INCBIN_U16("data/tilesets/secondary/fallarbor/anim/smoke/2.4bpp");

const u16 *const gTilesetAnims_Fallarbor_Smoke[] = {
    gTilesetAnims_Fallarbor_Smoke_Frame0,
    gTilesetAnims_Fallarbor_Smoke_Frame1,
    gTilesetAnims_Fallarbor_Smoke_Frame2
};

const u16 gTilesetAnims_Petalburg_Watermill1_Frame0[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_1/0.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill1_Frame1[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_1/1.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill1_Frame2[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_1/2.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill1_Frame3[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_1/3.4bpp");

const u16 *const gTilesetAnims_Petalburg_Watermill1[] = {
    gTilesetAnims_Petalburg_Watermill1_Frame0,
    gTilesetAnims_Petalburg_Watermill1_Frame1,
    gTilesetAnims_Petalburg_Watermill1_Frame2,
    gTilesetAnims_Petalburg_Watermill1_Frame3
};

const u16 gTilesetAnims_Petalburg_Watermill2_Frame0[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_2/0.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill2_Frame1[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_2/1.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill2_Frame2[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_2/2.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill2_Frame3[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_2/3.4bpp");

const u16 *const gTilesetAnims_Petalburg_Watermill2[] = {
    gTilesetAnims_Petalburg_Watermill2_Frame0,
    gTilesetAnims_Petalburg_Watermill2_Frame1,
    gTilesetAnims_Petalburg_Watermill2_Frame2,
    gTilesetAnims_Petalburg_Watermill2_Frame3
};

const u16 gTilesetAnims_Petalburg_Watermill3_Frame0[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_3/0.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill3_Frame1[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_3/1.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill3_Frame2[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_3/2.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill3_Frame3[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_3/3.4bpp");

const u16 *const gTilesetAnims_Petalburg_Watermill3[] = {
    gTilesetAnims_Petalburg_Watermill3_Frame0,
    gTilesetAnims_Petalburg_Watermill3_Frame1,
    gTilesetAnims_Petalburg_Watermill3_Frame2,
    gTilesetAnims_Petalburg_Watermill3_Frame3
};

const u16 gTilesetAnims_Petalburg_Watermill4_Frame0[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_4/0.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill4_Frame1[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_4/1.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill4_Frame2[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_4/2.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill4_Frame3[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_4/3.4bpp");

const u16 *const gTilesetAnims_Petalburg_Watermill4[] = {
    gTilesetAnims_Petalburg_Watermill4_Frame0,
    gTilesetAnims_Petalburg_Watermill4_Frame1,  
    gTilesetAnims_Petalburg_Watermill4_Frame2,
    gTilesetAnims_Petalburg_Watermill4_Frame3
};

const u16 gTilesetAnims_Petalburg_Watermill5_Frame0[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_5/0.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill5_Frame1[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_5/1.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill5_Frame2[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_5/2.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill5_Frame3[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_5/3.4bpp");

const u16 *const gTilesetAnims_Petalburg_Watermill5[] = {
    gTilesetAnims_Petalburg_Watermill5_Frame0,
    gTilesetAnims_Petalburg_Watermill5_Frame1,
    gTilesetAnims_Petalburg_Watermill5_Frame2,
    gTilesetAnims_Petalburg_Watermill5_Frame3
};

const u16 gTilesetAnims_Petalburg_Watermill6_Frame0[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_6/0.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill6_Frame1[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_6/1.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill6_Frame2[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_6/2.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill6_Frame3[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_6/3.4bpp");

const u16 *const gTilesetAnims_Petalburg_Watermill6[] = {
    gTilesetAnims_Petalburg_Watermill6_Frame0,
    gTilesetAnims_Petalburg_Watermill6_Frame1,
    gTilesetAnims_Petalburg_Watermill6_Frame2,
    gTilesetAnims_Petalburg_Watermill6_Frame3
};

const u16 gTilesetAnims_Petalburg_Watermill7_Frame0[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_7/0.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill7_Frame1[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_7/1.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill7_Frame2[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_7/2.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill7_Frame3[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_7/3.4bpp");

const u16 *const gTilesetAnims_Petalburg_Watermill7[] = {
    gTilesetAnims_Petalburg_Watermill7_Frame0,
    gTilesetAnims_Petalburg_Watermill7_Frame1,
    gTilesetAnims_Petalburg_Watermill7_Frame2,
    gTilesetAnims_Petalburg_Watermill7_Frame3
};

const u16 gTilesetAnims_Petalburg_Watermill8_Frame0[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_8/0.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill8_Frame1[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_8/1.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill8_Frame2[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_8/2.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill8_Frame3[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_8/3.4bpp");

const u16 *const gTilesetAnims_Petalburg_Watermill8[] = {
    gTilesetAnims_Petalburg_Watermill8_Frame0,
    gTilesetAnims_Petalburg_Watermill8_Frame1,
    gTilesetAnims_Petalburg_Watermill8_Frame2,
    gTilesetAnims_Petalburg_Watermill8_Frame3
};

const u16 gTilesetAnims_Petalburg_Watermill9_Frame0[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_9/0.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill9_Frame1[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_9/1.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill9_Frame2[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_9/2.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill9_Frame3[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_9/3.4bpp");

const u16 *const gTilesetAnims_Petalburg_Watermill9[] = {
    gTilesetAnims_Petalburg_Watermill9_Frame0,
    gTilesetAnims_Petalburg_Watermill9_Frame1,
    gTilesetAnims_Petalburg_Watermill9_Frame2,
    gTilesetAnims_Petalburg_Watermill9_Frame3
};

const u16 gTilesetAnims_Petalburg_Watermill10_Frame0[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_10/0.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill10_Frame1[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_10/1.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill10_Frame2[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_10/2.4bpp");
const u16 gTilesetAnims_Petalburg_Watermill10_Frame3[] = INCBIN_U16("data/tilesets/secondary/petalburg/anim/watermill_10/3.4bpp");

const u16 *const gTilesetAnims_Petalburg_Watermill10[] = {
    gTilesetAnims_Petalburg_Watermill10_Frame0,
    gTilesetAnims_Petalburg_Watermill10_Frame1,
    gTilesetAnims_Petalburg_Watermill10_Frame2,
    gTilesetAnims_Petalburg_Watermill10_Frame3
};

const u16 gTilesetAnims_Dewford_Turbine1_Frame0[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_1/0.4bpp");
const u16 gTilesetAnims_Dewford_Turbine1_Frame1[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_1/1.4bpp");
const u16 gTilesetAnims_Dewford_Turbine1_Frame2[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_1/2.4bpp");

const u16 *const gTilesetAnims_Dewford_Turbine1[] = {
    gTilesetAnims_Dewford_Turbine1_Frame0,
    gTilesetAnims_Dewford_Turbine1_Frame1,
    gTilesetAnims_Dewford_Turbine1_Frame2
};

const u16 gTilesetAnims_Dewford_Turbine2_Frame0[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_2/0.4bpp");
const u16 gTilesetAnims_Dewford_Turbine2_Frame1[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_2/1.4bpp");
const u16 gTilesetAnims_Dewford_Turbine2_Frame2[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_2/2.4bpp");

const u16 *const gTilesetAnims_Dewford_Turbine2[] = {
    gTilesetAnims_Dewford_Turbine2_Frame0,
    gTilesetAnims_Dewford_Turbine2_Frame1,
    gTilesetAnims_Dewford_Turbine2_Frame2
};

const u16 gTilesetAnims_Dewford_Turbine3_Frame0[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_3/0.4bpp");
const u16 gTilesetAnims_Dewford_Turbine3_Frame1[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_3/1.4bpp");
const u16 gTilesetAnims_Dewford_Turbine3_Frame2[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_3/2.4bpp");

const u16 *const gTilesetAnims_Dewford_Turbine3[] = {
    gTilesetAnims_Dewford_Turbine3_Frame0,
    gTilesetAnims_Dewford_Turbine3_Frame1,
    gTilesetAnims_Dewford_Turbine3_Frame2
};

const u16 gTilesetAnims_Dewford_Turbine4_Frame0[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_4/0.4bpp");
const u16 gTilesetAnims_Dewford_Turbine4_Frame1[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_4/1.4bpp");
const u16 gTilesetAnims_Dewford_Turbine4_Frame2[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_4/2.4bpp");

const u16 *const gTilesetAnims_Dewford_Turbine4[] = {
    gTilesetAnims_Dewford_Turbine4_Frame0,
    gTilesetAnims_Dewford_Turbine4_Frame1,
    gTilesetAnims_Dewford_Turbine4_Frame2
};

const u16 gTilesetAnims_Dewford_Turbine5_Frame0[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_5/0.4bpp");
const u16 gTilesetAnims_Dewford_Turbine5_Frame1[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_5/1.4bpp");
const u16 gTilesetAnims_Dewford_Turbine5_Frame2[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_5/2.4bpp");

const u16 *const gTilesetAnims_Dewford_Turbine5[] = {
    gTilesetAnims_Dewford_Turbine5_Frame0,
    gTilesetAnims_Dewford_Turbine5_Frame1,
    gTilesetAnims_Dewford_Turbine5_Frame2
};

const u16 gTilesetAnims_Dewford_Turbine6_Frame0[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_6/0.4bpp");
const u16 gTilesetAnims_Dewford_Turbine6_Frame1[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_6/1.4bpp");
const u16 gTilesetAnims_Dewford_Turbine6_Frame2[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/turbine_6/2.4bpp");

const u16 *const gTilesetAnims_Dewford_Turbine6[] = {
    gTilesetAnims_Dewford_Turbine6_Frame0,
    gTilesetAnims_Dewford_Turbine6_Frame1,
    gTilesetAnims_Dewford_Turbine6_Frame2
};

const u16 gTilesetAnims_Dewford_Flower_Frame0[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/flower/0.4bpp");
const u16 gTilesetAnims_Dewford_Flower_Frame1[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/flower/1.4bpp");
const u16 gTilesetAnims_Dewford_Flower_Frame2[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/flower/2.4bpp");

const u16 *const gTilesetAnims_Dewford_Flower[] = {
    gTilesetAnims_Dewford_Flower_Frame0,
    gTilesetAnims_Dewford_Flower_Frame1,
    gTilesetAnims_Dewford_Flower_Frame2,
    gTilesetAnims_Dewford_Flower_Frame1
};

const u16 gTilesetAnims_Dewford_Sunflower1_Frame0[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/sunflower_1/0.4bpp");
const u16 gTilesetAnims_Dewford_Sunflower1_Frame1[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/sunflower_1/1.4bpp");
const u16 gTilesetAnims_Dewford_Sunflower1_Frame2[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/sunflower_1/2.4bpp");

const u16 *const gTilesetAnims_Dewford_Sunflower1[] = {
    gTilesetAnims_Dewford_Sunflower1_Frame0,
    gTilesetAnims_Dewford_Sunflower1_Frame1,
    gTilesetAnims_Dewford_Sunflower1_Frame0,
    gTilesetAnims_Dewford_Sunflower1_Frame2
};

const u16 gTilesetAnims_Dewford_Sunflower2_Frame0[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/sunflower_2/0.4bpp");
const u16 gTilesetAnims_Dewford_Sunflower2_Frame1[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/sunflower_2/1.4bpp");
const u16 gTilesetAnims_Dewford_Sunflower2_Frame2[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/sunflower_2/2.4bpp");

const u16 *const gTilesetAnims_Dewford_Sunflower2[] = {
    gTilesetAnims_Dewford_Sunflower2_Frame0,
    gTilesetAnims_Dewford_Sunflower2_Frame1,
    gTilesetAnims_Dewford_Sunflower2_Frame0,
    gTilesetAnims_Dewford_Sunflower2_Frame2
};

const u16 gTilesetAnims_Underwater_Seaweed_Frame0[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/seaweed/0.4bpp");
const u16 gTilesetAnims_Underwater_Seaweed_Frame1[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/seaweed/1.4bpp");
const u16 gTilesetAnims_Underwater_Seaweed_Frame2[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/seaweed/2.4bpp");
const u16 gTilesetAnims_Underwater_Seaweed_Frame3[] = INCBIN_U16("data/tilesets/secondary/underwater/anim/seaweed/3.4bpp");

const u16 *const gTilesetAnims_Underwater_Seaweed[] = {
    gTilesetAnims_Underwater_Seaweed_Frame0,
    gTilesetAnims_Underwater_Seaweed_Frame1,
    gTilesetAnims_Underwater_Seaweed_Frame2,
    gTilesetAnims_Underwater_Seaweed_Frame3
};

const u16 gTilesetAnims_Pacifidlog_WaterCurrents_Frame0[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/water_currents/0.4bpp");
const u16 gTilesetAnims_Pacifidlog_WaterCurrents_Frame1[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/water_currents/1.4bpp");
const u16 gTilesetAnims_Pacifidlog_WaterCurrents_Frame2[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/water_currents/2.4bpp");
const u16 gTilesetAnims_Pacifidlog_WaterCurrents_Frame3[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/water_currents/3.4bpp");
const u16 gTilesetAnims_Pacifidlog_WaterCurrents_Frame4[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/water_currents/4.4bpp");
const u16 gTilesetAnims_Pacifidlog_WaterCurrents_Frame5[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/water_currents/5.4bpp");
const u16 gTilesetAnims_Pacifidlog_WaterCurrents_Frame6[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/water_currents/6.4bpp");
const u16 gTilesetAnims_Pacifidlog_WaterCurrents_Frame7[] = INCBIN_U16("data/tilesets/secondary/pacifidlog/anim/water_currents/7.4bpp");

const u16 *const gTilesetAnims_Pacifidlog_WaterCurrents[] = {
    gTilesetAnims_Pacifidlog_WaterCurrents_Frame0,
    gTilesetAnims_Pacifidlog_WaterCurrents_Frame1,
    gTilesetAnims_Pacifidlog_WaterCurrents_Frame2,
    gTilesetAnims_Pacifidlog_WaterCurrents_Frame3,
    gTilesetAnims_Pacifidlog_WaterCurrents_Frame4,
    gTilesetAnims_Pacifidlog_WaterCurrents_Frame5,
    gTilesetAnims_Pacifidlog_WaterCurrents_Frame6,
    gTilesetAnims_Pacifidlog_WaterCurrents_Frame7
};

const u16 gTilesetAnims_Mauville_Flower1_Frame0[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/flower_1/0.4bpp");
const u16 gTilesetAnims_Mauville_Flower1_Frame1[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/flower_1/1.4bpp");
const u16 gTilesetAnims_Mauville_Flower1_Frame2[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/flower_1/2.4bpp");
const u16 gTilesetAnims_Mauville_Flower1_Frame3[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/flower_1/3.4bpp");
const u16 gTilesetAnims_Mauville_Flower1_Frame4[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/flower_1/4.4bpp");
const u16 gTilesetAnims_Mauville_Flower2_Frame0[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/flower_2/0.4bpp");
const u16 gTilesetAnims_Mauville_Flower2_Frame1[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/flower_2/1.4bpp");
const u16 gTilesetAnims_Mauville_Flower2_Frame2[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/flower_2/2.4bpp");
const u16 gTilesetAnims_Mauville_Flower2_Frame3[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/flower_2/3.4bpp");
const u16 gTilesetAnims_Mauville_Flower2_Frame4[] = INCBIN_U16("data/tilesets/secondary/mauville/anim/flower_2/4.4bpp");
const u16 tileset_anims_space_1[16] = {};

u16 *const gTilesetAnims_Mauville_Flower1_VDests[] = {
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 96)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 100)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 104)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 108)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 112)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 116)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 120)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 124))
};

u16 *const gTilesetAnims_Mauville_Flower2_VDests[] = {
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 128)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 132)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 136)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 140)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 144)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 148)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 152)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 156))
};

const u16 *const gTilesetAnims_Mauville_Flower1[] = {
    gTilesetAnims_Mauville_Flower1_Frame0,
    gTilesetAnims_Mauville_Flower1_Frame0,
    gTilesetAnims_Mauville_Flower1_Frame1,
    gTilesetAnims_Mauville_Flower1_Frame2,
    gTilesetAnims_Mauville_Flower1_Frame3,
    gTilesetAnims_Mauville_Flower1_Frame3,
    gTilesetAnims_Mauville_Flower1_Frame3,
    gTilesetAnims_Mauville_Flower1_Frame3,
    gTilesetAnims_Mauville_Flower1_Frame3,
    gTilesetAnims_Mauville_Flower1_Frame3,
    gTilesetAnims_Mauville_Flower1_Frame2,
    gTilesetAnims_Mauville_Flower1_Frame1
};

const u16 *const gTilesetAnims_Mauville_Flower2[] = {
    gTilesetAnims_Mauville_Flower2_Frame0,
    gTilesetAnims_Mauville_Flower2_Frame0,
    gTilesetAnims_Mauville_Flower2_Frame1,
    gTilesetAnims_Mauville_Flower2_Frame2,
    gTilesetAnims_Mauville_Flower2_Frame3,
    gTilesetAnims_Mauville_Flower2_Frame3,
    gTilesetAnims_Mauville_Flower2_Frame3,
    gTilesetAnims_Mauville_Flower2_Frame3,
    gTilesetAnims_Mauville_Flower2_Frame3,
    gTilesetAnims_Mauville_Flower2_Frame3,
    gTilesetAnims_Mauville_Flower2_Frame2,
    gTilesetAnims_Mauville_Flower2_Frame1
};

const u16 *const gTilesetAnims_Mauville_Flower1_B[] = {
    gTilesetAnims_Mauville_Flower1_Frame0,
    gTilesetAnims_Mauville_Flower1_Frame0,
    gTilesetAnims_Mauville_Flower1_Frame4,
    gTilesetAnims_Mauville_Flower1_Frame4
};

const u16 *const gTilesetAnims_Mauville_Flower2_B[] = {
    gTilesetAnims_Mauville_Flower2_Frame0,
    gTilesetAnims_Mauville_Flower2_Frame0,
    gTilesetAnims_Mauville_Flower2_Frame4,
    gTilesetAnims_Mauville_Flower2_Frame4
};

/*const u16 gTilesetAnims_Lavaridge_Cave_Lava_Frame0[] = INCBIN_U16("data/tilesets/secondary/cave/anim/lava/0.4bpp");
const u16 gTilesetAnims_Lavaridge_Cave_Lava_Frame1[] = INCBIN_U16("data/tilesets/secondary/cave/anim/lava/1.4bpp");
const u16 gTilesetAnims_Lavaridge_Cave_Lava_Frame2[] = INCBIN_U16("data/tilesets/secondary/cave/anim/lava/2.4bpp");
const u16 gTilesetAnims_Lavaridge_Cave_Lava_Frame3[] = INCBIN_U16("data/tilesets/secondary/cave/anim/lava/3.4bpp");
const u16 gTilesetAnims_Lavaridge_Cave_Lava_Frame4[] = INCBIN_U16("data/tilesets/secondary/cave/anim/lava/4.4bpp");
const u16 gTilesetAnims_Lavaridge_Cave_Lava_Frame5[] = INCBIN_U16("data/tilesets/secondary/cave/anim/lava/5.4bpp");
const u16 gTilesetAnims_Lavaridge_Cave_Lava_Frame6[] = INCBIN_U16("data/tilesets/secondary/cave/anim/lava/6.4bpp");
const u16 gTilesetAnims_Lavaridge_Cave_Lava_Frame7[] = INCBIN_U16("data/tilesets/secondary/cave/anim/lava/7.4bpp");
const u16 tileset_anims_space_3[16] = {};

const u16 *const gTilesetAnims_Lavaridge_Cave_Lava[] = {
    gTilesetAnims_Lavaridge_Cave_Lava_Frame0,
    gTilesetAnims_Lavaridge_Cave_Lava_Frame1,
    gTilesetAnims_Lavaridge_Cave_Lava_Frame2,
    gTilesetAnims_Lavaridge_Cave_Lava_Frame3
};*/

const u16 gTilesetAnims_EverGrande_Flowers_Frame0[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/flowers/0.4bpp");
const u16 gTilesetAnims_EverGrande_Flowers_Frame1[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/flowers/1.4bpp");
const u16 gTilesetAnims_EverGrande_Flowers_Frame2[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/flowers/2.4bpp");
const u16 gTilesetAnims_EverGrande_Flowers_Frame3[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/flowers/3.4bpp");
const u16 gTilesetAnims_EverGrande_Flowers_Frame4[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/flowers/4.4bpp");
const u16 gTilesetAnims_EverGrande_Flowers_Frame5[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/flowers/5.4bpp");
const u16 gTilesetAnims_EverGrande_Flowers_Frame6[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/flowers/6.4bpp");
const u16 gTilesetAnims_EverGrande_Flowers_Frame7[] = INCBIN_U16("data/tilesets/secondary/ever_grande/anim/flowers/7.4bpp");
const u16 tileset_anims_space_4[16] = {};

u16 *const gTilesetAnims_EverGrande_VDests[] = {
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 224)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 228)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 232)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 236)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 240)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 244)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 248)),
    (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 252))
};

const u16 *const gTilesetAnims_EverGrande_Flowers[] = {
    gTilesetAnims_EverGrande_Flowers_Frame0,
    gTilesetAnims_EverGrande_Flowers_Frame1,
    gTilesetAnims_EverGrande_Flowers_Frame2,
    gTilesetAnims_EverGrande_Flowers_Frame3,
    gTilesetAnims_EverGrande_Flowers_Frame4,
    gTilesetAnims_EverGrande_Flowers_Frame5,
    gTilesetAnims_EverGrande_Flowers_Frame6,
    gTilesetAnims_EverGrande_Flowers_Frame7
};

const u16 gTilesetAnims_Dewford_Flag_Frame0[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/flag/0.4bpp");
const u16 gTilesetAnims_Dewford_Flag_Frame1[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/flag/1.4bpp");
const u16 gTilesetAnims_Dewford_Flag_Frame2[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/flag/2.4bpp");
const u16 gTilesetAnims_Dewford_Flag_Frame3[] = INCBIN_U16("data/tilesets/secondary/dewford/anim/flag/3.4bpp");

const u16 *const gTilesetAnims_Dewford_Flag[] = {
    gTilesetAnims_Dewford_Flag_Frame0,
    gTilesetAnims_Dewford_Flag_Frame1,
    gTilesetAnims_Dewford_Flag_Frame2,
    gTilesetAnims_Dewford_Flag_Frame3
};

const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame0[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_west/anim/flag/0.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame1[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_west/anim/flag/1.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame2[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_west/anim/flag/2.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame3[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_west/anim/flag/3.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideWest_Flag[] = {
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame0,
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame1,
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame2,
    gTilesetAnims_BattleFrontierOutsideWest_Flag_Frame3
};

const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame0[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_east/anim/flag/0.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame1[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_east/anim/flag/1.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame2[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_east/anim/flag/2.4bpp");
const u16 gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame3[] = INCBIN_U16("data/tilesets/secondary/battle_frontier_outside_east/anim/flag/3.4bpp");

const u16 *const gTilesetAnims_BattleFrontierOutsideEast_Flag[] = {
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame0,
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame1,
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame2,
    gTilesetAnims_BattleFrontierOutsideEast_Flag_Frame3
};

const u16 gTilesetAnims_Slateport_Balloons_Frame0[] = INCBIN_U16("data/tilesets/secondary/slateport/anim/balloons/0.4bpp");
const u16 gTilesetAnims_Slateport_Balloons_Frame1[] = INCBIN_U16("data/tilesets/secondary/slateport/anim/balloons/1.4bpp");
const u16 gTilesetAnims_Slateport_Balloons_Frame2[] = INCBIN_U16("data/tilesets/secondary/slateport/anim/balloons/2.4bpp");
const u16 gTilesetAnims_Slateport_Balloons_Frame3[] = INCBIN_U16("data/tilesets/secondary/slateport/anim/balloons/3.4bpp");

const u16 *const gTilesetAnims_Slateport_Balloons[] = {
    gTilesetAnims_Slateport_Balloons_Frame0,
    gTilesetAnims_Slateport_Balloons_Frame1,
    gTilesetAnims_Slateport_Balloons_Frame2,
    gTilesetAnims_Slateport_Balloons_Frame3
};

const u16 gTilesetAnims_Slateport_Water0_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/0/0.4bpp");
const u16 gTilesetAnims_Slateport_Water0_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/0/1.4bpp");
const u16 gTilesetAnims_Slateport_Water0_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/0/2.4bpp");

const u16 *const gTilesetAnims_Slateport_Water0[] = {
    gTilesetAnims_Slateport_Water0_Frame0,
    gTilesetAnims_Slateport_Water0_Frame1,
    gTilesetAnims_Slateport_Water0_Frame2,
    gTilesetAnims_Slateport_Water0_Frame1
};

const u16 gTilesetAnims_Slateport_Water1_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/1/0.4bpp");
const u16 gTilesetAnims_Slateport_Water1_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/1/1.4bpp");
const u16 gTilesetAnims_Slateport_Water1_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/1/2.4bpp");

const u16 *const gTilesetAnims_Slateport_Water1[] = {
    gTilesetAnims_Slateport_Water1_Frame0,
    gTilesetAnims_Slateport_Water1_Frame1,
    gTilesetAnims_Slateport_Water1_Frame2,
    gTilesetAnims_Slateport_Water1_Frame1
};

const u16 gTilesetAnims_Slateport_Water2_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/2/0.4bpp");
const u16 gTilesetAnims_Slateport_Water2_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/2/1.4bpp");
const u16 gTilesetAnims_Slateport_Water2_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/2/2.4bpp");

const u16 *const gTilesetAnims_Slateport_Water2[] = {
    gTilesetAnims_Slateport_Water2_Frame0,
    gTilesetAnims_Slateport_Water2_Frame1,
    gTilesetAnims_Slateport_Water2_Frame2,
    gTilesetAnims_Slateport_Water2_Frame1
};

const u16 gTilesetAnims_Slateport_Water3_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/3/0.4bpp");
const u16 gTilesetAnims_Slateport_Water3_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/3/1.4bpp");
const u16 gTilesetAnims_Slateport_Water3_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/3/2.4bpp");

const u16 *const gTilesetAnims_Slateport_Water3[] = {
    gTilesetAnims_Slateport_Water3_Frame0,
    gTilesetAnims_Slateport_Water3_Frame1,
    gTilesetAnims_Slateport_Water3_Frame2,
    gTilesetAnims_Slateport_Water3_Frame1
};

const u16 gTilesetAnims_Slateport_Water4_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/4/0.4bpp");
const u16 gTilesetAnims_Slateport_Water4_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/4/1.4bpp");
const u16 gTilesetAnims_Slateport_Water4_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/4/2.4bpp");

const u16 *const gTilesetAnims_Slateport_Water4[] = {
    gTilesetAnims_Slateport_Water4_Frame0,
    gTilesetAnims_Slateport_Water4_Frame1,
    gTilesetAnims_Slateport_Water4_Frame2,
    gTilesetAnims_Slateport_Water4_Frame1
};

const u16 gTilesetAnims_Slateport_Water5_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/5/0.4bpp");
const u16 gTilesetAnims_Slateport_Water5_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/5/1.4bpp");
const u16 gTilesetAnims_Slateport_Water5_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/5/2.4bpp");

const u16 *const gTilesetAnims_Slateport_Water5[] = {
    gTilesetAnims_Slateport_Water5_Frame0,
    gTilesetAnims_Slateport_Water5_Frame1,
    gTilesetAnims_Slateport_Water5_Frame2,
    gTilesetAnims_Slateport_Water5_Frame1
};

const u16 gTilesetAnims_Slateport_Water6_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/6/0.4bpp");
const u16 gTilesetAnims_Slateport_Water6_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/6/1.4bpp");
const u16 gTilesetAnims_Slateport_Water6_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/6/2.4bpp");

const u16 *const gTilesetAnims_Slateport_Water6[] = {
    gTilesetAnims_Slateport_Water6_Frame0,
    gTilesetAnims_Slateport_Water6_Frame1,
    gTilesetAnims_Slateport_Water6_Frame2,
    gTilesetAnims_Slateport_Water6_Frame1
};

const u16 gTilesetAnims_Slateport_Water7_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/7/0.4bpp");
const u16 gTilesetAnims_Slateport_Water7_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/7/1.4bpp");
const u16 gTilesetAnims_Slateport_Water7_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/7/2.4bpp");

const u16 *const gTilesetAnims_Slateport_Water7[] = {
    gTilesetAnims_Slateport_Water7_Frame0,
    gTilesetAnims_Slateport_Water7_Frame1,
    gTilesetAnims_Slateport_Water7_Frame2,
    gTilesetAnims_Slateport_Water7_Frame1
};

const u16 gTilesetAnims_Slateport_Water8_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/8/0.4bpp");
const u16 gTilesetAnims_Slateport_Water8_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/8/1.4bpp");
const u16 gTilesetAnims_Slateport_Water8_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/8/2.4bpp");

const u16 *const gTilesetAnims_Slateport_Water8[] = {
    gTilesetAnims_Slateport_Water8_Frame0,
    gTilesetAnims_Slateport_Water8_Frame1,
    gTilesetAnims_Slateport_Water8_Frame2,
    gTilesetAnims_Slateport_Water8_Frame1
};

const u16 gTilesetAnims_Slateport_Water9_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/9/0.4bpp");
const u16 gTilesetAnims_Slateport_Water9_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/9/1.4bpp");
const u16 gTilesetAnims_Slateport_Water9_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/water/9/2.4bpp");

const u16 *const gTilesetAnims_Slateport_Water9[] = {
    gTilesetAnims_Slateport_Water9_Frame0,
    gTilesetAnims_Slateport_Water9_Frame1,
    gTilesetAnims_Slateport_Water9_Frame2,
    gTilesetAnims_Slateport_Water9_Frame1
};

const u16 gTilesetAnims_Slateport_SmallRockTop_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/small_rock_top/0.4bpp");
const u16 gTilesetAnims_Slateport_SmallRockTop_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/small_rock_top/1.4bpp");
const u16 gTilesetAnims_Slateport_SmallRockTop_Frame2[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/small_rock_top/2.4bpp");

const u16 *const gTilesetAnims_Slateport_SmallRockTop[] = {
    gTilesetAnims_Slateport_SmallRockTop_Frame0,
    gTilesetAnims_Slateport_SmallRockTop_Frame1,
    gTilesetAnims_Slateport_SmallRockTop_Frame2,
    gTilesetAnims_Slateport_SmallRockTop_Frame1
};

const u16 gTilesetAnims_Slateport_SmallRockBottom_Frame0[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/small_rock_bottom/0.4bpp");
const u16 gTilesetAnims_Slateport_SmallRockBottom_Frame1[] = INCBIN_U16("data/tilesets/secondary/generic_building/anim/small_rock_bottom/1.4bpp");

const u16 *const gTilesetAnims_Slateport_SmallRockBottom[] = {
    gTilesetAnims_Slateport_SmallRockBottom_Frame0,
    gTilesetAnims_Slateport_SmallRockBottom_Frame1
};

const u16 gTilesetAnims_Building_TvTurnedOn_Frame0[] = INCBIN_U16("data/tilesets/primary/building/anim/tv_turned_on/0.4bpp");
const u16 gTilesetAnims_Building_TvTurnedOn_Frame1[] = INCBIN_U16("data/tilesets/primary/building/anim/tv_turned_on/1.4bpp");

const u16 *const gTilesetAnims_Building_TvTurnedOn[] = {
    gTilesetAnims_Building_TvTurnedOn_Frame0,
    gTilesetAnims_Building_TvTurnedOn_Frame1
};

const u16 gTilesetAnims_SootopolisGym_SideWaterfall_Frame0[] = INCBIN_U16("data/tilesets/secondary/sootopolis_gym/anim/side_waterfall/0.4bpp");
const u16 gTilesetAnims_SootopolisGym_SideWaterfall_Frame1[] = INCBIN_U16("data/tilesets/secondary/sootopolis_gym/anim/side_waterfall/1.4bpp");
const u16 gTilesetAnims_SootopolisGym_SideWaterfall_Frame2[] = INCBIN_U16("data/tilesets/secondary/sootopolis_gym/anim/side_waterfall/2.4bpp");
const u16 gTilesetAnims_SootopolisGym_FrontWaterfall_Frame0[] = INCBIN_U16("data/tilesets/secondary/sootopolis_gym/anim/front_waterfall/0.4bpp");
const u16 gTilesetAnims_SootopolisGym_FrontWaterfall_Frame1[] = INCBIN_U16("data/tilesets/secondary/sootopolis_gym/anim/front_waterfall/1.4bpp");
const u16 gTilesetAnims_SootopolisGym_FrontWaterfall_Frame2[] = INCBIN_U16("data/tilesets/secondary/sootopolis_gym/anim/front_waterfall/2.4bpp");

const u16 *const gTilesetAnims_SootopolisGym_SideWaterfall[] = {
    gTilesetAnims_SootopolisGym_SideWaterfall_Frame0,
    gTilesetAnims_SootopolisGym_SideWaterfall_Frame1,
    gTilesetAnims_SootopolisGym_SideWaterfall_Frame2
};

const u16 *const gTilesetAnims_SootopolisGym_FrontWaterfall[] = {
    gTilesetAnims_SootopolisGym_FrontWaterfall_Frame0,
    gTilesetAnims_SootopolisGym_FrontWaterfall_Frame1,
    gTilesetAnims_SootopolisGym_FrontWaterfall_Frame2
};

const u16 gTilesetAnims_EliteFour_FloorLight_Frame0[] = INCBIN_U16("data/tilesets/secondary/elite_four/anim/floor_light/0.4bpp");
const u16 gTilesetAnims_EliteFour_FloorLight_Frame1[] = INCBIN_U16("data/tilesets/secondary/elite_four/anim/floor_light/1.4bpp");
const u16 gTilesetAnims_EliteFour_WallLights_Frame0[] = INCBIN_U16("data/tilesets/secondary/elite_four/anim/wall_lights/0.4bpp");
const u16 gTilesetAnims_EliteFour_WallLights_Frame1[] = INCBIN_U16("data/tilesets/secondary/elite_four/anim/wall_lights/1.4bpp");
const u16 gTilesetAnims_EliteFour_WallLights_Frame2[] = INCBIN_U16("data/tilesets/secondary/elite_four/anim/wall_lights/2.4bpp");
const u16 gTilesetAnims_EliteFour_WallLights_Frame3[] = INCBIN_U16("data/tilesets/secondary/elite_four/anim/wall_lights/3.4bpp");
const u16 tileset_anims_space_5[16] = {};

const u16 *const gTilesetAnims_EliteFour_WallLights[] = {
    gTilesetAnims_EliteFour_WallLights_Frame0,
    gTilesetAnims_EliteFour_WallLights_Frame1,
    gTilesetAnims_EliteFour_WallLights_Frame2,
    gTilesetAnims_EliteFour_WallLights_Frame3
};

const u16 *const gTilesetAnims_EliteFour_FloorLight[] = {
    gTilesetAnims_EliteFour_FloorLight_Frame0,
    gTilesetAnims_EliteFour_FloorLight_Frame1
};

/*const u16 gTilesetAnims_MauvilleGym_ElectricGates_Frame0[] = INCBIN_U16("data/tilesets/secondary/mauville_gym/anim/electric_gates/0.4bpp");
const u16 gTilesetAnims_MauvilleGym_ElectricGates_Frame1[] = INCBIN_U16("data/tilesets/secondary/mauville_gym/anim/electric_gates/1.4bpp");
const u16 tileset_anims_space_6[16] = {};

const u16 *const gTilesetAnims_MauvilleGym_ElectricGates[] = {
    gTilesetAnims_MauvilleGym_ElectricGates_Frame0,
    gTilesetAnims_MauvilleGym_ElectricGates_Frame1
};*/

const u16 gTilesetAnims_BikeShop_BlinkingLights_Frame0[] = INCBIN_U16("data/tilesets/secondary/bike_shop/anim/blinking_lights/0.4bpp");
const u16 gTilesetAnims_BikeShop_BlinkingLights_Frame1[] = INCBIN_U16("data/tilesets/secondary/bike_shop/anim/blinking_lights/1.4bpp");
const u16 tileset_anims_space_7[16] = {};

const u16 *const gTilesetAnims_BikeShop_BlinkingLights[] = {
    gTilesetAnims_BikeShop_BlinkingLights_Frame0,
    gTilesetAnims_BikeShop_BlinkingLights_Frame1
};

const u16 gTilesetAnims_Sootopolis_StormyWater_Frame0[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/stormy_water/0.4bpp");
const u16 gTilesetAnims_Sootopolis_StormyWater_Frame1[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/stormy_water/1.4bpp");
const u16 gTilesetAnims_Sootopolis_StormyWater_Frame2[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/stormy_water/2.4bpp");
const u16 gTilesetAnims_Sootopolis_StormyWater_Frame3[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/stormy_water/3.4bpp");
const u16 gTilesetAnims_Sootopolis_StormyWater_Frame4[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/stormy_water/4.4bpp");
const u16 gTilesetAnims_Sootopolis_StormyWater_Frame5[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/stormy_water/5.4bpp");
const u16 gTilesetAnims_Sootopolis_StormyWater_Frame6[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/stormy_water/6.4bpp");
const u16 gTilesetAnims_Sootopolis_StormyWater_Frame7[] = INCBIN_U16("data/tilesets/secondary/sootopolis/anim/stormy_water/7.4bpp");
const u16 tileset_anims_space_8[16] = {};

const u16 gTilesetAnims_Unused1_Frame0[] = INCBIN_U16("data/tilesets/secondary/unused_1/0.4bpp");
const u16 gTilesetAnims_Unused1_Frame1[] = INCBIN_U16("data/tilesets/secondary/unused_1/1.4bpp");
const u16 gTilesetAnims_Unused1_Frame2[] = INCBIN_U16("data/tilesets/secondary/unused_1/2.4bpp");
const u16 gTilesetAnims_Unused1_Frame3[] = INCBIN_U16("data/tilesets/secondary/unused_1/3.4bpp");

const u16 *const gTilesetAnims_Sootopolis_StormyWater[] = {
    gTilesetAnims_Sootopolis_StormyWater_Frame0,
    gTilesetAnims_Sootopolis_StormyWater_Frame1,
    gTilesetAnims_Sootopolis_StormyWater_Frame2,
    gTilesetAnims_Sootopolis_StormyWater_Frame3,
    gTilesetAnims_Sootopolis_StormyWater_Frame4,
    gTilesetAnims_Sootopolis_StormyWater_Frame5,
    gTilesetAnims_Sootopolis_StormyWater_Frame6,
    gTilesetAnims_Sootopolis_StormyWater_Frame7
};

const u16 gTilesetAnims_BattlePyramid_Torch_Frame0[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/torch/0.4bpp");
const u16 gTilesetAnims_BattlePyramid_Torch_Frame1[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/torch/1.4bpp");
const u16 gTilesetAnims_BattlePyramid_Torch_Frame2[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/torch/2.4bpp");
const u16 tileset_anims_space_9[16] = {};

const u16 gTilesetAnims_BattlePyramid_StatueShadow_Frame0[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/statue_shadow/0.4bpp");
const u16 gTilesetAnims_BattlePyramid_StatueShadow_Frame1[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/statue_shadow/1.4bpp");
const u16 gTilesetAnims_BattlePyramid_StatueShadow_Frame2[] = INCBIN_U16("data/tilesets/secondary/battle_pyramid/anim/statue_shadow/2.4bpp");
const u16 tileset_anims_space_10[7808] = {};

const u16 gTilesetAnims_Unused2_Frame0[] = INCBIN_U16("data/tilesets/secondary/unused_2/0.4bpp");
const u16 tileset_anims_space_11[224] = {};

const u16 gTilesetAnims_Unused2_Frame1[] = INCBIN_U16("data/tilesets/secondary/unused_2/1.4bpp");

const u16 *const gTilesetAnims_BattlePyramid_Torch[] = {
    gTilesetAnims_BattlePyramid_Torch_Frame0,
    gTilesetAnims_BattlePyramid_Torch_Frame1,
    gTilesetAnims_BattlePyramid_Torch_Frame2
};

const u16 *const gTilesetAnims_BattlePyramid_StatueShadow[] = {
    gTilesetAnims_BattlePyramid_StatueShadow_Frame0,
    gTilesetAnims_BattlePyramid_StatueShadow_Frame1,
    gTilesetAnims_BattlePyramid_StatueShadow_Frame2
};

static const u16 *const sTilesetAnims_BattleDomeFloorLightPals[] = {
    gTilesetAnims_BattleDomePals0_0,
    gTilesetAnims_BattleDomePals0_1,
    gTilesetAnims_BattleDomePals0_2,
    gTilesetAnims_BattleDomePals0_3,
};

const u16 gTilesetAnims_BattleTent_Tv_Ten_Frame0[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/ten/0.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Ten_Frame1[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/ten/1.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Ten_Frame2[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/ten/2.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Ten_Frame3[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/ten/3.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Ten_Frame4[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/ten/4.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Ten_Frame5[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/ten/5.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Ten_Frame6[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/ten/6.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Ten_Frame7[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/ten/7.4bpp");

const u16 *const gTilesetAnims_BattleTent_Tv_Ten[] = {
    gTilesetAnims_BattleTent_Tv_Ten_Frame0,
    gTilesetAnims_BattleTent_Tv_Ten_Frame1,
    gTilesetAnims_BattleTent_Tv_Ten_Frame2,
    gTilesetAnims_BattleTent_Tv_Ten_Frame3,
    gTilesetAnims_BattleTent_Tv_Ten_Frame4,
    gTilesetAnims_BattleTent_Tv_Ten_Frame5,
    gTilesetAnims_BattleTent_Tv_Ten_Frame6,
    gTilesetAnims_BattleTent_Tv_Ten_Frame7
};

const u16 gTilesetAnims_BattleTent_Tv_Poke_Frame0[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/poke/0.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Poke_Frame1[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/poke/1.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Poke_Frame2[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/poke/2.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Poke_Frame3[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/poke/3.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Poke_Frame4[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/poke/4.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Poke_Frame5[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/poke/5.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Poke_Frame6[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/poke/6.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Poke_Frame7[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/poke/7.4bpp");

const u16 *const gTilesetAnims_BattleTent_Tv_Poke[] = {
    gTilesetAnims_BattleTent_Tv_Poke_Frame0,
    gTilesetAnims_BattleTent_Tv_Poke_Frame1,
    gTilesetAnims_BattleTent_Tv_Poke_Frame2,
    gTilesetAnims_BattleTent_Tv_Poke_Frame3,
    gTilesetAnims_BattleTent_Tv_Poke_Frame4,
    gTilesetAnims_BattleTent_Tv_Poke_Frame5,
    gTilesetAnims_BattleTent_Tv_Poke_Frame6,
    gTilesetAnims_BattleTent_Tv_Poke_Frame7
};

const u16 gTilesetAnims_BattleTent_Tv_Trainer_Frame0[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/trainer/0.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Trainer_Frame1[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/trainer/1.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Trainer_Frame2[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/trainer/2.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Trainer_Frame3[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/trainer/3.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Trainer_Frame4[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/trainer/4.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Trainer_Frame5[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/trainer/5.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Trainer_Frame6[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/trainer/6.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Trainer_Frame7[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/trainer/7.4bpp");

const u16 *const gTilesetAnims_BattleTent_Tv_Trainer[] = {
    gTilesetAnims_BattleTent_Tv_Trainer_Frame0,
    gTilesetAnims_BattleTent_Tv_Trainer_Frame1,
    gTilesetAnims_BattleTent_Tv_Trainer_Frame2,
    gTilesetAnims_BattleTent_Tv_Trainer_Frame3,
    gTilesetAnims_BattleTent_Tv_Trainer_Frame4,
    gTilesetAnims_BattleTent_Tv_Trainer_Frame5,
    gTilesetAnims_BattleTent_Tv_Trainer_Frame6,
    gTilesetAnims_BattleTent_Tv_Trainer_Frame7
};

const u16 gTilesetAnims_BattleTent_Tv_Drowzee_Frame0[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/drowzee/0.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Drowzee_Frame1[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/drowzee/1.4bpp");

const u16 *const gTilesetAnims_BattleTent_Tv_Drowzee[] = {
    gTilesetAnims_BattleTent_Tv_Drowzee_Frame0,
    gTilesetAnims_BattleTent_Tv_Drowzee_Frame1
};

const u16 gTilesetAnims_BattleTent_Tv_Cliff_Frame0[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/cliff/0.4bpp");
const u16 gTilesetAnims_BattleTent_Tv_Cliff_Frame1[] = INCBIN_U16("data/tilesets/secondary/battle_tent/anim/cliff/1.4bpp");

const u16 *const gTilesetAnims_BattleTent_Tv_Cliff[] = {
    gTilesetAnims_BattleTent_Tv_Cliff_Frame0,
    gTilesetAnims_BattleTent_Tv_Cliff_Frame1
};

static void ResetTilesetAnimBuffer(void)
{
    sTilesetDMA3TransferBufferSize = 0;
    CpuFill32(0, sTilesetDMA3TransferBuffer, sizeof sTilesetDMA3TransferBuffer);
}

static void AppendTilesetAnimToBuffer(const u16 *src, u16 *dest, u16 size)
{
    if (sTilesetDMA3TransferBufferSize < 20)
    {
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].src = src;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].dest = dest;
        sTilesetDMA3TransferBuffer[sTilesetDMA3TransferBufferSize].size = size;
        sTilesetDMA3TransferBufferSize ++;
    }
}

void TransferTilesetAnimsBuffer(void)
{
    int i;

    for (i = 0; i < sTilesetDMA3TransferBufferSize; i ++)
        DmaCopy16(3, sTilesetDMA3TransferBuffer[i].src, sTilesetDMA3TransferBuffer[i].dest, sTilesetDMA3TransferBuffer[i].size);

    sTilesetDMA3TransferBufferSize = 0;
}

void InitTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    _InitPrimaryTilesetAnimation();
    _InitSecondaryTilesetAnimation();
}

void InitSecondaryTilesetAnimation(void)
{
    _InitSecondaryTilesetAnimation();
}

void UpdateTilesetAnimations(void)
{
    ResetTilesetAnimBuffer();
    if (++sPrimaryTilesetAnimCounter >= sPrimaryTilesetAnimCounterMax)
        sPrimaryTilesetAnimCounter = 0;
    if (++sSecondaryTilesetAnimCounter >= sSecondaryTilesetAnimCounterMax)
        sSecondaryTilesetAnimCounter = 0;

    if (sPrimaryTilesetAnimCallback)
        sPrimaryTilesetAnimCallback(sPrimaryTilesetAnimCounter);
    if (sSecondaryTilesetAnimCallback)
        sSecondaryTilesetAnimCallback(sSecondaryTilesetAnimCounter);
}

static void _InitPrimaryTilesetAnimation(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 0;
    sPrimaryTilesetAnimCallback = NULL;
    if (gMapHeader.mapLayout->primaryTileset && gMapHeader.mapLayout->primaryTileset->callback)
        gMapHeader.mapLayout->primaryTileset->callback();
}

static void _InitSecondaryTilesetAnimation(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 0;
    sSecondaryTilesetAnimCallback = NULL;
    if (gMapHeader.mapLayout->secondaryTileset && gMapHeader.mapLayout->secondaryTileset->callback)
        gMapHeader.mapLayout->secondaryTileset->callback();
}

void InitTilesetAnim_General(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 256;
    sPrimaryTilesetAnimCallback = TilesetAnim_General;
}

void InitTilesetAnim_Building(void)
{
    sPrimaryTilesetAnimCounter = 0;
    sPrimaryTilesetAnimCounterMax = 256;
    sPrimaryTilesetAnimCallback = TilesetAnim_Building;
}

static void TilesetAnim_General(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_General_Flower(timer >> 4);
    if (timer % 16 == 1)
        QueueAnimTiles_General_Water(timer >> 5);
    if (timer % 16 == 2)
        QueueAnimTiles_General_SandWaterEdge(timer >> 4);
    if (timer % 16 == 3)
        QueueAnimTiles_General_MainWater(timer / 16);
    if (timer % 16 == 4)
        QueueAnimTiles_General_Waterfall(timer >> 3);
        QueueAnimTiles_General_WaterfallBottom(timer >> 4);
    if (timer % 16 == 5)
        QueueAnimTiles_General_LandWaterEdge(timer >> 4);
    if (timer % 16 == 6)
        QueueAnimTiles_General_PondWaterEdge(timer >> 5);
    if (timer % 16 == 7)
        QueueAnimTiles_General_PondWaterSide(timer >> 5);
    if (timer % 16 == 8)
        QueueAnimTiles_General_PondWaterTop(timer >> 5);
    if (timer % 16 == 9)
        QueueAnimTiles_General_WeedT(timer >> 4);
    if (timer % 16 == 10)
        QueueAnimTiles_General_WeedNT(timer >> 4);
    if (timer % 16 == 11)
        QueueAnimTiles_General_WhiteFlower(timer >> 4);
}

static void TilesetAnim_Building(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Building_TVTurnedOn(timer / 8);
}

static void QueueAnimTiles_General_Flower(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_General_Flower);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_Flower[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(504)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_WhiteFlower(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_General_WhiteFlower);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_WhiteFlower[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(508)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_Water(u16 timer)
{
    u8 i = timer % ARRAY_COUNT(gTilesetAnims_General_Water);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_Water[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(490)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_MainWater(u16 timer)
{
    u8 i = timer % ARRAY_COUNT(gTilesetAnims_General_MainWater);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_MainWater[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(432)), 30 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_PondWaterEdge(u16 timer)
{
    u16 i = timer % 2; 
    AppendTilesetAnimToBuffer(gTilesetAnims_General_PondWaterEdge[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(475)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_PondWaterSide(u16 timer)
{
    u16 i = timer % 8; 
    AppendTilesetAnimToBuffer(gTilesetAnims_General_PondWaterSide[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(476)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_PondWaterTop(u16 timer)
{
    u16 i = timer % 8; 
    AppendTilesetAnimToBuffer(gTilesetAnims_General_PondWaterTop[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(477)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_SandWaterEdge(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_General_SandWaterEdge);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_SandWaterEdge[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(464)), 10 * TILE_SIZE_4BPP);
}

/*static void QueueAnimTiles_General_Sea(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_General_Sea);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_Sea[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(484)), 4 * TILE_SIZE_4BPP);
}*/

static void QueueAnimTiles_General_Waterfall(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_General_Waterfall);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_Waterfall[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(494)), 6 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_WaterfallBottom(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_General_WaterfallBottom);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_WaterfallBottom[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(500)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_WeedT(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_General_WeedT);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_WeedT[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(16)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_General_WeedNT(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_General_WeedNT);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_WeedNT[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(6)), 1 * TILE_SIZE_4BPP);
}

void InitTilesetAnim_Petalburg(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Petalburg;
}

void InitTilesetAnim_Dewford(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Dewford;
}

void InitTilesetAnim_Slateport(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Slateport;
}

void InitTilesetAnim_Mauville(void)
{
    sSecondaryTilesetAnimCounter = sPrimaryTilesetAnimCounter;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Mauville;
}

void InitTilesetAnim_Lavaridge(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Lavaridge;
}

void InitTilesetAnim_Fallarbor(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Fallarbor;
}

void InitTilesetAnim_Fortree(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = NULL;
}

void InitTilesetAnim_Lilycove(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Lilycove;
}

void InitTilesetAnim_Mossdeep(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = NULL;
}

void InitTilesetAnim_EverGrande(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_EverGrande;
}

void InitTilesetAnim_Pacifidlog(void)
{
    sSecondaryTilesetAnimCounter = sPrimaryTilesetAnimCounter;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Pacifidlog;
}

void InitTilesetAnim_Sootopolis(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = NULL;
}

void InitTilesetAnim_BattleFrontierOutsideWest(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_BattleFrontierOutsideWest;
}

void InitTilesetAnim_BattleFrontierOutsideEast(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_BattleFrontierOutsideEast;
}

void InitTilesetAnim_BattleTent(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_BattleTent;
}

void InitTilesetAnim_Underwater(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 128;
    sSecondaryTilesetAnimCallback = TilesetAnim_Underwater;
}

void InitTilesetAnim_SootopolisGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 240;
    sSecondaryTilesetAnimCallback = TilesetAnim_SootopolisGym;
}

void InitTilesetAnim_Cave(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Cave;
}

void InitTilesetAnim_EliteFour(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = 128;
    sSecondaryTilesetAnimCallback = TilesetAnim_EliteFour;
}

/*void InitTilesetAnim_MauvilleGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_MauvilleGym;
}*/

void InitTilesetAnim_BikeShop(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_BikeShop;
}

void InitTilesetAnim_BattlePyramid(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_BattlePyramid;
}

void InitTilesetAnim_BattleDome(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_BattleDome;
}

void InitTilesetAnim_GenericBuilding(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_GenericBuilding;
}

void InitTilesetAnim_Rustboro(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_Rustboro;
}

void InitTilesetAnim_RustboroGym(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_RustboroGym;
}

void InitTilesetAnim_PokemonCenter(void)
{
    sSecondaryTilesetAnimCounter = 0;
    sSecondaryTilesetAnimCounterMax = sPrimaryTilesetAnimCounterMax;
    sSecondaryTilesetAnimCallback = TilesetAnim_PokemonCenter;
}

static void TilesetAnim_Dewford(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Dewford_Flower(timer >> 4);
        QueueAnimTiles_Dewford_Sunflower1(timer >> 4);
        QueueAnimTiles_Dewford_Sunflower2(timer >> 4);
    if (timer % 8 == 1)
        QueueAnimTiles_Dewford_Turbine1(timer >> 4);
        QueueAnimTiles_Dewford_Turbine2(timer >> 4);
        QueueAnimTiles_Dewford_Turbine3(timer >> 4);
        QueueAnimTiles_Dewford_Turbine4(timer >> 4);
        QueueAnimTiles_Dewford_Turbine5(timer >> 4);
        QueueAnimTiles_Dewford_Turbine6(timer >> 4);
    //if (timer % 8 == 3)
    //   QueueAnimTiles_Dewford_Flag(timer / 8);
}

static void TilesetAnim_Slateport(u16 timer)
{
    if (timer % 8 == 0)
    {
        //QueueAnimTiles_Slateport_Balloons(timer / 16);*/
        QueueAnimTiles_Slateport_Water0(timer >> 5);
        QueueAnimTiles_Slateport_Water1(timer >> 5);
        QueueAnimTiles_Slateport_Water2(timer >> 5);
        QueueAnimTiles_Slateport_Water3(timer >> 5);
        QueueAnimTiles_Slateport_Water4(timer >> 5);
        QueueAnimTiles_Slateport_Water5(timer >> 5);
        QueueAnimTiles_Slateport_Water6(timer >> 5);
        QueueAnimTiles_Slateport_Water7(timer >> 5);
        QueueAnimTiles_Slateport_Water8(timer >> 5);
        QueueAnimTiles_Slateport_Water9(timer >> 5);
    }
    if (timer % 8 == 1)
    {
        QueueAnimTiles_Slateport_SmallRockTop(timer >> 4);
        QueueAnimTiles_Slateport_SmallRockBottom(timer >> 4);
    }
}

static void TilesetAnim_Mauville(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Mauville_Flowers(timer / 8, 0);
    if (timer % 8 == 1)
        QueueAnimTiles_Mauville_Flowers(timer / 8, 1);
    if (timer % 8 == 2)
        QueueAnimTiles_Mauville_Flowers(timer / 8, 2);
    if (timer % 8 == 3)
        QueueAnimTiles_Mauville_Flowers(timer / 8, 3);
    if (timer % 8 == 4)
        QueueAnimTiles_Mauville_Flowers(timer / 8, 4);
    if (timer % 8 == 5)
        QueueAnimTiles_Mauville_Flowers(timer / 8, 5);
    if (timer % 8 == 6)
        QueueAnimTiles_Mauville_Flowers(timer / 8, 6);
    if (timer % 8 == 7)
        QueueAnimTiles_Mauville_Flowers(timer / 8, 7);
}

static void TilesetAnim_Lavaridge(u16 timer)
{
    /*if (timer % 16 == 0)
        QueueAnimTiles_Lavaridge_Steam(timer / 16);
    if (timer % 16 == 1)
        QueueAnimTiles_Lavaridge_Lava(timer / 16);*/
}

static void TilesetAnim_EverGrande(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_EverGrande_Flowers(timer / 8, 0);
    if (timer % 8 == 1)
        QueueAnimTiles_EverGrande_Flowers(timer / 8, 1);
    if (timer % 8 == 2)
        QueueAnimTiles_EverGrande_Flowers(timer / 8, 2);
    if (timer % 8 == 3)
        QueueAnimTiles_EverGrande_Flowers(timer / 8, 3);
    if (timer % 8 == 4)
        QueueAnimTiles_EverGrande_Flowers(timer / 8, 4);
    if (timer % 8 == 5)
        QueueAnimTiles_EverGrande_Flowers(timer / 8, 5);
    if (timer % 8 == 6)
        QueueAnimTiles_EverGrande_Flowers(timer / 8, 6);
    if (timer % 8 == 7)
        QueueAnimTiles_EverGrande_Flowers(timer / 8, 7);
}

static void TilesetAnim_Pacifidlog(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Pacifidlog_LogBridges(timer / 16);
    if (timer % 16 == 1)
        QueueAnimTiles_Pacifidlog_WaterCurrents(timer / 16);
}

static void TilesetAnim_Petalburg(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Petalburg_Chimney_Smoke(timer >> 4);
    if (timer % 16 == 1)
        QueueAnimTiles_Petalburg_Watermill1(timer >> 4);
    //if (timer % 16 == 2)
        QueueAnimTiles_Petalburg_Watermill2(timer >> 4);
    //if (timer % 16 == 3)
        QueueAnimTiles_Petalburg_Watermill3(timer >> 4);
    //if (timer % 16 == 4)
        QueueAnimTiles_Petalburg_Watermill4(timer >> 4);
    //if (timer % 16 == 5)
        QueueAnimTiles_Petalburg_Watermill5(timer >> 4);
    //if (timer % 16 == 6)
        QueueAnimTiles_Petalburg_Watermill6(timer >> 4);
    //if (timer % 16 == 7)
        QueueAnimTiles_Petalburg_Watermill7(timer >> 4);
    //if (timer % 16 == 8)
        QueueAnimTiles_Petalburg_Watermill8(timer >> 4);
    //if (timer % 16 == 9)
        QueueAnimTiles_Petalburg_Watermill9(timer >> 4);
    //if (timer % 16 == 10)
        QueueAnimTiles_Petalburg_Watermill10(timer >> 4);
}

static void TilesetAnim_Rustboro(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Rustboro_Chimney_Smoke(timer >> 4);
}

static void TilesetAnim_Sootopolis(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Sootopolis_StormyWater(timer / 16);
}

static void TilesetAnim_Underwater(u16 timer)
{
    if (timer % 16 == 0)
        QueueAnimTiles_Underwater_Seaweed(timer / 16);
}

static void TilesetAnim_Cave(u16 timer)
{
    /*if (timer % 16 == 1)
        QueueAnimTiles_Cave_Lava(timer / 16);*/
}

static void TilesetAnim_BattleFrontierOutsideWest(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_BattleFrontierOutsideWest_Flag(timer / 8);
}

static void TilesetAnim_BattleFrontierOutsideEast(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_BattleFrontierOutsideEast_Flag(timer / 8);
}

static void TilesetAnim_BattleTent(u16 timer)
{
    if (timer % 8 == 0) {
        QueueAnimTiles_BattleTent_Tv_Ten(timer / 8);
        QueueAnimTiles_BattleTent_Tv_Poke(timer / 8);
        QueueAnimTiles_BattleTent_Tv_Trainer(timer / 8);
        QueueAnimTiles_BattleTent_Tv_Drowzee(timer / 8);
        QueueAnimTiles_BattleTent_Tv_Cliff(timer / 8);
    }
}

static void QueueAnimTiles_General_LandWaterEdge(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_General_LandWaterEdge);
    AppendTilesetAnimToBuffer(gTilesetAnims_General_LandWaterEdge[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(480)), 10 * TILE_SIZE_4BPP);
}

/*static void QueueAnimTiles_Lavaridge_Steam(u8 timer)
{
    u8 i = timer % ARRAY_COUNT(gTilesetAnims_Lavaridge_Steam);
    AppendTilesetAnimToBuffer(gTilesetAnims_Lavaridge_Steam[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 288)), 4 * TILE_SIZE_4BPP);

    i = (timer + 2) % (int)ARRAY_COUNT(gTilesetAnims_Lavaridge_Steam);
    AppendTilesetAnimToBuffer(gTilesetAnims_Lavaridge_Steam[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 292)), 4 * TILE_SIZE_4BPP);
}*/

static void QueueAnimTiles_Pacifidlog_LogBridges(u8 timer)
{
    u8 i = timer % ARRAY_COUNT(gTilesetAnims_Pacifidlog_LogBridges);
    AppendTilesetAnimToBuffer(gTilesetAnims_Pacifidlog_LogBridges[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 464)), 30 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Petalburg_Chimney_Smoke(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Petalburg_Chimney_Smoke);
    AppendTilesetAnimToBuffer(gTilesetAnims_Petalburg_Chimney_Smoke[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 374)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Rustboro_Chimney_Smoke(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Rustboro_Chimney_Smoke);
    AppendTilesetAnimToBuffer(gTilesetAnims_Rustboro_Chimney_Smoke[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 220)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Petalburg_Watermill1(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Petalburg_Watermill1);
    AppendTilesetAnimToBuffer(gTilesetAnims_Petalburg_Watermill1[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 155)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Petalburg_Watermill2(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Petalburg_Watermill2);
    AppendTilesetAnimToBuffer(gTilesetAnims_Petalburg_Watermill2[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 171)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Petalburg_Watermill3(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Petalburg_Watermill3);
    AppendTilesetAnimToBuffer(gTilesetAnims_Petalburg_Watermill3[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 187)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Petalburg_Watermill4(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Petalburg_Watermill4);
    AppendTilesetAnimToBuffer(gTilesetAnims_Petalburg_Watermill4[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 203)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Petalburg_Watermill5(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Petalburg_Watermill5);
    AppendTilesetAnimToBuffer(gTilesetAnims_Petalburg_Watermill5[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 219)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Petalburg_Watermill6(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Petalburg_Watermill6);
    AppendTilesetAnimToBuffer(gTilesetAnims_Petalburg_Watermill6[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 235)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Petalburg_Watermill7(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Petalburg_Watermill7);
    AppendTilesetAnimToBuffer(gTilesetAnims_Petalburg_Watermill7[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 251)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Petalburg_Watermill8(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Petalburg_Watermill8);
    AppendTilesetAnimToBuffer(gTilesetAnims_Petalburg_Watermill8[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 267)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Petalburg_Watermill9(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Petalburg_Watermill9);
    AppendTilesetAnimToBuffer(gTilesetAnims_Petalburg_Watermill9[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 283)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Petalburg_Watermill10(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Petalburg_Watermill10);
    AppendTilesetAnimToBuffer(gTilesetAnims_Petalburg_Watermill10[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 299)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Dewford_Turbine1(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Dewford_Turbine1);
    AppendTilesetAnimToBuffer(gTilesetAnims_Dewford_Turbine1[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 12)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Dewford_Turbine2(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Dewford_Turbine2);
    AppendTilesetAnimToBuffer(gTilesetAnims_Dewford_Turbine2[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 16)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Dewford_Turbine3(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Dewford_Turbine3);
    AppendTilesetAnimToBuffer(gTilesetAnims_Dewford_Turbine3[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 20)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Dewford_Turbine4(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Dewford_Turbine4);
    AppendTilesetAnimToBuffer(gTilesetAnims_Dewford_Turbine4[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 24)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Dewford_Turbine5(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Dewford_Turbine5);
    AppendTilesetAnimToBuffer(gTilesetAnims_Dewford_Turbine5[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 76)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Dewford_Turbine6(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Dewford_Turbine6);
    AppendTilesetAnimToBuffer(gTilesetAnims_Dewford_Turbine6[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 80)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Dewford_Flower(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Dewford_Flower);
    AppendTilesetAnimToBuffer(gTilesetAnims_Dewford_Flower[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 154)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Dewford_Sunflower1(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Dewford_Sunflower1);
    AppendTilesetAnimToBuffer(gTilesetAnims_Dewford_Sunflower1[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 218)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Dewford_Sunflower2(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Dewford_Sunflower2);
    AppendTilesetAnimToBuffer(gTilesetAnims_Dewford_Sunflower2[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 234)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Underwater_Seaweed(u8 timer)
{
    u8 i = timer % ARRAY_COUNT(gTilesetAnims_Underwater_Seaweed);
    AppendTilesetAnimToBuffer(gTilesetAnims_Underwater_Seaweed[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 496)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Pacifidlog_WaterCurrents(u8 timer)
{
    u8 i = timer % ARRAY_COUNT(gTilesetAnims_Pacifidlog_WaterCurrents);
    AppendTilesetAnimToBuffer(gTilesetAnims_Pacifidlog_WaterCurrents[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 496)), 8 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Mauville_Flowers(u16 timer_div, u8 timer_mod)
{
    timer_div -= timer_mod;
    if (timer_div < min(ARRAY_COUNT(gTilesetAnims_Mauville_Flower1), ARRAY_COUNT(gTilesetAnims_Mauville_Flower2)))
    {
        timer_div %= min(ARRAY_COUNT(gTilesetAnims_Mauville_Flower1), ARRAY_COUNT(gTilesetAnims_Mauville_Flower2));
        AppendTilesetAnimToBuffer(gTilesetAnims_Mauville_Flower1[timer_div], gTilesetAnims_Mauville_Flower1_VDests[timer_mod], 4 * TILE_SIZE_4BPP);
        AppendTilesetAnimToBuffer(gTilesetAnims_Mauville_Flower2[timer_div], gTilesetAnims_Mauville_Flower2_VDests[timer_mod], 4 * TILE_SIZE_4BPP);
    }
    else
    {
        timer_div %= min(ARRAY_COUNT(gTilesetAnims_Mauville_Flower1_B), ARRAY_COUNT(gTilesetAnims_Mauville_Flower2_B));
        AppendTilesetAnimToBuffer(gTilesetAnims_Mauville_Flower1_B[timer_div], gTilesetAnims_Mauville_Flower1_VDests[timer_mod], 4 * TILE_SIZE_4BPP);
        AppendTilesetAnimToBuffer(gTilesetAnims_Mauville_Flower2_B[timer_div], gTilesetAnims_Mauville_Flower2_VDests[timer_mod], 4 * TILE_SIZE_4BPP);
    }
}

/*static void QueueAnimTiles_Lavaridge_Lava(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Lavaridge_Cave_Lava);
    AppendTilesetAnimToBuffer(gTilesetAnims_Lavaridge_Cave_Lava[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 160)), 4 * TILE_SIZE_4BPP);
}*/

static void QueueAnimTiles_EverGrande_Flowers(u16 timer_div, u8 timer_mod)
{
    timer_div -= timer_mod;
    timer_div %= ARRAY_COUNT(gTilesetAnims_EverGrande_Flowers);

    AppendTilesetAnimToBuffer(gTilesetAnims_EverGrande_Flowers[timer_div], gTilesetAnims_EverGrande_VDests[timer_mod], 4 * TILE_SIZE_4BPP);
}

/*static void QueueAnimTiles_Cave_Lava(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Lavaridge_Cave_Lava);
    AppendTilesetAnimToBuffer(gTilesetAnims_Lavaridge_Cave_Lava[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 416)), 4 * TILE_SIZE_4BPP);
}*/

static void QueueAnimTiles_Dewford_Flag(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Dewford_Flag);
    AppendTilesetAnimToBuffer(gTilesetAnims_Dewford_Flag[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 170)), 6 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_BattleFrontierOutsideWest_Flag(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BattleFrontierOutsideWest_Flag);
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideWest_Flag[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 218)), 6 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_BattleFrontierOutsideEast_Flag(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BattleFrontierOutsideEast_Flag);
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleFrontierOutsideEast_Flag[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 218)), 6 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Slateport_Balloons(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Slateport_Balloons);
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport_Balloons[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 224)), 4 * TILE_SIZE_4BPP);
}


static void QueueAnimTiles_Slateport_Water0(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Slateport_Water0);
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport_Water0[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 69)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Slateport_Water1(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Slateport_Water1);
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport_Water1[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 85)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Slateport_Water2(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Slateport_Water2);
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport_Water2[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 101)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Slateport_Water3(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Slateport_Water3);
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport_Water3[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 117)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Slateport_Water4(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Slateport_Water4);
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport_Water4[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 133)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Slateport_Water5(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Slateport_Water5);
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport_Water5[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 134)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Slateport_Water6(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Slateport_Water6);
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport_Water6[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 135)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Slateport_Water7(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Slateport_Water7);
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport_Water7[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 70)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Slateport_Water8(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Slateport_Water8);
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport_Water8[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 86)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Slateport_Water9(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Slateport_Water9);
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport_Water9[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 87)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Slateport_SmallRockTop(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Slateport_SmallRockTop);
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport_SmallRockTop[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 182)), 2 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Slateport_SmallRockBottom(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Slateport_SmallRockBottom);
    AppendTilesetAnimToBuffer(gTilesetAnims_Slateport_SmallRockBottom[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 198)), 2 * TILE_SIZE_4BPP);
}

/*static void TilesetAnim_MauvilleGym(u16 timer)
{
    if (timer % 2 == 0)
        QueueAnimTiles_MauvilleGym_ElectricGates(timer / 2);
}*/

static void TilesetAnim_SootopolisGym(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_SootopolisGym_Waterfalls(timer / 8);
}

static void TilesetAnim_EliteFour(u16 timer)
{
    if (timer % 64 == 1)
        QueueAnimTiles_EliteFour_GroundLights(timer / 64);
    if (timer % 8 == 1)
        QueueAnimTiles_EliteFour_WallLights(timer / 8);
}

static void TilesetAnim_BikeShop(u16 timer)
{
    if (timer % 4 == 0)
        QueueAnimTiles_BikeShop_BlinkingLights(timer / 4);
}

static void TilesetAnim_GenericBuilding(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_GenericBuilding_SunBeams(timer >> 6);
    if (timer % 8 == 1)
    {
        QueueAnimTiles_GenericBuilding_Water0(timer >> 5);
        QueueAnimTiles_GenericBuilding_Water1(timer >> 5);
        QueueAnimTiles_GenericBuilding_Water2(timer >> 5);
        QueueAnimTiles_GenericBuilding_Water3(timer >> 5);
        QueueAnimTiles_GenericBuilding_Water4(timer >> 5);
        QueueAnimTiles_GenericBuilding_Water5(timer >> 5);
        QueueAnimTiles_GenericBuilding_Water6(timer >> 5);
        QueueAnimTiles_GenericBuilding_Water7(timer >> 5);
        QueueAnimTiles_GenericBuilding_Water8(timer >> 5);
        QueueAnimTiles_GenericBuilding_Water9(timer >> 5);
        QueueAnimTiles_GenericBuilding_Rapid(timer >> 5);
    }
    if (timer % 8 == 2)
        QueueAnimTiles_GenericBuilding_BigRock(timer >> 4);
    if (timer % 8 == 3)
    {
        QueueAnimTiles_GenericBuilding_SmallRockTop(timer >> 4);
        QueueAnimTiles_GenericBuilding_SmallRockBottom(timer >> 4);
    }
    if (timer % 8 == 4)
        QueueAnimTiles_GenericBuilding_Wood(timer >> 5);
}

static void TilesetAnim_BattlePyramid(u16 timer)
{
    if (timer % 8 == 0)
    {
        QueueAnimTiles_BattlePyramid_Torch(timer / 8);
        QueueAnimTiles_BattlePyramid_StatueShadow(timer / 8);
    }
}

static void TilesetAnim_RustboroGym(u16 timer)
{
    if (timer % 8 == 0)
    {
        QueueAnimTiles_RustboroGym_Water0(timer >> 5);
        QueueAnimTiles_RustboroGym_Water1(timer >> 5);
        QueueAnimTiles_RustboroGym_Water2(timer >> 5);
        QueueAnimTiles_RustboroGym_Water3(timer >> 5);
        QueueAnimTiles_RustboroGym_Water4(timer >> 5);
        QueueAnimTiles_RustboroGym_Water5(timer >> 5);
        QueueAnimTiles_RustboroGym_Water6(timer >> 5);
        QueueAnimTiles_RustboroGym_Water7(timer >> 5);
        QueueAnimTiles_RustboroGym_Water8(timer >> 5);
        QueueAnimTiles_RustboroGym_Water9(timer >> 5);
        QueueAnimTiles_RustboroGym_Rapid(timer >> 5);
    }
    if (timer % 16 == 1)
    {
        QueueAnimTiles_RustboroGym_GreenBeams(timer >> 6);
        QueueAnimTiles_RustboroGym_GreyBeams(timer >> 6);
    }
    if (timer % 16 == 2)
        QueueAnimTiles_RustboroGym_Weed(timer >> 4);
}

static void TilesetAnim_PokemonCenter(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_PokemonCenter_Map(timer >> 5);
    if (timer % 4 == 1)
        QueueAnimTiles_PokemonCenter_Stripe(timer >> 2);
}

static void TilesetAnim_Lilycove(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Lilycove_Flag(timer / 8);
}

static void TilesetAnim_Fallarbor(u16 timer)
{
    if (timer % 8 == 0)
        QueueAnimTiles_Fallarbor_Campfire(timer / 8);
    if (timer % 8 == 1)
        QueueAnimTiles_Fallarbor_Smoke(timer >> 4);
}

static void TilesetAnim_BattleDome(u16 timer)
{
    if (timer % 4 == 0)
        BlendAnimPalette_BattleDome_FloorLights(timer / 4);
}

static void TilesetAnim_BattleDome2(u16 timer)
{
    if (timer % 4 == 0)
        BlendAnimPalette_BattleDome_FloorLightsNoBlend(timer / 4);
}

static void QueueAnimTiles_Building_TVTurnedOn(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Building_TvTurnedOn);
    AppendTilesetAnimToBuffer(gTilesetAnims_Building_TvTurnedOn[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(496)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_SootopolisGym_Waterfalls(u16 timer)
{
    u16 i = timer % min(ARRAY_COUNT(gTilesetAnims_SootopolisGym_SideWaterfall), ARRAY_COUNT(gTilesetAnims_SootopolisGym_FrontWaterfall));
    AppendTilesetAnimToBuffer(gTilesetAnims_SootopolisGym_SideWaterfall[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 496)), 12 * TILE_SIZE_4BPP);
    AppendTilesetAnimToBuffer(gTilesetAnims_SootopolisGym_FrontWaterfall[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 464)), 20 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_EliteFour_WallLights(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_EliteFour_WallLights);
    AppendTilesetAnimToBuffer(gTilesetAnims_EliteFour_WallLights[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 504)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_EliteFour_GroundLights(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_EliteFour_FloorLight);
    AppendTilesetAnimToBuffer(gTilesetAnims_EliteFour_FloorLight[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 480)), 4 * TILE_SIZE_4BPP);
}

/*static void QueueAnimTiles_MauvilleGym_ElectricGates(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_MauvilleGym_ElectricGates);
    AppendTilesetAnimToBuffer(gTilesetAnims_MauvilleGym_ElectricGates[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 144)), 16 * TILE_SIZE_4BPP);
}*/

static void QueueAnimTiles_BikeShop_BlinkingLights(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BikeShop_BlinkingLights);
    AppendTilesetAnimToBuffer(gTilesetAnims_BikeShop_BlinkingLights[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 496)), 9 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_SunBeams(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_SunBeams);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_SunBeams[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 10)), 6 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_Water0(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_Water0);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_Water0[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 221)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_Water1(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_Water1);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_Water1[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 237)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_Water2(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_Water2);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_Water2[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 253)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_Water3(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_Water3);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_Water3[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 269)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_Water4(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_Water4);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_Water4[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 285)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_Water5(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_Water5);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_Water5[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 286)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_Water6(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_Water6);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_Water6[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 287)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_Water7(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_Water7);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_Water7[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 334)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_Water8(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_Water8);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_Water8[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 350)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_Water9(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_Water9);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_Water9[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 351)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_BigRock(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_BigRock);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_BigRock[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 346)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_SmallRockTop(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_SmallRockTop);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_SmallRockTop[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 222)), 2 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_SmallRockBottom(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_SmallRockBottom);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_SmallRockBottom[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 238)), 2 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_Wood(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_Wood);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_Wood[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 206)), 2 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_GenericBuilding_Rapid(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_GenericBuilding_Rapid);
    AppendTilesetAnimToBuffer(gTilesetAnims_GenericBuilding_Rapid[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 188)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Sootopolis_StormyWater(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Sootopolis_StormyWater);
    AppendTilesetAnimToBuffer(gTilesetAnims_Sootopolis_StormyWater[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 240)), 96 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_BattlePyramid_Torch(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BattlePyramid_Torch);
    AppendTilesetAnimToBuffer(gTilesetAnims_BattlePyramid_Torch[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 151)), 8 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_BattlePyramid_StatueShadow(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BattlePyramid_StatueShadow);
    AppendTilesetAnimToBuffer(gTilesetAnims_BattlePyramid_StatueShadow[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 135)), 8 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_BattleTent_Tv_Ten(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BattleTent_Tv_Ten);
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleTent_Tv_Ten[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 148)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_BattleTent_Tv_Poke(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BattleTent_Tv_Poke);
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleTent_Tv_Poke[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 152)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_BattleTent_Tv_Trainer(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BattleTent_Tv_Trainer);
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleTent_Tv_Trainer[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 168)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_BattleTent_Tv_Drowzee(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BattleTent_Tv_Drowzee);
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleTent_Tv_Drowzee[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 156)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_BattleTent_Tv_Cliff(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_BattleTent_Tv_Cliff);
    AppendTilesetAnimToBuffer(gTilesetAnims_BattleTent_Tv_Cliff[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 164)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_Water0(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_Water0);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_Water0[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 45)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_Water1(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_Water1);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_Water1[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 61)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_Water2(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_Water2);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_Water2[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 77)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_Water3(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_Water3);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_Water3[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 93)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_Water4(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_Water4);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_Water4[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 109)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_Water5(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_Water5);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_Water5[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 110)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_Water6(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_Water6);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_Water6[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 111)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_Water7(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_Water7);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_Water7[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 46)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_Water8(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_Water8);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_Water8[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 62)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_Water9(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_Water9);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_Water9[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 63)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_GreenBeams(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_GreenBeams);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_GreenBeams[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 5)), 9 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_GreyBeams(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_GreyBeams);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_GreyBeams[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 21)), 9 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_Weed(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_Weed);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_Weed[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 231)), 1 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_RustboroGym_Rapid(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_RustboroGym_Rapid);
    AppendTilesetAnimToBuffer(gTilesetAnims_RustboroGym_Rapid[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 171)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_PokemonCenter_Map(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_PokemonCenter_Map);
    AppendTilesetAnimToBuffer(gTilesetAnims_PokemonCenter_Map[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 296)), 8 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_PokemonCenter_Stripe(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_PokemonCenter_Stripe);
    AppendTilesetAnimToBuffer(gTilesetAnims_PokemonCenter_Stripe[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 243)), 4 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Lilycove_Flag(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Lilycove_Flag);
    AppendTilesetAnimToBuffer(gTilesetAnims_Lilycove_Flag[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 106)), 6 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Fallarbor_Campfire(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Fallarbor_Campfire);
    AppendTilesetAnimToBuffer(gTilesetAnims_Fallarbor_Campfire[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 309)), 6 * TILE_SIZE_4BPP);
}

static void QueueAnimTiles_Fallarbor_Smoke(u16 timer)
{
    u16 i = timer % ARRAY_COUNT(gTilesetAnims_Fallarbor_Smoke);
    AppendTilesetAnimToBuffer(gTilesetAnims_Fallarbor_Smoke[i], (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(NUM_TILES_IN_PRIMARY + 293)), 4 * TILE_SIZE_4BPP);
}

static void BlendAnimPalette_BattleDome_FloorLights(u16 timer)
{
    CpuCopy16(sTilesetAnims_BattleDomeFloorLightPals[timer % ARRAY_COUNT(sTilesetAnims_BattleDomeFloorLightPals)], &gPlttBufferUnfaded[0x80], 32);
    BlendPalette(0x80, 16, gPaletteFade.y, gPaletteFade.blendColor & 0x7FFF);
    if ((u8)FindTaskIdByFunc(Task_BattleTransition_Intro) != TASK_NONE)
    {
        sSecondaryTilesetAnimCallback = TilesetAnim_BattleDome2;
        sSecondaryTilesetAnimCounterMax = 32;
    }
}

static void BlendAnimPalette_BattleDome_FloorLightsNoBlend(u16 timer)
{
    CpuCopy16(sTilesetAnims_BattleDomeFloorLightPals[timer % ARRAY_COUNT(sTilesetAnims_BattleDomeFloorLightPals)], &gPlttBufferUnfaded[0x80], 32);
    if ((u8)FindTaskIdByFunc(Task_BattleTransition_Intro) == TASK_NONE)
    {
        BlendPalette(0x80, 16, gPaletteFade.y, gPaletteFade.blendColor & 0x7FFF);
        if (!--sSecondaryTilesetAnimCounterMax)
            sSecondaryTilesetAnimCallback = NULL;
    }
}
