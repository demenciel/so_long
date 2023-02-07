/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:58:52 by acouture          #+#    #+#             */
/*   Updated: 2023/02/07 16:30:30 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "../inc/so_long.h"

/*for image*/
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	        t_img;

/*for mlx data*/
typedef struct s_data
{
	void	*mlx;
	void	*win;
    t_img   img;
}			t_data;
/*rectangle*/
typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rect;

