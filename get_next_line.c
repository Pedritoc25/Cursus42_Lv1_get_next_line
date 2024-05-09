/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcabanas <pcabanas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:53:44 by pcabanas          #+#    #+#             */
/*   Updated: 2024/05/09 15:31:44 by pcabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*p_buffer;
	ssize_t		bytes;
	int			i;
	static char	*still;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	p_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!p_buffer)
		return (NULL);
	bytes = read(fd, p_buffer, BUFFER_SIZE);
	p_buffer[bytes] = '\0';
	free(p_buffer);
	return (bytes);
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
