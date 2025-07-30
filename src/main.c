/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:51:20 by srogozin          #+#    #+#             */
/*   Updated: 2025/07/30 19:00:18 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		ft_printf("Error: Can not initialize MiniLibX.\n");
		return(1);
	}
	ft_printf("MiniLibX initialized.\n");

	int	width = 800;
	int	height = 600;
	char	*window_title = "So_Long";

	win_ptr = mlx_new_window(mlx_ptr, width, height, window_title);
	if (win_ptr == NULL)
	{
		ft_printf("Error: Can not generate new window.\n");
		return(1);
	}
	ft_printf("New window initialized.\n");

	ft_printf("Initialize loop for MiniLibX");
	mlx_loop(mlx_ptr);

	ft_printf("Exiting loop and free memory");
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);

	return(0);
}
