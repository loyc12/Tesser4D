#ifndef TILE_HPP
# define TILE_HPP

# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

# include "Coords.hpp"

class Tile
{
	private:
		// Attributes
		Coords		C;
		int			T;
		//Tile		*front;
		//Tile		*right;
		//Tile		*top;
		//Tile		*back;
		//Tile		*left;
		//Tile		*bottom;
		int			fff;

	protected:

		// Nested Classes
		class BadCoords : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "Tile error : out of bound"; }
		};
		class BadType : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "Tile error : invalid type"; }
		};

	public:
		// Constructors - Destructor
		Tile();
		Tile( int _T );
		Tile( int _X, int _Y, int _Z);
		Tile( int _X, int _Y, int _Z, int _T);
		Tile( const Coords _C );
		Tile( const Coords _C, const int _T);
		Tile( const Tile &other );
		~Tile();

		// Operators
		Tile &operator= ( const Tile &other );

		// Setters - Getters
		void	setCoords( const Coords _C  );
		void	setType( const int _T );

		const Coords	getCoords( void ) const;
		int				getType( void ) const;

		void	setFFF( void );
		bool	getFFF( void ) const;
		void	resetFFF( void );

	/*
		void	setFront( Tile *T );
		void	setRight( Tile *T );
		void	setTop( Tile *T );
		void	setBack( Tile *T );
		void	setLeft( Tile *T );
		void	setBottom( Tile *T );

		Tile	*getFront( void );
		Tile	*getRight( void );
		Tile	*getTop( void );
		Tile	*getBack( void );
		Tile	*getLeft( void );
		Tile	*getBottom( void );
	*/

		// Checkers
		void	checkCoords( const Coords _C ) const;
		void	checkType( const int _T) const;
		bool	matchTile( const Tile &other ) const;
		bool	matchCoords( const Coords _C ) const;

		// Others
		void	printTile( void );

};

std::ostream &operator<< (std::ostream &out, const Tile &rhs);

#endif // TILE_HPP