/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:00:56 by acouture          #+#    #+#             */
/*   Updated: 2023/02/05 09:42:27 by utilisateur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_get(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr_get(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

char	*malloc_join(char *saved, char *buf)
{
	char	*str;

	str = malloc((((ft_strlen_get(saved)) + ft_strlen_get(buf)) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*ft_strjoin_get(char *saved, char *buf)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!saved)
	{
		saved = (char *)malloc(sizeof(char) * 1);
		saved[0] = '\0';
	}
	if (!saved || !buf)
		return (NULL);
	str = malloc_join(saved, buf);
	while (saved[i])
	{
		str[i] = saved[i];
		i++;
	}
	while (buf[j])
		str[i++] = buf[j++];
	str[i] = '\0';
	free(saved);
	return (str);
}

char	*get_line_out(char *saved)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!saved[i])
		return (NULL);
	while (saved[i] != '\0' && saved[i] != '\n')
		i++;
	i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
		str[j++] = saved[i++];
	if (saved[i] == '\n')
		str[j++] = saved[i++];
	str[j] = '\0';
	return (str);
}
