/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:50:22 by vdescham          #+#    #+#             */
/*   Updated: 2020/03/02 17:50:24 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

int		key_pressed(int key, t_data *data)
{
	if (key == 53)
		exit_game(data);
	else if (key == 13)
		data->key.up = true;
	else if (key == 1)
		data->key.down = true;
	else if (key == 124)
		data->key.r_right = true;
	else if (key == 123)
		data->key.r_left = true;
	else if (key == 0)
		data->key.left = true;
	else if (key == 2)
		data->key.right = true;
	else if (key == 257)
		data->player.move_speed = 0.08;
	else if (key == 8)
		bmp_create(data, "screenshot_c.bmp");
	else if (key == 14 && data->player.is_shooting == false)
	{
		data->key.shoot = true;
		system("afplay Musics/gun.mp3 & afplay Musics/reload.mp3 -v 4 &");
		shoot(data);
	}
	return (0);
}

int		key_released(int key, t_data *data)
{
	if (key == 13)
		data->key.up = false;
	else if (key == 1)
		data->key.down = false;
	else if (key == 124)
		data->key.r_right = false;
	else if (key == 123)
		data->key.r_left = false;
	else if (key == 0)
		data->key.left = false;
	else if (key == 2)
		data->key.right = false;
	else if (key == 257)
		data->player.move_speed = 0.05;
	else if (key == 14)
		data->key.shoot = false;
	return (0);
}
