#pragma once

#include <lcom/lcf.h>
#include <stdio.h>
#include "handlers.h"
#include "images.h"
/**
 * In the menu, it goes to the next option.
 * If there is no next option, the selection remains unchanged
 * 
 */
void (addMenuEntry)();
/**
 * In the menu, it goes to the previous option.
 * If there is no previous option, the selection remains unchanged
 * 
 */
void (backMenuEntry)();
/**
 * Returns the value of the corrent entry in the menu
 * @return  
 * 
 */
int (getCurrentEntryImg)();

/**
 * Struct that saves all data about one player
 * 
 */
struct Player{
    int x_pos;          /*!< Position of the player on the x-axis */
    int y_pos;          /*!< Position of the player on the y-axis */
    unsigned int color; /*!< Colour with which the player is drawn  */
    int vel;            /*!< Distance, on the y-axis, per unit of time */
    int height;         /*!< Height of the player's paddle */
    int width;          /*!< Width of the player's paddle */
    int score;          /*!< Total points scored in the match */
};
/**
 * Struct that saves all data about the ball
 * 
 */
struct Ball{
    int x_pos;          /*!< Position of the ball on the x-axis */
    int y_pos;          /*!< Position of the ball on the y-axis */
    unsigned int color; /*!< Colour with which the ball is drawn  */
    int vel_x;          /*!< Distance, on the x-axis, per unit of time */
    int vel_y;          /*!< Distance, on the y-axis, per unit of time */
    int height;         /*!< Height of the ball */
    int width;          /*!< Width of the ball */
};
/**
 * Struct that saves all data about game arena
 * 
 */
struct Arena{
    int max_y;          /*!< Maximum value of position on y-axis */
    int min_y;          /*!< Minimum value of position on y-axis */
    int max_x;          /*!< Maximum value of position on x-axis */
    int min_x;          /*!< Minimum value of position on y-axis */
    int height;         /*!< Length of the arena */
    int width;          /*!< Width of the arena */
};
/**
 * Struct that saves all data about the mouse
 * 
 */
struct Mouse{
    int x_pos;          /*!< Position of the mouse on the x-axis */
    int y_pos;          /*!< Position of the mouse on the y-axis */
    unsigned int color; /*!< Colour with which the mouse is drawn  */
    int height;         /*!< Lenght of the mouse */
    int width;          /*!< Width of the mouse */
};

/**
 * Returns a default Player1 
 * @return
 * 
 */
struct Player (getPlayer)();
/**
 * Returns a default Arena
 * @return
 */
struct Arena (getArena)();
/**
 * Returns a default ball 
 * @return
 */
struct Ball (getBall)();
/**
 * Resets the ball and the player(s) after someone has scored a point
 * 
 */
void resetPositions();
/**
 * Resets the ball, the player(s) and the scores at the start of a match
 * 
 */
void (resetGame)();
/**
 * Receives a Player and moves it up (y-axis) 
 * @param player
 */
void (playerUp)();
/**
 * Receives a Player and moves it down (y-axis) 
 * @param player
 */
void (playerDown)();
/**
 * Checks if any player has scored a point and raises his score if so
 * Returns true if someone has scored
 * 
 * @return true 
 * @return false 
 */
bool goal();
/**
 * Calculates and moves the ball to its next position
 * Changes trajectory if collisions are detected
 */
bool (moveBall)();
/**
 *  Moves the computer-controlled player in the case of Single Player mode
 * 
 */
void (movePCPlayer)();
/**
 * Return true if any of the players has won the game
 * @return true
 * @return false
 */
bool (gameWinner)();
/**
 * Changes the position of the mouse cursor depending on the input data (x-axis, y-axis)
 * @param x
 * @param y
 */
void (moveMouse)(int x, int y);
