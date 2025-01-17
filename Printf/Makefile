# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 19:09:37 by cmayne-p          #+#    #+#              #
#    Updated: 2025/01/17 14:05:43 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES_DIR = includes
LIBFT_DIR = libft

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_DIR) -g #TODO: quitar el flag para debugar

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = $(INCLUDES_DIR)/ft_printf.h $(INCLUDES_DIR)/ft_utils.h

SRCS = ft_printf.c write_conversions.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS) Makefile
	ar rcs $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

# --------------- BONUS --------------------
SRCS_BONUS = ft_printf_bonus.c write_conversions.c utils.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

bonus: $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS) $(LIBFT)

bonus_clean:
	rm -rf $(OBJS_BONUS)
# --------------------------------------------


norm:
	norminette $(SRCS) $(LIBFT_DIR) $(INCLUDES)

.PHONY: all clean fclean re norm
