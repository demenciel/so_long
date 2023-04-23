/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:03:33 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:32:51 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies a string to another string and returns the 
 	size of the original string.
 * The maximum number of characters that can be copied is limited by dstsize.
 * @param dst The string to copy to.
 * @param src The string to copy.
 * @param dstsize The maximum size of the destination string.
 * @return The size of the original string.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	size_t			srcsize;

	i = 0;
	if (!dst || !src)
		return (0);
	srcsize = ft_strlen(src);
	if (dstsize == 0)
		return (srcsize);
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize < srcsize)
		dst[dstsize - 1] = '\0';
	else if (dstsize != 0)
		dst[i] = '\0';
	return (srcsize);
}
