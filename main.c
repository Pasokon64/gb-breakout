#include "main.h"

const int SCREEN_WIDTH = 160;
const int SCREEN_HEIGHT = 144;

int gameSpeed = 0;

void main()
{
    /* Setup player */
    set_sprite_data(0, 3, TilePlayer);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 1);
    set_sprite_tile(2, 2);

    move_sprite(0, SCREEN_WIDTH / 2 - 8, SCREEN_HEIGHT + 8);
    move_sprite(1, SCREEN_WIDTH / 2, SCREEN_HEIGHT + 8);
    move_sprite(2, SCREEN_WIDTH / 2 + 8, SCREEN_HEIGHT + 8);

    SHOW_SPRITES;

    while (true)
    {
        keyboard();
        delay(10 - gameSpeed);
    }
}

void keyboard()
{
    switch (joypad())
    {
    case J_LEFT:
        movePlayer(-1);
        break;
    case J_RIGHT:
        movePlayer(1);
        break;
    default:
        break;
    }
}

void movePlayer(int x)
{
    scroll_sprite(0, x, 0);
    scroll_sprite(1, x, 0);
    scroll_sprite(2, x, 0);
}