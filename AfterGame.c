#include <stdio.h>
#include <time.h>
#include "AfterGame.h"

void saveResultsToFile(FILE *out) {

}

/**
 * Function to print out print game results out to the pre-defined txt file
 * the function also takes in a file pointer, this will allow a message to be printed out to the console
 * as well as the txt file
 */
void gameResults(FILE *out) {
   /**
    * Creates the desired output txt file and appends the results to the file
    * if the file doesnt exist, it will be created
    */
   if ((fp = fopen(file, "a")) == NULL)
	   perror;
   //Variable t that will store the current time
   time_t t;
   //Seeds variable t with current time
   time(&t);
   //For now we're printing out the message string/array from main and the current time
   fprintf(out, "================================================================================================\n");
   fprintf(out, "  _______      ___       ____  ____   _______      ______   ____    ____  _______  ______               \n"
                       " /  _____|    /   \\     |    \\/    | |   ____|    /  __  \\  \\   \\  /   / |   ____||   _  \\        \n"
                       "|  |  __     /  ^  \\    |  ^    ^  | |  |__      |  |  |  |  \\   \\/   /  |  |__   |  |_)  |           \n"
                       "|  | |_ |   /  /_\\  \\   |  |\\__/|  | |   __|     |  |  |  |   \\      /   |   __|  |      /          \n"
                       "|  |__| |  /  _____  \\  |  |    |  | |  |____    |  '--'  |    \\    /    |  |____ |  |\\  \\___      \n"
                       " \\______| /__/     \\__\\ |__|    |__| |_______|    \\______/      \\__/     |_______||__| \\_____|    \n\n");
   fprintf(out, "Game Over, good game players!\nTime finished at:\n%s", ctime(&t));

   if (out == fp)
      saveResultsToFile(fp);
}