NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a
GNL = gnl/gnl.a
MLX = ./MLX42/build/libmlx42.a
MLX_LIBFT = ./MLX42/lib/MLX42/MLX42.h

INCLUDES = -I$(LIBFT) -I$(PRINTF) -I$(GNL) -I$(MLX)
CCMLX = ./MLX42/build/libmlx42.a -ldl -lglfw -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm

SRCS =	sources/so_long.c\
		sources/init_map.c\
		sources/init_game.c\
		sources/check_map.c\
		sources/check_path.c\
		sources/render_map.c\
		sources/handle_input.c\
		sources/free_memory.c\
		sources/close_game.c\
		sources/utils.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(MLX):
	@cd MLX42 && cmake -B build
	@cd MLX42 && cmake --build build -j4

$(NAME): $(OBJS) $(MLX)
	@make -s all -C libft
	@make -s all -C printf
	@make -s all -C gnl
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(GNL) $(MLX) $(CCMLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -s clean -C libft
	@make -s clean -C printf
	@make -s clean -C gnl
fclean:	clean
	@make -s fclean -C libft
	@make -s fclean -C printf
	@make -s fclean -C gnl
	@rm -f $(NAME)
	@rm -f $(MLX)
	@rm -rf ./MLX42/build

re: fclean all
