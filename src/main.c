/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:42:13 by acouture          #+#    #+#             */
/*   Updated: 2023/05/22 15:52:49 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_access_exit(t_data *data)
{
	int	x;
	int	y;
	int	flag;

	flag = 0;
	y = data->flood.exit_y;
	x = data->flood.exit_x;
	if (data->flood.map_flood[y - 1][x] == 'X' || data->flood.map_flood[y
		- 1][x] == '1')
		flag++;
	if (data->flood.map_flood[y + 1][x] == 'X' || data->flood.map_flood[y
		+ 1][x] == '1')
		flag++;
	if (data->flood.map_flood[y][x - 1] == 'X' || data->flood.map_flood[y][x
		- 1] == '1')
		flag++;
	if (data->flood.map_flood[y][x + 1] == 'X' || data->flood.map_flood[y][x
		+ 1] == '1')
		flag++;
	if (flag == 0)
		ft_error("Exit not reachable");
}

void	init_map(t_data *data, char **av)
{
	int	ext;

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
	data->flood.exit_x = 0;
	data->flood.exit_y = 0;
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
		free_textures(data);
	}
	free_arr(data, data->map_cpy);
	free(data);
}


int	check_full(void)
{
	t_data	*data;
	int		nb_eat;

	data = call_struct();
	if (data->must_eat)
	{
		pthread_mutex_lock(&data->mutex.nb_eat_mutex);
		nb_eat = data->total_eaten;
		pthread_mutex_unlock(&data->mutex.nb_eat_mutex);
		if (nb_eat == data->must_eat)
			return (1);
	}
	return (0);
}

/**
 * For each philo,
	checks if the time since the last meal as exceeded time_to_die
*/
int	check_death(void)
{
	int		time_check;
	int		i;
	t_philo	*philo;
	t_data	*data;

	i = 0;
	data = call_struct();
	while (i < data->nb_philo)
	{
		philo = &data->philo[i];
		pthread_mutex_lock(&data->mutex.last_meal);
		time_check = time_stamp() - philo->time_last_meal;
		pthread_mutex_unlock(&data->mutex.last_meal);
		if (time_check >= data->time_to_die)
		{
			print_action(philo->philo_id, time_stamp(), PHILO_DEAD);
			pthread_mutex_lock(&data->mutex.change_state);
			data->dead = true;
			pthread_mutex_unlock(&data->mutex.change_state);
			return (1);
		}
		i++;
	}
	return (0);
}