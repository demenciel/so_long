/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:20:12 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:22:14 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two memory blocks of a certain size and returns the 
 * difference between the first differing byte in the two blocks.
 * Returns 0 if the blocks are equal.
 * @param s1 The first memory block to compare.
 * @param s2 The second memory block to compare.
 * @param n The size of the memory blocks to compare.
 * @return The difference between the first differing byte in the two blocks,
 * or 0 if they are equal.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
