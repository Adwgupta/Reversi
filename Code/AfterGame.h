/**
 * Library file to print out game results
 */

#ifndef REVERSI_AFTERGAME_H
#define REVERSI_AFTERGAME_H

//Name for the results txt file
#define file "othello-results.txt"
//File pointer
FILE *fp;

/**
 * Function to print out print game results out to the pre-defined txt file
 * the function also takes in a file pointer, this will allow a message to be printed out to the console
 * as well as the txt file
 */
void resultsFile(FILE *out, char printingMessage[]);

#endif //REVERSI_AFTERGAME_H
