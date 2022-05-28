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

int (getPlayerX)(){
    return player_pos_x;
}

int (getPlayerY)(){
    return player_pos_y;
}

void (playerDown)(){
    player_pos_y += 15;
}

void (playerUp)(){
    player_pos_y -= 15;
}
