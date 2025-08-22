/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:22:10 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/22 21:17:28 by srogozin         ###   ########.fr       */
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
	image = "image/player3.xmp";
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
	image = "image/wall.xmp";
	wall = mlx_xpm_file_to_image(game->mlx_ptr, image, &width, &height);
	if (wall == NULL)
		return (NULL);
	return (wall);
}

int	load_textures(t_game *game)
{
	game->textures.player = player_texture(game);
	if (game->textures.player == NULL)
		return (0);
	game->textures.wall = wall_texture(game);
	if (game->textures.wall == NULL)
		return (0);
	return (1);
}
