#include "images.h"

void (load_all_images)(){
    xpm_load(MENU_SPRITE, XPM_8_8_8_8, &game_images[MENU_IMG]);
    xpm_load(PLAYER1_SELECTED_SPRITE, XPM_8_8_8_8, &game_images[PLAYER1_SELECTED_IMG]);
    xpm_load(PLAYER2_SELECTED_SPRITE, XPM_8_8_8_8, &game_images[PLAYER2_SELECTED_IMG]);
    xpm_load(ABOUT_SELECTED_SPRITE, XPM_8_8_8_8, &game_images[ABOUT_SELECTED_IMG]);
}
