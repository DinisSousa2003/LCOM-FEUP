#pragma once

#include <lcom/lcf.h>
#include <stdio.h>

#include "images.h"

void (addMenuEntry)();
void (backMenuEntry)();
int (getCurrentEntryImg)();

struct Player{
    int x_pos;
    int y_pos;
    unsigned int color;
    int vel;
    int height;
    int width;
};

struct Ball{
    int x_pos;
    int y_pos;
    unsigned int color;
    int vel_x;
    int vel_y;
    int height;
    int width;
};

struct Arena{
    int max_y;
    int min_y;
    int max_x;
    int min_x;
    int height;
    int width;
};

struct Player (getPlayer)();
struct Arena (getArena)();
struct Ball (getBall)();
void (playerUp)();
void (playerDown)();
void (moveBall)();
bool (goal)();
void movePCplayer();
