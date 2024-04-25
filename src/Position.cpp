#include "Position.hpp"

// Destructor
Position::~Position() {} //{ DEBUG( std::cout << "[ Destroying a POSITION instance ]\n" ); }

// Constructors
Position::Position()
{
	//DEBUG( std::cout << "[ Called def. constr. for a POSITION instance ]\n" );
	this->x = 0;  this->y = 0;  this->z = 0;
}
Position::Position( double x, double y, double z )
{
	//DEBUG( std::cout << "[ Called param. constr. for a POSITION instance ]\n" );
	this->x = x;  this->y = y;  this->z = z;
}
Position::Position( const Coords C )
{
	//DEBUG( std::cout << "[ Called param. constr. for a POSITION instance ]\n" );
	this->x = C.getX();  this->y = C.getY();  this->z = C.getZ();
}

// Reconstructors
Position::Position( const Position &other )
{
	//DEBUG( std::cout << "[ Called copy constr. for a POSITION instance ]\n" );
	this->x = other.getX();  this->y = other.getY();  this->z = other.getZ();
}
Position &Position::operator= ( const Position &other )
{
	//DEBUG( std::cout << "[ Called assign. op. for a POSITION instance ]\n" );
	this->x = other.getX();  this->y = other.getY();  this->z = other.getZ();
	return *this;
}

// Setters
void	Position::setX( double _x ) { this->x = _x; }
void	Position::setY( double _y ) { this->y = _y; }
void	Position::setZ( double _z ) { this->z = _z; }

// Getters
double	Position::getX( void ) const { return ( this->x ); }
double	Position::getY( void ) const { return ( this->y ); }
double	Position::getZ( void ) const { return ( this->z ); }

// Clearers
void	Position::clearX( void ) { this->x = 0; }
void	Position::clearY( void ) { this->y = 0; }
void	Position::clearZ( void ) { this->z = 0; }
void	Position::clearPos( void ) { this->clearX();  this->clearY();  this->clearZ(); }

// Fetchers

// Checkers
bool	Position::checkPos() const { return ( this->x >= 0 && this->y >= 0 && this->z >= 0 ); } // TODO : check with world dimensions instead
bool	Position::matchPos( const Position &other ) const { return ( this->x == other.getX() && this->y == other.getY() && this->z == other.getZ() ); }

// Writers
void	Position::writePos( std::ostream &out ) const { out << "[ " << this->x << " : " << this->y << " : " << this->z << " ]"; }
void	Position::printPos( void ) const { this->writePos( std::cout );  std::cout << std::endl; }
std::ostream &operator<<( std::ostream &out, const Position &rhs ) { rhs.writePos( out );  return out; }
