/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:50:48 by acouture          #+#    #+#             */
/*   Updated: 2023/01/13 10:00:18 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dstlen;
	size_t			srclen;
	unsigned int	i;
	unsigned int	n;

	n = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = dstlen;
	if (!src || !dst)
		return (0);
	if (dstsize == 0)
		return (srclen);
	if (dstsize < dstlen)
		return (srclen + dstsize);
	else
	{
		while (src[n] && (dstlen + n) < dstsize)
			dst[i++] = src[n++];
		if ((dstlen + n) == dstsize && dstlen < dstsize)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (dstlen + srclen);
	}
}
