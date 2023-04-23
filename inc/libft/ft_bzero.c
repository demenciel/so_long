/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:04:22 by acouture          #+#    #+#             */
/*   Updated: 2023/04/21 16:53:03 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Set a memory block to 0
 * This function sets the first 'n' bytes pointed to by s to zero
 * @param s Pointer to the memory area to be zeroed
 * @param n Number of bytes to be zeroed
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	if (!s)
		return ;
	p = s;
	while (n--)
		*p++ = 0;
}
