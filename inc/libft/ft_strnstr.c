/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:50:11 by acouture          #+#    #+#             */
/*   Updated: 2023/01/13 10:34:51 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (!needle || !haystack)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack != '\0' && len-- >= needle_len)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle,
				needle_len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
