/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:53:33 by pcabanas          #+#    #+#             */
/*   Updated: 2024/08/26 11:04:49 by pcabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

char	*get_next_line(int fd);

size_t	ft_strlen(char *s);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strchr(char *s, int c);

char	*ft_strjoin(char *dst, char *src);

char	*ft_substr(char *s, unsigned int start, size_t len);

#endif