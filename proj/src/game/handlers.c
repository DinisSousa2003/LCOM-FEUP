#include "handlers.h"

extern uint8_t scancode[2];

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
            drawMenu();
            break;
        }
        default:
            break;
    }
}
