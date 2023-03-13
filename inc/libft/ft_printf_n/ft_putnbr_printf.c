/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:54:26 by acouture          #+#    #+#             */
/*   Updated: 2023/02/05 09:39:25 by utilisateur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_printf(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar_printf('-', fd);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_printf(n / 10, fd);
			n = n % 10;
		}
		ft_putchar_printf(n + '0', fd);
	}
}
