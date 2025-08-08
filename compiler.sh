# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compiler.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 17:42:30 by srogozin          #+#    #+#              #
#    Updated: 2025/08/08 15:54:55 by srogozin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

echo "Making of Libft.\n"

cd Libft/
if [ -f "libft.a" ]; then
    echo "make is already done. \n"
else 
    make
fi

cd ..

echo "Compiling so_long\n"

if [ -f "so_long" ]; then
    echo "Deleting so_long and setting new one \n"
	rm so_long
	cc src/main.c src/events.c src/utils.c -Lmlx -lmlx -LLibft -lft -Imlx -Iinclude -I./Libft -I./Libft/ft_printf -I./Libft/GNL -o so_long -Wall -Wextra -Werror -lX11 -lXext
else 
    cc src/main.c src/events.c src/utils.c -Lmlx -lmlx -LLibft -lft -Imlx -Iinclude -I./Libft -I./Libft/ft_printf -I./Libft/GNL -o so_long -Wall -Wextra -Werror -lX11 -lXext
fi