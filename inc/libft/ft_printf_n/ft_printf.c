/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:32 by acouture          #+#    #+#             */
/*   Updated: 2023/02/05 09:40:39 by utilisateur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;

	var.fd = STDOUT_FILENO;
	var.i = 0;
	va_start(args, format);

	if (*format == '\0')
		return(0);
	while (format[var.i])
	{
		if (format[var.i] == '%')
		{
			var.i++;
			check_format_sp(format[var.i], args);
		}
		else
			ft_putchar_printf(format[var.i], var.fd);
		var.i++;
	}
	return (var.i - 1);
}

void	check_format_sp(char c, va_list args)
{
	var.fd = STDOUT_FILENO;
	if (c == 'c')
		ft_putchar_printf(va_arg(args, int), var.fd);
	else if (c == 's')
		ft_putstr_printf(va_arg(args, char *), var.fd);
	else if (c == 'p')
		ft_putpointer_fd(va_arg(args, unsigned long));
	else if (c == 'i' || c == 'd')
		ft_putnbr_printf((va_arg(args, int)), var.fd);
	else if (c == 'u')
		ft_putnbr_unsigned_printf((va_arg(args, unsigned int)), var.fd);
	else if (c == 'x')
		ft_itoa_to_hexa((va_arg(args, long long unsigned int)), c);
	else if (c == 'X')
		ft_itoa_to_hexa((va_arg(args, long long unsigned int)), c);
	else if (c == '%')
		ft_putchar_printf('%', var.fd);
}
