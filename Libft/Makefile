# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srogozin <srogozin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 18:22:19 by srogozin          #+#    #+#              #
#    Updated: 2025/08/14 17:29:45 by srogozin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CFLAGS	=	-Wall -Wextra -Werror

PRINTF_SRCS := $(wildcard ft_printf/*.c)
PRINTF_OBJS := $(patsubst %.c,%.o,$(PRINTF_SRCS))

SOURCE	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
			ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			GNL/get_next_line.c \

OBJECTS	=	$(SOURCE:.c=.o) $(PRINTF_OBJS)

CC	=	cc

SUBDIRS = ft_printf

.PHONY: all clean fclean re $(SUBDIRS)

all:	$(SUBDIRS) $(NAME)

$(SUBDIRS):
	$(MAKE) -C $@

$(NAME):	$(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)
			
%.o:	%.c libft.h get_next_line.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJECTS)
		$(MAKE) -C $(SUBDIRS) clean

fclean:	clean
		rm -f $(NAME)
		$(MAKE) -C $(SUBDIRS) fclean
	
re:		fclean all
