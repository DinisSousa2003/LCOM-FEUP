#include "model.h"

/*MENU MODEL*/

#define ENTRIES 3

int menu_entries[ENTRIES] = {PLAYER1_SELECTED_IMG, PLAYER2_SELECTED_IMG, ABOUT_SELECTED_IMG};
int curEntry = 0;


void (addMenuEntry)(){
    if((curEntry + 1) >= ENTRIES) return;
    curEntry++;
}

void (backMenuEntry)(){
    if((curEntry - 1) < 0) return;
    curEntry--;
}

int (getCurrentEntryImg)(){
    return menu_entries[curEntry];
}

/*GAME MODEL*/

struct Player player = {650, 300, 0xffffff, 15, 40, 20};

struct Ball ball = {398, 298, 0xffffff, 20, 10, 2, 2};

struct Arena arena = {500, 100, 750, 50, 400, 700};

struct Player getPlayer(){
    return player;
}

struct Arena getArena(){
    return arena;
}

struct Ball getBall(){
    return ball;
}

void (playerDown)(){
    if(player.y_pos <= (arena.max_y - player.height - player.vel)){
        player.y_pos += player.vel;
    }
    else if (player.y_pos > (arena.max_y - player.height - player.vel))
    {
        player.y_pos += (arena.max_y - player.y_pos - player.height);
    }
}

void (playerUp)(){
    if(player.y_pos >= (arena.min_y + player.vel)){
        player.y_pos -= player.vel;
    }
    else if (player.y_pos < (arena.min_y + player.vel))
    {
        player.y_pos -= (player.y_pos - arena.min_y);
    }
}

bool ballCollidesPlayer(){
    if(!((ball.y_pos + ball.height >= player.y_pos) && (ball.y_pos <= player.y_pos + player.height))){
        return false;
    }
    if(!((ball.x_pos + ball.width >= player.x_pos) && (ball.x_pos <= player.x_pos + player.width))){
        return false;
    }
    return true;
}

void (moveBall)(){
    if(ball.x_pos + ball.vel_x < arena.min_x || ball.x_pos + ball.vel_x > arena.max_x ){
        ball.vel_x = -ball.vel_x;
    }
    if(ball.y_pos + ball.vel_y < arena.min_y || ball.y_pos + ball.vel_y > arena.max_y ){
        ball.vel_y = -ball.vel_y;
    }
    if(ballCollidesPlayer()){
        ball.vel_x = -ball.vel_x;
    }

    ball.x_pos += ball.vel_x;
    ball.y_pos += ball.vel_y;
}
