/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:38:47 by acouture          #+#    #+#             */
/*   Updated: 2023/03/07 15:29:58 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_side_walls(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_cpy[i])
	{
		if (data->map_cpy[i][0] != '1')
		{
			perror("Wall error");
			exit(EXIT_FAILURE);
		}
		if (data->map_cpy[i][data->map_row - 2] != '1')
		{
			perror("Wall errro");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_walls(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = -1;
	while (data->map_cpy[0][++y])
	{
		if (data->map_cpy[0][y] != '1')
			perror("Wall error");
	}
	y = -1;
	while (data->map_cpy[data->map_col][++y])
	{
		if (data->map_cpy[data->map_col][y] != '1')
			perror("Wall error");
	}
	check_side_walls(data);
}

void	check_map_rectangle(t_data *data)
{
	size_t	i;
	size_t	row_size;

	i = 0;
	row_size = (size_t)data->map_row;
	while (data->map_cpy[i])
	{
		if (ft_strlen(data->map_cpy[i]) != (row_size - 1))
		{
			perror("Mauvais format de carte");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	copy_map(t_data *data, char *map)
{
	int	i;

	i = 0;
	data->map_row = ft_strlen(get_next_line(data->fd));
	while (get_next_line(data->fd) != NULL)
		++data->map_col;
	close(data->fd);
	data->fd = open(map, O_RDONLY);
	data->map_cpy = malloc(sizeof(char *) * data->map_col);
	while (i <= data->map_col)
	{
		data->map_cpy[i] = malloc(sizeof(char *) * data->map_row);
		data->map_cpy[i] = get_next_line(data->fd);
		modify_line(data->map_cpy[i]);
		i++;
	}
	data->map_cpy[i] = NULL;
	close(data->fd);
}

void	map_parsing(t_data *data, char *map)
{
	data->fd = open(map, O_RDONLY);
	if (data->fd < 0)
		perror("File failed");
	copy_map(data, map);
	check_map_rectangle(data);
	check_walls(data);
    check_elems(data);
    ft_double_arr_cpy(data);
    flood_fill(data->player.y, data->player.x, data);
	access_elem(data);
}
