#include "../cell.h"

int SIZE_X = 5;
int SIZE_Y = 5;

void initialize_cells(cell *cells);

typedef struct t_coordinate {
	int x;
	int y;
}Coordinate;

typedef struct t_cases {
	char Description[10];
	cell *cells;
	Coordinate Position;
	bool Expected;
}Cases;

int LIMIT_CELLS = 5;

void TestIsAlive() {
	cell *tcells; 

	tcells = (cell *)malloc(LIMIT_CELLS*sizeof(cell));
	initialize_cells(tcells);
	SIZE_Y = SIZE_X = 5;

	//alive test
	tcells[0][1] = ALIVE;

	Cases cases[5] = {
		{
		  .Description = "When Try",	
		  .cells = tcells,
		  .Position = {.x= 0, .y=1},
		  .Expected = true

		},
		{
		  .Description = "When Try",	
		  .cells = tcells,
		  .Position = {.x= 0, .y=1},
		  .Expected = true

		},
		{
		  .Description = "When Try",	
		  .cells = tcells,
		  .Position = {.x= 0, .y=1},
		  .Expected = true

		},
		{
		  .Description = "When Try",	
		  .cells = tcells,
		  .Position = {.x= 0, .y=1},
		  .Expected = true

		}
	}; 

	int i;

	for(i =0; i < 5; i += 1) {
		Cases cs = cases[i];
		bool result = isAlive(cs.cells, cs.Position.x, cs.Position.y);
		if(result != cs.Expected) {
		   printf("Unexpected result %d, expected %d",result,cs.Expected);
		}
	}
} 

void initialize_cells(cell *cells) {
	int x = 0;
	int y = 0;
	cells = (cell *)malloc(LIMIT_CELLS*sizeof(cell));

	for(x = 0; x <  SIZE_X; x+=1) {
		cells[x] = (cell)malloc(LIMIT_CELLS*sizeof(int));
		for(y = 0; y <  SIZE_Y; y+=1) { 
			cells[x][y] = 0;	
		}
	}
}

