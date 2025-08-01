# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compiler.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 17:42:30 by srogozin          #+#    #+#              #
#    Updated: 2025/07/31 18:32:18 by srogozin         ###   ########.fr        #
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
    echo "so_long is compiled. \n"
else 
    cc src/main.c -Lmlx -lmlx -LLibft -lft -Imlx -Iinclude -I./Libft -I./Libft/ft_printf -I./Libft/GNL -o so_long -Wall -Wextra -Werror -lX11 -lXext
fi