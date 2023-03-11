/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:40:53 by acouture          #+#    #+#             */
/*   Updated: 2023/03/11 15:34:38 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// MACROS ------------------------------------------------------
# define PX 64
# define TILES "./png/dirt.png"
# define WALLS "./png/walls.png"
# define COLLECTIBLE "./png/meat.png"
# define EXIT "./png/exit.png"
# define WOOD "./png/wood.png"
# define X_UP "./png/enemy/back.png"
# define X_DOWN "./png/enemy/front.png"
# define X_LEFT "./png/enemy/left.png"
# define X_RIGHT "./png/enemy/right.png"

// COLORS ------------------------------------------------------

# define GREEN "\033[0;92m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

// STRUCTURES ------------------------------------------------------
typedef struct s_elem
{
	int				collec;
	int				player;
	int				exit;
	int				enemy;
}					t_elem;

typedef struct s_player
{
	int				x;
	int				y;
}					t_player;

typedef struct s_enemy
{
	int				x;
	int				y;
}					t_enemy;

typedef struct s_flood
{
	char			**map_flood;
	int				collect;
	int				exit;
	int				enemy;
}					t_flood;

typedef struct s_player_anim
{
	int				p;
	int				refresh_count;
}					t_player_anim;

typedef struct s_textures
{
	mlx_texture_t	*tiles;
	mlx_texture_t	*walls;
	mlx_texture_t	*exit;
	mlx_texture_t	*collectible;
	mlx_texture_t	*wood;
	mlx_texture_t	*player_front[3];
	mlx_texture_t	*player_back[3];
	mlx_texture_t	*player_left[3];
	mlx_texture_t	*player_right[3];
	mlx_texture_t	*enemy[4];
}					t_textures;

typedef struct s_img_t
{
	mlx_image_t		*tiles_img;
	mlx_image_t		*walls_img;
	mlx_image_t		*collec_img;
	mlx_image_t		*wood_img;
	mlx_image_t		*exit_img;
	mlx_image_t		*player;
	mlx_image_t		*enemy_img;
}					t_img_t;

typedef struct data
{
	char			**map_cpy;
	int				fd;
	int				map_row;
	int				map_col;
	int				counter;
	int				direction;
	int				dir_ene;
	int				count_moves;
	char			*count_mv_str;
	t_elem			elem;
	t_player		player;
	t_enemy			enemy;
	t_flood			flood;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_textures		textures;
	t_img_t			img_t;
	t_img_t			old_img_t;
	t_player_anim	anim;
}					t_data;

// FOR THE MAP PARSING ------------------------------------------------------
void				map_parsing(t_data *data, char *map);
void				copy_map(t_data *data, char *map);
void				count_row_lines(t_data *data, char *map);
void				modify_line(char *s1);
void				check_walls(t_data *data);
void				check_map_rectangle(t_data *data);
void				check_elems(t_data *data);
void				enem_player_pos(t_data *data, int i, int y);
void				check_elems_error(t_data *data);

// RENDERING ------------------------------------------------------
void				init_map(t_data *data, char **av);
void				map_main(t_data *data);
void				render_map(void *param);
void				load_textures(t_data *data);
void				load_textures_player(t_data *data);
void				textures_to_img(t_data *data);
void				my_keyhook(mlx_key_data_t keydata, void *param);
void				loop_player(t_data *data);
void				loop_enemy(t_data *data);
mlx_image_t			*load_images(char c, t_data *data);

// MOVES -----------------------------------------------------------------
void				check_exit(int x, int y, t_data *data);
void				count_moves(t_data *data);
void				ft_down_enemy(t_data *data);
void				loop_enemy_move(t_data *data);

// UTILS ------------------------------------------------------
void				ft_double_arr_cpy(t_data *data);
void				struct_init(t_data *data);
void				flood_fill(int y, int x, t_data *data);
void				access_elem(t_data *data);

// FREE FUNCTIONS ----------------------------------------------------------
void				free_arr(t_data *data, char **tab);
void				free_arr_flood(t_data *data);
void				free_textures(t_data *data);
void				free_textures_player(t_data *data);
void				free_old_images(t_data *data);

#endif