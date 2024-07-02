/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:48:23 by pcabanas          #+#    #+#             */
/*   Updated: 2024/07/02 18:47:45 by pcabanas         ###   ########.fr       */
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
	size_t			total_bytes;
	void			*result;
	size_t			i;
	unsigned char	*uc;

	if (size != 0 && nmemb > (__SIZE_MAX__ / size))
		return (NULL);
	total_bytes = nmemb * size;
	result = malloc(total_bytes);
	if (result != NULL)
	{
		i = 0;
		uc = (unsigned char *)result;
		while (i < total_bytes)
		{
			uc[i] = '\0';
			i++;
		}
	}
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

//combine elements
char	*ft_strjoin(char *dst, char *src)
{
	size_t	i;
	char	*s;

	if (!dst || !src)
		return (NULL);
	s = (char *)ft_calloc((ft_strlen(dst) + ft_strlen(src) + 1), sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (dst[i] != '\0')
	{
		s[i] = dst[i];
		i++;
	}
	while (*src != '\0')
	{
		s[i] = *src;
		i++;
		src++;
	}
	if (s == NULL)
		return (NULL);
	else
		return ((char *)s);
}

//copy memory area and prevents overlapping
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*uc_dest;

	i = 0;
	uc_dest = (unsigned char *)dest;
	if (!(dest || src))
		return (NULL);
	if (uc_dest <= (unsigned char *)src || uc_dest >= (unsigned char *)src + n)
	{
		while (i < n)
		{
			uc_dest[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			uc_dest[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}
