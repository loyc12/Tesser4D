#ifndef GAME_HPP
# define GAME_HPP

# include "DefLibs.hpp"

# include "Tile.hpp"
# include "Entity.hpp"
# include "Screen.hpp"

# define MAX_MAP_SIZE	( int )64

class Game
{
	private:
		// Attributes
		Entity	player;
		Screen	screen;
		Tile	tileMap[ MAX_MAP_SIZE ][ MAX_MAP_SIZE ][ MAX_MAP_SIZE ];

		bool	hasUpdated;
		bool	hasRendered;

	protected:
		// Nested Classes
		class BadInit	: XCPT( "Game error : failed to initialise"; );
		class BadPlayer	: XCPT( "Game error : invalid player data"; );
		class BadMap	: XCPT( "Game error : invalid map data"; );

	public:
		// Destructor
		~Game();

		// Constructors
		Game();
		Game( const Screen _screen );

		// Reconstructors
		Game( const Game &other );
		Game &operator= ( const Game &other );

		// Clearers
		void	clearGame( void );
		void	clearPlayer( void );
		void	clearScreen( void );

		void	clearMap( void );
		void 	clearTile( const Coords _C );
		void	clearTile( int X, int Y, int Z );

		// Setters
		void	setPlayer( const Entity _player );
		void	setScreen( const Screen _screen );

		void	setMap( Tile ***_map );
		void	setTile( const Coords _C, const Tile _tile );
		void	setTile( int X, int Y, int Z, const Tile _tile );

		void	setHasUpdated( bool _hasUpdated );
		void	setHasRendered( bool _hasRendered );

		// Getters
		Entity	getPlayer( void ) const;
		Screen	getScreen( void ) const;

		Tile	getTile( const Coords _C ) const;
		Tile	getTile( int X, int Y, int Z ) const;

		bool	getHasUpdated( void );
		bool	getHasRendered( void );

		// Fetchers
		Entity	&fetchPlayer( void );
		Screen	&fetchScreen( void );

		Tile	***fetchMap( void );
		Tile	&fetchTile( const Coords _C );
		Tile	&fetchTile( int X, int Y, int Z );

		// Checkers

		// writters
		void	writeGame( std::ostream &out ) const;
		void	writeMap( std::ostream &out ) const;

		void	printGame( void ) const;
		void	printMap( void ) const;

		friend std::ostream &operator<<( std::ostream &out, const Game &rhs );

		// Others
		void	initScreen( int width, int height);
		void	initMap( str mapFile );
		void	initPlayer( void );

		void	runGame( void );

		void	updateGame( void );
		void	renderGame( void );
		void	quitGame( void );
};

#endif // GAME_HPP