/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:28:18 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/11 19:09:28 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

char	*find_line(int fd, char *buffer, char *temp)
{
	ssize_t	num_of_bytes;
	char	*line;

	num_of_bytes = 1;
	while (num_of_bytes)
	{
		num_of_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_of_bytes < 0)
		{
			free(temp);
			return (NULL);
		}
		if (num_of_bytes == 0 && !temp)
			return (NULL);
		buffer[num_of_bytes] = '\0';
		if (!temp)
			temp = ft_strdup("");
		line = ft_strjoin(temp, buffer);
		free(temp);
		temp = line;
		if (!num_of_bytes || ft_strchr(temp, '\n'))
			break ;
	}
	return (temp);
}

char	*extract_line(char **temp)
{
	char	*line;
	char	*temp_line;
	int		i;

	i = 0;
	if (!*temp)
		return (NULL);
	while ((*temp)[i] && (*temp)[i] != '\n')
		i++;
	if ((*temp)[i] == '\n')
		i++;
	line = ft_substr(*temp, 0, i);
	temp_line = ft_strdup(*temp + i);
	free(*temp);
	*temp = temp_line;
	if (!*temp[0])
	{
		free(*temp);
		*temp = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*temp[1024];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (fd >= 1024)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	temp[fd] = find_line(fd, buffer, temp[fd]);
	free(buffer);
	line = extract_line(&temp[fd]);
	return (line);
}
