/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:53:44 by pcabanas          #+#    #+#             */
/*   Updated: 2024/09/11 12:49:36 by pcabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer_text, BUFFER_SIZE);
		if (bytes_read <= 0 || !stable)
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

	if (!stable)
		return (NULL);
	i = 0;
	while (stable[i] != '\n' && stable[i] != '\0')
		i++;
	if (stable[i] == '\n')
		temp = ft_substr(stable, 0, i + 1);
	else
		temp = ft_substr(stable, 0, i);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buffer_text;
	char		*line;
	static char	*stable[_SC_OPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= _SC_OPEN_MAX)
		return (NULL);
	buffer_text = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer_text)
		return (NULL);
	if (!stable[fd])
		stable[fd] = (char *)ft_calloc(sizeof(char), 1);
	if (!ft_strchr(stable[fd], '\n'))
		stable[fd] = read_text(fd, buffer_text, stable[fd]);
	if (!stable[fd])
		return (free(buffer_text), NULL);
	line = shape_line(stable[fd]);
	if (!line)
		return (free(buffer_text), NULL);
	stable[fd] = trim_static(stable[fd], line);
	free (buffer_text);
	buffer_text = NULL;
	return (line);
}
/*#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int	fd;
	char	*line;
	int	l;

	
	for (int i = 1; i < argc; i++)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			return (0);
		l = 1;
		printf("Get_Next_Line de: %s \n", argv[i]);
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
			{
				printf("Fin del fichero\n");
				free(line);
				break;
			}
			printf("[%d]: %s", l, line);
			l++;
			free(line);
		}
		close(fd);
	}
	return (0);
}*/