/**  
 *   Link to Github repo
 *   https://github.com/Adwgupta/Reversi
 */

#include <stdio.h>
//Name for the results txt file
#define file "othello-results.txt"
//File pointer
FILE *fp;

//Function to print out print game results out to the pre-defined txt file
void resultsFile(char printingMessage[]) {
   //Creates the desired output txt file, replaces the previous file contents with the new code output
   fp = fopen(file, "a");
   //For now we're printing out message from main
   fprintf(fp, printingMessage);
}

//Main function to initialise board & players, place tokens and play game
void main() {
   //trial message to be printed out
   char message[] = "Kenobi:\t\t\"Hello There!\"\nGrevious:\t\"General Kenobi!\"\nGrevious:\t\"You ARE a bold one!\"\n";
   //Printing message to the console
   printf("%s", message);
   //prints out the game results to the pre-defined txt file
   resultsFile(message);
}
