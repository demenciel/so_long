/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:41 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:11:45 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies a memory block to another memory block up to a certain size
 * @param dst The copy of the memory block
 * @param src The memory block to be copied
 * @param n The size of the memory block to be copied
 * @return A pointer to the new copy of the memory block
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*source;

	if (!src || !dst)
		return (dst);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
