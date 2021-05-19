#ifndef OTHELLO_COLOUR_H
#define OTHELLO_COLOUR_H

/**
 * Function prototypes:
 * 
 * the following 8 functions print an output in a specific colour using ANSI escape sequences
 * 
Function to print output to the console in Bold Red */
void red();
//Function to print output to the console in Bold Green
void green();
//Function to print output to the console in Bold Blue
void blue();
//Function to print output to the console in Bold Purple
void purple();
//Function to print output to the console in Bold Yellow
void yellow();

//Function to print out a black background 
void blackMarker();
//Function to print out a white background 
void whiteMarker();

//Function to reset the output colour back to the orginal colour
void resetcolour();

#endif 