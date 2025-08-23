/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_viz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:17:13 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/23 16:17:34 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_textures(t_game *game)
{
	game->textures.player = player_texture(game);
	if (game->textures.player == NULL)
		return (0);
	game->textures.wall = wall_texture(game);
	if (game->textures.wall == NULL)
		return (0);
	game->textures.collectible = collectibe_texture(game);
	if (game->textures.collectible == NULL)
		return (0);
	game->textures.floor = floor_texture(game);
	if (game->textures.floor == NULL)
		return (0);
	game->textures.exit = exit_texture(game);
	if (game->textures.exit == NULL)
		return (0);
	return (1);
}

