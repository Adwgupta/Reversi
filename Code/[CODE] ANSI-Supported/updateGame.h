#ifndef OTHELLO_UPDATE_GAME_H
#define OTHELLO_UPDATE_GAME_H

//Function that handles updating the disks and score of each turnS
void updateGame(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col);

/**
 * The following are functions that updates moves in each direction, in a clockwork-like fashion
 *
 * For each direction, the disk and score changes are only changed 
 * If it the current player's disk can be found around anopponent disk. 
 * If that position holds an opponent disk or no disk, it is ignored.
 *
 * The following three functions check moves in the northern regions of the board 
 * 
 * 
This function updates disks upwards diagonalally left from a player's disks, ie in a north westerly direction */
void updateNorthWest(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col);
//This function updates disks upwards from a player's disks, ie in a northerly direction
void updateNorth(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col);
//This function updates disks upwards diagonalally right  from a player's disks, ie in a north westerly direction
void updateNorthEast(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col);


//This function updates disks sideways (left) from a player's disks, ie in a westerly direction
void updateWest(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col);
//This function updates disks sideways (right) from a player's disks, ie in a easterly direction
void updateEast(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col);

/**
 * The following three moves updates disks in the southern regions of the board
 *
 * 
This function updates disks downwards diagonalally left from a player's disks, ie in a south westerly direction */
void updateSouthWest(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col);
//This function updates disks downwards from a player's disks, ie in a southerly direction
void updateSouth(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col);
//This function updates disks downwards diagonalally right from a player's disks, ie in a south easterly direction
void updateSouthEast(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col);

#endif 