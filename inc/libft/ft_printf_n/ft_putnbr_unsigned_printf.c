/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_printf.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:21 by acouture          #+#    #+#             */
/*   Updated: 2023/02/22 16:06:07 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned_printf(unsigned int u, int fd)
{
	fd = STDOUT_FILENO;
	if (u < 0)
		write(fd, "4294967176", 11);
	else
	{
		if (u > 9)
		{
			ft_putnbr_printf(u / 10, fd);
			u = u % 10;
		}
		ft_putchar_printf(u + '0', fd);
	}
}
