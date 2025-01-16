NAME = test.out

LIBFT_DIR = ../libft
PRINTF_DIR = ..

LIBFT = $(LIBFT_DIR)/libft.a
LIBFTPRINTF = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(INCLUDES_DIR)

INCLUDES_DIR = ../includes

SRCS = main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFTPRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L. $(LIBFTPRINTF) -L. $(LIBFT)

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
