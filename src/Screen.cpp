#include "Screen.hpp"

// Destructor
Screen::~Screen() { DEBUG( std::cout << "[ Destroying a SCREEN instance ]\n" ); }

// Constructors
Screen::Screen()
{
	DEBUG( std::cout << "[ Called def. constr. for a SCREEN instance ]\n" );
	this->width = 0;  this->height = 0;
}
Screen::Screen( int _width, int _height )
{
	DEBUG( std::cout << "[ Called param. constr. for a SCREEN instance ]\n" );
	this->width = _width;  this->height = _height;
}

// Reconstructors
Screen::Screen( const Screen &other )
{
	DEBUG( std::cout << "[ Called copy constr. for a SCREEN instance ]\n" );
	this->width = other.getWidth();  this->height = other.getHeight();
}
Screen &Screen::operator= ( const Screen &other )
{
	DEBUG( std::cout << "[ Called assign. op. for a SCREEN instance ]\n" );
	this->width = other.getWidth();  this->height = other.getHeight();
	return *this;
}

// Clearers
void	Screen::clearWidth( void ) { this->width = 0; }
void	Screen::clearHeight( void ) { this->height = 0; }
void	Screen::clearDims( void ) { this->clearWidth();  this->clearHeight(); }

// Setters
void	Screen::setWidth( int _width ) { this->width = _width; }
void	Screen::setHeight( int _height ) { this->height = _height; }
void	Screen::setDims( int _width, int _height ) { this->setWidth( _width );  this->setHeight( _height ); }

// Getters
int		Screen::getWidth( void ) const { return ( this->width ); }
int		Screen::getHeight( void ) const { return ( this->height ); }

// Checkers
bool	Screen::checkScreen( void ) const { return ( this->checkDims() ); }
bool	Screen::checkDims( void ) const { return ( this->width > 0 && this->height > 0 ); }

// writters
void	Screen::writeScreen( std::ostream &out ) const { out << "[ " << this->width << " : " << this->height << " ]"; }
void	Screen::printScreen( void ) const { this->writeScreen( std::cout );  std::cout << std::endl; }
std::ostream &operator<<( std::ostream &out, const Screen &rhs ) { rhs.writeScreen( out );  return out; }