#include "handlers.h"

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
            draw_sprite(0, 0, game_images[getCurrentEntry()]);
            break;
        }
        case TIMER: {
            break;
        }
    }
}
