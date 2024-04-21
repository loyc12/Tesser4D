/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:56:01 by llord             #+#    #+#             */
/*   Updated: 2024/04/21 16:51:44 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

//# include "Default_Libs.hpp"

// ======== ENUM STATES ======== //

//game states (where the game is at execution wise)
typedef enum e_gstate
{
	GSTATE_ERROR	= -1,
	GSTATE_STARTING	= 0,
	GSTATE_RUNNING	= 1,
	GSTATE_ENDING	= 2
}			t_mstate;

//direction ID (
typedef enum e_did
{
	DID_NONE	= -1,
	DID_FRONT	= 0,
	DID_RIGHT	= 1,
	DID_TOP		= 2,
	DID_BACK	= 3,
	DID_LEFT	= 4,
	DID_BOTTOM	= 5,
}			t_tid;

//tile type (how should we interact/display this tile)
typedef enum e_ttype
{
	TTYPE_ERROR	= -1,
	TTYPE_VOID	= 0,
	TTYPE_FULL	= 1,
}			t_ttype;

#endif //	ENUMS_H