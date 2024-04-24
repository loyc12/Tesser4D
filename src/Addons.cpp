# include "Addons.hpp"

// Screen addons
uint32_t	convColour( const t_colour &colour ) { return ( convColour( colour.r, colour.g, colour.b, colour.a )); }
uint32_t	convColour( byte r, byte g, byte b, byte a )
{
	uint32_t	conv = 0;

	conv |= r;
	conv <<= 8;
	conv |= g;
	conv <<= 8;
	conv |= b;
	conv <<= 8;
	conv |= a;

	return ( conv );
}
t_colour	makeColour( byte r, byte g, byte b ) { return ( makeColour( r, g, b, 0xFF )); }
t_colour	makeColour( byte r, byte g, byte b, byte a )
{
	t_colour	colour;

	colour.r = r;
	colour.g = g;
	colour.b = b;
	colour.a = a;

	return ( colour );
}


// Game addons
# include "Game.hpp"


