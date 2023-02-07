/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:03:33 by acouture          #+#    #+#             */
/*   Updated: 2023/01/13 10:00:52 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
