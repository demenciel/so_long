/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:18:35 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:23:39 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Iterates over a linked list, applies a given function 
 * to each element's content, and creates a new linked list with 
 * the modified content. Deletes the original list if the content
 * modification or list creation fails. Returns a pointer to the new list.
 * @param lst The linked list to iterate over.
 * @param f The function to apply to each element's content.
 * @param del The function to delete an element's content.
 * @return A pointer to the new list, or NULL if content modification 
 	or list creation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*new;
	void	*temp;

	if (!lst || !f)
		return (NULL);
	n_lst = NULL;
	while (lst)
	{
		temp = f(lst->content);
		new = ft_lstnew(temp);
		if (!new)
		{
			free(temp);
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&n_lst, new);
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (n_lst);
}
