#include "Tile.hpp"

// Constructors - Destructor

Tile::Tile()
{
	std::cout << "[ Called def. constr. for a TILE instance ]\n";
	//this->c = Coords( 0, 0 );
}
Tile::Tile( int X, int Y )
{
	(void)X;
	(void)Y;

	std::cout << "[ Called param. constr. for a TILE instance ]\n";
	//this->c = Coords( X, Y );
}
Tile::Tile( const Coords _c )
{
	std::cout << "[ Called param. constr. for a TILE instance ]\n";
	this->c = _c;
}
Tile::Tile( const Coords _c, int _t )
{
	std::cout << "[ Called param. constr. for a TILE instance ]\n";
	this->c = _c;
	this->t = _t;
}
Tile::Tile( const Tile &other )
{
	std::cout << "[ Called copy constr. for a TILE instance ]\n";
	this->c = other.getCoords();
}
Tile::~Tile() { std::cout << "[ Destroying a TILE instance ]\n"; }

// Operators

Tile &Tile::operator= ( const Tile &other )
{
	std::cout << "[ Called assign. op. for a TILE instance ]\n";
	this->c = other.getCoords();

	return *this;
}

// Checkers

void	Tile::checkCoords( const Coords _c ) const
{
	(void)_c;

	//if ( _c.checkPos() )
		//throw BadCoords();
}
void	Tile::checkType( const int _t ) const
{
	(void)_t;

	//if ( _t < 0 || _t > 3 )
		//throw BadType();
}

void	Tile::matchTile( const Tile &other ) const
{
	(void)other;

	//return ( this == &other)
}
void	Tile::matchCoords( const Coords _c ) const
{
	(void)_c;

	//return ( c_.x == this->c.x && c_.y == this->c.y )
}

// Setters - Getters

const Coords	Tile::getCoords( void ) const
{
	return ( this->c );
}

void	Tile::setFFF( void )		{ this->fff = true; }
void	Tile::resetFFF( void )		{ this->fff = false; }
bool	Tile::getFFF( void ) const	{ return ( this->fff ); }

// Others

void	Tile::printTile( void )
{
	//std::cout << this->getCoords();
}

std::ostream &operator<< (std::ostream &out, const Tile &rhs)
{
	(void)rhs;

	//out << rhs.getCoords();
	return ( out );
}
