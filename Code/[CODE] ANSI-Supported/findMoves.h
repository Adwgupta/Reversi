#ifndef OTHELLO_FIND_MOVES_H
#define OTHELLO_FIND_MOVES_H

#include "initialize.h"
/**
 * Function prototypes
 *
 * 
Fuction that checs if a move is in the linked list  */
int isInList(listNodePtr currentPtr, int r, int c);
//Function that adds a new move into the linked list
void insert(listNodePtr *sPtr, int r, int c);
//This function handles checking moves
void findPossibleMoves(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col);

/**
 * The following are functions that check moves in each direction, in a clockwork-like fashion
 * For each direction, the possible move is only registered if there are no disks there. 
 * If there is an opponent disk or player disk, it is ignored.
 * 
 * Each function checks the perimeter for an opponent's disk, 
 * If opponent disk exists, the function goes further that direction.
 * In that direction, if more opponent disks exist then the function continues until we get an empty square or the player's disk
 *  - If we get a NONE, that means we can place our disk there.
 *  - If we get player's own disk colour, it means we simply ignore that path.
 * 
 * The following three functions check moves in the northern regions of the board 
 *
 *  
This function checks for moves upwards diagonalally left from a player's disks, ie in a north westerly direction */
void checkNorthWest(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col);
//This function checks for moves upwards from a player's disks, ie in a northerly direction
void checkNorth(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col);
//This function checks for moves upwards diagonalally right from a player's disks, ie in a north easterly direction
void checkNorthEast(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col);


//This function checks for moves sideways (left) from a player's disks, ie in a westerly direction
void checkWest(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col);
//This function checks for moves sideways (right) from a player's disks, ie in a easterly direction
void checkEast(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col);

/**
 * The following three moves checks moves in the southern regions of the board
 *
 * 
This function checks for moves downwards diagonalally left from a player's disks, ie in south westerly direction */
void checkSouthWest(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col);
//This function checks for moves downwards from a player's disks, ie in southerly direction
void checkSouth(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col);
//This function checks for moves downwards diagonalally right from a player's disks, ie in south easterly direction
void checkSouthEast(Disk board[][BOARD_SIZE], listNodePtr *sPtr, Player pOpponent, int row, int col);

#endif