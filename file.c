#include "file.h"
#include <stdio.h>

void createPopulation(char *generation, cell *c, int *population_size){
    int i = 0, j = 0;
    int pos;
    FILE *fPopulation;
    
    fPopulation = fopen(generation, "r");
    while (!feof(fPopulation)) {
        pos = fgetc(fPopulation);

        if (pos != '\n') {
            if (i == -1) {
                *population_size = pos;
            } else {
                c[i][j] = pos;
                j++;
            }
        } else {
            i++;
            j = 0;
        }   
    }

    fclose(fPopulation);
}
