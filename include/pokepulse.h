#ifndef GUARD_POKEPULSE_H
#define GUARD_POKEPULSE_H

struct PokePulse
{
    u8 bg2TilemapBuffer[BG_SCREEN_SIZE];
    MainCallback exitCallback;
    MainCallback newScreenCallback;
    u8 graphicsLoadState;
    u8 iconSpriteIds[5];
    u8 selection;
    u8 selectionBoxSpriteId;
    u8 inputTaskId;
    u8 pokepulseIconSpriteId;
};

struct PokePulseApplication 
{
    const u8 *name;
    const u8 *desc;
    const struct SpriteTemplate *iconTemplate;
    u16 flag;
    MainCallback openCallback;
};

void CB2_StartPokePulseFromField(void);
void GoToPokePulse(MainCallback cb);

#endif // GUARD_POKEPULSE_H