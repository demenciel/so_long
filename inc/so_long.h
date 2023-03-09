/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:40:53 by acouture          #+#    #+#             */
/*   Updated: 2023/03/09 15:58:53 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <MLX42/MLX42.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// MACROS ------------------------------------------------------
# define PX 64
# define TILES "./png/dirt.png"
# define WALLS "./png/walls.png"
# define COLLECTIBLE "./png/meat.png"
# define UP "./png/up.png"
# define DOWN "./png/down.png"
# define LEFT "./png/left.png"
# define RIGHT "./png/right.png"
# define EXIT "./png/exit.png"

// STRUCTURES ------------------------------------------------------

typedef struct s_elem
{
	int				collec;
	int				player;
	int				exit;
}					t_elem;

typedef struct s_player
{
	int				x;
	int				y;
}					t_player;

typedef struct s_flood
{
	char			**map_flood;
	int				collect;
	int				exit;
}					t_flood;

typedef struct s_textures
{
	mlx_texture_t	*tiles;
	mlx_texture_t	*walls;
	mlx_texture_t	*exit;
	mlx_texture_t	*collectible;
	mlx_texture_t	*player[4];
}					t_textures;

typedef struct s_img_t
{
	mlx_image_t		*tiles_img;
	mlx_image_t		*walls_img;
	mlx_image_t		*collec_img;
	mlx_image_t		*exit_img;
	mlx_image_t		*player_img;
}					t_img_t;

typedef struct data
{
	char			**map_cpy;
	int				fd;
	int				map_row;
	int				map_col;
	int				direction;
	t_elem			elem;
	t_player		player;
	t_flood			flood;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_textures		textures;
	t_img_t			img_t;
	t_img_t			old_img_t;
}					t_data;

// FOR THE MAP PARSING ------------------------------------------------------
void				map_parsing(t_data *data, char *map);
void				copy_map(t_data *data, char *map);
void				count_row_lines(t_data *data, char *map);
void				modify_line(char *s1);
void				check_side_walls(t_data *data);
void				check_walls(t_data *data);
void				check_map_rectangle(t_data *data);
void				check_elems(t_data *data);
void				check_elems_error(t_data *data);

// FOR GRAPHIC ------------------------------------------------------
void				init_map(t_data *data, char **av);
void				free_textures(t_data *data);
void    			free_images(t_data *data);
void				map_main(t_data *data);
void				ft_error(void);
void				load_textures(t_data *data);
void				textures_to_img(t_data *data);
mlx_image_t			*load_images(char c, t_data *data);
void				render_map(t_data *data);
void				my_keyhook(mlx_key_data_t keydata, void *param);
void				ft_up(t_data *data);
void				check_exit(int x, int y, t_data *data);

// UTILS ------------------------------------------------------
void				ft_double_arr_cpy(t_data *data);
void				free_arr(t_data *data, char **tab);
void				free_arr_flood(t_data *data);
void				struct_init(t_data *data);
void				flood_fill(int y, int x, t_data *data);
void				access_elem(t_data *data);

#endif