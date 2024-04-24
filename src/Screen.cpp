#include "Screen.hpp"

// Destructor
Screen::~Screen() { DEBUG( std::cout << "[ Destroying a SCREEN instance ]\n" ); }

// Constructors
Screen::Screen()
{
	DEBUG( std::cout << "[ Called def. constr. for a SCREEN instance ]\n" );
	this->width = 0;  this->height = 0;
}
Screen::Screen( int _width, int _height )
{
	DEBUG( std::cout << "[ Called param. constr. for a SCREEN instance ]\n" );
	this->width = _width;  this->height = _height;
}

// Reconstructors
Screen::Screen( const Screen &other )
{
	DEBUG( std::cout << "[ Called copy constr. for a SCREEN instance ]\n" );
	this->width = other.getWidth();  this->height = other.getHeight();
}
Screen &Screen::operator= ( const Screen &other )
{
	DEBUG( std::cout << "[ Called assign. op. for a SCREEN instance ]\n" );
	this->width = other.getWidth();  this->height = other.getHeight();
	return *this;
}

// Clearers
void	Screen::clearWidth( void ) { this->width = 0; }
void	Screen::clearHeight( void ) { this->height = 0; }
void	Screen::clearDims( void ) { this->clearWidth();  this->clearHeight(); }
void	Screen::clearWindow( void ) { this->window = nullptr; }
void	Screen::clearCanvas( void ) { this->canvas = nullptr; }

// Setters
void	Screen::setWidth( int _width ) { this->width = _width; }
void	Screen::setHeight( int _height ) { this->height = _height; }
void	Screen::setDims( int _width, int _height ) { this->setWidth( _width );  this->setHeight( _height ); }
void	Screen::setWindow( mlx_t *_window ) { this->window = _window; }
void	Screen::setCanvas( mlx_image_t *_canvas ) { this->canvas = _canvas; }

// Getters
int		Screen::getWidth( void ) const { return ( this->width ); }
int		Screen::getHeight( void ) const { return ( this->height ); }

// Fetchers
mlx_t		*Screen::fetchWindow( void ) { return ( this->window ); }
mlx_image_t	*Screen::fetchCanvas( void ) { return ( this->canvas ); }

// Checkers
bool	Screen::checkScreen( void ) const { return ( this->checkDims() ); }
bool	Screen::checkDims( void ) const { return ( this->width > 0 && this->height > 0 ); }

// writters
void	Screen::writeScreen( std::ostream &out ) const { out << "[ " << this->width << " : " << this->height << " ]"; }
void	Screen::printScreen( void ) const { this->writeScreen( std::cout );  std::cout << std::endl; }
std::ostream &operator<<( std::ostream &out, const Screen &rhs ) { rhs.writeScreen( out );  return out; }

// Others
void	Screen::drawRect( int w, int h, int _width, int _height, t_colour colour )
{
	for ( int i = 0; i < _width; i++ )
		for ( int j = 0; j < _height; j++ )
			mlx_put_pixel( this->canvas, w + i, h + j, convColour( colour ));
}
void	Screen::fillCanvas( t_colour colour )
{
	for ( int h = 0; h < ( int )this->canvas->height; h++ )
		for ( int w = 0; w < ( int )this->canvas->width; w++ )
			mlx_put_pixel( this->canvas, w, h, convColour( colour ));
}
void	Screen::drawMPixel( int w, int h, t_colour colour ) { this->drawRect( w, h, MPX_SIZE, MPX_SIZE, colour ); }
void	Screen::initCanvas( void )
{
	this->canvas = mlx_new_image( this->window, this->window->width, this->window->height );
	if ( this->canvas == nullptr )
		throw Screen::BadCanvas();
	this->fillCanvas( makeColour( 0x00, 0x00, 0x00 ));
}

void	Screen::initWindow( void )
{
	this->window = mlx_init( ( int32_t )this->width, ( int32_t )this->height, TITLE, true );
	if ( this->window == nullptr )
		throw Screen::BadWindow();
	this->initCanvas();
}