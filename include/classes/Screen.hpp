#ifndef SCREEN_HPP
# define SCREEN_HPP

# include "Default_Libs.hpp"

class Screen
{
	private:
		// Attributes
		int	width;
		int	height;

	protected:
		// Nested Classes
		class BadInit : XCPT( "Screen error : failed to initialise"; );

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

		// Setters
		void	setWidth( int _width );
		void	setHeight( int _height );
		void	setDims( int _width, int _height );

		// Getters
		int		getWidth( void ) const;
		int		getHeight( void ) const;

		// Fetchers

		// Checkers
		bool	checkScreen( void ) const;
		bool	checkDims( void ) const;

		// writters
		void	writeScreen( std::ostream &out ) const;
		void	printScreen( void ) const;

		friend	std::ostream &operator<<( std::ostream &out, const Screen &rhs );

};

#endif // SCREEN_HPP