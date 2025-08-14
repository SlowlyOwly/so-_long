/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:35:42 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/14 20:23:28 by srogozin         ###   ########.fr       */
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
		ft_printf("Error\nWrong map format.\n");
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

int	map_wall_checker(char **map_data)
{
	int	i;
	int	line_num;

	i = 0;
	line_num = 
	while (map_data[0][i] != '\0' || map_data[line_num - 1][i] != '\0')
	{
		if (map_data[0][i] != '1' || map_data[line_num - 1][i] != '\0')
		{
			ft_printf("Error\nMap has break in wall.\n");
			return (0);
		}
		i++;
	}
	return (1);
}
