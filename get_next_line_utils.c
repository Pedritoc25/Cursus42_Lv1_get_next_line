/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:48:23 by pcabanas          #+#    #+#             */
/*   Updated: 2024/05/17 12:26:55 by pcabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//calculate the length of a string
size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

//allocate and free dynamic memory
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_bytes;
	void	*result;

	if (size != 0 && nmemb > (SIZE_MAX / size))
		return (NULL);
	total_bytes = nmemb * size;
	result = malloc(total_bytes);
	if (result != NULL)
		ft_bzero(result, total_bytes);
	return (result);
}

//locate a substring in a string
char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

static char	*ft_mystrcat(const char *dst, const char *src)
{
	size_t	i;
	char	*s;
	size_t	s_len;

	s = (char *)ft_calloc((ft_strlen(dst) + ft_strlen(src) + 1), sizeof(char));
	if (!s)
	{
		return (NULL);
	}
	i = 0;
	s_len = 0;
	while (dst[i] != '\0')
	{
		s[i] = dst[i];
		i++;
	}
	s_len = ft_strlen(s);
	i = 0;
	while (src[i] != '\0')
	{
		s[s_len + i] = src[i];
		i++;
	}
	return (s);
}

//combine elements
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s = ft_mystrcat(s1, s2);
	if (s == NULL)
		return (NULL);
	else
		return ((char *)s);
}
