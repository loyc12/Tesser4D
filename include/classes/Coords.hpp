#ifndef COORDS_HPP
# define COORDS_HPP

# include "Default_Libs.hpp"

class Coords
{
	private:
		// Attributes
		int	X;
		int	Y;
		int	Z;

	protected:

		// Nested Classes
		class BadValiue : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "Coord error : invalid value"; }
		};

	public:
		// Constructors - Destructor
		Coords();
		Coords( int _X, int _Y, int _Z);
		Coords( const Coords &other );
		~Coords();

		// Operators
		Coords &operator= ( const Coords &other );

		// Setters - Getters
		void	setX( int _X );
		void	setY( int _Y );
		void	setZ( int _Z );

		int		getX( void ) const;
		int		getY( void ) const;
		int		getZ( void ) const;

		// Checkers
		bool	checkPos() const;
		bool	matchPos( const Coords &other ) const;

		// Others
		void	printPos( void ) const;

};

std::ostream &operator<< (std::ostream &out, const Coords &rhs);

#endif // COORDS_HPP