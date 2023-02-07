/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:04:40 by acouture          #+#    #+#             */
/*   Updated: 2023/02/07 14:04:41 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(void)
{
	t_data	data;
	void 	*img;

	// initialize the MLX Lib
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
 	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So long");
	if (data.win == NULL)
	{
		free(data.win);
		return (MLX_ERROR);
	}
	img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// keeps the window open through a loop
	mlx_loop(data.mlx);
	/* we will exit the loop if there's no window left, and execute this code */
	free(data.mlx);
}