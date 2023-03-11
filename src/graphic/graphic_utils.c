/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:32:39 by acouture          #+#    #+#             */
/*   Updated: 2023/03/11 10:11:35 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	free_old_images(t_data *data)
{
	mlx_delete_image(data->mlx, data->old_img_t.walls_img);
	mlx_delete_image(data->mlx, data->old_img_t.collec_img);
	mlx_delete_image(data->mlx, data->old_img_t.exit_img);
	mlx_delete_image(data->mlx, data->old_img_t.player);
	mlx_delete_image(data->mlx, data->old_img_t.tiles_img);
	mlx_delete_image(data->mlx, data->old_img_t.enemy_img);
	mlx_delete_image(data->mlx, data->old_img_t.wood_img);
}

void	free_textures(t_data *data)
{
	mlx_delete_texture(data->textures.tiles);
	mlx_delete_texture(data->textures.walls);
	mlx_delete_texture(data->textures.exit);
	mlx_delete_texture(data->textures.collectible);
	mlx_delete_texture(data->textures.wood);
	mlx_delete_texture(data->textures.enemy[0]);
	mlx_delete_texture(data->textures.enemy[1]);
	mlx_delete_texture(data->textures.enemy[2]);
	mlx_delete_texture(data->textures.enemy[3]);
	free_textures_player(data);
}

void	free_textures_player(t_data *data)
{
	mlx_delete_texture(data->textures.player_front[0]);
	mlx_delete_texture(data->textures.player_front[1]);
	mlx_delete_texture(data->textures.player_front[2]);
	mlx_delete_texture(data->textures.player_back[0]);
	mlx_delete_texture(data->textures.player_back[1]);
	mlx_delete_texture(data->textures.player_back[2]);
	mlx_delete_texture(data->textures.player_left[0]);
	mlx_delete_texture(data->textures.player_left[1]);
	mlx_delete_texture(data->textures.player_left[2]);
	mlx_delete_texture(data->textures.player_right[0]);
	mlx_delete_texture(data->textures.player_right[1]);
	mlx_delete_texture(data->textures.player_right[2]);
}

void	count_moves(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->count_moves);
	data->count_mv_str = ft_strjoin("Moves :", moves);
	free(moves);
}

void	check_exit(int x, int y, t_data *data)
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
