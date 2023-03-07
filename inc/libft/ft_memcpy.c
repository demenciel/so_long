/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:41 by acouture          #+#    #+#             */
/*   Updated: 2023/03/07 09:18:18 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
