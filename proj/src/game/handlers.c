#include "handlers.h"

extern uint8_t scancode[2];
extern int menu_entries[];
extern int curEntry;

void (mainHandler)(int device){
    switch (state){
        case MENU: {
            menuHandler(device);
            break;
        }
        case ONEPGAME: {
            gameOnePlayerHandler(device);
            break;
        }
        case TWOPGAME: {
            gameTwoPlayersHandler(device);
            break;
        }
        case ABOUT: {
            aboutHandler(device);
            break;
        }
    }
}

void (menuHandler)(int device){
    switch (device){
        case KEYBOARD: {
            if(scancode[0] == KBC_TWO_BYTE && scancode[1] == KEY_UP){
                backMenuEntry();
            }
            else if(scancode[0] == KBC_TWO_BYTE && scancode[1] == KEY_DOWN){
                addMenuEntry();
            }
            else if(scancode[0] == KEY_ENTER){
                if(menu_entries[curEntry] == PLAYER1_SELECTED_IMG){
                    state = ONEPGAME;
                    draw_pattern(10, 0, 100);
                    refresh_buffer();
                    return;
                }
                else if(menu_entries[curEntry] == PLAYER2_SELECTED_IMG){
                    state = TWOPGAME;
                    return;
                }
                else if(menu_entries[curEntry] == PLAYER2_SELECTED_IMG){
                    state = ABOUT;
                    return;
                }
            }
            drawMenu();
            break;
        }
        default:
            break;
    }
}

void (gameOnePlayerHandler)(int device){
    return;
}
void (gameTwoPlayersHandler)(int device){
    return;
}
void (aboutHandler)(int device){
    return;
}
