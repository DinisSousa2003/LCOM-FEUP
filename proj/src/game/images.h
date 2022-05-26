#pragma once

#include <lcom/lcf.h>
#include <stdio.h>

#include "../sprites/menu/menu.h"
#include "../sprites/menu/player1_selected.h"
#include "../sprites/menu/player2_selected.h"
#include "../sprites/menu/about_selected.h"

#define NUM_IMAGES 4

enum game_image_t{
    MENU_IMG,
    PLAYER1_SELECTED_IMG,
    PLAYER2_SELECTED_IMG,
    ABOUT_SELECTED_IMG
};

xpm_image_t game_images[NUM_IMAGES];

void (load_all_images)();
