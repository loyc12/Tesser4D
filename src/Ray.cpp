#include "Ray.hpp"

// Destructor
Ray::~Ray() {}

// Constructors
Ray::Ray() { this->clearRay(); }
Ray::Ray( const Position _origin, const Position _direction )
{
	this->clearRay();
	this->setOrigin( _origin );
	this->setDirection( _direction );
}

// Reconstructors
Ray::Ray( const Ray &other )
{
	this->clearRay();
	this->setOrigin( other.getOrigin() );
	this->setDirection( other.getDirection() );
	this->setHitpoint( other.getHitpoint() );
	this->setFirstVals( other.getFirstVals() );
	this->setStepVals( other.getStepVals() );
	this->setDistVals( other.getDistVals() );
}
Ray &Ray::operator= ( const Ray &other )
{
	this->clearRay();
	this->setOrigin( other.getOrigin() );
	this->setDirection( other.getDirection() );
	this->setHitpoint( other.getHitpoint() );
	this->setFirstVals( other.getFirstVals() );
	this->setStepVals( other.getStepVals() );
	this->setDistVals( other.getDistVals() );
	return ( *this );
}

// Clearers
void	Ray::clearOrigin( void ) { this->origin.clearPos(); }
void	Ray::clearDirection( void ) { this->direction.clearPos(); }
void	Ray::clearHitpoint( void ) { this->hitpoint.clearPos(); }

void	Ray::clearFirstVals( void ) { this->firstVals.clearPos(); }
void	Ray::clearStepVals( void ) { this->stepVals.clearPos(); }
void	Ray::clearDistVals( void ) { this->distVals.clearPos(); }

void	Ray::clearRay( void )
{
	this->clearOrigin();
	this->clearDirection();
	this->clearHitpoint();
	this->clearFirstVals();
	this->clearStepVals();
	this->clearDistVals();
}
void	Ray::resetRay( void )
{
	this->clearHitpoint();
	this->clearFirstVals();
	this->clearStepVals();
	this->clearDistVals();
}

// Setters
void	Ray::setOrigin( const Position _origin ) { this->origin = _origin; }
void	Ray::setDirection( const Position _direction ) { this->direction = _direction; }
void	Ray::setHitpoint( const Position _hitpoint ) { this->hitpoint = _hitpoint; }

void	Ray::setFirstVals( const Position _firstVals ) { this->firstVals = _firstVals; }
void	Ray::setStepVals( const Position _stepVals ) { this->stepVals = _stepVals; }
void	Ray::setDistVals( const Position _distVals ) { this->distVals = _distVals; }

// Getters
Position	Ray::getOrigin( void ) const { return ( this->origin ); }
Position	Ray::getDirection( void ) const { return ( this->direction ); }
Position	Ray::getHitpoint( void ) const { return ( this->hitpoint ); }

Position	Ray::getFirstVals( void ) const { return ( this->firstVals ); }
Position	Ray::getStepVals( void ) const { return ( this->stepVals ); }
Position	Ray::getDistVals( void ) const { return ( this->distVals ); }

// Fetchers

// Checkers
bool	Ray::checkRay( void ) const { return ( this->origin.checkPos() && this->direction.checkPos() ); }

// Writers
void	Ray::writeRay( std::ostream &out ) const
{
	out << "[ ";
	this->origin.writePos( out );
	out << " | ";
	this->direction.writePos( out );
	out << " | ";
	this->hitpoint.writePos( out );
	out << " | ";
	this->firstVals.writePos( out );
	out << " | ";
	this->stepVals.writePos( out );
	out << " | ";
	this->distVals.writePos( out );
	out << " ]";
}
void	Ray::printRay( void ) const
{
	std::cout << "[ ";
	this->origin.printPos();
	std::cout << " | ";
	this->direction.printPos();
	std::cout << " | ";
	this->hitpoint.printPos();
	std::cout << " | ";
	this->firstVals.printPos();
	std::cout << " | ";
	this->stepVals.printPos();
	std::cout << " | ";
	this->distVals.printPos();
	std::cout << " ]";
}

std::ostream &operator<<( std::ostream &out, const Ray &rhs )
{
	rhs.writeRay( out );
	return ( out );
}

