/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:49:49 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/08 19:44:41 by srogozin         ###   ########.fr       */
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
void	map_open(int *map)
{
	map = open("./maps/map1.ber", O_RDONLY);
	if (*map == -1)
	{
		ft_printf("Error\nCan not open map file.\n");
		exit(1);
	}
}

char	**load_map(char *map_file)
{
	char	**map_data;
	int		map;
	char	*line;
	int		i;
	char	**temp_map;

	i = 0;
	map_data = NULL;
	map_open(&map);
	line = get_next_line(map);
	while (1)
{
    line = get_next_line(map);
    if (line == NULL)
        break;

    temp_map = ft_realloc(map_data, (i + 2) * sizeof(char *));
    if (temp_map == NULL)
        return (NULL);
    map_data = temp_map;
    map_data[i] = line;
    i++;
}
	map_data[i] = NULL;
	close(map);
	return (map_data);
}
