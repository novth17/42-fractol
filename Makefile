NAME    = fractol

CC      = cc

INCLUDE := -Iinc -Ilibs/libft/inc -Ilibs/MLX42/include/MLX42

CFLAGS  = $(INCLUDE) -Wall -Wextra -Werror

LIBFT_DIR := libs/libft
LIBFT := $(LIBFT_DIR)/libft.a

MLX42_DIR := libs/MLX42
MLX42 := $(MLX42_DIR)/build/libmlx42.a

SRCS =	src/calculate.c \
		src/color.c \
		src/guide.c \
		src/hook_keyboard.c \
		src/hook_mouse.c \
		src/init.c \
		src/julia.c \
		src/main.c \
		src/mandelbrot.c \
		src/validate_input.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(MLX42):
	@if [ ! -d "$(MLX42_DIR)" ]; then \
		cd libs && git clone https://github.com/codam-coding-college/MLX42.git; \
	fi
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build && $(MAKE) -C $(MLX42_DIR)/build -j4

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(MLX42) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) -ldl -lglfw -pthread -lm -o $(NAME)
	@echo "Executable '$(NAME)' created successfully!"


%.o: %.c
	@echo "Compiling $< to create $@"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) 
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(MLX42_DIR)/build
	@echo "All object files removed."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Executable '$(NAME)' removed."

re: fclean all

opt: CFLAGS += -O3 -ffast-math -flto
opt: all

.PHONY: all clean fclean re
