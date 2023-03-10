/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:21:01 by acouture          #+#    #+#             */
/*   Updated: 2023/03/10 15:33:23 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	load_textures(t_data *data)
{
	data->textures.tiles = mlx_load_png(TILES);
	data->textures.walls = mlx_load_png(WALLS);
	data->textures.collectible = mlx_load_png(COLLECTIBLE);
	data->textures.exit = mlx_load_png(EXIT);
	data->textures.enemy[0] = mlx_load_png(X_UP);
	data->textures.enemy[1] = mlx_load_png(X_DOWN);
	data->textures.enemy[2] = mlx_load_png(X_LEFT);
	data->textures.enemy[3] = mlx_load_png(X_RIGHT);
}

void	load_textures_player(t_data *data)
{
	data->textures.player_front[0] = mlx_load_png("./png/front/front1.png");
	data->textures.player_front[1] = mlx_load_png("./png/front/front2.png");
	data->textures.player_front[2] = mlx_load_png("./png/front/front3.png");
	data->textures.player_back[0] = mlx_load_png("./png/back/back.png");
	data->textures.player_back[1] = mlx_load_png("./png/back/back1.png");
	data->textures.player_back[2] = mlx_load_png("./png/back/back2.png");
	data->textures.player_left[0] = mlx_load_png("./png/left/left.png");
	data->textures.player_left[1] = mlx_load_png("./png/left/left1.png");
	data->textures.player_left[2] = mlx_load_png("./png/left/left2.png");
	data->textures.player_right[0] = mlx_load_png("./png/right/right.png");
	data->textures.player_right[1] = mlx_load_png("./png/right/right1.png");
	data->textures.player_right[2] = mlx_load_png("./png/right/right2.png");
}