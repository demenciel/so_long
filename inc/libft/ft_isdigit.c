/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:27:32 by acouture          #+#    #+#             */
/*   Updated: 2023/04/23 13:05:40 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the parameter is a number
 * @param c Character to be checked
 * @return 1 if true, 0 if false
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
