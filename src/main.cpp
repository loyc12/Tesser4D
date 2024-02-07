#include "T4D.hpp"

t_master	*get_master(void)
{
	static t_master	*data;

	if (!data)
		data = (t_master *)calloc(1, sizeof(t_master));
	return (data);
}

//normal hook used during the game loop
void	loop_hook(void *param)
{
	t_master	*data;

	data = (t_master *)param;
}

//key hook used during the game loop
void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_master	*d;

	d = (t_master *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(get_master()->window);
}

void	play_game(t_master *data)
{
	mlx_key_hook(data->window, &key_hook, data);
	mlx_loop_hook(data->window, &loop_hook, data);
	mlx_loop(data->window);
	mlx_terminate(data->window);
}

//opens a blank window to draw on
void	init_window(void)
{
	t_master	*data;

	data = get_master();
	data->half_height = (SCREEN_HEIGHT / (PIXEL_SIZE * 2));
	data->half_width = (SCREEN_WIDTH / (PIXEL_SIZE * 2));
	data->window = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "CUBE3D", false);
	data->fov_ratio = ((PIXEL_SIZE * PLAYER_FOV) / SCREEN_WIDTH);
	data->fov_ratio /= sin((180 - (PLAYER_FOV / 2)) * M_PI / 360); // aproximately fixes the fish eye effect
	data->should_refresh = true;
	//make_canvas();
}

int	main(int ac, char **av)
{
	(void)	ac;
	(void)	av;

	init_window();
	play_game(get_master());
	printf("\n");
	return (0);
}