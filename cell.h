#include "utils.h"

//Cell functions
typedef enum e_direction {
	NORTH  =  1,
	SOUTH  =  2,
	EAST   =  3,
	WEST   =  4
} direction;

/** 
 * Alias to pointer of int, used to turn de code more verbose
 */
typedef int *cell

//FUNCTIONS

/** 
 * Verify if cell can stay alive in this generation  
 * 
 * @param cells its a typedef of pointer int 
 * @param position  its index of array you can check
 * @return  true to if cell can stay alive, and false if can't stay
  */
bool isStayAlive(cell cells, int position);

/** 
 * Verify if cell is current alive  
 *
 * @param cells its a typedef of pointer int 
 * @param position  its index of array you can check
 * @return  true to if current alive, and false if can't 
  */
bool isAlive(cell c, int position); 

/** 
 * Verify if cell can turn to alive in next generation  
 *
 * @param cells its a typedef of pointer int 
 * @param position  its index of array you can check
 * @return  true to if cell can turn to be alive and false if can't 
  */
bool canRise(cell c,int position );


/** 
 * Verify if cell can turn to alive in next generation  
 *
 * @param cells its a typedef of pointer int 
 * @param position  its index of array you can check
 * @return amout of neighbors to this cell
  */
int getNeighbors(cell c);

/** 
 * Kill all cell in this array 
 *
 * @param cells its a typedef of pointer int 
  */
void kill(cell *c, int size);

/** 
 * Turn to alive all cell in this array 
 *
 * @param cells its a typedef of pointer int 
  */
void rise(cell *c, int size);
