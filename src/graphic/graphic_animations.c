/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_animations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:18:15 by acouture          #+#    #+#             */
/*   Updated: 2023/03/10 15:33:03 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	loop_player(t_data *data)
{
	if (data->anim.refresh_count == 100)
		data->anim.refresh_count = 0;
	else if (data->anim.refresh_count > 33)
		data->anim.p = 1;
	else if (data->anim.refresh_count > 66)
		data->anim.p = 2;
	else
		data->anim.p = 0;
	data->anim.refresh_count++;
}

void	loop_enemy(t_data *data)
{
	if (data->anim.refresh_count == 60)
		data->anim.refresh_count = 0;
	else if (data->anim.refresh_count > 15)
		data->anim.e = 1;
	else if (data->anim.refresh_count > 30)
		data->anim.e = 2;
	else if (data->anim.refresh_count > 45)
		data->anim.e = 3;
	else
		data->anim.e = 0;
	data->anim.refresh_count++;
}
