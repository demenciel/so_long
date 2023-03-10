/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:40:05 by acouture          #+#    #+#             */
/*   Updated: 2023/03/10 13:30:39 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	textures_to_img(t_data *data)
{
	// int random;
	data->img_t.tiles_img = mlx_texture_to_image(data->mlx,
													data->textures.tiles);
	data->img_t.walls_img = mlx_texture_to_image(data->mlx,
													data->textures.walls);
	data->img_t.collec_img = mlx_texture_to_image(data->mlx,
													data->textures.collectible);
	data->img_t.exit_img = mlx_texture_to_image(data->mlx,
												data->textures.exit);
	data->img_t.enemy_img = mlx_texture_to_image(data->mlx,
													data->textures.enemy[1]);
}

mlx_image_t	*load_player(t_data *data)
{
	if (data->direction == 1)
	{
		data->img_t.player_front = mlx_texture_to_image(data->mlx,
														data->textures.player_front[data->player_anim.x]);
	}
	if (data->direction == 0)
	{
		data->img_t.player_img = mlx_texture_to_image(data->mlx,
														data->textures.player_back[data->player_anim.x]);
	}
	if (data->direction == 2)
	{
		data->img_t.player_img = mlx_texture_to_image(data->mlx,
														data->textures.player_left[data->player_anim.x]);
	}
	if (data->direction == 3)
	{
		data->img_t.player_img = mlx_texture_to_image(data->mlx,
														data->textures.player_right[data->player_anim.x]);
	}
	return (data->img_t.player_img);
}

mlx_image_t	*load_images(char c, t_data *data)
{
	if (c == '1')
		return (data->img_t.walls_img);
	if (c == 'P')
		return (load_player(data));
	if (c == 'C')
		return (data->img_t.collec_img);
	if (c == 'A')
		return (data->img_t.enemy_img);
	if (c == 'E')
		return (data->img_t.exit_img);
	else
		return (data->img_t.tiles_img);
}