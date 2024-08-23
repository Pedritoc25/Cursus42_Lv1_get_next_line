/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:53:33 by pcabanas          #+#    #+#             */
/*   Updated: 2024/08/23 02:41:46 by pcabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h> //BORRAR

char	*get_next_line(int fd);

size_t	ft_strlen(char *s);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strchr(char *s, int c);

char	*ft_strjoin(char *dst, char *src);

char	*ft_substr(char *s, unsigned int start, size_t len);

#endif