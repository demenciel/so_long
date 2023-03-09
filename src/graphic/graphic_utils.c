/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:32:39 by acouture          #+#    #+#             */
/*   Updated: 2023/03/09 14:35:51 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_error(void)
{
	exit(EXIT_FAILURE);
}

void	load_textures(t_data *data)
{
	data->textures.tiles = mlx_load_png(TILES);
	data->textures.walls = mlx_load_png(WALLS);
	data->textures.collectible = mlx_load_png(COLLECTIBLE);
	data->textures.exit = mlx_load_png(EXIT);
	data->textures.player[0] = mlx_load_png(DOWN);
    data->textures.player[1] = mlx_load_png(UP);
    data->textures.player[2] = mlx_load_png(LEFT);
    data->textures.player[3] = mlx_load_png(RIGHT);
}

void	textures_to_img(t_data *data)
{
	data->img_t.tiles_img = mlx_texture_to_image(data->mlx,
													data->textures.tiles);
	data->img_t.walls_img = mlx_texture_to_image(data->mlx,
													data->textures.walls);
	data->img_t.collec_img = mlx_texture_to_image(data->mlx,
													data->textures.collectible);
	data->img_t.exit_img = mlx_texture_to_image(data->mlx,
												data->textures.exit);
	data->img_t.player_img = mlx_texture_to_image(data->mlx,
													data->textures.player[0]);
}

void	free_textures(t_data *data)
{
	mlx_delete_texture(data->textures.tiles);
	mlx_delete_texture(data->textures.walls);
}

mlx_image_t	*load_images(char c, t_data *data)
{
	if (c == '1')
		return (data->img_t.walls_img);
	if (c == 'P')
		return (data->img_t.player_img);
	if (c == 'C')
		return (data->img_t.collec_img);
	if (c == 'E')
		return (data->img_t.exit_img);
	else
		return (data->img_t.tiles_img);
}
