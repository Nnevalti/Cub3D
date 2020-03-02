#include "../include/Cub3D.h"

void		init_win(char *line, t_data *data)
{
	int		i;

	i = 0;
	data->win.width = ft_atoi(&(line[i]));
	data->win.width = (data->win.width > 2560) ? 2560 : data->win.width;
	while (ft_isspace(line[i]))
		i++;
	while (ft_isdigit(line[i]))
		i++;
	data->win.height = ft_atoi(&(line[i]));
	data->win.height = (data->win.height > 1440) ? 1440 : data->win.height;
	while (ft_isdigit(line[i]) || ft_isspace(line[i]))
		i++;
	if (data->win.load == true || line[i] != '\0'
		|| data->win.width < 100 || data->win.height < 100)
		error_msg(data, "Windows resolution is invalid", true);
	if ((data->win_ptr = mlx_new_window(data->mlx_ptr,
		data->win.width, data->win.height, "Cub3D")))
	{
		data->win.load = true;
		data->depth_buffer = malloc(data->win.width * sizeof(int));
	}
}

void		init_display(t_data *data)
{
	if (!(data->display.img = mlx_new_image(data->mlx_ptr,
		data->win.width, data->win.height))
		|| !(data->display.addr = mlx_get_data_addr(data->display.img,
			&data->display.bpp, &data->display.s_line, &data->display.endian)))
		exit_game(data);
}

int			line_parse(t_data *data, char *line, int fd)
{
	if (line[0] == 'R')
		init_win(&line[1], data);
	if (line[0] == 'N' && line[1] == 'O')
		init_tex(data, &data->north, find_path(&line[3]));
	if ((line[0] == 'S' && line[1] == 'O'))
		init_tex(data, &data->south, find_path(&line[3]));
	if ((line[0] == 'W' && line[1] == 'E'))
		init_tex(data, &data->west, find_path(&line[3]));
	if ((line[0] == 'E' && line[1] == 'A'))
		init_tex(data, &data->east, find_path(&line[3]));
	if (line[0] == 'S' && line[1] == ' ')
		init_tex(data, &data->sprite, find_path(&line[2]));
	if (line[0] == 'F')
		init_color(data, &line[1], &data->floor);
	if (line[0] == 'C')
		init_color(data, &line[1], &data->ceilling);
	if (line[0] == '1')
	{
		init_map(data, line, fd);
		return (0);
	}
	return (1);
}

t_data		init_data(char **av, int fd)
{
	t_data		data;
	char		*line;

	data.file_line = 0;
	data.mlx_ptr = mlx_init();
	while (get_next_line(fd, &line) == 1)
	{
		data.file_line++;
		if (line_parse(&data, line, fd))
			free(line);
	}
	free(line);
	check_init(&data);
	init_display(&data);
	return (data);
}