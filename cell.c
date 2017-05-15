#include <stdio.h>
#include "cell.h"

void kill(cell c, int size) {
	int i;

    for (i = 0; i < size; i++) {
        c[i] = 0;
	}
}

void rise(cell c, int size){
    int i;

    for (i = 0; i < size; i++) {
        c[i] = 1;
    }
}
