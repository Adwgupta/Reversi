#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "initialize.h"
#include "preGame.h"

//Function to remove newline chars at the end of a string 
void removeNewline(char string[]) {
   int len = strlen(string) - 1;        //Gets the length of the string up to the 2nd last character

   if (string[len] == '\n')             //If the 2nd last character is a newline, replace it with the null character.
      string[len] = '\0';
}

//Function to take in user input for player's names, assigns each player a colour and the starting score of 2
void playerSetUp(Player *p1, Player *p2) {
   //Player 1 (black)
   printf("(Disk Colour: Black) - Player 1, please enter your name: ");
   fgets(p1->name, NAME_LENGTH, stdin); //Prompts for name.
   p1->type = BLACK;                    //Player 1 plays with black disks.
   p1->disks = 2;                       //Each player starts with 2 disks placed diagonally at the centre of the board.

   //Player 2 (white)
   printf("(Disk Colour: White) - Player 2, please enter your name: ");
   fgets(p2->name, NAME_LENGTH, stdin); //Prompts for name.
   p2->type = WHITE;                    //Player 2 plays with black disks.
   p2->disks = 2;                       //Each player starts with 2 disks placed diagonally at the centre of the board.

   //Removes the newline chars for the names of the players
   removeNewline(p1->name);
   removeNewline(p2->name);
}

//Function sets up the board with the 4 centre pieces with black white or "empty"
void boardSetUp(Disk board[][BOARD_SIZE]) {
   //This for loop iterates around the rows
   for (int i = 0; i < BOARD_SIZE; i++) {
      //This loop iterates around the columns
      for (int j = 0; j < BOARD_SIZE; j++) {
         switch (i) {
            case 3:
               switch (j) {
                  case 3:               //Marks position (4 4) as white
                     board[i][j].type = WHITE;
                     break;
                  case 4:               //Marks position (4 5) as white
                     board[i][j].type = BLACK;
                     break;
                     default:           //Marks the rest of the columns in row 4 as "empty"
                     board[i][j].type = EMPTY;
               }
            break;

            case 4:
               switch (j) {
                  case 3:                //Marks position (5 4) as white
                     board[i][j].type = BLACK;
                     break;
                  case 4:               //Marks position (5 4) as white
                     board[i][j].type = WHITE;
                     break;
                  default:              //Marks the rest of the columns in row 4 as "empty"
                     board[i][j].type = EMPTY;
               }
            break;

            default:                    //Marks all other positions as "empty"
            board[i][j].type = EMPTY;
         }
         board[i][j].pos.row = i;
         board[i][j].pos.col = j;

         
      }
   }
}

/**
 *  Function to print out the board 
 * 
 *  On CLion and command prompt the ANSCI colour escape sequences do not work so there are two versions created;
 *  One version (ANSI escape sequence supported) and one version which is not
 *  This version is ANSI supported
 */
void printBoard(Disk board[][BOARD_SIZE]) {
   printf("\n\n   ");

   //This for loop iterates around the columns to print out the column co-ordinates from A - H
   for (int i = 1; i <= BOARD_SIZE; i++) 
      printf("___%c___ ", i - 1 + 'A');

   //This for loop iterates around the rows
   for (int j = 0; j < BOARD_SIZE; j++) {
      printf("\n  |"); //Board border
      /**
       * The following 3 for loops prints out the actual board and the disks
       */

      //This for loop is for the "upper part" of the squares
      for (int i = 0; i < BOARD_SIZE; i++) {
         //For black discs
         if (board[j][i].type == BLACK) {
            blackMarker();              //This changes the colour output to print out a black background
            printf("       ");          //This will print out a black background text to serve as the black marker
            resetcolour();              //This resets the colour back to white
            printf("|");
         }
         //For white discs
         if (board[j][i].type == WHITE) {
            whiteMarker();              //This changes the colour output to print out a black background
            printf("       ");          //This will print out a black background text to serve as the black marker
            resetcolour();              //This resets the colour back to white
            printf("|");
         }
         //For playable co-ordinates
         if (board[j][i].type == EMPTY)
            printf("       |");
      }

      //The following printf and for loop are for the "middle part" of the squares
      printf("\n%d |", j + 1); //Left row co-ordinates from 1 - 8

      for (int i = 0; i < BOARD_SIZE; i++) {
         //For black discs
         if (board[j][i].type == BLACK) {
            blackMarker();              //This changes the colour output to print out a black background
            printf("       ");          //This will print out a black background text to serve as the black marker
            resetcolour();              //This resets the colour back to white
            printf("|");
         }
         //For white discs
         if (board[j][i].type == WHITE) {
            whiteMarker();              //This changes the colour output to print out a black background
            printf("       ");          //This will print out a black background text to serve as the black marker
            resetcolour();              //This resets the colour back to white
            printf("|");
         }
         //For playable co-ordinates
         if (board[j][i].type == EMPTY)
            printf("       |");
      }

      printf(" %d", j + 1);             //Left row co-ordinates from 1 - 8
      printf("\n  |");                  //Board border

      //This for loop is for the "lower part" of the squares
      for (int i = 0; i < BOARD_SIZE; i++) {
         //For black discs
         if (board[j][i].type == BLACK) {
            blackMarker();              //This changes the colour output to print out a black background
            printf("_______");          //This will print out a black background text to serve as the black marker
            resetcolour();              //This resets the colour back to white
            printf("|");
         }
         //For white discs
         if (board[j][i].type == WHITE) {
            whiteMarker();              //This changes the colour output to print out a black background
            printf("_______");          //This will print out a black background text to serve as the black marker
            resetcolour();              //This resets the colour back to white
            printf("|");
         }
         //For playable co-ordinates
         if (board[j][i].type == EMPTY)
            printf("_______|");
      }
   }

   printf("\n     ");
   //This for loop iterates around the columns to print out the column co-ordinates from A - H
   for (int i = 1; i <= BOARD_SIZE; i++)
      printf(" %c      ", i - 1 + 'A');
}