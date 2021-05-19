#include <stdio.h>
#include <time.h>
#include "preGame.h"

//Function to print out welcome in yellow
void w1(){
   //yellow();
   welcomeArt();
   //resetcolour();
}

//Function to handle pre game text printing
void openingCredits(Player p1, Player p2) {
   /**
    * Opens the txt output file created in the preGame file and appends the game opening to the file
    * if the file doesnt exist, it will be created
    */
   if ((fp = fopen(resultsFile, "a")) == NULL)
      perror;

   welcome(fp, p1, p2);
   instructions();
   printf("\nPlease take a look at the isntructions txt file that has just been created for a full list of the game instructions\n\n");

   //green();
   puts("");
   newGameArt(stdout);
   //resetcolour();
}

//Function to print out the time that the game started along with the player's names
void welcome(FILE *out, Player p1, Player p2) {
   //Variable t that will store the current time
   time_t t;
   //Seeds variable t with current time
   time(&t);
   newGameArt(out);
   fprintf(out, "\nGame started at:\n%s\nPlayers:\n\tP1: %s\n\tP2: %s\n\n", ctime(&t), p1.name, p2.name);
}

//Function to create the instructions txt file
void instructions() {
   /**
    * Creates the instructions txt file created in the preGame file
    * if the file doesnt exist, it will be created
    */
   if ((fp2 = fopen(instructFile, "w+")) == NULL)
      perror;

   instructionsArt(fp2);
   fprintf(fp2, "The game begins with four discs placed in a square in the middle of the grid,\n"
                "Two with their black side facing up, two with their white side facing up\n"
                "With the two discs with the same colour on a diagonal with each other, as shown below:\n\n"

                " --- --- \n"
                "| w | B |\n"
                " --- --- \n"
                "| w | B |\n"
                " --- --- \n\n"

                "==================== GAMEPLAY ====================\n\n"

                "On your turn, you place one piece on the board with your color facing up.\n"
                "You must place the piece so that an opponent's piece, or a row of opponent's pieces, is flanked by your pieces.\n"
                "All of the opponent's pieces between your pieces are then turned over to become your color.\n\n"

                "The following would be playable moves for the black disks, with \'*\' incidcating what would be a legal move:\n\n"

                " --- --- --- --- --- --- \n"
                "|   |   | * |   |   |   |\n"
                " --- --- --- --- --- --- \n"
                "|   | * | w | B |   |   |\n"
                " --- --- --- --- --- --- \n"
                "|   |   | B | W | * |   |\n"
                " --- --- --- --- --- --- \n"
                "|   |   |   | * |   |   |\n"
                " --- --- --- --- --- --- \n\n"

                "A move consists of placing one piece on an empty square.\n"
                "You can capture vertical, horizontal, and diagonal rows of pieces. Also, you can capture more than one row at once.\n\n"

                "==================== HOW TO WIN ====================\n\n"

                "The object of the game is to own more pieces than your opponent when the game is over.\n"
                "The game is over when neither player has a move. Usually, this means the board is full\n\n\n"

                "A full in depth video of how to play can be found on this youtube video:\n\t\t\t"
                "https://www.youtube.com/watch?v=Ol3Id7xYsY4\n\t\t\t"
                "https://www.youtube.com/watch?v=dQw4w9WgXcQ\n\t\t\t"
                "https://www.youtube.com/watch?v=Lrj2Hq7xqQ8\n\t\t\t"
                "https://www.youtube.com/watch?v=g_KYQltEAuc");
}
