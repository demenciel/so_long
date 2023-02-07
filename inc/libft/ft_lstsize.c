/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:40:18 by acouture          #+#    #+#             */
/*   Updated: 2023/01/14 15:42:11 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// compter le nombre d'éléments dans la liste
int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = lst;
	if (temp == NULL)
		return (count);
	while (temp->next != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (temp->next == NULL)
		count++;
	return (count);
}
