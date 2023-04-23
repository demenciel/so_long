/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:25:52 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:37:36 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
 * @brief Iterates over two strings and compares the difference of each
	characters up to a certain size
 * @param str1 String 1
 * @param str2 String 2
 * @param n Size of the content to be compared
 * @return The difference of the compared characters
*/
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (i < n && str1[i])
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if (i == n)
		return (0);
	else
		return (-str2[i]);
}
