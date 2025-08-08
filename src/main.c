/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:51:20 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/07 18:25:00 by srogozin         ###   ########.fr       */
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

	width = 800;
	height = 600;
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

static void	start_game(void)
{
	t_game	game;

	game.mlx_ptr = mlx_ptr();
	game.win_ptr = win_ptr(game.mlx_ptr);
	ft_printf("Initialize loop for MiniLibX.\n");
	setup_hooks(&game);
	mlx_loop(game.mlx_ptr);
	free_resources(&game);
}

int	main(void)
{
	start_game();
	return (0);
}
