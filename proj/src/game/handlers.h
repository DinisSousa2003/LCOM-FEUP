#pragma once

#include <lcom/lcf.h>
#include <stdio.h>

enum devices {
    TIMER,
    KEYBOARD,
    MOUSE
};

void menuHandler();
void gameOnePlayerHandler();
void gameTwoPlayersHandler();
void aboutHandler();