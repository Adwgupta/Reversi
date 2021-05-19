#ifndef OTHELLO_INITIALIZE_H
#define OTHELLO_INITIALIZE_H

/**
 * Custom library file to print out coloured output to the console
 * Note: This library cannot be used in CLion or command prompt as CLion does not support ANSI escape sequences
 */
/**
 * This libary is not being used as this version of the program
 * as this version has been created for termnials/ides which do not support ansi escape sequences
 * This is also the version you can run on command prompt
 * #include "colour.h"  
*/
#include "ascii.h"      

//Max length for player name
#define NAME_LENGTH 50  
//board size for an 8x8 board
#define BOARD_SIZE 8

//Disk colours
enum colour {
   BLACK, WHITE, EMPTY             //Disk colours
}; 

//Player info
typedef struct Player {
   char name[NAME_LENGTH];         //Player name.
   enum colour type;               //Player's disk colour.
	int disks;                      //Player's current number of disks on board.
}  Player;

//Disk position 
typedef struct Position {
	int row;                        //Row position for disks
	int col;                        //column position for disks
}  Position;

//Disk info.
typedef struct Disk {
	enum colour type;               //Disk colour.
	Position pos;                   //Disk position.
}  Disk;

//Linked List used to store the number of moves per turn.
struct ListNode {
	int row;
	int col;
	struct ListNode *nextPtr;       //Points to next node.
};

typedef struct ListNode listNode;  //ListNode is a synonym for struct ListNode.
typedef listNode *listNodePtr;     //ListNodePtr is a synonym for pointer to a listNode.

/**
 * Function prototypes
 *
 * 
Function to remove newline chars */
void removeNewline(char a[]);
//Function to assign player names and colours
void playerSetUp(Player *p1, Player *p2);
//Function to set up the 4 starting pieces on the board
void boardSetUp(Disk board[][BOARD_SIZE]);
//Function to print the board
void printBoard(Disk board[][BOARD_SIZE]);

#endif 