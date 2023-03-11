/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:25:28 by acouture          #+#    #+#             */
/*   Updated: 2023/03/11 14:11:21 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	enem_player_pos(t_data *data, int i, int y)
{
	if (data->map_cpy[i][y] == 'P')
	{
		data->player.y = i;
		data->player.x = y;
		++data->elem.player;
	}
	if (data->map_cpy[i][y] == 'A')
	{
		data->enemy.y = i;
		data->enemy.x = y;
		++data->elem.enemy;
	}
}

void	modify_line(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\n')
			s1[i] = '\0';
		i++;
	}
}

void	free_arr(t_data *data, char **tab)
{
	int	i;

	i = 0;
	while (i < data->map_col)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_arr_flood(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_col)
	{
		free(data->flood.map_flood[i]);
		i++;
	}
	free(data->flood.map_flood);
}

void	ft_double_arr_cpy(t_data *data)
{
	int	i;

	i = 0;
	data->flood.map_flood = malloc(sizeof(char *) * (data->map_col + 1));
	if (!data->flood.map_flood)
		ft_error("Malloc failed");
	while (i < data->map_col)
	{
		data->flood.map_flood[i] = malloc(sizeof(char *) * data->map_row + 1);
		if (!data->flood.map_flood[i])
			ft_error("Malloc failed");
		ft_memcpy(data->flood.map_flood[i], data->map_cpy[i], data->map_row);
		i++;
	}
	data->flood.map_flood[i] = NULL;
}
