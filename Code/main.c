/**  
 *   Link to Github repo
 *   https://github.com/Adwgupta/Reversi
 *   For some reason on vscode it wouldnt recognise the libaray aftergame.h and its source file aftergame.c
 *   Until i changed the include to aftergame.c
 *   Will have to do some research into this
 */

#include <stdio.h>
#include "AfterGame.c"
//Main function to initialise board & players, place tokens and play game
void main() {
   //trial message to be printed out
   char message[] = "Kenobi:\t\t\"Hello There!\"\nGrevious:\t\"General Kenobi!\"\nGrevious:\t\"You ARE a bold one!\"\n";
   //prints out the message to the console
   resultsFile(stdout, message);
   //prints out the message to the txt file
   resultsFile(fp, message);
}