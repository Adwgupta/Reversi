/**  
 *   Link to Github repo
 *   https://github.com/Adwgupta/Reversi-Othello.git
 *   For some reason on vscode it wouldnt recognise the libaray aftergame.h and its source file aftergame.c
 *   Until i changed the include to aftergame.c
 *   Will have to do some research into this
 */

#include <stdio.h>
#include "AfterGame.c"
#include "PreGame.c"

//Main function to initialise board & players, place tokens and play game
int main() {

   instructions();
   //prints out the message to the console
   gameResults(stdout);
   //prints out the message to the txt file
   gameResults(fp);

   return 0;
}