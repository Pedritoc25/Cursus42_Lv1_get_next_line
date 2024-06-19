/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:53:33 by pcabanas          #+#    #+#             */
/*   Updated: 2024/06/19 12:57:48 by pcabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
//# include <stdio.h> //BORRAR

char	*get_next_line(int fd);

size_t	ft_strlen(char *s);

char	*ft_strdup(char *s);

void	*ft_memmove(void *dest, const void *src, size_t n);

char	*ft_strchr(char *s, int c);

void	*ft_calloc(size_t nmemb, size_t size);

#endif