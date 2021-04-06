#include <stdio.h>
#define file "othello-results.txt"

FILE *results;

void resultsFile();

void main(){
   printf("Hello There!\nThis is the creation of the main file and the first commit of this project");
   resultsFile();
}
//Function to print out game results into a txt file
void resultsFile(){
   if ((results = fopen(file, "w")) == NULL) { 
      //display error if file cannot be opened
      perror;
   }
   else {
      fprintf(results, "Trial run");
   }
}