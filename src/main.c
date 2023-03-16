/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:42:13 by acouture          #+#    #+#             */
/*   Updated: 2023/03/16 15:20:38 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_map(t_data *data, char **av)
{
	int ext;
	
	ext = ft_strlen(av[1]) - 4;
	struct_init(data);
	if (ft_strncmp(&av[1][ext], ".ber", 4) != 0)
		ft_error("Wrong type of file");
	map_parsing(data, av[1]);
	free_arr_flood(data);
}

void	struct_init(t_data *data)
{
	data->map_cpy = NULL;
	data->flood.map_flood = NULL;
	data->direction = 1;
	data->dir_ene = 0;
	data->count_moves = 0;
	data->counter = 0;
	data->map_col = 0;
	data->map_row = 0;
	data->elem.collec = 0;
	data->elem.exit = 0;
	data->elem.player = 0;
	data->elem.enemy = 0;
	data->flood.collect = 0;
	data->flood.exit = 0;
	data->anim.p = 0;
	data->anim.refresh_count = 0;
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		ft_error("Malloc failed");
	if (ac != 2)
		ft_error("Wrong number of arguments");
	else
	{
		init_map(data, av);
		map_main(data);
	}
	free_textures(data);
	free_arr(data, data->map_cpy);
	free(data);
}
