/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:04:40 by acouture          #+#    #+#             */
/*   Updated: 2023/02/07 17:09:38 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	if (data->win == NULL)
		return ;
	i = 0;
	while (i < WINDOW_H)
	{
		j = 0;
		while (j < WINDOW_W)
			mlx_pixel_put(data->mlx, data->win, j++, i, color);
		++i;
	}
}


int	render(t_data *data)
{
	if (data->win == NULL)
		return (1);
	render_background(data, WHITE);	
	render_rect(&data->img, (t_rect){WINDOW_W / 2, WINDOW_H / 2, 100, 100, BLUE});
	
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data  data;
	t_img	image;
	void    *img;

	// open the window
	init_window();
	/*Create image*/
    data.img.mlx_img = mlx_new_image(data.mlx, WINDOW_W, WINDOW_H);
	mlx_get_data_addr(data.img.mlx_img, &image.bpp, &image.line_len, &image.endian);
	// setup hooks
	mlx_loop_hook(data.mlx, &render, &data);

	free(data.mlx);
}