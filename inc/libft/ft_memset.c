/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:05:18 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:15:32 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Replace the content of a memory block by a given parameter up to a
 * certain size.
 * @param str Pointer to the memory block.
 * @param i Content to replace the content of the pointer
 * @param len Size of block to be replaced
 * @return A pointer to the memory block
*/
void	*ft_memset(void *str, int i, size_t len)
{
	size_t	j;

	j = 0;
	if (str)
	{
		while (j < len)
		{
			*((unsigned char *)str + j) = (unsigned char)i;
			j++;
		}
		return (str);
	}
	return (NULL);
}
