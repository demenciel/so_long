/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 07:49:12 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:02:40 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Displays on the STDERR a given message and exits the program
 * @param s The message to be printed
*/
void	ft_error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}
