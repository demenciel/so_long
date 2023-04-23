/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:55:42 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:21:25 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check for a given character in a given string up to a certain size
 * @param s A pointer to the memory block
 * @param c Character to be found
 * @param n The size of the memory block to be checked
 * @return A pointer to the first occurrence of the character in the 
 	memory block, or NULL if not found.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned int		i;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
