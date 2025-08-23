/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_viz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:17:13 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/23 17:45:13 by srogozin         ###   ########.fr       */
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

void	draw_image(t_game *game, int col, int row)
{
	if (game->map[row][col] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures.wall, (col * 64), (row * 64));
	if (game->map[row][col] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures.floor, (col * 64), (row * 64));
	if (game->map[row][col] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures.player, (col * 64), (row * 64));
	if (game->map[row][col] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures.collectible, (col * 64), (row * 64));
	if (game->map[row][col] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures.exit, (col * 64), (row * 64));
}

void	draw_map(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (game->map[row] != NULL)
	{
		while (game->map[row][col] != '\0')
		{
			draw_image(game, col, row);
			col++;
		}
		col = 0;
		row++;
	}
}
