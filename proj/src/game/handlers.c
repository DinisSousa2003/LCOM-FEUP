#include "handlers.h"

extern uint8_t scancode[2];
extern int menu_entries[];
extern int counter;

state_t state = MENU;

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
                if(getCurrentEntryImg() == PLAYER1_SELECTED_IMG){
                    state = ONEPGAME;
                    clear_buffer();
                    refresh_buffer();
                }
                else if(getCurrentEntryImg() == PLAYER2_SELECTED_IMG){
                    state = TWOPGAME;
                    clear_buffer();
                    refresh_buffer();
                }
                else if(getCurrentEntryImg() == ABOUT){
                    state = ABOUT;
                    clear_buffer();
                    refresh_buffer();
                }
            }
            break;
        }
        case TIMER: {
            if(counter % REFRESH_RATE == 0){
                drawMenu();
                refresh_buffer();
            }
            break;
        }
        default:
            break;
    }
}

void (gameOnePlayerHandler)(int device){
    printf("Player.\n");
    switch (device){
        case KEYBOARD: {
            switch (scancode[0])
            {
            case KEY_W:
                playerUp();
                break;
            case KEY_S:
                playerDown();
                break;
            case KEY_A:
                //go left
                break;
            case KEY_D:
                //go right
                break;
            default:
                break;
            }
            break;
        }
        case TIMER: {
            if(counter % REFRESH_RATE == 0){
                drawGame();
                refresh_buffer();
            }
            break;
        }
        default:
            break;
    }
}
void (gameTwoPlayersHandler)(int device){
    return;
}
void (aboutHandler)(int device){
    return;
}
