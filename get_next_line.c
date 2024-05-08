/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:53:44 by pcabanas          #+#    #+#             */
/*   Updated: 2024/05/08 14:57:12 by pcabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*p_buffer;
	char	bytes;

	p_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!p_buffer || BUFFER_SIZE < 0)
	{
		return (-1);
	}
	bytes = read(fd, p_buffer, BUFFER_SIZE);
	printf("%s", p_buffer); //BORRAR
	return (bytes);

	/*buffer malloc = buffersize;
	bucle hasta 0 read	(fd, buf, 42);
	guardar lectura en variable statica;*/
}

int	main(void)
{
	int		fd;
	int		line;

	fd = open("prueba.txt", O_RDONLY | O_CREAT, 0666);
	line = get_next_line(fd);
	printf("\n%i", line);
	close(fd);
	return (0);
}
