#include "T4D.hpp"

//# include <time.h>
//# include <math.h>

# define SCREEN_WIDTH	( int )1536
# define SCREEN_HEIGHT	( int )1152

int main( void )
{
	Game	g = Game();

	g.initScreen( SCREEN_WIDTH, SCREEN_HEIGHT );
	g.runGame();

}