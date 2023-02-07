/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:14:19 by acouture          #+#    #+#             */
/*   Updated: 2023/01/13 10:08:27 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	len = ft_strlen(str);
	if (!str)
		return (NULL);
	while (len > 0)
	{
		if (str[len] == (char)c)
			return ((char *)str + len);
		len--;
	}
	if (str[len] == (char)c)
		return ((char *)str + len);
	return (NULL);
}
