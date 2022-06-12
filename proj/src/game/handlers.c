#include "handlers.h"

extern uint8_t scancode[2];
extern struct packet pp;
extern int menu_entries[];
extern int counter;
extern int actionLeftTimeout;
extern struct Player player;
extern struct Player player2;
extern uint8_t read_data;
extern struct Wall wall;

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
        case WAITING: {
            waitingHandler(device);
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
        case ENDGAME: {
            endGameHandler(device);
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
                    printf("2player\n");
                    ser_init();
                    state = WAITING;
                    printf("state: %d\n", state);
                    clear_buffer();
                    drawWaitMenu();
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
        case MOUSE: {
            break;
        }
        default:
            break;
    }
}

void (gameOnePlayerHandler)(int device){
    switch (device){
        case KEYBOARD: {
            switch (scancode[0])
            {
            case KEY_W:
                playerUp(&player);
                break;
            case KEY_S:
                playerDown(&player);
                break;
            default:
                break;
            }
            break;
        }
        case TIMER: {
            if(counter % REFRESH_RATE == 0){
                if(wall.active){
                    if (counter % wall.decreaseRate == 0){
                        wallDecrease();
                    }
                }
                else{
                    if(wall.timeout>0){
                        wall.timeout--;
                    }
                }

                if(actionLeftTimeout > 0){
                    actionLeftTimeout--;
                }

                if(moveBall()){
                    if(gameWinner()){
                        resetGame();
                        state = ENDGAME;
                    }
                }
                movePCPlayer();
                drawGame();
                drawArena();
                drawMouse();
                drawWall();
                
                refresh_buffer();
            }
            break;
        }
        case MOUSE:{
            moveMouse(pp.delta_x, pp.delta_y);

            if(pp.lb && actionLeftTimeout == 0){
                mouseActionLeft();
            }

            if(pp.rb && !wall.active && wall.timeout == 0){
                mouseActionRight();
            }
            break;
        }
        default:
            break;
    }
}
void (waitingHandler)(int device){
    switch (device)
    {
    case SERIALPORT:
        if (ser_check_connection())
            state = TWOPGAME;
        break;
    /*case TIMER:
        if(counter % 120 == 0)
            ser_transmit_data(SER_INIT);
        break;*/
    default:
        break;
    }
}
/*
void (gameTwoPlayersHandler)(int device){
    switch (device){
        case KEYBOARD: {
            switch (scancode[0])
            {
            case KEY_W:
                playerUp(&player);
                break;
            case KEY_S:
                playerDown(&player);
                break;
            case KBC_TWO_BYTE: {
                switch (scancode[1])
                {
                case KEY_UP:
                    playerUp(&player2);
                    break;
                case KEY_DOWN:
                    playerDown(&player2);
                    break;
                default:
                    break;
                }
            }
            default:
                break;
            }
            break;
        }
        case TIMER: {
            if(counter % REFRESH_RATE == 0){
                if(moveBall()){
                    if(gameWinner()){
                        resetGame();
                        state = ENDGAME;
                    }
                }
                drawGame();
                drawArena();
                
                refresh_buffer();
            }
            break;
        }
        default:
            break;
    }
}
*/

void (gameTwoPlayersHandler)(int device){
    switch (device){
        case KEYBOARD: {
            switch (scancode[0])
            {
            case KEY_W:
                playerUp(&player);
                ser_transmit_data(SER_PLAYER_UP);
                break;
            case KEY_S:
                playerDown(&player);
                ser_transmit_data(SER_PLAYER_DOWN);
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
                if(moveBall()){
                    if(gameWinner()){
                        resetGame();
                        state = ENDGAME;
                    }
                }
                drawGame();
                drawArena();
                
                refresh_buffer();
            }
            break;
        }
        case SERIALPORT: {
            switch (read_data)
            {
            case SER_PLAYER_UP:
                printf("up\n");
                playerUp(&player2);
                break;
            case SER_PLAYER_DOWN:
                printf("down\n");
                playerDown(&player2);
                break;
            default:
                break;
            }
        }
        default:
            break;
    }
}
void (aboutHandler)(int device){
    return;
}

void (endGameHandler)(int device){
    switch (device)
    {
    case KEYBOARD:{
        if(scancode[0] == KEY_ENTER){
            state = MENU;
        }
        break;
    }
    case TIMER: {
        if(counter % REFRESH_RATE == 0){
            drawEndGame();
            refresh_buffer();
        }
    }
    default:
        break;
    }
    return;
}
