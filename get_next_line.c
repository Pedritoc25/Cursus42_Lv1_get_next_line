/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:53:44 by pcabanas          #+#    #+#             */
/*   Updated: 2024/08/05 10:28:02 by pcabanas         ###   ########.fr       */
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

char	*leyendo(int fd, char *static)
{
	
}

char	*get_next_line(int fd)
{
	char		*buffer_text;
	char		*line;
	char		*temp;
	size_t		bytes_read;
	static char	*stable;


	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);

	stable = leyendo(fd, stable);
	if (!stable)
		return (NULL);
	
	buffer_text = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer_text)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer_text, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (stable)
			{
				line = stable;
				free(stable);
			}
			break ;
		}
		temp = stable;
		stable = ft_strjoin(stable, buffer_text);
		free(temp);
		temp = stable;
		if (ft_strchr(stable, '\n'))
		{
			line = ft_substr(stable, 0, ft_strchr(stable, '\n')
					- stable + 1);
			stable = ft_substr (stable, ft_strlen(line), ft_strlen(stable)
					- ft_strlen(line));
			break ;
		}
	}
	free (temp);
	temp = NULL;
	free(buffer_text);
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
	printf("\n%s", line);
	if (!line)
		break ;
	free (line);
	line = NULL;
	}
 //BORRAR
	close(fd);
	return (0);
}
