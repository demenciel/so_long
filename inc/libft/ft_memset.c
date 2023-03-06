/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:05:18 by acouture          #+#    #+#             */
/*   Updated: 2023/01/13 10:24:55 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
