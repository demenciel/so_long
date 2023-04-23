/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:17:06 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:35:42 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *@brief Creates a new string and applies the f function to the characters
	of the new string
 * @param s String
 * @param f The function to be applied to the content of the string
 * @return A pointer to the newly created string
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*n_str;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	n_str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!n_str)
		return (NULL);
	while (i < s_len)
	{
		n_str[i] = f(i, s[i]);
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
