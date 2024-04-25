#include "Tile.hpp"

// Destructor
Tile::~Tile() {} //{ DEBUG( std::cout << "[ Destroying a TILE instance ]\n" ); }

// Constructors
Tile::Tile()
{
	//DEBUG( std::cout << "[ Called def. constr. for a TILE instance ]\n" );
	this->C = Coords( 0, 0, 0 );
	this->T = 0;
	this->flag = false;
}
Tile::Tile( int _T )
{
	//DEBUG( std::cout << "[ Called param. constr. for a TILE instance ]\n" );
	this->C = Coords( 0, 0, 0 );
	this->T = _T;
	this->flag = false;
}
Tile::Tile( int X, int Y, int Z )
{
	//DEBUG( std::cout << "[ Called param. constr. for a TILE instance ]\n" );
	this->C = Coords( X, Y, Z );
	this->T = 0;
	this->flag = false;
}
Tile::Tile( int X, int Y, int Z, int _T)
{
	//DEBUG( std::cout << "[ Called param. constr. for a TILE instance ]\n" );
	this->C = Coords( X, Y, Z );
	this->T = _T;
	this->flag = false;
}
Tile::Tile( const Coords _C )
{
	//DEBUG( std::cout << "[ Called param. constr. for a TILE instance ]\n" );
	this->C = _C;
	this->T = 0;
	this->flag = false;
}
Tile::Tile( const Coords _C, int _T )
{
	//DEBUG( std::cout << "[ Called param. constr. for a TILE instance ]\n" );
	this->C = _C;
	this->T = _T;
	this->flag = false;
}

// Reconstructors
Tile::Tile( const Tile &other )
{
	//DEBUG( std::cout << "[ Called copy constr. for a TILE instance ]\n" );
	this->C = other.getCoords();
	this->T = other.getType();
}
Tile &Tile::operator= ( const Tile &other )
{
	//DEBUG( std::cout << "[ Called assign. op. for a TILE instance ]\n" );
	this->C = other.getCoords();
	this->T = other.getType();
	return *this;
}

// Checkers
bool	Tile::checkTile( void ) const { return ( this->C.checkCoords() && this->T >= TTYPE_VOID && this->T <= TTYPE_COUNT ); }
bool	Tile::matchTile( const Tile &other ) const { return ( this->C.matchCoords( other.getCoords() ) && this->T == other.getType() ); }

// Clearers
void	Tile::clearCoords( void ) { this->C = Coords(); }
void	Tile::clearType( void ) { this->T = TTYPE_VOID; }
void	Tile::clearFlag( void ) { this->flag = false; }
void 	Tile::clearDirs( void ) { this->setDirs( nullptr, nullptr, nullptr, nullptr, nullptr, nullptr ); }

// Setters
void	Tile::setCoords( const Coords _C ) { this->C = _C; }
void	Tile::setType( const int _T ) { this->T = _T; }
void	Tile::setFlag( void ) { this->flag = true; }
void	Tile::setDirs( Tile *Front, Tile *Right, Tile *Top, Tile *Back, Tile *Left, Tile *Bottom )
{
	this->setFront(  Front );
	this->setRight(  Right );
	this->setTop(    Top );
	this->setBack(   Back );
	this->setLeft(   Left );
	this->setBottom( Bottom );
}

void	Tile::setFront(  Tile *tile ) { this->front = tile; }
void	Tile::setRight(  Tile *tile ) { this->right = tile; }
void	Tile::setTop(    Tile *tile ) { this->top = tile; }
void	Tile::setBack(   Tile *tile ) { this->back = tile; }
void	Tile::setLeft(   Tile *tile ) { this->left = tile; }
void	Tile::setBottom( Tile *tile ) { this->bottom = tile; }

// Getters
Coords	Tile::getCoords( void ) const { return ( this->C ); }
int		Tile::getType( void ) const { return ( this->T ); }
bool	Tile::getFlag( void ) const { return ( this->flag ); }

// Fetchers
Coords	&Tile::fetchCoords( void ) { return ( this->C ); }
Tile	*Tile::fetchFront(  void ) { return ( this->front ); }
Tile	*Tile::fetchRight(  void ) { return ( this->right ); }
Tile	*Tile::fetchTop(    void ) { return ( this->top ); }
Tile	*Tile::fetchBack(   void ) { return ( this->back ); }
Tile	*Tile::fetchLeft(   void ) { return ( this->left ); }
Tile	*Tile::fetchBottom( void ) { return ( this->bottom ); }

// Writers
void	Tile::writeTile( std::ostream &out ) const
{
	out << "[ ";
	this->C.writeCoords( out );
	out << " ( T : " << this->T << " )]";
}
void	Tile::printTile( void ) const
{
	this->writeTile( std::cout );
	std::cout << std::endl;
}
std::ostream &operator<<( std::ostream &out, const Tile &rhs )
{
	rhs.writeTile( out );
	return ( out );
}
