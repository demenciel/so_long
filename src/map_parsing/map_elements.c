/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:47:56 by acouture          #+#    #+#             */
/*   Updated: 2023/03/09 11:22:56 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	access_elem(t_data *data)
{
	if (data->flood.collect != data->elem.collec)
	{
		perror("Collectible not accessible");
		exit(EXIT_FAILURE);
	}
	if (data->flood.exit != data->elem.exit)
	{
		perror("Collectible not accessible");
		exit(EXIT_FAILURE);
	}
}

void	flood_fill(int y, int x, t_data *data)
{
	if ((x < 0 || x > data->map_col - 1) && (y < 0 || y > data->map_row - 1))
		return ;
	if (data->flood.map_flood[y][x] == 'X'
		|| data->flood.map_flood[y][x] == '1')
		return ;
	if (data->flood.map_flood[y][x] == 'C')
		++data->flood.collect;
	if (data->flood.map_flood[y][x] == 'E')
		data->flood.exit++;
	data->flood.map_flood[y][x] = 'X';
	flood_fill(y - 1, x, data);
	flood_fill(y + 1, x, data);
	flood_fill(y, x + 1, data);
	flood_fill(y, x - 1, data);
}

void	check_elems_error(t_data *data)
{
	if (data->elem.player < 1)
	{
		perror("Éléments manquant");
		exit(EXIT_FAILURE);
	}
	if (data->elem.collec < 1)
	{
		perror("Éléments manquant");
		exit(EXIT_FAILURE);
	}
	if (data->elem.exit < 1)
	{
		perror("Éléments manquant");
		exit(EXIT_FAILURE);
	}
}

void	check_elems(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	while (data->map_cpy[i])
	{
		y = 0;
		while (data->map_cpy[i][y])
		{
			if (data->map_cpy[i][y] == 'P')
			{
				data->player.y = i;
				data->player.x = y;
				++data->elem.player;
			}
			if (data->map_cpy[i][y] == 'C')
				++data->elem.collec;
			if (data->map_cpy[i][y] == 'E')
				++data->elem.exit;
			y++;
		}
		i++;
	}
	check_elems_error(data);
}

void	count_row_lines(t_data *data, char *map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		perror("File failed");
	line = get_next_line(fd);
	if (!line)
	{
		perror("No map");
		exit(EXIT_FAILURE);
	}
	data->map_row = ft_strlen(line) - 1;
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		++data->map_col;
		free(line);
	}
	close(fd);
}
