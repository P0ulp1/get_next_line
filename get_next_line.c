/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:23:48 by phautena          #+#    #+#             */
/*   Updated: 2024/06/13 15:52:49 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line(int fd)
{
	static char	*line = "";
	char		*return_line;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = ft_strjoin(line, read_until_n(fd));
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	return_line = ft_substr(line, 0, i + 1);
	line = ft_substr(line, i + 1, ft_strlen(line));
	return (return_line);
}

char	*read_until_n(int fd)
{
	int		bytes_red;
	char	*current_line;
	char	*buffer;

	current_line = "";
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (ft_strchr(current_line, 10) == NULL)
	{
		bytes_red = read(fd, buffer, BUFFER_SIZE);
		if (bytes_red <= 0)
		{
			buffer[bytes_red] = '\0';
			free(buffer);
			return (current_line);
		}
		buffer[bytes_red] = '\0';
		current_line = ft_strjoin(current_line, buffer);
	}
	free(buffer);
	return (current_line);
}
