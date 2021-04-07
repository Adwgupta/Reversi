/**  
 *   Link to Github repo
 *   https://github.com/Adwgupta/Reversi
 */

#include <stdio.h>
#include <time.h>
//Name for the results txt file
#define file "othello-results.txt"
//File pointer
FILE *fp;

/**
 * Function to print out print game results out to the pre-defined txt file
 * the function also takes in a file pointer, this will allow a message to be printed out to the console
 * as well as the txt file
 */
void resultsFile(FILE *out, char printingMessage[]) {
   //Variable t that will store the current time
   time_t t;
   //Seeds variable t with current time
   time(&t);
   //For now we're printing out the message string/array from main and the current time
   fprintf(out, "Message:\n%s\nExecuted at:\n%s", printingMessage, ctime(&t));
}

//Main function to initialise board & players, place tokens and play game
void main() {
   //trial message to be printed out
   char message[] = "Kenobi:\t\t\"Hello There!\"\nGrevious:\t\"General Kenobi!\"\nGrevious:\t\"You ARE a bold one!\"\n";
   //Creates the desired output txt file, replaces the previous file contents with the new code output
   fp = fopen(file, "a");
   //prints out the message to the console
   resultsFile(stdout, message);
   //prints out the message to the txt file
   resultsFile(fp, message);
}