#ifndef TILE_HPP
# define TILE_HPP

# include "Default_Libs.hpp"
# include "Coords.hpp"

class Tile
{
	private:
		// Attributes
		Coords	C; // coord
		int		T; // type
		int		flag;

		Tile	*front;
		Tile	*right;
		Tile	*top;
		Tile	*back;
		Tile	*left;
		Tile	*bottom;

	protected:

		// Nested Classes
		class BadInit	: XCPT( "Tile error : failed to initialise"; );
		class BadCoords	: XCPT( "Tile error : out of bound"; );
		class BadType	: XCPT( "Tile error : invalid type"; );

	public:
		// Destructor
		~Tile();

		// Constructors
		Tile();
		Tile( int _T );

		Tile( int _X, int _Y, int _Z);
		Tile( int _X, int _Y, int _Z, int _T);

		Tile( const Coords _C );
		Tile( const Coords _C, const int _T);

		// Reconstructors
		Tile( const Tile &other );
		Tile &operator= ( const Tile &other );

		// Clearers
		void	clearCoords( void );
		void	clearType( void );
		void	clearFlag( void );
		void	clearDirs( void );

		// Setters
		void	setCoords( const Coords _C  );
		void	setType( const int _T );
		void	setFlag( void );
		void	setDirs( Tile *Front, Tile *Right, Tile *Top, Tile *Back, Tile *Left, Tile *Bottom );

		void	setFront(  Tile *T );
		void	setRight(  Tile *T );
		void	setTop(    Tile *T );
		void	setBack(   Tile *T );
		void	setLeft(   Tile *T );
		void	setBottom( Tile *T );

		// Getters
		Coords	getCoords( void ) const;
		int		getType( void ) const;
		bool	getFlag( void ) const;

		// Fetchers
		Coords	&fetchCoords( void );
		Tile	*fetchFront(  void );
		Tile	*fetchRight(  void );
		Tile	*fetchTop(    void );
		Tile	*fetchBack(   void );
		Tile	*fetchLeft(   void );
		Tile	*fetchBottom( void );

		// Checkers
		bool	checkTile( void ) const;
		bool	matchTile( const Tile &other ) const;

		// writters
		void	writeTile( std::ostream &out ) const;
		void	printTile( void ) const;

		friend std::ostream &operator<<( std::ostream &out, const Tile &rhs );

};

#endif // TILE_HPP