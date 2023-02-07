/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:44:59 by acouture          #+#    #+#             */
/*   Updated: 2023/02/07 14:03:18 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "inc/libft/libft.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

#define MLX_ERROR 1

typedef struct s_data
{
	void	*mlx;
	void	*win;
}              t_data;

#endif

