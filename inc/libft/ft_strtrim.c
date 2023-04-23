/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:56:47 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:42:35 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *@brief Creates a new string with leading and trailing characters 
 	removed from a given string. The leading and trailing characters 
	are determined by a given set of characters.
 *@param s1 The string to remove characters from.
 *@param set The set of characters to remove.
 *@return The new string with leading and trailing characters removed.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	new_str = (char *)malloc((end - start) + 1 * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1 + start, end - start + 1);
	return (new_str);
}
