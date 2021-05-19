#ifndef OTHELLO_AFTER_GAME_H
#define OTHELLO_AFTER_GAME_H

#include "initialize.h"
#include "ascii.h"
/**
 * This libary is not being used as this version of the program
 * as this version has been created for termnials/ides which do not support ansi escape sequences
 * This is also the version you can run on command prompt
 * #include "colour.h"  
*/

//Name for the results txt file
#define resultsFile "othello-results.txt"
//File pointer
FILE *fp;

/**
 * Function prototypes
 *
 * 
Function to handle the after game results */
void endCredits(Disk board[][BOARD_SIZE], Player p1, Player p2);
//Function to print the game results to either the console and the txt file
void gameResults(FILE *out, Disk board[][BOARD_SIZE], Player p1, Player p2);
//Function to print the final board to the txt file
void saveBoardToFile(FILE *out, Disk board[][BOARD_SIZE]);

#endif