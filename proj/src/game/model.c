#include "model.h"

#define ENTRIES 3

static int menu_entries[ENTRIES] = {PLAYER1_SELECTED_IMG, PLAYER2_SELECTED_IMG, ABOUT_SELECTED_IMG};
static int curEntry = 0;


void (addMenuEntry)(){
    if((curEntry + 1) >= ENTRIES) return;
    curEntry++;
}

void (backMenuEntry)(){
    if((curEntry - 1) < 0) return;
    curEntry--;
}

int (getCurrentEntry)(){
    return menu_entries[curEntry];
}

void (drawMenu)(){
    draw_sprite(0, 0, game_images[MENU_IMG]);
    draw_sprite(0, 0, game_images[menu_entries[curEntry]]);
}

