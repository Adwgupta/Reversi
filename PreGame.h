/**
 * Library file containing functions to print out instructions and pre-game
 * stuff
 */

#ifndef REVERSI_PREGAME_H
#define REVERSI_PREGAME_H

//Name for the results txt file
#define file "othello-results.txt"
//File pointer
FILE *fp;

/**
 * Function to print out instructions
 */

void newGameMan(FILE *out);

#endif //REVERSI_PREGAME_H