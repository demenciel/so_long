/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:00:32 by acouture          #+#    #+#             */
/*   Updated: 2023/02/05 09:41:44 by utilisateur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strchr_get(char *str, int c);
size_t	ft_strlen_get(char *str);
char	*ft_strjoin_get(char *s1, char *s2);
char	*read_saved(int fd, char *saved);
char	*get_next_line(int fd);
char	*get_line_out(char *saved);
char	*read_new_saved(char *saved);
char	*malloc_join(char *saved, char *buf);

#endif