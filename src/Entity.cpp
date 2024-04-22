# include "Entity.hpp"

// Destructor
Entity::~Entity() { DEBUG( std::cout << "[ Destroying an ENTITY instance ]\n" ); }

// Constructors
Entity::Entity()
{
	DEBUG( std::cout << "[ Called def. constr. for an ENTITY instance ]\n" );
	this->pos = Position( 0, 0, 0 );
	this->tile = Tile();
}
Entity::Entity( const Position _pos, const Tile _tile )
{
	DEBUG( std::cout << "[ Called param. constr. for an ENTITY instance ]\n" );
	this->pos = _pos;
	this->tile = _tile;
}

// Reconstructors
Entity::Entity( const Entity &other )
{
	DEBUG( std::cout << "[ Called copy constr. for an ENTITY instance ]\n" );
	this->pos = other.getPos();
	this->tile = other.getTile();
}
Entity &Entity::operator= ( const Entity &other )
{
	DEBUG( std::cout << "[ Called assign. op. for an ENTITY instance ]\n" );
	this->pos = other.getPos();
	this->tile = other.getTile();
	return *this;
}

// Clearers
void	Entity::clearPos( void ) { this->pos = Position(); }
void	Entity::clearTile( void ) { this->tile = Tile(); }

// Setters
void	Entity::setPos( const Position _pos ) { this->pos = _pos; }
void	Entity::setTile( const Tile _tile ) { this->tile = _tile; }

// Getters
Position	Entity::getPos( void ) const { return ( this->pos ); }
Tile		Entity::getTile( void ) const { return ( this->tile ); }

// Fetchers
Position	&Entity::fetchPos( void ) { return ( this->pos ); }
Tile		&Entity::fetchTile( void ) { return ( this->tile ); }

// Checkers
bool	Entity::checkEntity( void ) const { return ( this->pos.checkPos() && this->tile.checkTile() ); }

// writters
void	Entity::writeEntity( std::ostream &out ) const
{
	out << "[ ";
	this->pos.writePos( out );
	out << " | ";
	this->tile.writeTile( out );
	out << " ]";
}
