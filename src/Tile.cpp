#include "Tile.hpp"

// Constructors - Destructor

Tile::Tile()
{
	std::cout << "[ Called def. constr. for a TILE instance ]\n";
	this->C = Coords( 0, 0, 0 );
	this->T = 0;
	this->fff = false;
}
Tile::Tile( int _T )
{
	std::cout << "[ Called param. constr. for a TILE instance ]\n";
	this->C = Coords( 0, 0, 0 );
	this->T = _T;
	this->fff = false;
}
Tile::Tile( int X, int Y, int Z )
{
	std::cout << "[ Called param. constr. for a TILE instance ]\n";
	this->C = Coords( X, Y, Z );
	this->T = 0;
	this->fff = false;
}
Tile::Tile( int X, int Y, int Z, int _T)
{
	std::cout << "[ Called param. constr. for a TILE instance ]\n";
	this->C = Coords( X, Y, Z );
	this->T = _T;
	this->fff = false;
}
Tile::Tile( const Coords _C )
{
	std::cout << "[ Called param. constr. for a TILE instance ]\n";
	this->C = _C;
	this->T = 0;
	this->fff = false;
}
Tile::Tile( const Coords _C, int _T )
{
	std::cout << "[ Called param. constr. for a TILE instance ]\n";
	this->C = _C;
	this->T = _T;
	this->fff = false;
}
Tile::Tile( const Tile &other )
{
	std::cout << "[ Called copy constr. for a TILE instance ]\n";
	this->C = other.getCoords();
	this->T = other.getType();
}
Tile::~Tile() { std::cout << "[ Destroying a TILE instance ]\n"; }

// Operators

Tile &Tile::operator= ( const Tile &other )
{
	std::cout << "[ Called assign. op. for a TILE instance ]\n";
	this->C = other.getCoords();
	this->T = other.getType();

	return *this;
}

std::ostream &operator<< (std::ostream &out, const Tile &rhs)
{
	out << rhs.getCoords();
	return ( out );
}

// Checkers

void	Tile::checkCoords( const Coords _C ) const
{
	if ( _C.checkPos() )
		throw BadCoords();
}
void	Tile::checkType( const int _T ) const
{
	if ( _T < 0 || _T > 3 )
		throw BadType();
}

bool	Tile::matchTile( const Tile &other ) const
{
	return ( this->C.matchPos( other.getCoords() ) && this->T == other.getType() );
}
bool	Tile::matchCoords( const Coords _C ) const
{
	return ( this->C.matchPos( _C ));
}

// Setters - Getters

const Coords	Tile::getCoords( void ) const { return ( this->C ); }
int				Tile::getType( void ) const { return ( this->T ); }

void	Tile::setCoords( const Coords _C )
{
	this->checkCoords( _C );
	this->C = _C;
}
void	Tile::setType( const int _T )
{
	this->checkType( _T );
	this->T = _T;
}

void	Tile::setFFF( void )		{ this->fff = true; }
void	Tile::resetFFF( void )		{ this->fff = false; }
bool	Tile::getFFF( void ) const	{ return ( this->fff ); }



// Others

void	Tile::printTile( void ) { std::cout << this->getCoords(); }
