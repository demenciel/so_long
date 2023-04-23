/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:39:27 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 12:47:51 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Adds a given node to the end of the list
 * @param lst The list to add the node to
 * @param new The node to add to the list
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst)
	{
		if (*lst)
		{
			temp = ft_lstlast(*lst);
			temp->next = new;
		}
		else
			*lst = new;
	}
}
