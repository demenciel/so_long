/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:33:24 by acouture          #+#    #+#             */
/*   Updated: 2023/03/09 13:35:08 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void    render_map(t_data *data)
{
    int x;
    int y;

    x = 0;
    load_textures(data);
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

    render_map(data);
    mlx_loop(data->mlx);
    mlx_terminate(data->mlx);
}