#include <gb/gb.h>
#include <stdio.h>

#include "assets/janpu.c"


void main() 
{
    UINT8 currentSpriteIndex = 0;
    set_sprite_data(0, 2, janpu);
    set_sprite_tile(0, 0);
    move_sprite(0, 88, 78);
    SHOW_SPRITES;

    while (1)
    {
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

