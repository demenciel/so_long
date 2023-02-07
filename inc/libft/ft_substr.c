/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:28:35 by acouture          #+#    #+#             */
/*   Updated: 2023/01/13 13:16:20 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*n_str;

	if (!str)
		return (NULL);
	s_len = ft_strlen(str);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	n_str = malloc(len + 1);
	if (!n_str)
		return (NULL);
	ft_memcpy(n_str, str + start, len);
	n_str[len] = '\0';
	return (n_str);
}
