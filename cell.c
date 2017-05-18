#include <stdio.h>
#include "cell.h"

#ifndef LIMIT_CELLS  
  #define LIMIT_CELLS 4 
#endif
bool isStayAlive(cell *cells, int x, int y) {
	__validate_index_in_range_matriz(x,y);

	if(isAlive(cells, x, y) == false) {
		return false; 
	}

	int neighbors = getNeighbors(cells, x, y);
	if(neighbors < 2) {
		return false;	
	} else if(neighbors > 3) {
		return false;
	}

	return true;
}

bool isAlive(cell *c, int x, int y) {
	__validate_index_in_range_matriz(x,y);

	return (c[y][x] == ALIVE);
} 

bool canRise(cell *c,int x, int y) {
	__validate_index_in_range_matriz(x,y);
	return (c[y][x] == ALIVE);
}

int getNeighbors(cell *c, int x, int y) {
	__validate_index_in_range_matriz(x,y);
	int neighbors = 0;

	//verify left
	if(x > 0 && c[y][x-1] == ALIVE)  {
		neighbors += 1;	
	}

	//verify right 
	if(x < LIMIT_CELLS && c[y][x+1] == ALIVE)  {
		neighbors += 1;	
	}

	//verify top
	if(y > 0 && c[y-1][x] == ALIVE)  {
		neighbors += 1;	
	}

	//verify bottom
	if(y < LIMIT_CELLS && c[y+1][x] == ALIVE)  {
		neighbors += 1;	
	}

	return neighbors;
}

void kill(cell *c, int size) {
	int i;

	for (i = 0; i < size; i++) {
		*c[i] = 0;
	}
}

void rise(cell *c, int size){
    int i;

    for (i = 0; i < size; i++) {
        *c[i] = 1;
    }
}

int importPopulation(cell *c, char *path, int length) {
	int generation;
	char buff[length+2];
	FILE *file;

	file = fopen(path, "r");
	if (file == NULL) {
		fprintf(stderr, "%s: %s\n", CELL_ERR_FILE_NOT_OPEN, path);
		exit(EXIT_FAILURE);
	}
	int linha = 0;
	generation = -1;
	while (fgets(buff,sizeof buff, file) != NULL){
		 if(generation == -1) {
			generation = atoi(buff);
			continue;
		} 

		int coluna; 
		for(coluna=0; coluna < sizeof buff; coluna++) {
			if(buff[coluna] == '\n' ||
			   buff[coluna] == ' '  ||
			   buff[coluna] == '\0'  
			) { continue; }

			if(buff[coluna] == '0') {
				c[linha][coluna]= 0; 
			} else if(buff[coluna] == '1') {
				c[linha][coluna]= 1; 
			}
		}
		linha++;
	}
	fclose(file);

	return generation;
}

//HELPERS
void initialize_cells(cell *cells, int SIZE_X, int SIZE_Y) {
	int x = 0;
	int y = 0;

	for(x = 0; x <  SIZE_X; x+=1) {
		cells[x] = (cell)malloc(LIMIT_CELLS*sizeof(int));
		for(y = 0; y <  SIZE_Y; y+=1) { 
			cells[x][y] = 0;	
		}
	}
}

void __validate_index_in_range_matriz(int  x,int y) {
	if(x < 0 || y < 0 || x > LIMIT_CELLS || y > LIMIT_CELLS) {
		fprintf(stderr, "%s: line = %d, column = %d", CELL_ERR_INDEX_OUT_OF_RANGE, y, x);
		exit(EXIT_FAILURE);
	}
}
