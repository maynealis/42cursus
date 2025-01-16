# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 19:09:37 by cmayne-p          #+#    #+#              #
#    Updated: 2025/01/16 14:22:57 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES_DIR = includes
LIBFT_DIR = libft

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(INCLUDES_DIR) #TODO: quitar el flag para debugar

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = $(INCLUDES_DIR)/ft_printf.h

SRCS = ft_printf.c ft_uitoa_base.c write_conversions.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS) Makefile
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
