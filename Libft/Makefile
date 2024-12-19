# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 16:18:25 by cmayne-p          #+#    #+#              #
#    Updated: 2024/12/19 19:19:29 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

INCLUDES = libft.h
SRCS =	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c 
OBJS = $(SRCS:.c=.o)

# Default is the first target
all: $(NAME)

# To create .o
%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

# ar to create static library
# NOTE rcs: replace create and sort
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# --------- Rules for tests ---------
test: test.o $(NAME)
	$(CC) $(CFLAGS) -o test test.o -L. $(NAME)

test.o: test.c
	$(CC) $(CFLAGS) -c $< -o $@

tclean: fclean
	rm -rf test.o test
# -----------------------------------

norm: 
	norminette $(SRCS) $(INCLUDES)

.PHONY: all clean fclean re
