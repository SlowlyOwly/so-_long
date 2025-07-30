# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 16:51:57 by srogozin          #+#    #+#              #
#    Updated: 2025/02/08 19:48:21 by srogozin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

SOURCE	=	ft_printf.c \
			ft_printchar.c \
			ft_printnum.c \

OBJECTS	=	$(SOURCE:.c=.o)

CC		=	cc

all:		$(NAME)

$(NAME):	$(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)

%.o:		%.c ft_printf.h
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJECTS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
			