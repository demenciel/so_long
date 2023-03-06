/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:32 by acouture          #+#    #+#             */
/*   Updated: 2023/02/22 16:05:10 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;

	g_var.fd = STDOUT_FILENO;
	g_var.i = 0;
	va_start(args, format);
	if (*format == '\0')
		return (0);
	while (format[g_var.i])
	{
		if (format[g_var.i] == '%')
		{
			g_var.i++;
			check_format_sp(format[g_var.i], args);
		}
		else
			ft_putchar_printf(format[g_var.i], g_var.fd);
		g_var.i++;
	}
	return (g_var.i - 1);
}

void	check_format_sp(char c, va_list args)
{
	g_var.fd = STDOUT_FILENO;
	if (c == 'c')
		ft_putchar_printf(va_arg(args, int), g_var.fd);
	else if (c == 's')
		ft_putstr_printf(va_arg(args, char *), g_var.fd);
	else if (c == 'p')
		ft_putpointer_fd(va_arg(args, unsigned long));
	else if (c == 'i' || c == 'd')
		ft_putnbr_printf((va_arg(args, int)), g_var.fd);
	else if (c == 'u')
		ft_putnbr_unsigned_printf((va_arg(args, unsigned int)), g_var.fd);
	else if (c == 'x')
		ft_itoa_to_hexa((va_arg(args, long long unsigned int)), c);
	else if (c == 'X')
		ft_itoa_to_hexa((va_arg(args, long long unsigned int)), c);
	else if (c == '%')
		ft_putchar_printf('%', g_var.fd);
}
