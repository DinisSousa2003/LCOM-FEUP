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

struct Player player2 = {150, 300, 0xffffff, 5, 40, 20};

struct Ball ball = {398, 298, 0xffffff, 20, 10, 4, 4};

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

bool goal(){
    if(ball.x_pos == arena.min_x && (ball.y_pos >=270 && ball.y_pos <= 330)){
        //pontuacao para player 2
        return true;
    }
     if(ball.x_pos == arena.max_x && (ball.y_pos >=270 && ball.y_pos <= 330)){
        //pontuacao para player 1
        return true;
    }
    return false;

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
bool ballCollidesPlayer2(){
    if(!((ball.y_pos + ball.height >= player2.y_pos) && (ball.y_pos <= player2.y_pos + player2.height))){
        return false;
    }
    if(!((ball.x_pos + ball.width >= player2.x_pos) && (ball.x_pos <= player2.x_pos + player2.width))){
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
    if(ballCollidesPlayer2()){
        ball.vel_x = -ball.vel_x;
    }

    ball.x_pos += ball.vel_x;
    ball.y_pos += ball.vel_y;
}

void (movePlayer2)(){
    //idea of moving not good yet
    //pc player down (code duplicate)
    if(ball.vel_y>0){
        if(player2.y_pos <= (arena.max_y - player2.height - player2.vel)){
            player2.y_pos += player2.vel;
        }
        else if (player2.y_pos > (arena.max_y - player2.height - player2.vel))
        {
            player2.y_pos += (arena.max_y - player2.y_pos - player2.height);
        }
    }
    //pc player up
    else if(ball.vel_y<0){
        if(player2.y_pos >= (arena.min_y + player2.vel)){
            player2.y_pos -= player2.vel;
        }
        else if (player2.y_pos < (arena.min_y + player2.vel))
        {
            player2.y_pos -= (player2.y_pos - arena.min_y);
        }
    }
}
