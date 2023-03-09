/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:19:16 by acouture          #+#    #+#             */
/*   Updated: 2023/03/09 14:35:05 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void    ft_up(t_data *data)
{
    (void)data;
}

void    ft_down(t_data *data)
{
    (void)data;
}

void    ft_left(t_data *data)
{
    (void)data;
}

void    ft_right(t_data *data)
{
    (void)data;
}

void    my_keyhook(mlx_key_data_t keydata, void *param)
{
    t_data *data;

    data = param;
    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
    {
        if (keydata.key == MLX_KEY_W)
            ft_up(data);
        if (keydata.key == MLX_KEY_S)
            ft_down(data);
        if (keydata.key == MLX_KEY_A)
            ft_left(data);
        if (keydata.key == MLX_KEY_D)
            ft_right(data);
    }
}