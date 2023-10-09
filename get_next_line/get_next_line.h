/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:47:20 by cbolat            #+#    #+#             */
/*   Updated: 2023/10/10 00:11:58 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_left_to_right(int fd, char *d_line);
char	*ft_get_strchr(char *s, int c);
size_t	ft_g_strlen(char *s);
char	*ft_strconcat(char *d_line, char *buff);
char	*ft_get_line(char *d_line);
char	*ft_new_dinamic_line(char *d_line);

#endif
