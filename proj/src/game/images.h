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
#include "../sprites/end/Lost_menu.h"
#include "../sprites/end/Won_p1_menu.h"
#include "../sprites/end/Won_p2_menu.h"
#include "../sprites/powerups/power1.h"
#include "../sprites/powerups/power2.h"

#define NUM_IMAGES 15

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
    NUMBER5_IMG,
    LOST_MENU_IMG,
    WON_P1_MENU_IMG,
    WON_P2_MENU_IMG,
    POWER1_IMG,
    POWER2_IMG
};

xpm_image_t game_images[NUM_IMAGES];

void (load_all_images)();
