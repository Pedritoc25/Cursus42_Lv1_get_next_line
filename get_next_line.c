/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:53:44 by pcabanas          #+#    #+#             */
/*   Updated: 2024/07/16 13:05:54 by pcabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
bytes es el numero de caracteres que se leen en una pasada
line es el texto que devuelve getNextLine
buffer_text es el buffer, donde se encuentra lo que has leido del fd
stable es la variable estática
temp es la variable temporal para liberar la estatica cuando hga strjoin
*/

char	*get_next_line(int fd)
{
	char		*buffer_text;
	char		*line = NULL;
	char		*temp = NULL;
	ssize_t		bytes;
	static char	*stable;

	buffer_text = NULL;
	bytes = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer_text = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer_text)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read(fd, buffer_text, BUFFER_SIZE);
		if(stable == NULL)
			stable = ft_calloc(1, sizeof(char*));
		//buscar '\n' en stable
		temp = stable;
		stable = ft_strjoin(stable, buffer_text);
		free(temp);
		temp = stable;
		if (ft_strchr(stable, '\n'))
		{
			//funcion substr
			line = ft_substr(stable, 0, ft_strchr(stable, '\n') - stable + 1);
			
			//recortar estatica
			stable = subtring (stable, len line, len stable - len line);
			
			break;
		}
		//temp = stable;
		//stable = strjoin(temp, buffer_text);
		//si te devuelve puntero, para
		free (temp);
	}
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
