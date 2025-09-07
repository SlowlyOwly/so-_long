/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 11:23:54 by srogozin          #+#    #+#             */
/*   Updated: 2025/09/07 12:08:04 by srogozin         ###   ########.fr       */
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
