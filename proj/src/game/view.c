#include "view.h"

extern int menu_entries[];

void (drawMenu)(){
    draw_sprite(0, 0, game_images[MENU_IMG]);
    draw_sprite(0, 0, game_images[getCurrentEntryImg()]);
}

void (drawPlayer)(){
    draw_rectangle(0xffffff, getPlayerX(), getPlayerY(), 20, 40);
}

void (drawGame)(){
    draw_rectangle(0, 0, 0, 800, 600);
    drawPlayer();
}
