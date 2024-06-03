// Creator: Loyc12

#ifndef ENUMS_H
# define ENUMS_H

// ======== ENUMS ======== //

// flag_state
typedef enum e_fs // flag_state
{
	FS_OFF		= 0,
	FS_ON		= 1,
	FS_LOG		= 2,
	FS_DBG		= 3,
	FS_COUNT	= 3
}				t_fstate;

// direction ID (
typedef enum e_dir // direction id
{
	DIR_NONE	= -1,
	DIR_FRONT	= 0,
	DIR_RIGHT	= 1,
	DIR_TOP		= 2,
	DIR_BACK	= 3,
	DIR_LEFT	= 4,
	DIR_BOTTOM	= 5,
	DIR_COUNT	= 5
}				t_dir;

// tile type ( how should we interact/display this tile )
typedef enum e_tt
{
	TT_ERROR	= -1,
	TT_VOID	= 0,
	TT_FULL	= 1,
	TT_COUNT	= 1
}				t_tt;

// game state
typedef enum e_gs
{
	GS_ERROR	= -1,
	GS_MENU		= 0,
	GS_PLAY		= 1,
	GS_PAUSE	= 2,
	GS_COUNT	= 2
}				t_gs;

#endif // ENUMS_H