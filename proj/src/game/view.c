#include "view.h"


/*MENU VIEW*/

extern int menu_entries[];

void (drawMenu)(){
    draw_sprite(0, 0, game_images[MENU_IMG]);
    draw_sprite(0, 0, game_images[getCurrentEntryImg()]);
}

/*GAME_VIEW*/
extern struct Player player;
extern struct Player PCplayer;
extern struct Arena arena;
extern struct Ball ball;

void (drawPlayer)(){
    draw_rectangle(player.color, player.x_pos, player.y_pos, player.width, player.height);
}
void (drawPCPlayer)(){
    draw_rectangle(PCplayer.color, PCplayer.x_pos, PCplayer.y_pos, PCplayer.width, PCplayer.height);
}

void (drawBall)(){
    draw_rectangle(ball.color, ball.x_pos, ball.y_pos, ball.width, ball.height);
}

void (drawGame)(){
    draw_rectangle(0, 0, 0, 800, 600);
    drawPlayer();
    drawPCPlayer();
    drawBall();
}

void (drawArena)(){
    vg_draw_hline(arena.min_x, arena.min_y, arena.width, 0xffffff);
    vg_draw_vline(arena.min_x, arena.min_y, 170, 0xffffff);
    vg_draw_vline(arena.min_x, arena.min_y + 230, 170, 0xffffff);

    for (int i = 0; i <= arena.height; i+=30)
    {
        vg_draw_vline(400, 100+i, 10, 0xffffff);
    }

    vg_draw_hline(arena.min_x, arena.max_y, arena.width, 0xffffff);
    vg_draw_vline(arena.max_x, arena.min_y, 170, 0xffffff);
    vg_draw_vline(arena.max_x, arena.min_y + 230, 170, 0xffffff);

}
