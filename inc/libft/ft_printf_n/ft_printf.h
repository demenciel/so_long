/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:30:27 by acouture          #+#    #+#             */
/*   Updated: 2023/02/22 16:07:55 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct format_list
{
	char	*temp;
	int		i;
	int		fd;
}			t_var_list;
t_var_list	g_var;

int			ft_printf(const char *format, ...);
void		check_format_sp(char c, va_list args);

void		ft_putnbr_unsigned_printf(unsigned int u, int fd);
void		ft_itoa_to_hexa(long long unsigned nb, char c);
void		ft_putpointer_fd(uintptr_t y);
void		ft_putchar_printf(char c, int fd);
void		ft_putnbr_printf(int n, int fd);
void		ft_putstr_printf(char *s, int fd);
size_t		ft_strlen_printf(const char *str);

#endif