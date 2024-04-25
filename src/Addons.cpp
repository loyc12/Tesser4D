# include "Addons.hpp"


int	getSign( int val ) { return (( val > 0 ) - ( val < 0 )); }	// TODO : make template


// Screen addons
uint32_t	convColour( const t_colour &colour ) { return ( convColour( colour.r, colour.g, colour.b, colour.a )); }
uint32_t	convColour( byte r, byte g, byte b, byte a )
{
	uint32_t	conv = 0;

	conv |= r; conv <<= 8;
	conv |= g; conv <<= 8;
	conv |= b; conv <<= 8;
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

// Debug Addons

uint32_t getNextColour( void )
{
	static uint32_t	colour = C_BLACK;

	switch ( colour )
	{
		case C_RED:		colour = C_ORANGE;	break;
		case C_ORANGE:	colour = C_YELLOW;	break;
		case C_YELLOW:	colour = C_LIME;	break;
		case C_LIME:	colour = C_GREEN;	break;
		case C_GREEN:	colour = C_TEAL;	break;
		case C_TEAL:	colour = C_CYAN;	break;
		case C_CYAN:	colour = C_AZURE;	break;
		case C_AZURE:	colour = C_BLUE;	break;
		case C_BLUE:	colour = C_PURPLE;	break;
		case C_PURPLE:	colour = C_MAGENTA;	break;
		case C_MAGENTA:	colour = C_PINK;	break;
		case C_PINK:	colour = C_WHITE;	break;
		case C_WHITE:	colour = C_LGRAY;	break;
		case C_LGRAY:	colour = C_GRAY;	break;
		case C_GRAY:	colour = C_DGRAY;	break;
		case C_DGRAY:	colour = C_BLACK;	break;
		default:		colour = C_RED;		break;
	}
	return ( colour );
}


// Game addons
# include "Game.hpp"


