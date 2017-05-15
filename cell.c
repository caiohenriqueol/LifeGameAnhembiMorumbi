#include "cell.h"

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

	return (c[x][y] == ALIVE);
} 

bool canRise(cell *c,int x, int y) {
	__validate_index_in_range_matriz(x,y);
	return (c[x][y] == ALIVE);
}

int getNeighbors(cell *c, int x, int y) {
	__validate_index_in_range_matriz(x,y);
	int neighbors = 0;

	//verify top
	if(y > 0 && c[x][y-1] == ALIVE)  {
		neighbors += 1;	
	}

	//verify bottom
	if(y < LIMIT_CELLS && c[x][y+1] == ALIVE)  {
		neighbors += 1;	
	}

	//verify left
	if(x > 0 && c[x-1][y] == ALIVE)  {
		neighbors += 1;	
	}

	//verify right 
	if(x < LIMIT_CELLS && c[x+1][y] == ALIVE)  {
		neighbors += 1;	
	}

	return neighbors;
}

void __validate_index_in_range_matriz(int  x,int y) {
	if(x < 0 || y < 0 || x > LIMIT_CELLS || y > LIMIT_CELLS) {
		printf(stderr, CELL_ERR_INDEX_OUT_OF_RANGE);
		exit(EXIT_FAILURE);
	}
}
