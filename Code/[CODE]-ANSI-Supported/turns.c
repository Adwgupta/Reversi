#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turns.h"

//Function to check if the linked list is empty, 
int isEmpty(listNodePtr sPtr) {
   return sPtr == NULL;
}

/**
 *  Function to remove a node from the linked list,
 *  well as free the memory allocated to it
 */
void dequeue(listNodePtr *sPtr) {
   /**
    *  *sPtr -> Pointer that points to the start of the linked list
    *  used to store the number of possible moves per turn.
    */
   listNodePtr tempPtr = *sPtr;               
   *sPtr = (*sPtr)->nextPtr;
   free(tempPtr);
}


//Function that manages each turn by keeping track of number of turns and spaces left on board
void manageTurns(Disk board[][BOARD_SIZE], Player *p1, Player *p2) {
   int turns = 1;                                                            //Number of turns in current game.
   int boardSpaceLeft = BOARD_SIZE * BOARD_SIZE - (p1->disks + p2->disks);   //Number of spaces currently left on board.
   int draw = 0;                                                             //This variable will be used to make the game draw

   //This while loop iterates while there is a valid move to make
   while (boardSpaceLeft) {
      if (turns % 2 != 0) {                        //If turns are odd -> player 1's turns
         printf("\n\nTurn %d: %s's move\n[Current Score: Player 1: %d | Player 2: %d]\n", turns, p1->name, p1->disks, p2->disks);
         manageMoves(board, p1, p2, &draw);        //Function call to allow player 1's move
         printBoard(board);                        //Prints the updated board
         turns++;                                  //Increments the number of turns played
      }

      if (turns % 2 == 0) {                        //If turns are even -> player 1's turns
         printf("\n\nTurn %d: %s's move\n[Current Score: Player 2: %d | Player 1: %d]\n", turns, p2->name, p2->disks, p1->disks);
         manageMoves(board, p2, p1, &draw);        //Function call to allow player 1's move
         printBoard(board);                        //Prints the updated boards
         turns++;                                  //Increments the number of turns played
      }

      //As long as there were no erros made in disc placement
      boardSpaceLeft = BOARD_SIZE * BOARD_SIZE - (p1->disks + p2->disks);
   }
}

/** 
 *  Function to manage each move by finding out the total ammount legal moves playable, prints the legal moves
 *  and asks user to choose a move and then update the board with the respective move chosen  
 */
void manageMoves(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int *draw) {
	listNodePtr startPtr = NULL;                       //Sets the start of the linked list to empty
	getCoords(board, pCurrent, pOpponent, &startPtr);  //Gets the co-ordinates of the playable moves
	
	int max = 0;                                       //Stores the maximum number of possible moves.
	printCoords(startPtr, &max);
	
	if (max != 0) {                                    //As long as there is a move to be made
		int choice = 0;
		askChooseCoord(*pCurrent, max, &choice);
		
		int row = 0, col = 0;
		getChosenCoord(&startPtr, choice, &row, &col);
		placeDisks(board, pCurrent, pOpponent, row, col);
	}

   /**
    * If there is no legal move to play, the program will automatically allow the player to "pass"
    * i.e, their turn is skipped, and if two draws are made then the function ends early
    */
	else {                                            
		printf("\nUnfortunately, there are no legal moves for Player %s to make, your turn is skipped and passed to Player %s\n", pCurrent->name, pOpponent->name);
      draw++;

      if (*draw = 2) 
      return;
   }
   
}

/** 
 *  Function gets coordinates by finding the possible moves; it takes in:
 *  Disk board[][]: 2D array representing row and col of board
 */
void getCoords(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, listNodePtr *sPtr) {

   /**
    * Finds the current player's dics and then checks for the nearby dics of the other colour
    
   This for loop iterates around the rows */
   for (int i = 0; i < BOARD_SIZE; i++) {
      //This for loop iterates around the columns
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j].type == pCurrent->type)   //If the discs match
            findPossibleMoves(board, sPtr, *pOpponent, i, j); 
      }
   }
}

/**
 *  Function prints the legal playable move(s) to the console
 */
void printCoords(listNodePtr currentPtr, int *max) {
	int i = 1;                                      //i is set to the index of a possible move     
   int j, a;           
	while (currentPtr != NULL) {
		j = currentPtr->row;                         //j is set to the rows
		a = currentPtr->col;                         //a is set to the columns
      printf("Move %d: (%c %d) | ", i, a + 1 - 1 + 'A', j + 1);

      //This if statement only allows a max of 4 moves per line for aesthetic reasons
      if ((i % 4) == 0) {
         puts("");
      }

		i++;	                                       //Increments i
		*max = i-1;                                  //Sets max to i -1
		
		currentPtr = currentPtr->nextPtr;            //Go to the next node in the linked list
	}
}

/**
 *  Function prompts the user to choose a move 
 */
void askChooseCoord(Player pCurrent, int max, int *choice) { 
   fflush(stdin);                                  //Clears the pre-entered input for scanf

   //The following allows either user to end the game early if they wish to exit
   printf("\n\nWould you like to exit the game or continue? ");
   char answer[10];                                //String array to store the user's answer
   fflush(stdin);                                  //Clears the pre-entered input for scanf
   scanf("%s", answer);

   //This while loop will execute with an invalid input
   while ((strcmp(answer, "exit") != 0)     && (strcmp(answer, "Exit") != 0)     && (strcmp(answer, "EXIT") != 0)     &&
         (strcmp(answer, "continue") != 0)  && (strcmp(answer, "Continue") != 0) && (strcmp(answer, "CONTINUE") != 0) &&
         (strcmp(answer, "E") != 0)         && (strcmp(answer, "e") != 0)        && (strcmp(answer, "C") != 0)        && (strcmp(answer, "c") != 0)) {

      fflush(stdin);                               //Clears the pre-entered input for scanf
      printf("Error 404!\nCommands:\n\tE \\ Exit - To exit\n\tC \\ Continue - To continue\n\nTry again: ");
      scanf("%s", answer);
   }

   //If the user wishes to exit, the following will execute
   if ((strcmp(answer, "exit") == 0) || (strcmp(answer, "Exit") == 0) || (strcmp(answer, "EXIT") == 0) || (strcmp(answer, "e") == 0) || (strcmp(answer, "E") == 0)) {
      puts("\nThank you for playing players!\nHave a good day!");
      exit(EXIT_SUCCESS);
   }

   //Otherwise the players play on
   else{
      do {
         printf("%s; Your move: ", pCurrent.name);
         scanf("%d", choice);

         //If the player chooses an invalid choice, they are prompted for a correct answer
         if (!(*choice > 0 && *choice <= max)){
            printf("Error 404: try again: ");
         }
      }
      //This do while loop will continue to execute until the user enters a correct answer
      while (!(*choice > 0 && *choice <= max));
   }
   fflush(stdin);                                  //Clears the pre-entered input for the next turn
}

/**
 * Function that check own disks in order to replace opponent's disks after each turn and updates each player's number of disks
 */
void getChosenCoord(listNodePtr *sPtr, int choice, int *row, int *col) {
	int i = 0;

   //As long as the linked list is not empty
	if (!(isEmpty(*sPtr))) {
		listNodePtr previousPtr = *sPtr;
		listNodePtr currentPtr = (*sPtr)->nextPtr;
		
		//This while loop will continue to execute until the user's choice is met
		while (previousPtr != NULL) {
			++i;
			if (i == choice) {
				*row = previousPtr->row;
				*col = previousPtr->col;
				break;                                 //Break out of the loop once the user's choice is met
			}
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
	}	
	while (!(isEmpty(*sPtr)))                       //Remove the current nodes and free up the allocated memory for this specific turn
		dequeue(sPtr);
}

/** 
 * Function places user disks according to their choice and make changes to opponent's disks
 */
void placeDisks(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col) {
   //Check the current disk for its marker before updating
	if (board[row][col].type == EMPTY) {
		board[row][col].type = pCurrent->type;
		pCurrent->disks++;
		
		//replace all disks of the opposite colour
		updateGame(board, pCurrent, pOpponent, row, col);
	}
}