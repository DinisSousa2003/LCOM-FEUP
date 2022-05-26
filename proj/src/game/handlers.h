#pragma once

#include <lcom/lcf.h>
#include <stdio.h>

#include "model.h"
#include "images.h"
#include "../video/video.h"

enum devices {
    TIMER,
    KEYBOARD,
    MOUSE
};

typedef enum states {
    MENU,
    ONEPGAME,
    TWOPGAME,
    ABOUT
} state_t;

static state_t state = MENU;

void (mainHandler)(int device);
void (menuHandler)(int device);
void (gameOnePlayerHandler)(int device);
void (gameTwoPlayersHandler)(int device);
void (aboutHandler)(int device);
