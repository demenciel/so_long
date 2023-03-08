/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:40:53 by acouture          #+#    #+#             */
/*   Updated: 2023/03/08 15:12:15 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
// # include <MLX42/MLX42.h>

// STRUCTURES ------------------------------------------------------

typedef struct  s_elem {
    int collec;
    int player;
    int exit;
}               t_elem;

typedef struct  s_player {
    int x;
    int y;
}               t_player;

typedef struct  s_flood {
    char    **map_flood;
    int     collect;
    int     exit;
}               t_flood;


typedef struct  data {
    char        **map_cpy;
    int         fd;
    int         map_row;
    int         map_col;
    t_elem      elem;
    t_player    player;
    t_flood     flood; 
}               t_data;

// FOR THE MAP PARSING ------------------------------------------------------
void    map_parsing(t_data *data, char *map);
void    copy_map(t_data *data, char *map);
void    count_row_lines(t_data *data, char *map);
void    modify_line(char *s1);
void	check_side_walls(t_data *data);
void	check_walls(t_data *data);
void    check_map_rectangle(t_data *data);
void	check_elems(t_data *data);
void    check_elems_error(t_data *data);


// UTILS ------------------------------------------------------
void    ft_double_arr_cpy(t_data *data);
void	free_arr(t_data *data, char **tab);
void	free_arr_flood(t_data *data);
void	struct_init(t_data *data);
void	flood_fill(int y, int x, t_data *data);
void    access_elem(t_data *data);

#endif