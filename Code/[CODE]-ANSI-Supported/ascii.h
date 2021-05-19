/**
 * Library file containing functions to print out instructions and pre-game
 * stuff
 */

#ifndef OTHELLO_ASCII_H
#define OTHELLO_ASCII_H
#include <stdio.h>

/**
 * Function prototypes
 * 
 * 
 * Function to print out ascii art spelling out "NEW GAME"
 * using Star Wars font that I created myself
 */
void newGameArt(FILE *out);
/**
 * Function to print out ascii art spelling out "WELCOME TO OTHELLO"
 * using Star Wars font that I created myself
 */
void welcomeArt();
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

#endif 
