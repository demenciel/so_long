/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:32:39 by acouture          #+#    #+#             */
/*   Updated: 2023/03/09 13:35:02 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void ft_error(void)
{
	exit(EXIT_FAILURE);
}

void    load_textures(t_data *data)
{
    data->textures.tiles = mlx_load_png(TILES);
    data->textures.walls = mlx_load_png(WALLS);
}


void    textures_to_img(t_data *data)
{
    data->img_t.tiles_img = mlx_texture_to_image(data->mlx, data->textures.tiles);
    data->img_t.walls_img = mlx_texture_to_image(data->mlx, data->textures.walls);
}

void    free_textures(t_data *data)
{
    mlx_delete_texture(data->textures.tiles);
    mlx_delete_texture(data->textures.walls);
}

mlx_image_t *load_images(char c, t_data *data)
{
    if (c == '1')
        return (data->img_t.walls_img);
    if (c == 'P')
        return (data->img_t.walls_img);
    if (c == 'C')
        return (data->img_t.walls_img);
    if (c == 'E')
        return (data->img_t.walls_img);
    else
        return (data->img_t.tiles_img);
}
