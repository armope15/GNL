/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armolina < armolina@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:04:42 by armolina          #+#    #+#             */
/*   Updated: 2024/06/11 23:04:42 by armolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	buffer = read_buffer(fd, buffer);
	line = read_line(buffer);
	clean_buffer(buffer);
	if(line == NULL){
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

char	*read_buffer(int fd, char *buffer)
{
	char	temp[BUFFER_SIZE + 1];
	int		bytes_read;

	while (find_end_line(buffer) == -1)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (buffer);
		temp[bytes_read] = '\0';
		buffer = ft_strcat(buffer, temp);
	}
	return (buffer);
}

char	*read_line(const char *buffer)
{
	int		end_line;
	char	*line;
	int		i;

	i = 0;
	end_line = find_end_line(buffer);
	if (end_line == -1)
		return (NULL);
	line = malloc(end_line + 2);
	if (!line)
		return (NULL);
	while (i <= end_line)
	{
		line[i] = buffer[i];
		i++;
	}
	line[end_line + 1] = '\0';
	return (line);
}

void	clean_buffer(char *buffer)
{
	int	end_line;
	int	i;

	end_line = find_end_line(buffer);
	if (end_line != -1)
	{
		i = 0;
		while (buffer[end_line + 1 + i])
		{
			buffer[i] = buffer[end_line + 1 + i];
			i++;
		}
		buffer[i] = '\0';
	}
}
