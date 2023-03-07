/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:25:28 by acouture          #+#    #+#             */
/*   Updated: 2023/03/07 13:23:42 by acouture         ###   ########.fr       */
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

void    ft_double_arr_cpy(char **tab, t_data *data)
{
    char    **res;
    int     i;
    
    i = 0;
    res = malloc(sizeof(data->map_col));
    while (tab[i])
    {
        res[i] = malloc(sizeof(data->map_row));
        ft_memcpy(res[i], tab[i], ft_strlen(tab[i]));
        ft_printf("%s\n", res[i]);
        i++;
    }
}