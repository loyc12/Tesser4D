#ifndef GAME_HPP
# define GAME_HPP

# include "Default_Libs.hpp"

# include "Tile.hpp"
# include "Entity.hpp"
# include "Screen.hpp"

class Game
{
	private:
		// Attributes
		Entity	player;
		Screen	screen;
		Tile	tileMap[ MAX_MAP_SIZE ][ MAX_MAP_SIZE ][ MAX_MAP_SIZE ];

	protected:
		// Nested Classes
		class BadInit	: XCPT( "Game error : failed to initialise"; );

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

		// Getters
		Entity	getPlayer( void ) const;
		Screen	getScreen( void ) const;

		Tile	getTile( const Coords _C ) const;
		Tile	getTile( int X, int Y, int Z ) const;

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

};

#endif // GAME_HPP