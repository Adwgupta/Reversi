#include <stdio.h>
#include <stdlib.h>

//Custom header files
#include "ascii.h"
#include "colour.h"
#include "preGame.h"
#include "afterGame.h"
#include "initialize.h"
#include "turns.h"

int main () {
   //Creates the player 1 struct with the name "R2D2" as the starting name
   Player p1 = {
      "R2D2", EMPTY, 0
   };
   //Creates the player 2 struct with the name "Jarvis" as the starting name
   Player p2 = {
      "Jarvis", EMPTY, 0
   };

   //Creates the board	
	Disk board[BOARD_SIZE][BOARD_SIZE];
   /**
    * Function calls to play the game
    * 
    This function prints out the welcome text */
   w1();
   //Initialise the players
   playerSetUp(&p1, &p2);
   //Initialise out pre-game set ups
   openingCredits(p1, p2);
   //Initialise the board
   boardSetUp(board);
   //Print the board
	printBoard(board);
   //Initialise the turn handling
   manageTurns(board, &p1, &p2);
   //End the game
	endCredits(board, p1, p2);

   //End the program
   return 0;
}
