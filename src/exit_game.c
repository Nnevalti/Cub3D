#include "../include/Cub3D.h"

// void	free_map(t_data *data, int line)
// {
// 	int		i;
//
// 	i = 0;
// 	while (i < line)
// 	{
// 		free(data->map.map[i]);
// 	}
// 	free(data->map.map);
// }

void	free_tex(t_data *data)
{
	if (data->north.load == true)
		mlx_destroy_image(data->mlx_ptr, data->north.img);
	if (data->south.load == true)
		mlx_destroy_image(data->mlx_ptr, data->south.img);
	if (data->east.load == true)
		mlx_destroy_image(data->mlx_ptr, data->east.img);
	if (data->west.load == true)
		mlx_destroy_image(data->mlx_ptr, data->west.img);
	if (data->sprite.load == true)
		mlx_destroy_image(data->mlx_ptr, data->sprite.img);
	if (data->display.load == true)
		mlx_destroy_image(data->mlx_ptr, data->display.img);
}

int		exit_game(t_data *data)
{
	// if (data->map.load == true)
	// 	free_map(data, data->map.height);
	if (data->north.load == true || data->south.load == true
	|| data->east.load == true || data->west.load == true
	|| data->sprite.load == true || data->display.load == true)
		free_tex(data);
	if (data->win.load == true)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	check_error(data);
	system("leaks Cub3D");
	exit (0);
}
