#ifndef RAY_HPP
# define RAY_HPP

# include "DefLibs.hpp"

# include "Tile.hpp"
# include "Position.hpp"

class Ray
{
	private:
		// Attributes
		Position	origin;		// cam position
		Position	direction;	// non-normalized is fine
		Position	hitpoint;	// currently found hitpoint

		Position	firstVals;	// iX, iY, iZ	// distances to next intersections ( int )
		Position	stepVals;	// dX, dY, dX	// lenghts of each steps
		Position	distVals;	// sX, sY, sZ	// current depth of their respective search

	protected:
		// Nested Classes
		class BadInit	: XCPT( "Ray error : failed to initialise"; );
		class BadNorm	: XCPT( "Ray error : failed to normalize ( magnitude can't be zero )"; );

		// Clearers
		void	clearOrigin( void );
		void	clearDirection( void );
		void	clearHitpoint( void );

		void	clearFirstVals( void );
		void	clearStepVals( void );
		void	clearDistVals( void );

		// Setters
		void	setHitpoint( const Position _hitpoint );

		void	setFirstVals( const Position _firstVals );
		void	setStepVals( const Position _stepVals );
		void	setDistVals( const Position _distVals );

		// Getters
		Position	getFirstVals( void ) const;
		Position	getStepVals( void ) const;
		Position	getDistVals( void ) const;

	public:
		// Destructor
		~Ray();

		// Constructors
		Ray();
		Ray( const Position _origin, const Position _direction );

		// Reconstructors
		Ray( const Ray &other );
		Ray &operator= ( const Ray &other );

		// Clearers
		void	clearRay( void );
		void	resetRay( void );

		// Setters
		void	setOrigin( const Position _origin );
		void	setDirection( const Position _direction );

		// Getters
		Position	getOrigin( void ) const;
		Position	getDirection( void ) const;
		Position	getHitpoint( void ) const;

		// Fetchers

		// Checkers
		bool	checkRay( void ) const;

		// Writers
		void	writeRay( std::ostream &out ) const;
		void	printRay( void ) const;

		friend std::ostream &operator<<( std::ostream &out, const Ray &rhs );

		// Finders
		double findFirstVals( void );
		double findStepVals( void );

		// Math functions
		void normalize( void );

		// Raycasting functions
		void findNextHit( void );
		void findNextHit( int type );
		Tile *findHitTile( void );

};

#endif // RAY_HPP