#include <stdio.h>
#include "colour.h"

//Function to print output to the console in Bold Red
void red() {
   printf("\e[1;91m");
}

//Function to print output to the console in Bold Green
void green() {
   printf("\e[1;92m");
}

//Function to print output to the console in Bold Blue
void blue() {
   printf("\e[1;96m");
}

//Function to print output to the console in Bold Purple
void purple() {
   printf("\e[1;95m");
}

//Function to print output to the console in Bold Yellow
void yellow (){
   printf("\e[1;93m");
}

//Function to print out a black background
void blackMarker() {
   printf("\e[0;100m");  
}

//Function to print out a white background
void whiteMarker() {
   printf("\e[0;107m");  
}

//Function to reset the output colour back to the orginal colour
void resetcolour() {
   printf("\033[0m");
}