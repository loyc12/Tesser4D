// Creator: Loyc12

#ifndef DEFS_H
# define DEFS_H

# define DEBUG_MODE true


// ======== SHORTCUTS ======== //

// Redefs
# define elif	else if
# define byte	unsigned char
# define str	std::string
# define cstr	const char *

// Snipets
# define DEBUG( x )	if ( DEBUG_MODE ) { x; }
# define XCPT( x )	public std::exception { public: virtual const char *what() const throw() { return x; }}

# define RELEASED( keydata, match )	( keydata.key == match && keydata.action == MLX_RELEASE )
# define PRESSED( keydata, match )	( keydata.key == match && keydata.action == MLX_PRESS )
# define HELD( keydata, match )		( keydata.key == match && keydata.action == MLX_REPEAT )

// ======== CONSTANTS ======== //


// ======== STRUCTS ======== //

typedef struct s_colour
{
	byte	r;
	byte	g;
	byte	b;
	byte	a;
}			t_colour;

// ======== ENUMS ======== //	t_gstate;

//direction ID (
typedef enum e_did
{
	DID_NONE	= -1,
	DID_FRONT	= 0,
	DID_RIGHT	= 1,
	DID_TOP		= 2,
	DID_BACK	= 3,
	DID_LEFT	= 4,
	DID_BOTTOM	= 5,
	DID_COUNT		= 5
}				t_tid;

//tile type (how should we interact/display this tile)
typedef enum e_ttype
{
	TTYPE_ERROR	= -1,
	TTYPE_VOID	= 0,
	TTYPE_FULL	= 1,
	TTYPE_COUNT	= 1
}				t_ttype;
#endif // DEFS_H


/*

// ======== CONSTANTS ======== //

// SPEED REF (1 tile ~= 3m)
# define WALK_SPEED		( double )0.05
# define TURN_SPEED		( double )1.5
# define RUN_FACTOR		( double )2.5

// SIZE
# define MAX_CHAR_COUNT	( int )8192 //		lvl file size
# define MAX_MAP_SIZE	( int )64 //		map size (in tiles)
# define PLAYER_RADIUS	( double )0.2
# define ASSET_COUNT	( int )4 //			asset count

// VIEW
//# define COLOUR_DEF	( int)1 //			(1 to 32) slows rendering by ~10%
# define PLAYER_FOV		( double )70 //		(10 to 100)	field of view
# define SHADE_DISTANCE	( double )32 //		(0 to 100)	wall shading distance (inverse strenght)
# define SHADE_FACTOR	( double )0.66 //	(0 to 1)	floor/ceiling shading strenght
# define INV_SHADE_C	( int )1 //			(0 or 1)	(inverted ceiling shading creates a better sky effect)
# define INV_SHADE_F	( int )0 //			(0 or 1)

*/