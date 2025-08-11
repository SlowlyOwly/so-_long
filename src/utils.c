/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:49:49 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/11 18:37:49 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	char	*new_ptr;
	size_t	ptr_size;

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	ptr_size = ft_strlen(ptr);
	if (new_size < ptr_size)
		ptr_size = new_size;
	ft_memcpy(new_ptr, ptr, ptr_size);
	free(ptr);
	return (new_ptr);
}

int	map_open(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nCan not open map file.\n");
		exit(1);
	}
	return (fd);
}

char	**load_map(char *map_file)
{
	char	**map_data;
	int		map;
	char	*line;
	int		i;

	i = 0;
	map_data = NULL;
	map = map_open(map_file);
	while (1)
	{
		line = get_next_line(map);
		if (line == NULL)
			break ;
		map_data = ft_realloc(map_data, (i + 2) * sizeof(char *));
		if (map_data == NULL)
			return (NULL);
		map_data[i] = line;
		i++;
	}
	map_data[i] = NULL;
	close(map);
	return (map_data);
}
