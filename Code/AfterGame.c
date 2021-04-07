#include <stdio.h>
#include <time.h>
#include "AfterGame.h"

//Prints out game results
void resultsFile(FILE *out) {
    /**
     * Creates the desired output txt file and appends the results to the file
     * if the file doesnt exist, it will be created
     */
    if ((fp = fopen(file, "a")) == NULL)
		perror;
    //Variable t that will store the current time
    time_t t;
    //Seeds variable t with current time
    time(&t);
    //For now we're printing out the message string/array from main and the current time
    fprintf(out, "Executed at:\n%s", ctime(&t));
}