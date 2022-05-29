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

void (drawArena)(){
    vg_draw_hline(50, 100, 700, 0xffffff);
    vg_draw_vline(50, 100, 400, 0xffffff);

    for (size_t i = 0; i <= 400; i+=30)
    {
        vg_draw_vline(400, 100+i, 10, 0xffffff);
    }

    vg_draw_hline(50, 500, 700, 0xffffff);
    vg_draw_vline(750, 100, 400, 0xffffff);
}
