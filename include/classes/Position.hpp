#ifndef POSITION_HPP
# define POSITION_HPP

# include "DefLibs.hpp"

class Coords;
# include "Coords.hpp"

class Position
{
	private:
		// Attributes
		double	x;
		double	y;
		double	z;

	protected:
		// Nested Classes
		class BadInit : XCPT( "Position error : failed to initialise"; );

	public:
		// Destructor
		~Position();

		// Constructors
		Position();
		Position( double _x, double _y, double _z );
		Position( const Coords _C );

		// Reconstructors
		Position( const Position &other );
		Position &operator= ( const Position &other );

		// Clearers
		void	clearX( void );
		void	clearY( void );
		void	clearZ( void );
		void 	clearPos( void );

		// Setters
		void	setX( double _x );
		void	setY( double _y );
		void	setZ( double _z );
		void	setPos( double _x, double _y, double _z );

		// Getters
		double	getX( void ) const;
		double	getY( void ) const;
		double	getZ( void ) const;

		// Fetchers

		// Checkers
		bool	checkPos( void ) const;
		bool	matchPos( const Position &other ) const;

		// writters
		void	writePos( std::ostream &out ) const;
		void	printPos( void ) const;

		friend	std::ostream &operator<<( std::ostream &out, const Position &rhs );

};

#endif // POSITION_HPP