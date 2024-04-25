#ifndef ADDONS_HPP
# define ADDONS_HPP

# include "DefLibs.hpp"

// Screen Addons
uint32_t	convColour( const t_colour &colour );
uint32_t	convColour( byte r, byte g, byte b, byte a );

t_colour	makeColour( byte r, byte g, byte b );
t_colour	makeColour( byte r, byte g, byte b, byte a );

// Debug Addons
uint32_t getNextColour( void );

#endif //	ADDONS_HPP