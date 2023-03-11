/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:33:24 by acouture          #+#    #+#             */
/*   Updated: 2023/03/11 15:34:33 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	render_map(void *param)
{
	int		x;
	int		y;
	t_data	*data;

	data = param;
	x = 0;
	free_old_images(data);
	data->old_img_t = data->img_t;
	textures_to_img(data);
	count_moves(data);
	mlx_put_string(data->mlx, data->count_mv_str, 16, 16);
	free(data->count_mv_str);
	while (x < data->map_row)
	{
		y = 0;
		while (y < data->map_col)
		{
			data->img = load_images(data->map_cpy[y][x], data);
			mlx_image_to_window(data->mlx, data->img, (x * PX), (y * PX));
			y++;
		}
		x++;
	}
	loop_enemy_move(data);
}

void	map_main(t_data *data)
{
	int	x;

	x = 0;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init((data->map_row * PX), (data->map_col * PX), "So_long",
			true);
	load_textures(data);
	load_textures_player(data);
	mlx_loop_hook(data->mlx, &render_map, data);
	mlx_key_hook(data->mlx, &my_keyhook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
