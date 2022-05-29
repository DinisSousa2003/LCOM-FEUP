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

int player_pos_x = 650;
int player_pos_y = 300;
int arena_max_y = 500;
int arena_min_y = 100;
int player_height = 40;

int (getPlayerX)(){
    return player_pos_x;
}

int (getPlayerY)(){
    return player_pos_y;
}

void (playerDown)(){
    if(getPlayerY() <= (arena_max_y-player_height-15)){
        player_pos_y += 15;
    }
    else if (getPlayerY() > (arena_max_y-player_height-15))
    {
        player_pos_y += (arena_max_y-getPlayerY()-player_height);
    }
}

void (playerUp)(){
    if(getPlayerY() >= (arena_min_y+15)){
        player_pos_y -= 15;
    }
    else if (getPlayerY() < (arena_min_y+15))
    {
        player_pos_y -= (getPlayerY()-arena_min_y);
    }
}
