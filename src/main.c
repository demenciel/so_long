/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:42:13 by acouture          #+#    #+#             */
/*   Updated: 2023/03/07 11:46:14 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
		perror("Mauvais nombres d'arguments");
	else
	{
		if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
			perror("Mauvais format de carte");
		map_parsing(&data, av[1]);
	}
}
