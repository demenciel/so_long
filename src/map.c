/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:52:13 by acouture          #+#    #+#             */
/*   Updated: 2023/02/07 16:53:23 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
            img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}


int	init_window(void)
{
	t_data  data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WINDOW_W, WINDOW_H, "So long");
	if (data.win == NULL)
	{
		free(data.win);
		return (MLX_ERROR);
	}
	mlx_loop(data.mlx);
	return (0);
}
