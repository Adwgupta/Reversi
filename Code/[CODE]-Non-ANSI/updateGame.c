#include "initialize.h"
#include "updateGame.h"

//Function updates both player's disks based on current user's choice of move
void updateGame(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col) {
   //This for loop iterates around the rows
	for (int i = row-1; i <= row+1; i++) {
      //This for loop iterates around the columns
		for (int j = col-1; j <= col+1; j++) {

         //As long the disk being updated is the other colour
			if (board[i][j].type == pOpponent->type) {
				//Upwards
				if (i == row-1) {
               //North West
               if (j == col-1) 
						updateNorthWest(board, pCurrent, pOpponent, row, col);
               //North
               else if (j == col)
						updateNorth(board, pCurrent, pOpponent, row, col);
               //North East
               else if (j == col+1) 
						updateNorthEast(board, pCurrent, pOpponent, row, col);
				}

            //Left and right
				else if (i == row) {
               //West
               if (j == col-1) 
						updateWest(board, pCurrent, pOpponent, row, col);
               //East
               else if (j == col+1) 
						updateEast(board, pCurrent, pOpponent, row, col);
				}

            //Downwards
				else if (i == row+1) {
               //South West
               if (j == col-1) 
						updateSouthWest(board, pCurrent, pOpponent, row, col);
               //South
					else if (j == col) 
						updateSouth(board, pCurrent, pOpponent, row, col);
               //South East
					else if (j == col+1) 
						updateSouthEast(board, pCurrent, pOpponent, row, col);
				}
			}
      }
   }
}

//This function updates disks upwards diagonalally left from a player's disks, ie in a north westerly direction
void updateNorthWest(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col) {
	//This for loop loops until we get to the disk that will be the furthest being updated
	for (int r = row-2, c = col-2; r >= 0 && c >= 0; ) {
      //If the current disk is the opposing colour keep going
		if (board[r][c].type == pOpponent->type) {
			r--;
			c--;
		}
      //Once we reach the current player's colour
		else if (board[r][c].type == pCurrent->type) {
         /**
          * This for loop loops back to the loation of the starting disk
          * and updates all of the disks along the way
          */
			for (int x = r+1, y = c+1; x < row && y < col; )
				//If the disk is the opponent's disk, ONLY then it gets updated
				if (board[x][y].type == pOpponent->type) {	
					board[x][y].type = pCurrent->type;
					x++;
					y++;

               //Update the score of each player
					pCurrent->disks++;
					pOpponent->disks--;
				}
				
			break;
		}
      //Ignore empty locations
      else 
			break;
	}
}

//This function updates disks upwards from a player's disks, ie in a northerly direction
void updateNorth(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col) {
	//This for loop loops until we get to the disk that will be the furthest being updated
   for (int r = row-2, c = col; r >= 0; ) {
      //If the current disk is the opposing colour keep going
      if (board[r][c].type == pOpponent->type)
			r--;

      //Once we reach the current player's colour
      else if (board[r][c].type == pCurrent->type) {
         /**
          * This for loop loops back to the loation of the starting disk
          * and updates all of the disks along the way
          */
         for (int x = r+1, y = c; x < row; )
            //If the disk is the opponent's disk, ONLY then it gets updated
            if (board[x][y].type == pOpponent->type) {
					board[x][y].type = pCurrent->type;
					x++;

               //Update the score of each player
               pCurrent->disks++;
					pOpponent->disks--;
				}
			break;
		}
      //Ignore empty locations
      else
			break;
	}
}

//This function updates disks upwards diagonalally right  from a player's disks, ie in a north westerly direction
void updateNorthEast(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col) {
	//This for loop loops until we get to the disk that will be the furthest being updated
   for (int r = row-2, c = col+2; r >= 0 && c < BOARD_SIZE; ) {
      //If the current disk is the opposing colour keep going
      if (board[r][c].type == pOpponent->type) {
			r--;
			c++;
		}

      //Once we reach the current player's colour
      else if (board[r][c].type == pCurrent->type) {
         /**
          * This for loop loops back to the loation of the starting disk
          * and updates all of the disks along the way
          */
         for (int x = r+1, y = c-1; x < row && y > col; )
            //If the disk is the opponent's disk, ONLY then it gets updated
            if (board[x][y].type == pOpponent->type) {
					board[x][y].type = pCurrent->type;
					x++;
					y--;

               //Update the score of each player
               pCurrent->disks++;
					pOpponent->disks--;
				}
			break;
		}
      //Ignore empty locations
      else
			break;
	}
}

//This function updates disks sideways (left) from a player's disks, ie in a westerly direction
void updateWest(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col) {
	//This for loop loops until we get to the disk that will be the furthest being updated
   for (int c = col-2, r = row; c >= 0; ) {
      //If the current disk is the opposing colour keep going
      if (board[r][c].type == pOpponent->type)
			c--;

      //Once we reach the current player's colour
      else if (board[r][c].type == pCurrent->type) {
         /**
          * This for loop loops back to the loation of the starting disk
          * and updates all of the disks along the way
          */
         for (int y = c+1, x = r; y < col; )
            //If the disk is the opponent's disk, ONLY then it gets updated
            if (board[x][y].type == pOpponent->type) {
					board[x][y].type = pCurrent->type;
					y++;

               //Update the score of each player
               pCurrent->disks++;
					pOpponent->disks--;
				}
			break;
		}
      //Ignore empty locations
      else
			break;
	}
}

//This function updates disks sideways (right) from a player's disks, ie in a easterly direction
void updateEast(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col) {
	//This for loop loops until we get to the disk that will be the furthest being updated
   for (int c = col+2, r = row; c < BOARD_SIZE; ) {
      //If the current disk is the opposing colour keep going
      if (board[r][c].type == pOpponent->type)
			c++;

      //Once we reach the current player's colour
      else if (board[r][c].type == pCurrent->type) {
         /**
          * This for loop loops back to the loation of the starting disk
          * and updates all of the disks along the way
          */
         for (int y = c-1, x = r; y > col; )
            //If the disk is the opponent's disk, ONLY then it gets updated
            if (board[x][y].type == pOpponent->type) {
					board[x][y].type = pCurrent->type;
					y--;

               //Update the score of each player
               pCurrent->disks++;
					pOpponent->disks--;
				}
			break;
		}
      //Ignore empty locations
      else
			break;
	}
}

//This function updates disks downwards diagonalally left from a player's disks, ie in a south westerly direction
 void updateSouthWest(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col) {
   //This for loop loops until we get to the disk that will be the furthest being updated
   for (int r = row + 2, c = col - 2; r < BOARD_SIZE && c >= 0;) {
      //If the current disk is the opposing colour keep going
      if (board[r][c].type == pOpponent->type) {
         r++;
         c--;
      }

      //Once we reach the current player's colour
      else if (board[r][c].type == pCurrent->type) {
         /**
          * This for loop loops back to the loation of the starting disk
          * and updates all of the disks along the way
          */
         for (int x = r - 1, y = c + 1; x > row && y < col;)
            //If the disk is the opponent's disk, ONLY then it gets updated
            if (board[x][y].type == pOpponent->type) {
               board[x][y].type = pCurrent->type;
               x--;
               y++;

               //Update the score of each player
               pCurrent->disks++;
               pOpponent->disks--;
            }
         break;
      }
      //Ignore empty locations
      else
         break;
   }
}

//This function updates disks downwards from a player's disks, ie in a southerly direction
void updateSouth(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col) {
	//This for loop loops until we get to the disk that will be the furthest being updated
   for (int r = row+2, c = col; r < BOARD_SIZE; ) {
      //If the current disk is the opposing colour keep going
      if (board[r][c].type == pOpponent->type)
			r++;

      //Once we reach the current player's colour
      else if (board[r][c].type == pCurrent->type) {
         /**
          * This for loop loops back to the loation of the starting disk
          * and updates all of the disks along the way
          */
         for (int x = r-1, y = c; x > row; )
            //If the disk is the opponent's disk, ONLY then it gets updated
            if (board[x][y].type == pOpponent->type) {
					board[x][y].type = pCurrent->type;
					x--;

               //Update the score of each player
               pCurrent->disks++;
					pOpponent->disks--;
				}
			break;
		}
      //Ignore empty locations
      else
			break;
	}
}

//This function updates disks downwards diagonalally right from a player's disks, ie in a south easterly direction
void updateSouthEast(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col) {
   //This for loop loops until we get to the disk that will be the furthest being updated
   for (int r = row + 2, c = col + 2; r < BOARD_SIZE && c < BOARD_SIZE;) {
      //If the current disk is the opposing colour keep going
      if (board[r][c].type == pOpponent->type) {
			r++;
			c++;
		}

      //Once we reach the current player's colour
      else if (board[r][c].type == pCurrent->type) {
         /**
          * This for loop loops back to the loation of the starting disk
          * and updates all of the disks along the way
          */
         for (int x = r-1, y = c-1; x > row && y > col; )
            //If the disk is the opponent's disk, ONLY then it gets updated
            if (board[x][y].type == pOpponent->type) {
					board[x][y].type = pCurrent->type;
					x--;
					y--;

               //Update the score of each player
               pCurrent->disks++;
					pOpponent->disks--;
				}
			break;
		}
      //Ignore empty locations
      else
			break;
   }
}