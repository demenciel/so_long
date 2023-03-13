/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:11:42 by acouture          #+#    #+#             */
/*   Updated: 2023/01/11 14:19:08 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int		j;
	int		i;
	char	last;

	i = 0;
	j = 0;
	last = c;
	while (str[i])
	{
		if (last == c && str[i] != c)
			j++;
		last = str[i];
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			k = i;
			while (s[i] && s[i] != c)
				i++;
			tab[j++] = ft_substr(s, k, i - k);
		}
	}
	tab[j] = NULL;
	return (tab);
}
