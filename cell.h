#include "utils.h"

//Cell functions
typedef enum {
	NORTH  =  1,
	SOUTH  =  2,
	EAST   =  3,
	WEST   =  4
} direction;

typedef struct cell cell; 
struct cell {
	int life;
	cell *top;
	cell *bottom;
	cell *left;
	cell *right;
}; 

//FUNCTIONS
bool isStayAlive(cell c);
bool isAlive(cell c); 
bool canRise(cell c);
int getNeighbors(cell c);
void Next(cell c, cell *next, direction dir);
void rise(cell *c);

