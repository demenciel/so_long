/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:33:24 by acouture          #+#    #+#             */
/*   Updated: 2023/03/10 13:08:52 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void    render_map(t_data *data)
{
    int x;
    int y;

    x = 0;
    free_images(data);
    textures_to_img(data);
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
}

void    map_main(t_data *data)
{
    int x;

    x = 0;
    data->mlx = mlx_init((data->map_row * PX), (data->map_col * PX), "So_long", true);
    load_textures(data);
    load_textures_player(data);
    render_map(data);
    mlx_put_string(data->mlx, count_moves(data), 16, 16);
    mlx_key_hook(data->mlx, &my_keyhook, data);
    // mlx_key_hook(data->mlx, &player_animation, data);
    mlx_loop(data->mlx);
    free_textures(data);
    mlx_terminate(data->mlx);
}
