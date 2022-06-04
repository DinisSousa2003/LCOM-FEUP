#pragma once

#include <lcom/lcf.h>
#include <stdio.h>

#include "model.h"
#include "images.h"
#include "view.h"       
#include "../video/video.h"
#include "../keyboard/kbc.h"

#define REFRESH_RATE (60/30)

enum devices {
    TIMER,
    KEYBOARD,
    MOUSE
};

typedef enum states {
    MENU,
    ONEPGAME,
    TWOPGAME,
    ABOUT,
    ENDGAME
} state_t;


void (mainHandler)(int device);
void (menuHandler)(int device);
void (gameOnePlayerHandler)(int device);
void (gameTwoPlayersHandler)(int device);
void (aboutHandler)(int device);
void (endGameHandler)(int device);
