#include <stdio.h> 
#include <stdlib.h> 
#include "findMoves.h"

/**
 * Function checks if the position already exists in the linked list or not
 */
int isInList(listNodePtr currentPtr, int r, int c) {
   while (currentPtr != NULL) {
      /**
       * If the co-ordinates exist in the list, return 1
       * Otherwise keep searching til the end of the list
       * and return 0 if it is not in the list
       */
      if (currentPtr->row == r && currentPtr->col == c)
         return 1;

      currentPtr = currentPtr->nextPtr;
   }
   return 0;
}

/**
 * Function now inserts the position, into the linked list
 */
void insert(listNodePtr *sPtr, int r, int c) {
   //Check if coordinates is already in the linked list.
   if (!(isInList(*sPtr, r, c))) {
      listNodePtr newPtr = malloc(sizeof(listNode));

      //Check for sufficient memory
      if (newPtr != NULL) {
         newPtr->row = r;
         newPtr->col = c;
         newPtr->nextPtr = NULL;

         listNodePtr previousPtr = NULL;
         listNodePtr currentPtr = *sPtr;

         //Loop to find the correct location in the list.
         while (currentPtr != NULL && ((r > currentPtr->row) || (r == currentPtr->row && c > currentPtr->col))) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
         }

         //Insert at the beginning of linked list, if no nodes in linked list.
         if (previousPtr == NULL) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
         }

         //Insert new node between previousPtr and currentPtr.
         else { 
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
         }
      }
      else
         printf("Error 404! Memory insufficient.\n");
   }
}

/**
 * Function handles checking moves
 * This function is called to check each of current player's disks' perimeter for opponent's disks on board for every turn.
 */
void findPossibleMoves(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col) {
   //This for loop iterates around the rows
   for (int i = row-1; i <= row+1; i++) {
		//Ignore coords outside board.
		if (!(i >= 0 && i < BOARD_SIZE))
			continue;

		//This for loop loops around the columns
		for (int j = col-1; j <= col+1; j++) {
			//Ignore coords outside board.
			if (!(j >= 0 && j < BOARD_SIZE))
				continue;
      
         //Ignores itself
         if (i == row && j == col) 
				continue;

         /**
          * If the current disk is not empty and not the current player's colour
          * Check further towards that direction for opponent disks.
          * Check for opponent disks in the perimeter.
          */
         if (board[i][j].type == pOpponent.type) {
            //Upwards
            if (i == row-1) {
               //North West
               if (j == col-1) 
						checkNorthWest(board, sPtr, pOpponent, row, col);
               //North
               else if (j == col)
						checkNorth (board, sPtr, pOpponent, row, col);
               //North East
               else if (j == col+1) 
						checkNorthEast(board, sPtr, pOpponent, row, col);
				}

            //Left or right
				else if (i == row) {
               //West
               if (j == col-1)
						checkWest(board, sPtr, pOpponent, row, col);
               //East
               else if (j == col+1)
						checkEast(board, sPtr, pOpponent, row, col);
				}

            //Downwards
				else if (i == row+1) {
               //South West
               if (j == col-1)
						checkSouthWest(board, sPtr, pOpponent, row, col);
               //South
               else if (j == col) 
						checkSouth (board, sPtr, pOpponent, row, col);
               //South East
               else if (j == col+1) 
						checkSouthEast(board, sPtr, pOpponent, row, col);
				}
			}
		}
	}
}

//This function checks for moves upwards diagonalally left from a player's disks, ie in a north westerly direction
void checkNorthWest(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col) {
   /**
    * This for loop will iterate around the rows and columns,
    * until the conditions for this direction are met
    */
   for (int r = row-2, c = col-2; r >= 0 && c >= 0; ) {
      if (board[r][c].type == pOpponent.type) {
			r--;
			c--;
		}

      //If empty, a disk can be placed here
      else if (board[r][c].type == EMPTY) {
			insert(sPtr, r, c);
			break;
		}

      //Ignore the player's own disk color
      else 
			break;
	}
}

//This function checks for moves upwards from a player's disks, ie in a north westerly direction
void checkNorth(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col) {
   /**
    * This for loop will iterate around the rows and columns,
    * until the conditions for this direction are met
    */
   for (int r = row-2, c = col; r >= 0; ) {
		if (board[r][c].type == pOpponent.type)
			r--;

      //If empty, a disk can be placed here
      else if (board[r][c].type == EMPTY) {
			insert(sPtr, r, c);
			break;
		}

      //Ignore the player's own disk color
      else
			break;
	}
}

//This function checks for moves upwards diagonalally right from a player's disks, ie in a north easterly direction
void checkNorthEast(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col) {
   /**
    * This for loop will iterate around the rows and columns,
    * until the conditions for this direction are met
    */
   for (int r = row-2, c = col+2; r >= 0 && c < BOARD_SIZE; ) {
		if (board[r][c].type == pOpponent.type) {
			r--;
			c++;
		}

      //If empty, a disk can be placed here
      else if (board[r][c].type == EMPTY) {
			insert(sPtr, r, c);
			break;
		}

      //Ignore the player's own disk color
      else
			break;
	}
}

//This function checks for moves sideways (left)  from a player's disks, ie in a westerly direction
void checkWest(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col) {
   /**
    * This for loop will iterate around the rows and columns,
    * until the conditions for this direction are met
    */
   for (int c = col-2, r = row; c >= 0; ) {
		if (board[r][c].type == pOpponent.type)
			c--;

      //If empty, a disk can be placed here
      else if (board[r][c].type == EMPTY) {
			insert(sPtr, r, c);
			break;
		}

      //Ignore the player's own disk color
      else
			break;
	}
}

//This function checks for moves sideways (right) from a player's disks, ie in a easterly direction
void checkEast(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col) {
   /**
    * This for loop will iterate around the rows and columns,
    * until the conditions for this direction are met
    */
   for (int c = col+2, r = row; c < BOARD_SIZE; ) {
		if (board[r][c].type == pOpponent.type)
			c++;

      //If empty, a disk can be placed here
      else if (board[r][c].type == EMPTY) {
			insert(sPtr, r, c);
			break;
		}

      //Ignore the player's own disk color
      else
			break;
	}
}

//This function checks for moves downwards diagonalally left from a player's disks, ie in south westerly direction
void checkSouthWest(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col) {
   /**
    * This for loop will iterate around the rows and columns,
    * until the conditions for this direction are met
    */
   for (int r = row+2, c =col-2; r < BOARD_SIZE&& c >= 0; ) {
		if (board[r][c].type == pOpponent.type) {
			r++;
			c--;
		}

      //If empty, a disk can be placed here
      else if (board[r][c].type == EMPTY) {
			insert(sPtr, r, c);
			break;
		}

      //Ignore the player's own disk color
      else
			break;
	}
}

//This function checks for moves downwards from a player's disks, ie in southerly direction
void checkSouth(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col) {
   /**
    * This for loop will iterate around the rows and columns,
    * until the conditions for this direction are met
    */
   for (int r = row + 2, c = col; r < BOARD_SIZE;) {
      //Inner loop, (for direction heading towards a direction)
      if (board[r][c].type == pOpponent.type)
			r++;

      //If empty, a disk can be placed here
      else if (board[r][c].type == EMPTY) {
			insert(sPtr, r, c);
			break;
		}

      //Ignore the player's own disk color
      else
			break;
   }
}

//This function checks for moves downwards diagonalally right from a player's disks, ie in south easterly direction
void checkSouthEast(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col) {
   /**
    * This for loop will iterate around the rows and columns,
    * until the conditions for this direction are met
    */
   for (int r = row+2, c = col+2; r < BOARD_SIZE && c < BOARD_SIZE;) {
      if (board[r][c].type == pOpponent.type) {
			r++;
			c++;
		}

      //If empty, a disk can be placed here
      else if (board[r][c].type == EMPTY) {
			insert(sPtr, r, c);
			break;
		}

      //Ignore the player's own disk color
      else
			break;
   }
}