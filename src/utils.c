/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:49:49 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/20 17:21:13 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	map_line_checker(char *map_file)
{
	int		i;
	int		map;
	char	*line;

	i = 0;
	map = map_open(map_file);
	line = get_next_line(map);
	while (line != NULL)
	{
		i++;
		free (line);
		line = get_next_line(map);
	}
	close(map);
	return (i);
}

static void	change_last_sign(char *line)
{
	int	i;

	i = ft_strlen(line);
	if (line[i - 1] == '\n')
		line[i - 1] = '\0';
}

char	**load_map(char *map_file)
{
	char	**map_data;
	int		lines_num;
	int		i;
	int		map;
	char	*line;

	i = 0;
	lines_num = map_line_checker(map_file);
	map = map_open(map_file);
	map_data = malloc((lines_num + 1) * sizeof(char *));
	if (map_data == NULL)
		return (NULL);
	line = get_next_line(map);
	while (line != NULL)
	{
		if (i != lines_num)
			change_last_sign(line);
		map_data[i] = line;
		i++;
		line = get_next_line(map);
	}
	close (map);
	map_data[i] = NULL;
	return (map_data);
}
