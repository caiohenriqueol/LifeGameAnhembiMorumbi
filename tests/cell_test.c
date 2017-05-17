#include "testunit.h"
#include "../cell.h"

int SIZE_X = 5;
int SIZE_Y = 5;

void initialize_cells(cell *cells);

typedef struct t_coordinate {
	int x;
	int y;
}Coordinate;

typedef struct t_cases {
	char Description[40];
	cell *cells;
	Coordinate Position;
	bool Expected;
}Cases;


void TestIsAlive() {
	cell *tcells; 
	tcells = (cell *)malloc(LIMIT_CELLS*sizeof(cell));
	initialize_cells(tcells);
	SIZE_Y = SIZE_X = 5;

	//alive test
	tcells[0][1] = ALIVE;
	tcells[2][3] = ALIVE;
	tcells[4][4] = ALIVE;
	tcells[3][1] = ALIVE;

	Cases cases[3] = {
		{
		  .Description = "When try verify a cell alive",	
		  .cells = tcells,
		  .Position = {.x= 0, .y=1},
		  .Expected = true
		},
		{
		  .Description = "When try verify a cell dead",	
		  .cells = tcells,
		  .Position = {.x= 0, .y=0},
		  .Expected = DEAD
		},
	}; 

	int i;

	for(i =0; i < 2; i += 1) {
		Cases cs = cases[i];
		printf("%s\n",cs.Description);
		bool result = isAlive(cs.cells, cs.Position.x, cs.Position.y);
		if(result != cs.Expected) {
		   FAIL("	Unexpected result %d, expected %d\n", result, cs.Expected);
		} else {
		   SUCESS("	PASS\n");
		}
	}
} 

void initialize_cells(cell *cells) {
	int x = 0;
	int y = 0;

	for(x = 0; x <  SIZE_X; x+=1) {
		cells[x] = (cell)malloc(LIMIT_CELLS*sizeof(int));
		for(y = 0; y <  SIZE_Y; y+=1) { 
			cells[x][y] = 0;	
		}
	}
}


