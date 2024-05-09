/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:48:23 by pcabanas          #+#    #+#             */
/*   Updated: 2024/05/09 12:51:04 by pcabanas         ###   ########.fr       */
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

//duplicate a string
char	*ft_strdup(char *s)
{
	char	*s2;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

//removes "set" characters from the beginning and end of string
char	*ft_strtrim(char *s1, char *set)
{
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	if (s1[0] != '\0')
	{
		while (ft_strchr(set, s1[i]) != 0)
			i++;
		while (ft_strrchr(set, s1[len]) != 0)
			len--;
		return (ft_substr(s1, i, (len - i) + 1));
	}
	return (ft_strdup(s1));
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
