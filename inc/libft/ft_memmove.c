/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:49:21 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:20:54 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**

* @brief Copies a memory block to another memory block of a given size. 
 * The memory blocks may overlap. Returns a pointer to the
 * destination memory block.
 * @param dst The destination memory block.
 * @param src The source memory block.
 * @param len The size of the memory blocks to copy.
 * @return A pointer to the destination memory block.
*/
void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned int		i;
	unsigned char		*dest;
	const unsigned char	*source;

	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dest < source)
		return (ft_memcpy(dest, src, len));
	else
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = source[i - 1];
			i--;
		}
	}
	return (dst);
}
