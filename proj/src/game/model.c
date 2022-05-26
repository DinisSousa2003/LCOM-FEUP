#include "model.h"

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

int (getCurrentEntry)(){
    return menu_entries[curEntry];
}

