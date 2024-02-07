/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T4D.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:56:01 by llord             #+#    #+#             */
/*   Updated: 2024/02/07 16:36:51 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T4D_H
# define T4D_H

// ======== LIBRARIES ======== //

# include "../MLX42/include/MLX42/MLX42.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>

# include "Tile.hpp"
# include "defs.h"
# include "enums.h"
# include "structs.h"

#endif // T4D_H

/*

	0======== IDEAS ========0

attach current tile to entities/player
prevent placing tiles on entities
be able to place walls on non-tiles (map borders)
respawn in proper direction
use mouse to turn cameras
add a minimap
add music & sounds
give voids its own texture

*/