#ifndef TILE_HPP
# define TILE_HPP

# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

// CLASS ( implemented in .cpp file )

class Coords {};

class Tile
{
	private:
		// Attributes
		Coords		c;
		int			t;
		Tile		*front;
		Tile		*right;
		//Tile		*top;
		Tile		*back;
		Tile		*left;
		//Tile		*bottom;
		int			fff;

	protected:
		// Checkers
		void checkCoords( const Coords _c ) const;
		void checkType( const int _t) const;
		void matchTile( const Tile &other ) const;
		void matchCoords( const Coords _c ) const;

		// Nested Classes
		class BadName : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "Tile error : out of bound"; }
		};

	public:
		// Constructors - Destructor
		Tile();
		Tile( int X, int Y );
		Tile( const Coords _c );
		Tile( const Coords _c, const int _t);
		Tile( const Tile &other );
		~Tile();

		// Operators
		Tile &operator= ( const Tile &other );

		// Setters - Getters
		void			setCoords( const Coords _c  );
		const Coords	getCoords( void ) const;

		void			setFFF( void );
		bool			getFFF( void ) const;
		void			resetFFF( void );

		// Others
		void			printTile( void );

};

std::ostream &operator<< (std::ostream &out, const Tile &rhs);

#endif // TILE_HPP