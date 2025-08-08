/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:59:11 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/08 15:50:20 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	free_resources(game);
	exit(0);
	return (0);
}

int esc_key(int keycode, t_game *game)
{
	ft_printf("Nacisnieto klawisz: %d\n", keycode);
	if (keycode == 65307)
	{
		free_resources(game);
		exit(0);
	}
	return(0);
}
void	setup_hooks(t_game *game)
{
	mlx_hook(game->win_ptr, 17, 0, close_window, game);
	mlx_key_hook(game->win_ptr, esc_key, game);
}
