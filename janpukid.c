#include <gb/gb.h>
#include <gbdk/font.h>

#include "assets/janpu.c"
#include "assets/world1map.c"
#include "assets/world1tiles.c"
#include "assets/windowmap.c"


void main() 
{
    font_t min_font;

    font_init();
    min_font = font_load(font_min); 
    font_set(min_font);

    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;

    set_bkg_data(36,8,world1tiles);
    set_bkg_tiles(0,0,40,18,world1map);
    
    UINT8 currentSpriteIndex = 0;
    set_sprite_data(0, 2, janpu);

    set_win_tiles(0,0,9,1,windowmap);

    set_sprite_tile(0, 0);
    move_sprite(0, 88, 78);
    move_win(12,132);

    SHOW_WIN;
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    while (1)
    {
        scroll_bkg(1, 0);
        switch (joypad())
        {
        case J_LEFT:
            scroll_sprite(0, -1, 0);
            currentSpriteIndex = 1;
            set_sprite_tile(0, currentSpriteIndex);
            break;
        case J_RIGHT:
            currentSpriteIndex = 0;
            scroll_sprite(0, 1, 0);
            set_sprite_tile(0, currentSpriteIndex);
            break;
        case J_UP:
            currentSpriteIndex = 0;
            scroll_sprite(0, 0, -1);
            set_sprite_tile(0, currentSpriteIndex);
            break;
        case J_DOWN:
            currentSpriteIndex = 1;
            scroll_sprite(0, 0, 1);
            set_sprite_tile(0, currentSpriteIndex);
            break;
        default:
            break;
        }
        delay(10);
    }
    
}

