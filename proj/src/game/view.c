#include "view.h"

extern int menu_entries[];

void (drawMenu)(){
    draw_sprite(0, 0, game_images[MENU_IMG]);
    draw_sprite(0, 0, game_images[getCurrentEntryImg()]);
}

void (drawPlayer)(){
    vg_draw_rectangle(getPlayerX(), getPlayerY(), 20, 40, 0xFF0000);
}
