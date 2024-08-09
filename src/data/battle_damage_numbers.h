static const u32 sDamageNumbers[] = INCBIN_U32("graphics/battle_interface/damage_numbers.4bpp");

static const u16 sDamageNumber_NormalPalette[] = INCBIN_U16("graphics/battle_interface/damage_num_normal.gbapal");

// This image table contains all 10 digits, repeated multiple times with different colors.
// This is the solution I came up with to be able to assign a context-sensitive color (e.g. restoring HP = green)
// under the limitation that it's possible for multiple sets of numbers to be on screen at once (e.g. finishing off a mon with a draining move)
static const struct SpriteFrameImage sDamageNumberPicTable[] =
{
	overworld_frame(sDamageNumbers, 2, 2, 0), // normal
	overworld_frame(sDamageNumbers, 2, 2, 1),
	overworld_frame(sDamageNumbers, 2, 2, 2),
	overworld_frame(sDamageNumbers, 2, 2, 3),
	overworld_frame(sDamageNumbers, 2, 2, 4),
	overworld_frame(sDamageNumbers, 2, 2, 5),
	overworld_frame(sDamageNumbers, 2, 2, 6),
	overworld_frame(sDamageNumbers, 2, 2, 7),
	overworld_frame(sDamageNumbers, 2, 2, 8),
	overworld_frame(sDamageNumbers, 2, 2, 9),
	overworld_frame(sDamageNumbers, 2, 2, 10), // green (healing)
	overworld_frame(sDamageNumbers, 2, 2, 11),
	overworld_frame(sDamageNumbers, 2, 2, 12),
	overworld_frame(sDamageNumbers, 2, 2, 13),
	overworld_frame(sDamageNumbers, 2, 2, 14),
	overworld_frame(sDamageNumbers, 2, 2, 15),
	overworld_frame(sDamageNumbers, 2, 2, 16),
	overworld_frame(sDamageNumbers, 2, 2, 17),
	overworld_frame(sDamageNumbers, 2, 2, 18),
	overworld_frame(sDamageNumbers, 2, 2, 19),
	overworld_frame(sDamageNumbers, 2, 2, 20), // orange (Super Effective)
	overworld_frame(sDamageNumbers, 2, 2, 21),
	overworld_frame(sDamageNumbers, 2, 2, 22),
	overworld_frame(sDamageNumbers, 2, 2, 23),
	overworld_frame(sDamageNumbers, 2, 2, 24),
	overworld_frame(sDamageNumbers, 2, 2, 25),
	overworld_frame(sDamageNumbers, 2, 2, 26),
	overworld_frame(sDamageNumbers, 2, 2, 27),
	overworld_frame(sDamageNumbers, 2, 2, 28),
	overworld_frame(sDamageNumbers, 2, 2, 29),
	overworld_frame(sDamageNumbers, 2, 2, 30), // gray (Not Very Effective)
	overworld_frame(sDamageNumbers, 2, 2, 31),
	overworld_frame(sDamageNumbers, 2, 2, 32),
	overworld_frame(sDamageNumbers, 2, 2, 33),
	overworld_frame(sDamageNumbers, 2, 2, 34),
	overworld_frame(sDamageNumbers, 2, 2, 35),
	overworld_frame(sDamageNumbers, 2, 2, 36),
	overworld_frame(sDamageNumbers, 2, 2, 37),
	overworld_frame(sDamageNumbers, 2, 2, 38),
	overworld_frame(sDamageNumbers, 2, 2, 39),
};

static const struct OamData sDamageNumberOam =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sDamageNumsAnim_0[] =
{
    ANIMCMD_FRAME(0, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_1[] =
{
    ANIMCMD_FRAME(1, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_2[] =
{
    ANIMCMD_FRAME(2, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_3[] =
{
    ANIMCMD_FRAME(3, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_4[] =
{
    ANIMCMD_FRAME(4, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_5[] =
{
    ANIMCMD_FRAME(5, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_6[] =
{
    ANIMCMD_FRAME(6, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_7[] =
{
    ANIMCMD_FRAME(7, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_8[] =
{
    ANIMCMD_FRAME(8, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_9[] =
{
    ANIMCMD_FRAME(9, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_Healing0[] =
{
    ANIMCMD_FRAME(10, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_Healing1[] =
{
    ANIMCMD_FRAME(11, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_Healing2[] =
{
    ANIMCMD_FRAME(12, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_Healing3[] =
{
    ANIMCMD_FRAME(13, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_Healing4[] =
{
    ANIMCMD_FRAME(14, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_Healing5[] =
{
    ANIMCMD_FRAME(15, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_Healing6[] =
{
    ANIMCMD_FRAME(16, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_Healing7[] =
{
    ANIMCMD_FRAME(17, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_Healing8[] =
{
    ANIMCMD_FRAME(18, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_Healing9[] =
{
    ANIMCMD_FRAME(19, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_SE0[] =
{
    ANIMCMD_FRAME(20, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_SE1[] =
{
    ANIMCMD_FRAME(21, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_SE2[] =
{
    ANIMCMD_FRAME(22, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_SE3[] =
{
    ANIMCMD_FRAME(23, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_SE4[] =
{
    ANIMCMD_FRAME(24, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_SE5[] =
{
    ANIMCMD_FRAME(25, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_SE6[] =
{
    ANIMCMD_FRAME(26, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_SE7[] =
{
    ANIMCMD_FRAME(27, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_SE8[] =
{
    ANIMCMD_FRAME(28, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_SE9[] =
{
    ANIMCMD_FRAME(29, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_NVE0[] =
{
    ANIMCMD_FRAME(30, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_NVE1[] =
{
    ANIMCMD_FRAME(31, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_NVE2[] =
{
    ANIMCMD_FRAME(32, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_NVE3[] =
{
    ANIMCMD_FRAME(33, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_NVE4[] =
{
    ANIMCMD_FRAME(34, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_NVE5[] =
{
    ANIMCMD_FRAME(35, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_NVE6[] =
{
    ANIMCMD_FRAME(36, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_NVE7[] =
{
    ANIMCMD_FRAME(37, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_NVE8[] =
{
    ANIMCMD_FRAME(38, 30),
	ANIMCMD_END
};

static const union AnimCmd sDamageNumsAnim_NVE9[] =
{
    ANIMCMD_FRAME(39, 30),
	ANIMCMD_END
};

static const union AnimCmd *const sDamageNumAnims[] =
{
    sDamageNumsAnim_0,
    sDamageNumsAnim_1,
    sDamageNumsAnim_2,
    sDamageNumsAnim_3,
    sDamageNumsAnim_4,
    sDamageNumsAnim_5,
    sDamageNumsAnim_6,
    sDamageNumsAnim_7,
    sDamageNumsAnim_8,
    sDamageNumsAnim_9,
    sDamageNumsAnim_Healing0,
    sDamageNumsAnim_Healing1,
    sDamageNumsAnim_Healing2,
    sDamageNumsAnim_Healing3,
    sDamageNumsAnim_Healing4,
    sDamageNumsAnim_Healing5,
    sDamageNumsAnim_Healing6,
    sDamageNumsAnim_Healing7,
    sDamageNumsAnim_Healing8,
    sDamageNumsAnim_Healing9,
    sDamageNumsAnim_SE0,
    sDamageNumsAnim_SE1,
    sDamageNumsAnim_SE2,
    sDamageNumsAnim_SE3,
    sDamageNumsAnim_SE4,
    sDamageNumsAnim_SE5,
    sDamageNumsAnim_SE6,
    sDamageNumsAnim_SE7,
    sDamageNumsAnim_SE8,
    sDamageNumsAnim_SE9,
    sDamageNumsAnim_NVE0,
    sDamageNumsAnim_NVE1,
    sDamageNumsAnim_NVE2,
    sDamageNumsAnim_NVE3,
    sDamageNumsAnim_NVE4,
    sDamageNumsAnim_NVE5,
    sDamageNumsAnim_NVE6,
    sDamageNumsAnim_NVE7,
    sDamageNumsAnim_NVE8,
    sDamageNumsAnim_NVE9,
};

#define PALETTE_TAG_DAMAGE_NUMS 33033

static const struct SpritePalette sDamageNumSpritePalette_Normal =
{
    .data = sDamageNumber_NormalPalette,
    .tag = PALETTE_TAG_DAMAGE_NUMS
};

static const struct SpritePalette sDamageNumSpritePalette_Heal =
{
    .data = sDamageNumber_NormalPalette,
    .tag = PALETTE_TAG_DAMAGE_NUMS
};

static const struct SpritePalette sDamageNumSpritePalette_SE =
{
    .data = sDamageNumber_NormalPalette,
    .tag = PALETTE_TAG_DAMAGE_NUMS
};

static const struct SpritePalette sDamageNumSpritePalette_NVE =
{
    .data = sDamageNumber_NormalPalette,
    .tag = PALETTE_TAG_DAMAGE_NUMS
};

static void SpriteCB_DamageNumber(struct Sprite *sprite);

static const struct SpriteTemplate sDamageNumberSpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_DAMAGE_NUMS,
    .oam = &sDamageNumberOam,
    .anims = sDamageNumAnims,
    .images = sDamageNumberPicTable,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_DamageNumber,
};
