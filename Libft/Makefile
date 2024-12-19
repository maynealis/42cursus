# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 16:18:25 by cmayne-p          #+#    #+#              #
#    Updated: 2024/12/18 16:29:32 by cmayne-p         ###   ########.fr        #
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
		ft_isprint.c
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
	$(CC) -o test test.o -L. $(NAME)

test.o: test.c
	$(CC) $(CFLAGS) -c $< -o $@

tclean: fclean
	rm -rf test.o test
# -----------------------------------

.PHONY: all clean fclean re
