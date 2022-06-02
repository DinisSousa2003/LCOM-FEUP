#pragma once

#include <lcom/lcf.h>
#include <stdio.h>

#include "../sprites/menu/menu.h"
#include "../sprites/menu/player1_selected.h"
#include "../sprites/menu/player2_selected.h"
#include "../sprites/menu/about_selected.h"
#include "../sprites/numbers/0.h"
#include "../sprites/numbers/1.h"
#include "../sprites/numbers/2.h"
#include "../sprites/numbers/3.h"
#include "../sprites/numbers/4.h"
#include "../sprites/numbers/5.h"

#define NUM_IMAGES 10

enum game_image_t{
    MENU_IMG,
    PLAYER1_SELECTED_IMG,
    PLAYER2_SELECTED_IMG,
    ABOUT_SELECTED_IMG,
    NUMBER0_IMG,
    NUMBER1_IMG,
    NUMBER2_IMG,
    NUMBER3_IMG,
    NUMBER4_IMG,
    NUMBER5_IMG
};

xpm_image_t game_images[NUM_IMAGES];

void (load_all_images)();
