/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:14:19 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:40:49 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *@brief Checks for a certain character in a string
 *@param str String
 *@param c Character to be found
 *@return A pointer to the character that was found, or NULL if the character
	was not found or if the string is empty.
*/
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
