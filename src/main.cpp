#include "T4D.hpp"

// initializes the game data
void init_data( t_data *d )
{
	DEBUG( std::cout << "initializing game data" << std::endl; )
	// NOTE : values are all 0 by default

	d->window = NULL;
	d->update = true;
	d->redraw = true;

}

// fetched the game data ( singleton )
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

// cleans up the game data
void clean_data( void )
{
	DEBUG( std::cout << "cleaning up game data" << std::endl; )

	t_data *d = get_data();

	if ( d->window ) mlx_terminate( d->window );

	free( d );
}

// initiates the world
void init_world( void )
{
	DEBUG( std::cout << "initializing world data" << std::endl; )

	t_data *d = get_data();
	( void )d;
}

// opens a blank window to draw on
void init_window( void )
{
	DEBUG( std::cout << "initializing window" << std::endl; )
	t_data *d = get_data();

	d->half_height = ( SCREEN_HEIGHT / ( PIXEL_SIZE * 2 ));
	d->half_width =  ( SCREEN_WIDTH  / ( PIXEL_SIZE * 2 ));
	d->window = mlx_init( SCREEN_WIDTH, SCREEN_HEIGHT, "TESSER4D", false) ;

}

// render the game screen
void render_screen( void )
{
	DEBUG( std::cout << "rendering game" << std::endl; )

	t_data *d = get_data();
	( void )d;
}

// update game states
void update_game( void )
{
	DEBUG( std::cout << "updating game states" << std::endl; )

	t_data *d = get_data();
	( void )d;
}

// loops until mlx_terminate is called
void loop_hook( void *param )
{
	t_data *d = ( t_data* )param;
	( void )d;

	// update game state
	if ( d->update ) update_game();

	// render screen
	if ( d->redraw ) render_screen();
}

//interpret key signals during the gama loop
void key_hook( mlx_key_data_t keydata, void *param )
{
	t_data *d = ( t_data* )param;
	( void )d;

	if ( keydata.key == MLX_KEY_ESCAPE ) mlx_close_window( d->window );
}

// main game loop
void run_game( void )
{

	// initialize game and world
	init_window();
	init_world();

	DEBUG( std::cout << "\nstarting game loop" << std::endl; )
	t_data *d = get_data();

	{ // core loop ( done automatically by mlx )
		mlx_key_hook(	d->window, &key_hook, d );
		mlx_loop_hook(	d->window, &loop_hook, d );
		mlx_loop(		d->window );
	}
	DEBUG( std::cout << "\nending game loop" << std::endl; )

	// cleanup
	clean_data();
	DEBUG( std::cout << "quitting..." << std::endl; )
}

// main function
int main( int ac, char **av )
{
	( void ) ac;
	( void ) av;

	run_game();

	return ( 0 );
}