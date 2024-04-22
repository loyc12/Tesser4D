#ifndef COORDS_HPP
# define COORDS_HPP

# include "Default_Libs.hpp"

class Position;
# include "Position.hpp"

class Coords
{
	private:
		// Attributes
		int	X;
		int	Y;
		int	Z;

	protected:
		// Nested Classes
		class BadInit : XCPT( "Coords error : failed to initialise"; );

	public:
		// Destructor
		~Coords();

		// Constructors
		Coords();
		Coords( int _X, int _Y, int _Z );
		Coords( const Position _P );

		// Reconstructors
		Coords( const Coords &other );
		Coords &operator= ( const Coords &other );

		// Clearers
		void	clearX( void );
		void	clearY( void );
		void	clearZ( void );
		void 	clearCoords( void );

		// Setters
		void	setX( int _X );
		void	setY( int _Y );
		void	setZ( int _Z );
		void	setCoords( int _X, int _Y, int _Z );

		// Getters
		int		getX( void ) const;
		int		getY( void ) const;
		int		getZ( void ) const;

		// Fetchers

		// Checkers
		bool	checkCoords() const;
		bool	matchCoords( const Coords &other ) const;

		// writters
		void	writeCoords( std::ostream &out ) const;
		void	printCoords( void ) const;

		friend	std::ostream &operator<<( std::ostream &out, const Coords &rhs );

};

#endif // COORDS_HPP