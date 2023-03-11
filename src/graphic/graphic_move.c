/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:19:16 by acouture          #+#    #+#             */
/*   Updated: 2023/03/11 15:13:12 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_up(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	data->direction = 0;
	check_exit(x, y - 1, data);
	if (data->map_cpy[y - 1][x] == '0' || data->map_cpy[y - 1][x] == 'C')
	{
		if (data->map_cpy[y - 1][x] == 'C')
			data->elem.collec--;
		data->map_cpy[y - 1][x] = 'P';
		data->player.y -= 1;
		data->map_cpy[y][x] = '0';
		data->count_moves++;
	}
}

void	ft_down(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	data->direction = 1;
	check_exit(x, y + 1, data);
	if (data->map_cpy[y + 1][x] == '0' || data->map_cpy[y + 1][x] == 'C')
	{
		if (data->map_cpy[y + 1][x] == 'C')
			data->elem.collec--;
		data->map_cpy[y + 1][x] = 'P';
		data->player.y += 1;
		data->map_cpy[y][x] = '0';
		data->count_moves++;
	}
}

void	ft_left(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	data->direction = 2;
	check_exit(x - 1, y, data);
	if (data->map_cpy[y][x - 1] == '0' || data->map_cpy[y][x - 1] == 'C')
	{
		if (data->map_cpy[y][x - 1] == 'C')
			data->elem.collec--;
		data->map_cpy[y][x - 1] = 'P';
		data->player.x -= 1;
		data->map_cpy[y][x] = '0';
		data->count_moves++;
	}
}

void	ft_right(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	data->direction = 3;
	check_exit(x + 1, y, data);
	if (data->map_cpy[y][x + 1] == '0' || data->map_cpy[y][x + 1] == 'C')
	{
		if (data->map_cpy[y][x + 1] == 'C')
			data->elem.collec--;
		data->map_cpy[y][x + 1] = 'P';
		data->player.x += 1;
		data->map_cpy[y][x] = '0';
		data->count_moves++;
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			ft_up(data);
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			ft_down(data);
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			ft_left(data);
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			ft_right(data);
		if (keydata.key == MLX_KEY_ESCAPE)
			exit(0);
	}
}
