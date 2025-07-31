/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:51:20 by srogozin          #+#    #+#             */
/*   Updated: 2025/07/31 19:43:08 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

void *mlx_ptr()
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		ft_printf("Error: Can not initialize MiniLibX.\n");
		return(NULL);
	}
	ft_printf("MiniLibiX initialized.\n");
	return(mlx_ptr);
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
		return(NULL);
	}
	ft_printf("New window initialized.\n");
	return(win_ptr);
}

void start_game()
{
	void	*mlx;
	void	*win;
	
	mlx = mlx_ptr();
	win = win_ptr(mlx);
	ft_printf("Initialize loop for MiniLibX.\n");
	mlx_loop(mlx);
	ft_printf("Exiting loop and free memory.\n");
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	
}

int	main()
{
	
	start_game();

	return(0);
}
