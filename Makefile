NAME    = fractol
BONUS_NAME = .fractol_bonus

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

SRCS_BONUS = 	src_bonus/calculate_bonus.c \
				src_bonus/color_bonus.c \
				src_bonus/guide_bonus.c \
				src_bonus/hook_keyboard_bonus.c \
				src_bonus/hook_mouse_bonus.c \
				src_bonus/init_bonus.c \
				src_bonus/julia_bonus.c \
				src_bonus/main_bonus.c \
				src_bonus/mandelbrot_bonus.c \
				src_bonus/validate_input_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
bonus: $(BONUS_NAME)

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

$(BONUS_NAME): $(MLX42) $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX42) -ldl -lglfw -pthread -lm -o $(NAME)
	@echo "Executable '$(NAME)' created successfully!"
	@touch .fractol_bonus

%.o: %.c
	@echo "Compiling $< to create $@"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(MLX42_DIR)/build
	@rm -f $(BONUS_NAME)
	@echo "All object files removed."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Executable '$(NAME)' removed."

re: fclean all

opt: CFLAGS += -O3 -ffast-math -flto
opt: all

opt_bonus: CFLAGS += -O3 -ffast-math -flto
opt_bonus: bonus

.PHONY: all clean fclean re
