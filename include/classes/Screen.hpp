#ifndef SCREEN_HPP
# define SCREEN_HPP

# include "DefLibs.hpp"
# include "Colours.hpp"

# define MPX_SIZE	( int )4
# define TITLE		( char* )"Screen Test"
# define BPP		( int )4 // byte per pixel

class Screen
{
	private:
		// Attributes
		int	width;
		int	height;

		mlx_t			*window;
		mlx_image_t		*canvas;
		//t_colour		**colours;
		//mlx_texture_t	**textures;

	protected:
		// Nested Classes
		class BadInit   : XCPT( "Screen error : failed to initialise"; );
		class BadWindow : XCPT( "Screen error : failed to create window"; );
		class BadCanvas : XCPT( "Screen error : failed to create canvas"; );

	public:
		// Destructor
		~Screen();

		// Constructors
		Screen();
		Screen( int _width, int _height );

		// Reconstructors
		Screen( const Screen &other );
		Screen &operator= ( const Screen &other );

		// Clearers
		void	clearWidth( void );
		void	clearHeight( void );
		void	clearDims( void );
		void	clearWindow( void );
		void	clearCanvas( void );

		// Setters
		void	setWidth( int _width );
		void	setHeight( int _height );
		void	setDims( int _width, int _height );
		void	setWindow( mlx_t *_window );
		void	setCanvas( mlx_image_t *_canvas );

		// Getters
		int		getWidth( void ) const;
		int		getHeight( void ) const;

		// Fetchers
		mlx_t		*fetchWindow( void );
		mlx_image_t	*fetchCanvas( void );

		// Checkers
		bool	checkScreen( void ) const;
		bool	checkDims( void ) const;

		// Writers
		void	writeScreen( std::ostream &out ) const;
		void	printScreen( void ) const;

		friend	std::ostream &operator<<( std::ostream &out, const Screen &rhs );

		// Drawers

		void	drawRect( int w, int h, int _width, int _height, const t_colour &colour );
		void	drawRect( int w, int h, int _width, int _height, uint32_t colour );

		void	fillCanvas( const t_colour &colour );
		void	fillCanvas( uint32_t colour );

		void	drawMPixel( int w, int h, const t_colour &colour );
		void	drawMPixel( int w, int h, uint32_t colour );

		// Others
		void	initWindow( void );
		void	initCanvas( void );

};

#endif // SCREEN_HPP