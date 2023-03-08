/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:42:13 by acouture          #+#    #+#             */
/*   Updated: 2023/03/08 09:08:18 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	struct_init(t_data *data)
{
	data->map_cpy = NULL;
	data->flood.map_flood = NULL;
	data->map_col = 0;
	data->map_row = 0;
}

int	main(int ac, char **av)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (ac != 2)
	{
		perror("Mauvais nombres d'arguments");
		exit(EXIT_FAILURE);
	}
	else
	{
		struct_init(data);
		if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
			perror("Mauvais format de carte");
		map_parsing(data, av[1]);
		free_arr(data->map_cpy);
		free(data);
	}
}
