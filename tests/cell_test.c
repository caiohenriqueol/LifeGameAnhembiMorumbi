#include "testunit.h"
#include "../cell.h"

#define LIMIT_CELLS 5
typedef struct t_coordinate {
	int x;
	int y;
}Coordinate;

typedef struct t_cases {
	char Description[100];
	cell *cells;
	Coordinate Position;
	bool Expected;
}Cases;

typedef struct t_cases_neighbors {
	char Description[100];
	cell *cells;
	Coordinate Position;
	int Amount;
}CasesNeighbors;

void TestIsStayAlive() {
	cell *tcells; 
	tcells = (cell *)malloc(LIMIT_CELLS*sizeof(cell));
	initialize_cells(tcells, 5, 5);

	//that can be alive test (0,1)
	tcells[0][1] = ALIVE;
	tcells[1][1] = ALIVE;
	tcells[0][2] = ALIVE;

	//that can't be alive
	tcells[2][3] = ALIVE;
	tcells[4][4] = ALIVE;
	tcells[3][1] = ALIVE;

	Cases cases[3] = {
		{
		  .Description = "When try verify a cell that can be stay alive",	
		  .cells = tcells,
		  .Position = {.y= 0, .x=1},
		  .Expected = true
		},
		{
		  .Description = "When try verify a cell that can't be stay alive",	
		  .cells = tcells,
		  .Position = {.y= 3, .x=1},
		  .Expected = false 
		},
		{
		  .Description = "When try verify a cell dead can stay alive",	
		  .cells = tcells,
		  .Position = {.y= 0, .x=0},
		  .Expected = false 
		},
	}; 

	int i;
	for(i =0; i < 3; i += 1) {
		Cases cs = cases[i];
		printf("%s\n",cs.Description);
		bool result = isStayAlive(cs.cells, cs.Position.x, cs.Position.y);
		if(result != cs.Expected) {
		   FAIL("	Unexpected result %d, expected %d\n", result, cs.Expected);
		} else {
		   SUCESS("	PASS\n");
		}
	}
}

void TestGetNeighbors() {
	cell *tcells; 
	tcells = (cell *)malloc(LIMIT_CELLS*sizeof(cell));
	initialize_cells(tcells, 10, 10);

	//that can be alive test (0,1)
	tcells[0][1] = ALIVE; //has 2 neighbors
	tcells[1][1] = ALIVE;
	tcells[0][2] = ALIVE;

	//that can't be alive
	tcells[2][3] = ALIVE;
	tcells[4][4] = ALIVE;
	tcells[3][1] = ALIVE;

	CasesNeighbors cases[3] = {
		{
		  .Description = "When have a two neighbors",	
		  .cells = tcells,
		  .Position = {.x= 1, .y=0},
		  .Amount = 2 
		},
		{
		  .Description = "When have a no one neighbors",	
		  .cells = tcells,
		  .Position = {.x= 1, .y=3},
		  .Amount = 0 
		},
	}; 

	int i;
	for(i =0; i < 2; i += 1) {
		CasesNeighbors cs = cases[i];
		printf("%s\n",cs.Description);
		int result = getNeighbors(cs.cells, cs.Position.x, cs.Position.y);
		if(result != cs.Amount) {
		   FAIL("	Unexpected amount of neighbors %d, expected %d\n", result, cs.Amount);
		} else {
		   SUCESS("	PASS\n");
		}
	}
}

void TestIsAlive() {
	cell *tcells; 
	tcells = (cell *)malloc(LIMIT_CELLS*sizeof(cell));
	initialize_cells(tcells, 5,5);

	//alive test
	tcells[0][1] = ALIVE;
	tcells[2][3] = ALIVE;
	tcells[4][4] = ALIVE;
	tcells[3][1] = ALIVE;

	Cases cases[3] = {
		{
		  .Description = "When try verify a cell alive",	
		  .cells = tcells,
		  .Position = {.y= 0, .x=1},
		  .Expected = true
		},
		{
		  .Description = "When try verify a cell dead",	
		  .cells = tcells,
		  .Position = {.y= 0, .x=0},
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

