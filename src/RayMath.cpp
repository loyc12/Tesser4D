#include "Ray.hpp"

// Math functions
void	Ray::normalize( void )
{
	double mag = this->direction.getLength();

	if ( mag == 0 )
		throw Ray::BadNorm();
	this->direction.setX( this->direction.getX() / mag );
	this->direction.setY( this->direction.getY() / mag );
	this->direction.setZ( this->direction.getZ() / mag );
}

// Finders
double	Ray::findFirstVals( void )
{
	return 0;
}
double	Ray::findStepVals( void )
{
	return 0;
}

// Raycasting functions
void	Ray::findNextHit( void ) { this->findNextHit( 0 ); }
void	Ray::findNextHit( int type )
{
	(void)type;
}
Tile	*Ray::findHitTile( void )
{
	return ( nullptr );
}
