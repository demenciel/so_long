/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:48:43 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:05:54 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the parameter is a printable character
 * @param c Character to be checked
 * @return 1 if true, 0 if false
*/
int	ft_isprint(int c)
{
	return ((c >= 32 && c <= 126));
}
