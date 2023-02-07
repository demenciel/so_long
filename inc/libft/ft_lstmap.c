/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:18:35 by acouture          #+#    #+#             */
/*   Updated: 2023/01/14 17:02:00 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
