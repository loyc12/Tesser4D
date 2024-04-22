#ifndef RAY_HPP
# define RAY_HPP

# include "Default_Libs.hpp"

# include "Coords.hpp"
# include "Position.hpp"

class Ray
{
	private:
		// Attributes
		Position	origin;
		Position	direction;

	protected:
		// Nested Classes
		class BadInit : XCPT( "Ray error : failed to initialise"; );

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
		void	clearOrigin( void );
		void	clearDirection( void );
		void	clearRay( void );

		// Setters
		void	setOrigin( const Position _origin );
		void	setDirection( const Position _direction );
		void	setRay( const Position _origin, const Position _direction );

		// Getters
		Position	getOrigin( void ) const;
		Position	getDirection( void ) const;

		// Fetchers
		Position	&fetchOrigin( void );
		Position	&fetchDirection( void );

		// Checkers
		bool	checkRay( void ) const;

		// writters
		void	writeRay( std::ostream &out ) const;
		void	printRay( void ) const;

		friend std::ostream &operator<<( std::ostream &out, const Ray &rhs );

};


#endif // RAY_HPP