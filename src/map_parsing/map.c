/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:38:47 by acouture          #+#    #+#             */
/*   Updated: 2023/03/13 10:53:56 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	check_walls(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = -1;
	while (data->map_cpy[0][++y])
	{
		if (data->map_cpy[0][y] != '1')
			ft_error("Wall Error");
	}
	y = -1;
	while (data->map_cpy[data->map_col - 1][++y])
	{
		if (data->map_cpy[data->map_col - 1][y] != '1')
			ft_error("Wall Error");
	}
	while (data->map_cpy[i])
	{
		if (data->map_cpy[i][0] != '1')
			ft_error("Wall Error");
		if (data->map_cpy[i][data->map_row - 1] != '1')
			ft_error("Wall Error");
		i++;
	}
}

void	check_map_rectangle(t_data *data)
{
	size_t	i;
	size_t	row_size;

	i = 0;
	row_size = (size_t)data->map_row;
	while (data->map_cpy[i])
	{
		if (ft_strlen(data->map_cpy[i]) != (row_size))
			ft_error("Map is not rectangle");
		i++;
	}
}

void	copy_map(t_data *data, char *map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Can't open file");
	data->map_cpy = malloc(sizeof(char *) * (data->map_col + 1));
	if (!data->map_cpy)
		ft_error("Malloc failed");
	while (i < data->map_col)
	{
		line = get_next_line(fd);
		data->map_cpy[i] = line;
		modify_line(data->map_cpy[i]);
		i++;
	}
	data->map_cpy[i] = NULL;
	close(fd);
}

void	check_map_overflow(t_data *data)
{
	if (data->map_col > 50)
		ft_error("Map too big");
	if (data->map_row > 50)
		ft_error("Map too big");
}

void	map_parsing(t_data *data, char *map)
{
	count_row_lines(data, map);
	check_map_overflow(data);
	copy_map(data, map);
	check_map_rectangle(data);
	check_walls(data);
	check_elems(data);
	ft_double_arr_cpy(data);
	flood_fill(data->player.y, data->player.x, data);
	access_elem(data);
}
