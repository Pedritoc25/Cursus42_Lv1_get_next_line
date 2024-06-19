/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:53:44 by pcabanas          #+#    #+#             */
/*   Updated: 2024/06/19 10:03:31 by pcabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*p_buffer;
	char		*line;
	ssize_t		bytes;
	static char	*still;

	i = 0;
	p_buffer = NULL;
	bytes = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	p_buffer = (char *)ft_calloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!p_buffer)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read(fd, p_buffer, BUFFER_SIZE);
		if(statica == NULL)
			statica = calloc(1)
		tem = Statica
		sta = strjoin(tem, buf)
		free temp
		tem = NULL
		//si te devuelve puntero, para
		ft_strchr(p_buffer, '\n');
	}
	free(p_buffer);
	p_buffer = NULL;
	return (line);
}

int	main(void) //COMENTAR
{
	int		fd;
	int		line;

	fd = open("prueba.txt", O_RDONLY | O_CREAT, 0666);
	line = get_next_line(fd);
	printf("\n%i", line); //BORRAR
	close(fd);
	return (0);
}
