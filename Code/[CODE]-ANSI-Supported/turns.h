#ifndef OTHELLO_TURNS_H
#define OTHELLO_TURNS_H

#include "initialize.h"
#include "findMoves.h"
#include "updateGame.h"

/**
 * Function prototypes
 * 
 * 
Function to check if a linked list is empty */
int isEmpty(listNodePtr sPtr);
//Function to remove a node from a linked list
void dequeue(listNodePtr *sPtr);

//Function to manage turns
void manageTurns(Disk board[][BOARD_SIZE], Player *p1, Player *p2);
//FUnction to handle player's moves
void manageMoves(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int *draw);

//Function to get playable positions
void getCoords(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, listNodePtr *sPtr);
//Function to print moves
void printCoords(listNodePtr currentPtr, int *max);
//Function to allow the user to choose a move
void askChooseCoord(Player pCurrent, int max, int *choice);
//Function to check current disks
void getChosenCoord(listNodePtr *sPtr, int choice, int *row, int *col);

//Function to update the board
void placeDisks(Disk board[][BOARD_SIZE], Player *pCurrent, Player *pOpponent, int row, int col);

#endif 