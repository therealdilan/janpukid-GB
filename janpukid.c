#include <gb/gb.h>
#include <stdio.h>

#include "assets/janpu.c"
#include "assets/world1map.c"
#include "assets/world1tiles.c"


void main() 
{
    set_bkg_data(0,10,world1tiles);
    set_bkg_tiles(0,0,40,18,world1map);

    UINT8 currentSpriteIndex = 0;
    set_sprite_data(0, 2, janpu);
    set_sprite_tile(0, 0);
    move_sprite(0, 88, 78);
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

