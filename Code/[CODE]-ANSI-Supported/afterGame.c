#include <stdio.h>
#include <time.h>
#include "afterGame.h"

void endCredits(Disk board[][BOARD_SIZE], Player p1, Player p2) {
   /**
    * Opens the txt output file created in the preGame file and appends the results to the file
    * if the file doesnt exist, it will be created
    */
   if ((fp = fopen(resultsFile, "a")) == NULL)
      perror;

   //The following 2 function calls prints the game results to the txt file
   gameResults(fp, board, p1, p2);
   saveBoardToFile(fp, board);

   //Print out game over to the console
   gameResults(stdout, board, p1, p2);
}

/**
 * Function to print out the game results to either the console and the pre-defined txt file
 * the function takes in a file pointer as its parameter to allow the results to be printed out to the console
 */
void gameResults(FILE *out, Disk board[][BOARD_SIZE], Player p1, Player p2) {
   red();
   gameOverArt(out);
   purple();

   //Variable t that will store the current time at which the game finished
   time_t t;
   //Seeds variable t with current time
   time(&t);
   //Time that game finished at
   fprintf(out, "========================== [GAME RESULTS:] ==========================");
   fprintf(out, "\n\nGame finished at:\n%s", ctime(&t));
   
   /**
    * Print out the score
    * Player 1
    */
   fprintf(out, "\n(Black) - Player %s's points: %d.", p1.name, p1.disks);
   //Player 2
   fprintf(out, "\n(White) - Player %s's points: %d.", p2.name, p2.disks);
	
   //If Player 1 wins
   if (p1.disks > p2.disks)
      fprintf(out, "\n\nCongratulations %s, you've unlocked the achievement [100%% TRUE JEDI] and you have won the game!\n", p1.name);
	
   //If Player 2 wins
   if (p2.disks > p1.disks)
      fprintf(out, "\n\nCongratulations %s, you've unlocked the achievement [100%% TRUE JEDI] and you have won the game!\n", p2.name);
	
   //If its a draw
   else 
      fprintf(out, "\nGood game players %s and %s!\nYou've both unlocked the achievements [50%% TRUE JEDI] as you've somehow drawed!\n", p1.name, p2.name);
   
   resetcolour();
}

/**
 * Function to print the final board out to the pre-defined txt file
 * the function also takes in a file pointer, this will allow a message to be printed out to the console
 * as well as the txt file
 */
void saveBoardToFile(FILE *out, Disk board[][BOARD_SIZE]) {
   fprintf(out, "\n====================== The final board played: ======================\n\n   ");

   //This for loop iterates around the columns to print out the column co-ordinates from A - H
   for (int i = 1; i <= BOARD_SIZE; i++) 
      fprintf(out, "___%c___ ", i - 1 + 'A');
   
   //This for loop iterates around the rows
   for (int j = 0; j < BOARD_SIZE; j++) {
      fprintf(out, "\n  |       |       |       |       |       |       |       |       |"); 
      fprintf(out, "\n%d |", j + 1);                 //Left row co-ordinates from 1 - 8

      for (int i = 0; i < BOARD_SIZE; i++) {

         //For black discs
         if (board[j][i].type == BLACK) 
            fprintf(out, "   B   |");                //This will print out a black background text to serve as the black marker

         //For white discs
         if (board[j][i].type == WHITE)
            fprintf(out, "   W   |");                //This will print out a black background text to serve as the black marker
      
         //For playable co-ordinates
         if (board[j][i].type == EMPTY)
            fprintf(out, "       |");
      }

      fprintf(out, " %d\n", j + 1);                  //Left row co-ordinates from 1 - 8
      fprintf(out, "  |_______|_______|_______|_______|_______|_______|_______|_______|");
   }
	
   fprintf(out, "\n     ");
   //This for loop iterates around the columns to print out the column co-ordinates from A - H
   for (int i = 1; i <= BOARD_SIZE; i++)
      fprintf(out, " %c      ", i - 1 + 'A');
	
   printf("\n\n\n");
   resetcolour();
}
