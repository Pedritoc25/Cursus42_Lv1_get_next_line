/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:53:44 by pcabanas          #+#    #+#             */
/*   Updated: 2024/08/23 20:19:09 by pcabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
bytes_read es el numero de caracteres que se leen en una pasada
line es el texto que devuelve getNextLine
buffer_text es el buffer, donde se encuentra lo que has leido del fd
stable es la variable estática
temp es la variable temporal para liberar la estatica cuando hga strjoin
*/

char	*trim_static(char *stable, char *line)
{
	char	*new_stable;

	if (!stable || !line)
		return (NULL);
	new_stable = ft_substr(stable, ft_strlen(line), ft_strlen(stable)
			- ft_strlen(line));
	free (stable);
	stable = NULL;
	return (new_stable);
}

char	*read_text(int fd, char *buffer_text, char *stable)
{
	char	*temp;
	size_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer_text, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (stable[0] != '\0')
				return (stable);
			return (free(stable), NULL);
		}
		buffer_text[bytes_read] = '\0';
		temp = stable;
		stable = ft_strjoin(stable, buffer_text);
		free(temp);
		temp = NULL;
		if (!stable)
			return (NULL);
		if (ft_strchr(stable, '\n'))
			break ;
	}
	return (stable);
}

char	*shape_line(char *stable)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (stable[i] != '\n' && stable[i] != '\0')
		i++;
	if (i > 0)
		temp = ft_substr(stable, 0, &stable[i] - stable + 1);
	else
		temp = (ft_substr(stable, 0, ft_strlen(stable)));
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buffer_text;
	char		*line;
	static char	*stable;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer_text = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer_text)
		return (NULL);
	if (!ft_strchr(stable, '\n'))
		stable = read_text(fd, buffer_text, stable);
	if (!stable)
		return (free(buffer_text), NULL);
	line = shape_line(stable);
	if (!line)
		return (free(buffer_text), NULL);
	stable = trim_static(stable, line);
	free (buffer_text);
	buffer_text = NULL;
	return (line);
}


int	main(void) //COMENTAR
{
	int		fd;
	char	*line;

	fd = open("prueba.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			break ;
		free (line);
		line = NULL;
	}
 //BORRAR
	close(fd);
	return (0);
}
