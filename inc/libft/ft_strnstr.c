/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:50:11 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:39:11 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Searches a string for a substring of a given length,
 	up to a maximum length, and returns a pointer to the first occurrence of
	the substring in the string. If the substring is not found, returns NULL.
 * @param haystack The string to search in.
 * @param needle The substring to search for.
 * @param len The maximum length to search up to.
 * @return A pointer to the first occurrence of the substring in the string, 
 	or NULL if not found.
*/
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
