/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_loops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:03:27 by acouture          #+#    #+#             */
/*   Updated: 2023/05/09 15:34:32 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	loop_player(t_data *data)
{
	if (data->anim.refresh_count == 75)
		data->anim.refresh_count = 0;
	else if (data->anim.refresh_count > 25)
		data->anim.p = 1;
	else if (data->anim.refresh_count > 50)
		data->anim.p = 2;
	else
		data->anim.p = 0;
	data->anim.refresh_count++;
}

void	ft_down_enemy(t_data *data)
{
	int	x;
	int	y;

	x = data->enemy.x;
	y = data->enemy.y;
	if (data->map_cpy[y + 1][x] == 'P')
	{
		ft_printf("%sYou were killed by an enemy\n", RED);
		exit(0);
	}
	if (data->map_cpy[y + 1][x] == '0')
	{
		data->map_cpy[y + 1][x] = 'A';
		data->enemy.y += 1;
		data->map_cpy[y][x] = '0';
	}
	data->dir_ene = 1;
}

void	ft_up_enemy(t_data *data)
{
	int	x;
	int	y;

	x = data->enemy.x;
	y = data->enemy.y;
	if (data->map_cpy[y - 1][x] == 'P')
	{
		ft_printf("%sYou were killed by an enemy\n", RED);
		exit(0);
	}
	if (data->map_cpy[y - 1][x] == '0')
	{
		data->map_cpy[y - 1][x] = 'A';
		data->enemy.y -= 1;
		data->map_cpy[y][x] = '0';
	}
	data->dir_ene = 0;
}

void	loop_enemy_move(t_data *data)
{
	if (data->counter == 350)
		data->counter = 0;
	else if (data->counter == 50)
		ft_down_enemy(data);
	else if (data->counter == 100)
		ft_down_enemy(data);
	else if (data->counter == 150)
		ft_down_enemy(data);
	else if (data->counter == 200)
		ft_up_enemy(data);
	else if (data->counter == 250)
		ft_up_enemy(data);
	else if (data->counter == 300)
		ft_up_enemy(data);
	data->counter++;
}
