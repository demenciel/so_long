/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:32:39 by acouture          #+#    #+#             */
/*   Updated: 2023/03/10 10:15:49 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void    free_images(t_data *data)
{
    mlx_delete_image(data->mlx, data->img_t.walls_img);
    mlx_delete_image(data->mlx, data->img_t.collec_img);
    mlx_delete_image(data->mlx, data->img_t.exit_img);
    mlx_delete_image(data->mlx, data->img_t.player_img);
    mlx_delete_image(data->mlx, data->img_t.tiles_img);
    mlx_delete_image(data->mlx, data->img_t.enemy_img);
}

void	free_textures(t_data *data)
{
	mlx_delete_texture(data->textures.tiles);
	mlx_delete_texture(data->textures.walls);
    mlx_delete_texture(data->textures.exit);
	mlx_delete_texture(data->textures.collectible);
    mlx_delete_texture(data->textures.player[0]);
	mlx_delete_texture(data->textures.player[1]);
    mlx_delete_texture(data->textures.player[2]);
    mlx_delete_texture(data->textures.player[3]);
    mlx_delete_texture(data->textures.enemy[0]);
	mlx_delete_texture(data->textures.enemy[1]);
    mlx_delete_texture(data->textures.enemy[2]);
    mlx_delete_texture(data->textures.enemy[3]);
}

char *count_moves(t_data *data)
{
    char *moves;
    char *final_str;
    
    moves = ft_itoa(data->count_moves);
    final_str = ft_strjoin("Moves :", moves);
    return (final_str);
}

void    check_exit(int x, int y, t_data *data)
{
    if (data->map_cpy[y][x] == 'A')
        exit(1);
    if (data->elem.collec == 0)
    {
        if (data->map_cpy[y][x] == 'E')
        {
            data->map_cpy[y][x + 1] = 'P';
            data->player.x += 1;
            data->map_cpy[y][x] = '0';
            exit(1);
        }
    }
}
