/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 11:23:54 by srogozin          #+#    #+#             */
/*   Updated: 2025/09/07 14:00:11 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_width(t_game *game)
{
	int	width;

	width = 0;
	while (game->map[0][width] != '\0')
		width++;
	width = width * 64;
	return (width);
}

int	win_height(t_game *game)
{
	int	height;

	height = 0;
	while (game->map[height] != NULL)
		height++;
	height = height * 64;
	return (height);
}

int	window_size_check(t_game *game)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(game->mlx_ptr, &screen_width, &screen_height);
	if (screen_width < win_width(game) || screen_height < win_height(game))
	{
		ft_printf("Map is to large to display on screen\n");
		return (0);
	}
	return (1);
}