/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:59:25 by srogozin          #+#    #+#             */
/*   Updated: 2025/08/08 16:51:09 by srogozin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define TILE_SIZE 64

typedef struct s_game {
	char	**map;
	int 	width;
	int 	height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		exits;
	void	*mlx_ptr;
	void	*win_ptr;
} t_game;

void	*mlx_ptr();
void	*win_ptr(void	*mlx_ptr);
void	free_resources(t_game *game);
int		close_window(t_game *game);
int 	esc_key(int keycode, t_game *game);
void	setup_hooks(t_game *game);
char	**load_map(char *map_file);
void	*ft_realloc(void *ptr, size_t new_size)


#endif