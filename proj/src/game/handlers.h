#pragma once

#include <lcom/lcf.h>
#include <stdio.h>

#include "model.h"
#include "images.h"
#include "view.h"       
#include "../video/video.h"
#include "../keyboard/kbc.h"
#include "../rtc/rtc.h"
#include "../serialport/serialport.h"

#define REFRESH_RATE (60/30) /*!< Every two ticks of the timer */

/**
 * @brief Enumerates the devices used in the game
 * 
 */
enum devices {
    TIMER,      /*!< Timer device */
    KEYBOARD,   /*!< Keyboard device */
    MOUSE,      /*!< Mouse device */
    RTC,        /*!< RTC device */
    SERIALPORT  /*!< Serial port device */
};

/**
 * @brief Enumerates the different possible game states
 */
typedef enum states {
    MENU,       /*!< Menu options */ 
    ONEPGAME,   /*!< Player1 Vs Computer */
    TWOPGAME,   /*!< Player1 Vs Player2  */
    WAITING,    /*!< Waiting menu */
    ABOUT,      /*!< Informations about the project */
    ENDGAME     /*!< Informations about the end of the match */
} state_t;

/** 
 * @brief Invokes the respective handler according to the game state
 * @param device
 */
void (mainHandler)(int device);
/**
 * @brief Proceed with the actions in the Menu State of the respective given device
 * @param device
 */
void (menuHandler)(int device);
/**
 * @brief Proceed with the actions in the One Player Game State of the respective given device
 * @param device
 */
void (gameOnePlayerHandler)(int device);
/**
 * @brief Proceed with the actions in the Wait Menu State of the respective given device
 * @param device
 */
void (waitingHandler)(int device);
/**
 * @brief Proceed with the actions in the Two Players Game State of the respective given device
 * @param device
 */
void (gameTwoPlayersHandler)(int device);
/**
 * @brief Proceed with the actions in the About State of the respective given device
 * @param device
 */
void (aboutHandler)(int device);
/**
 * @brief Proceed with the actions in the End Game State of the respective given device
 * @param device
 */
void (endGameHandler)(int device);
