/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_animations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:18:15 by acouture          #+#    #+#             */
/*   Updated: 2023/03/10 14:31:18 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	enemy_moves(void *param)
{
	t_data	*data;

	data = param;
	ft_up(data);
	ft_down(data);
	ft_left(data);
	ft_right(data);
}

// void	loop_player_arr(void *param)
// {
//     t_data *data;

//     data = param;
//     if (data->player_anim.x == 2)
//             data->player_anim.x = 0;
//     data->player_anim.x++;
// }

