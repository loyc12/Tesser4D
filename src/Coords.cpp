#include "Coords.hpp"

// Constructors - Destructor

Coords::Coords()
{
	std::cout << "[ Called def. constr. for a COORDS instance ]\n";
	this->X = 0;
	this->Y = 0;
	this->Z = 0;
}
Coords::Coords( int X, int Y, int Z )
{
	std::cout << "[ Called param. constr. for a COORDS instance ]\n";
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}
Coords::Coords( const Coords &other )
{
	std::cout << "[ Called copy constr. for a COORDS instance ]\n";
	this->X = other.getX();
	this->Y = other.getY();
	this->Z = other.getZ();
}
Coords::~Coords() { std::cout << "[ Destroying a COORDS instance ]\n"; }

// Operators

Coords &Coords::operator= ( const Coords &other )
{
	std::cout << "[ Called assign. op. for a COORDS instance ]\n";
	this->X = other.getX();
	this->Y = other.getY();
	this->Z = other.getZ();

	return *this;
}

std::ostream &operator<< (std::ostream &out, const Coords &rhs)
{
	out << "X: " << rhs.getX() << " Y: " << rhs.getY() << " Z: " << rhs.getZ();
	return ( out );
}

// Setters - Getters

void	Coords::setX( int _X ) { this->X = _X; }
void	Coords::setY( int _Y ) { this->Y = _Y; }
void	Coords::setZ( int _Z ) { this->Z = _Z; }

int		Coords::getX( void ) const { return ( this->X ); }
int		Coords::getY( void ) const { return ( this->Y ); }
int		Coords::getZ( void ) const { return ( this->Z ); }

// Checkers

bool	Coords::checkPos() const
{
	return ( this->X >= 0 && this->Y >= 0 && this->Z >= 0 ); // NOTE: check world dimensions instead
}
bool	Coords::matchPos( const Coords &other ) const
{
	return ( this->X == other.getX() && this->Y == other.getY() && this->Z == other.getZ() );
}

// Others

void	Coords::printPos( void ) const
{
	std::cout << " X: " << this->X;
	std::cout << " Y: " << this->Y;
	std::cout << " Z: " << this->Z;
	std::cout << std::endl;
}
