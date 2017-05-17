#include "cell.c"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int i, j, verify;
    int cont_kill, cont_rise;    
    cell vKill;
    cell vRise;
    cell *population;
    int generation = 1;
    int population_size = 10;
    int kill_rise_size = 100;

    vKill = (cell)calloc(kill_rise_size, sizeof(cell));
    vRise = (cell)calloc(kill_rise_size, sizeof(cell));
    population = (cell*)calloc(population_size, sizeof(cell));

    srand(time(NULL));

    for (i = 0; i < population_size; i++) {
        population[i] = (cell)calloc(population_size, sizeof(cell));
    }

    printf("******************* POPULACAO *****************\n");
    for (i = 0; i < population_size; i++) {
        for (j = 0; j < population_size; j++) {
            population[i][j] = rand()%2;
            printf("%d  ", population[i][j]);
        }
        printf("\n");
    }
    printf("******************* POPULACAO *****************\n");
    printf("\n\n\n");

    for (verify = 0; verify < generation; verify++) {
        cont_kill = cont_rise = 0;
        for (i = 0; i < population_size; i++) {
            for (j = 0; j < population_size; j++) {
		  printf("posição %d, %d\n", i, j);

                if (isStayAlive(population, i, j)) {
                    vRise[cont_rise] = population[i][j];
                    cont_rise++;
                } else {
                    vKill[cont_kill] = population[i][j];
                    cont_kill++;
                }
            }
        }
        kill(vKill, population_size);
        rise(vRise, population_size);
    }


    printf("\n\n\n");
    printf("************** RESULTADO *****************\n");

    for (i = 0; i < population_size; i++){
        for (j = 0; j < population_size; j++){
            printf("%d  ", population[i][j]);
        }
        printf("\n");
    }
    printf("************** RESULTADO *****************");
    return 1;
}
