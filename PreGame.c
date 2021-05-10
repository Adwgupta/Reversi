#include <stdio.h>
#include <time.h>
#include "PreGame.h"
#include "ascii.h"
/**
 * Function to print out instructions
 */

void newGameMan(FILE *out) {
   /**
    * Creates the desired output txt file and appends the results to the file
    * if the file doesnt exist, it will be created
    */
   if ((fp = fopen(file, "a")) == NULL)
      perror;
   instructionsArt(out);
   newGameArt(out);
   welcomeArt(out);
   //Variable t that will store the current time
   time_t t;
   //Seeds variable t with current time
   time(&t);
   fprintf(out, "\nGame started at:\n%s", ctime(&t));
    
}