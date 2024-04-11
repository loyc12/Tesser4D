#include "T4D.hpp"

void init_data( t_data *d )
{
	d->window = NULL;
	d->redraw = true;
	d->update = true;
}

t_data *get_data( void )
{
	static t_data *d;
	if ( !d )
	{
		d = ( t_data* )calloc( 1, sizeof( t_data ));
		init_data( d );
	}
	return ( d );
}

void load_world( void )
{
	t_data *d = get_data();
	( void )d;
}

void render_screen( void )
{
	t_data *d = get_data();
	( void )d;
}

void update_game( void )
{
	t_data *d = get_data();
	( void )d;
}

// normal hook used during the game loop
void loop_hook( void *param )
{
	t_data *d = ( t_data* )param;
	( void )d;

	// update game state
	if ( d->update )
		update_game();

	// render screen
	if ( d->redraw )
		render_screen();
}

// key hook used during the game loop
void key_hook( mlx_key_data_t keydata, void *param )
{
	t_data *d = ( t_data* )param;
	( void )d;

	if ( keydata.key == MLX_KEY_ESCAPE )
		mlx_close_window( d->window );
}

// main game loop
void loop_game( void )
{
	t_data *d = get_data();

	{ // core loop
		mlx_key_hook(	d->window, &key_hook, d );
		mlx_loop_hook(	d->window, &loop_hook, d );
		mlx_loop(		d->window );
	}

	mlx_terminate( d->window );
}

// opens a blank window to draw on
void init_window( void )
{
	t_data *d = get_data();

	d->half_height = ( SCREEN_HEIGHT / ( PIXEL_SIZE * 2 ));
	d->half_width =  ( SCREEN_WIDTH  / ( PIXEL_SIZE * 2 ));
	d->window = mlx_init( SCREEN_WIDTH, SCREEN_HEIGHT, "TESSER4D", false) ;

}

int main( int ac, char **av )
{
	( void ) ac;
	( void ) av;

	init_window();
	load_world();
	loop_game();

	std::cout << std::endl;
	return ( 0 );
}