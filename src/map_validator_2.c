/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:24:24 by srogozin          #+#    #+#             */
/*   Updated: 2025/09/10 18:01:40 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	left_wall_checker(char **map_data)
{
	int	num_lines;

	num_lines = line_num_checker(map_data);
	while (map_data[num_lines] != NULL)
	{
		if (map_data[num_lines][0] != '1')
		{
			ft_printf("Error\n Map has brak in left wall.\n");
			return (0);
		}
		num_lines++;
	}
	return (1);
}

int	right_wall_chacker(char **map_data)
{
	int	line_lenght;
	int	i;

	i = 0;
	line_lenght = ft_strlen(map_data[0]);
	while (map_data[i] != NULL)
	{
		if (map_data[i][line_lenght - 1] != '1')
		{
			ft_printf("Error\nMap has break in right wall.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	player_checker(char **map_data)
{
	int	player;
	int	line;
	int	i;

	player = 0;
	line = 0;
	while (map_data[line] != NULL)
	{
		i = 0;
		while (map_data[line][i] != '\0')
		{
			if (map_data[line][i] == 'P')
				player++;
			i++;
		}
		line++;
	}
	if (player > 1 || player < 1)
	{
		ft_printf("Error\nWrong number of players on the map\n");
		return (0);
	}
	return (1);
}

int	exit_checker(char **map_data)
{
	int	exit;
	int	line;
	int	i;

	exit = 0;
	line = 0;
	while (map_data[line] != NULL)
	{
		i = 0;
		while (map_data[line][i] != '\0')
		{
			if (map_data[line][i] == 'E')
				exit++;
			i++;
		}
		line++;
	}
	if (exit < 1 || exit > 1)
	{
		ft_printf("Error\nWrong number of exit\n");
		return (0);
	}
	return (1);
}

int	colectible_checker(char **map_data)
{
	int	colectible;
	int	line;
	int	i;

	colectible = 0;
	line = 0;
	while (map_data[line] != NULL)
	{
		i = 0;
		while (map_data[line][i] != '\0')
		{
			if (map_data[line][i] == 'C')
				colectible++;
			i++;
		}
		line++;
	}
	if (colectible < 1)
	{
		ft_printf("Error\nNo collectible on map.\n");
		return (0);
	}
	return (1);
}
