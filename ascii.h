/**
 * Library file containing functions to print out instructions and pre-game
 * stuff
 */

#ifndef REVERSI_ASCII_H
#define REVERSI_ASCII_H
#include <stdio.h>
/**
 * Function to print out ascii art spelling out "NEW GAME"
 * using Star Wars font that I created myself
 */
void newGameArt(FILE *out);
/**
 * Function to print out ascii art spelling out "WELCOME TO OTHELLO"
 * using Star Wars font that I created myself
 */
void welcomeArt(FILE *out);
/**
 * Function to print out ascii art spelling out "INSTRUCTIONS"
 * using Star Wars font that I created myself
 */
void instructionsArt(FILE *out);
/**
 * Function to print out ascii art spelling out "GAME OVER"
 * using Star Wars font that I created myself
 */
void gameOverArt(FILE *out);

#endif //REVERSI_ASCII_H
