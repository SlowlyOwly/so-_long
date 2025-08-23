# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/22 14:49:56 by srogozin          #+#    #+#              #
#    Updated: 2025/08/23 16:25:33 by srogozin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CFLAGS	=	-Wall -Wextra -Werror -Iinclude -Imlx -ILibft -ILibft/ft_printf -ILibft/GNL
LIBFT_SRC	:= $(wildcard Libft/*.c)
LIBFT_OBJS	:= $(patsubst %.c,%.o,$(LIBFT_SRC))

SOURCE	=	src/main.c src/events.c src/map_validator.c src/map_validator_2.c \
			src/utils.c src/textures.c src/map_viz.c \

OBJECTS	=	$(SOURCE:.c=.o) $(LIBFT_OBJS)

CC		=	cc

SUBDIRS	=	Libft

.PHONY:		all clean fclean re $(SUBDIRS)

all:		$(SUBDIRS) $(NAME)

$(SUBDIRS):
	$(MAKE) -C $@

$(NAME):	$(OBJECTS)
			$(CC) $(CFLAGS) $(OBJECTS) -lmlx -Lmlx -lft -L./Libft -lX11 -lXext -o $(NAME)

%.o:		%.c so_long.h
			$(CC) $(CFLAGS) -c $< -o $@
			
clean:
			rm -f $(OBJECTS)
			$(MAKE) -C $(SUBDIRS) clean

fclean:		clean
			rm -f $(NAME)
			$(MAKE) -C $(SUBDIRS) fclean

re:			fclean all