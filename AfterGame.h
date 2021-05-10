/**
 * Library file to print out overall game results to a txt file
 * as well as printing the necessary ones to the console
 */

#ifndef REVERSI_AFTERGAME_H
#define REVERSI_AFTERGAME_H

//Name for the results txt file
#define file "othello-results.txt"
//File pointer
FILE *fp;

/**
 * Function to print out the last board to the pre-defined txt file
 * the function takes in a file pointer as its parameter to allow the results to be printed out to the console
 */
void saveResultsToFile(FILE *out);

/**
 * Function to print out print game results out to the pre-defined txt file
 * the function also takes in a file pointer, this will allow a message to be printed out to the console
 * as well as the txt file
 */
void gameResults(FILE *out);

#endif //REVERSI_AFTERGAME_H
