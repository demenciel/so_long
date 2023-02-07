/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:44:59 by acouture          #+#    #+#             */
/*   Updated: 2023/02/07 17:05:16 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "struct.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define WINDOW_W 800
# define WINDOW_H 800

# define MLX_ERROR 1

# define BLUE 0x362FD9
# define WHITE 0xFFFFFF

int		init_window(void);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_data *data, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
void	*mlx_new_image(void *mlx_ptr, int width, int height);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line,
			int *endian);

#endif
