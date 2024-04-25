#ifndef ENTITY_HPP
# define ENTITY_HPP

# include "DefLibs.hpp"

# include "Position.hpp"
# include "Tile.hpp"

class Entity
{
	private:
		// Attributes
		Position	pos;
		Tile		tile;

	protected:
		// Nested Classes
		class BadInit	: XCPT( "Entity error : failed to initialise"; );
		class BadEntity	: XCPT( "Entity error : invalid entity"; );

	public:
		// Destructor
		~Entity();

		// Constructors
		Entity();
		Entity( const Position _pos, const Tile _tile );

		// Reconstructors
		Entity( const Entity &other );
		Entity &operator= ( const Entity &other );

		// Clearers
		void	clearPos( void );
		void	clearTile( void );

		// Setters
		void	setPos( const Position _pos );
		void	setTile( const Tile _tile );

		// Getters
		Position	getPos( void ) const;
		Tile		getTile( void ) const;

		// Fetchers
		Position	&fetchPos( void );
		Tile		&fetchTile( void );

		// Checkers
		bool	checkEntity( void ) const;

		// Writers
		void	writeEntity( std::ostream &out ) const;
		void	printEntity( void ) const;

		friend std::ostream &operator<<( std::ostream &out, const Entity &rhs );

};

#endif // ENTITY_HPP