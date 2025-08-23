/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:35:42 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/23 18:14:56 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_shape_checker(char **map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (map_data[i] != NULL)
		i++;
	if (i < 3 || ft_strlen(map_data[0]) < 3)
	{
		ft_printf("Error\nWrong map shape.\n");
		ft_printf("Num of rows: %d\n", i);
		ft_printf("Line len: %d\n", ft_strlen(map_data[0]));
		return (0);
	}
	while (j < i)
	{
		if (ft_strlen(map_data[0]) != ft_strlen(map_data[j]))
		{
			ft_printf("Error.\nMap line %d have wrong size.", j);
			return (0);
		}
		j++;
	}
	return (1);
}

int	line_num_checker(char **map_data)
{
	int	line_num;

	line_num = 0;
	while (map_data[line_num] != NULL)
		line_num++;
	return (line_num);
}

int	first_line_wall_checker(char **map_data)
{
	int	i;

	i = 0;
	while (map_data[0][i] != '\0')
	{
		if (map_data[0][i] != '1')
		{
			ft_printf("Error\nMap has break in top wall\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	last_line_wall_checker(char **map_data)
{
	int	i;
	int	line_num;

	i = 0;
	line_num = line_num_checker(map_data);
	while (map_data[line_num - 1][i] != '\0')
	{
		if (map_data[line_num - 1][i] != '1')
		{
			ft_printf("Error\nMap has break in bottom wall.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	map_checker(char **map_data)
{
	if (map_shape_checker(map_data) != 1)
		return (0);
	if (first_line_wall_checker(map_data) != 1)
		return (0);
	if (last_line_wall_checker(map_data) != 1)
		return (0);
	if (left_wall_checker(map_data) != 1)
		return (0);
	if (right_wall_chacker(map_data) != 1)
		return (0);
	if (player_checker(map_data) != 1)
		return (0);
	if (exit_checker(map_data) != 1)
		return (0);
	if (colectible_checker(map_data) != 1)
		return (0);
	return (1);
}
