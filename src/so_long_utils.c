/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:25:28 by acouture          #+#    #+#             */
/*   Updated: 2023/03/07 14:53:20 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	free_arr(t_data *data)
{
	int i;

	i = 0;
	while (data->map_cpy[i])
	{
		free(data->map_cpy[i]);
		i++;
	}
	free(data->map_cpy);
}

void    ft_double_arr_cpy(t_data *data)
{
    int     i;
    
    i = -1;
    data->flood.map_flood = malloc(sizeof(char *) * data->map_col + 1);
    while (data->map_cpy[++i])
    {
        data->flood.map_flood[i] = malloc(sizeof(char *) * data->map_row);
        ft_memcpy(data->flood.map_flood[i], data->map_cpy[i], data->map_row);
    }
	data->flood.map_flood[i] = NULL;
}