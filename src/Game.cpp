#include "Game.hpp"

// Destructor
Game::~Game() { DEBUG( std::cout << "[ Destroying a GAME instance ]\n" ); }

// Constructors
Game::Game()
{
	DEBUG( std::cout << "[ Called def. constr. for a GAME instance ]\n" );
	this->player = Entity();
	this->screen = Screen();
	this->clearMap();
}
Game::Game( const Screen _screen )
{
	DEBUG( std::cout << "[ Called param. constr. for a GAME instance ]\n" );
	this->player = Entity();
	this->screen = _screen;
	this->clearMap();
}

// Reconstructors
Game::Game( const Game &other )
{
	DEBUG( std::cout << "[ Called copy constr. for a GAME instance ]\n" );
	this->player = other.getPlayer();
	this->screen = other.getScreen();
	this->clearMap();
}
Game &Game::operator= ( const Game &other )
{
	DEBUG( std::cout << "[ Called assign. op. for a GAME instance ]\n" );
	this->player = other.getPlayer();
	this->screen = other.getScreen();
	this->clearMap();
	return *this;
}

// Clearers
void	Game::clearGame( void )
{
	this->clearPlayer();
	this->clearScreen();
	this->clearMap();
}
void	Game::clearPlayer( void ) { this->player = Entity(); }
void	Game::clearScreen( void ) { this->screen = Screen(); }
void	Game::clearMap( void )
{
	for ( int i = 0; i < MAX_MAP_SIZE; i++ )
		for ( int j = 0; j < MAX_MAP_SIZE; j++ )
			for ( int k = 0; k < MAX_MAP_SIZE; k++ )
				this->tileMap[ i ][ j ][ k ] = Tile();
}
void	Game::clearTile( const Coords _C ) { this->clearTile( _C.getX(), _C.getY(), _C.getZ() ); }
void	Game::clearTile( int X, int Y, int Z ) { this->tileMap[ X ][ Y ][ Z ] = Tile(); }

// Setters
void	Game::setPlayer( const Entity _player ) { this->player = _player; }
void	Game::setScreen( const Screen _screen ) { this->screen = _screen; }

void	Game::setMap( Tile ***_map )
{
	for ( int i = 0; i < MAX_MAP_SIZE; i++ )
		for ( int j = 0; j < MAX_MAP_SIZE; j++ )
			for ( int k = 0; k < MAX_MAP_SIZE; k++ )
				this->tileMap[ i ][ j ][ k ] = _map[ i ][ j ][ k ];
}
void	Game::setTile( const Coords _C, const Tile _tile ) { this->setTile( _C.getX(), _C.getY(), _C.getZ(), _tile ); }
void	Game::setTile( int X, int Y, int Z, const Tile _tile ) { this->tileMap[ X ][ Y ][ Z ] = _tile; }

// Getters
Entity	Game::getPlayer( void ) const { return this->player; }
Screen	Game::getScreen( void ) const { return this->screen; }

Tile	Game::getTile( const Coords _C ) const { return this->getTile( _C.getX(), _C.getY(), _C.getZ() ); }
Tile	Game::getTile( int X, int Y, int Z ) const { return this->tileMap[ X ][ Y ][ Z ]; }

// Fetchers
Entity	&Game::fetchPlayer( void ) { return this->player; }
Screen	&Game::fetchScreen( void ) { return this->screen; }

Tile***	Game::fetchMap( void ) { return ( Tile*** )this->tileMap; }
Tile	&Game::fetchTile( const Coords _C ) { return this->fetchTile( _C.getX(), _C.getY(), _C.getZ() ); }
Tile	&Game::fetchTile( int X, int Y, int Z ) { return this->tileMap[ X ][ Y ][ Z ]; }

// Checkers

// writters
void	Game::writeGame( std::ostream &out ) const
{
	out << "[ ";
	this->player.writeEntity( out );
	out << " | ";
	this->screen.writeScreen( out );
	out << " ]";
}
void	Game::writeMap( std::ostream &out ) const
{
	for ( int i = 0; i < MAX_MAP_SIZE; i++ )
	{
		for ( int j = 0; j < MAX_MAP_SIZE; j++ )
		{
			for ( int k = 0; k < MAX_MAP_SIZE; k++ )
			{
				this->tileMap[ i ][ j ][ k ].writeTile( out );
				out << " ";
			}
			out << std::endl;
		}
		out << std::endl;
	}
}

void	Game::printGame( void ) const { this->writeGame( std::cout ); }
void    Game::printMap( void ) const { this->writeMap( std::cout ); }

std::ostream &operator<<( std::ostream &out, const Game &rhs ) { rhs.writeGame( out );  return out; }




