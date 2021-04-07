#include <stdio.h>
#include <time.h>
#include "AfterGame.h"

//Prints out game results
void resultsFile(FILE *out, char printingMessage[]) {
    //Creates the desired output txt file, replaces the previous file contents with the new code output
    fp = fopen(file, "a");
    //Variable t that will store the current time
    time_t t;
    //Seeds variable t with current time
    time(&t);
    //For now we're printing out the message string/array from main and the current time
    fprintf(out, "Message:\n%s\nExecuted at:\n%s", printingMessage, ctime(&t));
}