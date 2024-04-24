# include "Game.hpp"

// loops until mlx_terminate is called
void loop_hook( void *param )
{
	Game *g = ( Game* )param;
	( void )g;

	g->updateGame();
	g->renderGame();
}

//interpret key signals during the gama loop
void key_hook( mlx_key_data_t keydata, void *param )
{
	Game *g = ( Game* )param;
	( void )g;

	if   ( keydata.key == MLX_KEY_ESCAPE ) { g->quitGame(); }

	elif PRESSED( keydata, MLX_KEY_W ) { std::cout << "W pressed" << std::endl; }
	elif PRESSED( keydata, MLX_KEY_A ) { std::cout << "A pressed" << std::endl; }
	elif PRESSED( keydata, MLX_KEY_S ) { std::cout << "S pressed" << std::endl; }
	elif PRESSED( keydata, MLX_KEY_D ) { std::cout << "D pressed" << std::endl; }

	elif RELEASED( keydata, MLX_KEY_W ) { std::cout << "W released" << std::endl; }
	elif RELEASED( keydata, MLX_KEY_A ) { std::cout << "A released" << std::endl; }
	elif RELEASED( keydata, MLX_KEY_S ) { std::cout << "S released" << std::endl; }
	elif RELEASED( keydata, MLX_KEY_D ) { std::cout << "D released" << std::endl; }

	elif HELD( keydata, MLX_KEY_W ) { std::cout << "W held" << std::endl; }
	elif HELD( keydata, MLX_KEY_A ) { std::cout << "A held" << std::endl; }
	elif HELD( keydata, MLX_KEY_S ) { std::cout << "S held" << std::endl; }
	elif HELD( keydata, MLX_KEY_D ) { std::cout << "D held" << std::endl; }

	else { std::cout << "key pressed: " << keydata.key << std::endl; }
}

void	Game::runGame( void )
{

	DEBUG( std::cout << "\nstarting game loop" << std::endl; )

	{ // core loop ( done automatically by mlx )
		mlx_key_hook( this->screen.fetchWindow(), &key_hook, this );
		mlx_loop_hook( this->screen.fetchWindow(), &loop_hook, this );
		mlx_loop( this->screen.fetchWindow() );
	}

	this->quitGame();
}

void	Game::updateGame( void )
{
	if ( !this->hasUpdated )
	{
		//DEBUG( std::cout << "updating game" << std::endl; )

		this->hasUpdated = true;
		this->hasRendered = false;
	}
}

void	Game::renderGame( void )
{
	if ( !this->hasRendered )
	{
		//DEBUG( std::cout << "rendering game" << std::endl; )

		this->hasRendered = true;
		this->hasUpdated = false;
	}
}
