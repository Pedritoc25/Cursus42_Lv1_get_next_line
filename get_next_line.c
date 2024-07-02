/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:53:44 by pcabanas          #+#    #+#             */
/*   Updated: 2024/07/02 20:41:26 by pcabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
bytes es el numero de caracteres que se leen en una pasada
line es el texto que devuelve getNextLine
buffer_text es el buffer, donde se encuentra lo que has leido del fd
stable es la variable estática
temp es la variable temporal
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
		temp = ft_calloc(1, sizeof(char));
		bytes = read(fd, buffer_text, BUFFER_SIZE);
		if(stable == NULL)
			stable = ft_calloc(1, sizeof(char));
		//buscar '\n' en stable
		if (ft_strchr(stable, '\n'))
		{
			temp = ft_strchr(stable, '\n');
			line = stable;
		}
		else
			stable = ft_strjoin(stable, buffer_text);
		//temp = stable;
		//stable = strjoin(temp, buffer_text);
		stable = temp;
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
	//int		line;

	fd = open("prueba.txt", O_RDONLY);
	get_next_line(fd);
//	printf("\n%i", line); //BORRAR
	close(fd);
	return (0);
}
