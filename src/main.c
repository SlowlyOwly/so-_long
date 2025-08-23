/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:51:20 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/23 18:03:38 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*mlx_ptr(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		ft_printf("Error: Can not initialize MiniLibX.\n");
		return (NULL);
	}
	ft_printf("MiniLibiX initialized.\n");
	return (mlx_ptr);
}

void	*win_ptr(void *mlx_ptr)
{
	void	*win_ptr;
	int		width;
	int		height;
	char	*window_title;

	width = 1200;
	height = 400;
	window_title = "So_long";
	win_ptr = mlx_new_window(mlx_ptr, width, height, window_title);
	if (win_ptr == NULL)
	{
		ft_printf("Error: Can not generate new window.\n");
		return (NULL);
	}
	ft_printf("New window initialized.\n");
	return (win_ptr);
}

void	free_resources(t_game *game)
{
	ft_printf("Exiting loop and free memory.\n");
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
}

static void	start_game(t_game *game)
{
	game->mlx_ptr = mlx_ptr();
	game->win_ptr = win_ptr(game->mlx_ptr);
	ft_printf("Initialize loop for MiniLibX.\n");
	setup_hooks(game);
	load_textures(game);
	draw_map(game);
	mlx_loop(game->mlx_ptr);
	free_resources(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nNot given map name.\n");
		return (1);
	}
	game.map = load_map(argv[1]);
	if (game.map == NULL)
		return (0);
	if (map_checker(game.map) != 1)
	{
		free(game.map);
		return (1);
	}
	start_game(&game);
	return (0);
}
