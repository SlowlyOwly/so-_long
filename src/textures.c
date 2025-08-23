/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:22:10 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/23 16:17:08 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*player_texture(t_game *game)
{
	int			height;
	int			width;
	void		*player;
	char		*image;

	height = 64;
	width = 64;
	image = "images/player3.xpm";
	player = mlx_xpm_file_to_image(game->mlx_ptr, image, &width, &height);
	if (player == NULL)
		return (NULL);
	return (player);
}

void	*wall_texture(t_game *game)
{
	int		height;
	int		width;
	void	*wall;
	char	*image;

	height = 64;
	width = 64;
	image = "images/wall.xpm";
	wall = mlx_xpm_file_to_image(game->mlx_ptr, image, &width, &height);
	if (wall == NULL)
		return (NULL);
	return (wall);
}

void	*collectibe_texture(t_game *game)
{
	int		height;
	int		width;
	void	*collectibe;
	char	*image;

	height = 64;
	width = 64;
	image = "images/collectible.xpm";
	collectibe = mlx_xpm_file_to_image(game->mlx_ptr, image, &width, &height);
	if (collectibe == NULL)
		return (NULL);
	return (collectibe);
}

void	*floor_texture(t_game *game)
{
	int		height;
	int		width;
	void	*floor;
	char	*image;

	height = 64;
	width = 64;
	image = "images/floor.xpm";
	floor = mlx_xpm_file_to_image(game->mlx_ptr, image, &width, &height);
	if (floor == NULL)
		return (NULL);
	return (floor);
}

void	*exit_texture(t_game *game)
{
	int		height;
	int		width;
	void	*exit;
	char	*image;

	height = 64;
	width = 64;
	image = "images/exit2.xpm";
	exit = mlx_xpm_file_to_image(game->mlx_ptr, image, &width, &height);
	if (exit == NULL)
		return (NULL);
	return (exit);
}

