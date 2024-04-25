#include "Coords.hpp"

// Destructor
Coords::~Coords() {} //{ DEBUG( std::cout << "[ Destroying a COORDS instance ]\n" ); }

// Constructors
Coords::Coords()
{
	//DEBUG( std::cout << "[ Called def. constr. for a COORDS instance ]\n" );
	this->X = 0;  this->Y = 0;  this->Z = 0;
}
Coords::Coords( int X, int Y, int Z )
{
	//DEBUG( std::cout << "[ Called param. constr. for a COORDS instance ]\n" );
	this->X = X;  this->Y = Y;  this->Z = Z;
}
Coords::Coords( const Position P )
{
	//DEBUG( std::cout << "[ Called param. constr. for a COORDS instance ]\n" );
	this->X = P.getX();  this->Y = P.getY();  this->Z = P.getZ();
}

// Reconstructors
Coords::Coords( const Coords &other )
{
	//DEBUG( std::cout << "[ Called copy constr. for a COORDS instance ]\n" );
	this->X = other.getX();  this->Y = other.getY();  this->Z = other.getZ();
}
Coords &Coords::operator= ( const Coords &other )
{
	//DEBUG( std::cout << "[ Called assign. op. for a COORDS instance ]\n" );
	this->X = other.getX();  this->Y = other.getY();  this->Z = other.getZ();
	return *this;
}

// Setters
void	Coords::setX( int _X ) { this->X = _X; }
void	Coords::setY( int _Y ) { this->Y = _Y; }
void	Coords::setZ( int _Z ) { this->Z = _Z; }

// Getters
int		Coords::getX( void ) const { return ( this->X ); }
int		Coords::getY( void ) const { return ( this->Y ); }
int		Coords::getZ( void ) const { return ( this->Z ); }

// Clearers
void	Coords::clearX( void ) { this->X = 0; }
void	Coords::clearY( void ) { this->Y = 0; }
void	Coords::clearZ( void ) { this->Z = 0; }
void	Coords::clearCoords( void ) { this->clearX();  this->clearY();  this->clearZ(); }

// Fetchers

// Checkers
bool	Coords::checkCoords() const { return ( this->X >= 0 && this->Y >= 0 && this->Z >= 0 ); } // TODO : check with world dimensions instead
bool	Coords::matchCoords( const Coords &other ) const { return ( this->X == other.getX() && this->Y == other.getY() && this->Z == other.getZ() ); }

// Writers
void	Coords::writeCoords( std::ostream &out ) const { out << "[ " << this->X << " : " << this->Y << " : " << this->Z << " ]"; }
void	Coords::printCoords( void ) const { this->writeCoords( std::cout );  std::cout << std::endl; }
std::ostream &operator<<( std::ostream &out, const Coords &rhs ) { rhs.writeCoords( out );  return out; }