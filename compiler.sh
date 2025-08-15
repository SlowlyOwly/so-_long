# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compiler.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 17:42:30 by srogozin          #+#    #+#              #
#    Updated: 2025/08/15 19:07:06 by srogozin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

echo "Making of Libft."

cd Libft/
if [ -f "libft.a" ]; then
    echo "make is already done."
else 
    make
fi

cd ..

echo "Compiling so_long"

if [ -f "so_long" ]; then
    echo "Deleting so_long and setting new one"
	rm so_long
	cc src/*.c -Lmlx -lmlx -LLibft -lft -Imlx -Iinclude -I./Libft -I./Libft/ft_printf -I./Libft/GNL -o so_long -Wall -Wextra -Werror -lX11 -lXext
else 
    cc src/*.c -Lmlx -lmlx -LLibft -lft -Imlx -Iinclude -I./Libft -I./Libft/ft_printf -I./Libft/GNL -o so_long -Wall -Wextra -Werror -lX11 -lXext
fi