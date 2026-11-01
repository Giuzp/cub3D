# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcresce <dcresce@student.42lausanne.ch>   	+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 16:33:55 by dcresce           #+#    #+#              #
#    Updated: 2026/11/01 21:37:49 by dcresce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
RESET	= \033[0m

#Standard

.DEFAULT_GOAL := all

NAME		= cub
INC_DIR		= inc
SRCS_DIR 	= ./
OBJS_DIR 	= obj/
CC 			= gcc
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror -std=c99 -g #-fsanitize=address

#mlx
MLX_DIR = minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
MLX_LNK = -L$(MLX_DIR) -lXext -lX11 -lm -lbsd

#libft
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

#Sources

MAIN = src/main

PARS_DIR = src/parsing/
PARS = get_config store_map validate_map validate_map_helpers \
#read_store_cubfile \
utils_parsing \
checking_parsing \
check_map_is_ok \
config_init

MLX_SRC_DIR = src/mlx/
MLX = mlx_init mlx_keys mlx_loop

CLEANING_DIR = src/cleaning/
CLEANING = clean_exit clean_helpers

SRC_FILES += $(MAIN)
SRC_FILES += $(addprefix $(PARS_DIR),$(PARS))
SRC_FILES += $(addprefix $(CLEANING_DIR),$(CLEANING))
SRC_FILES += $(addprefix $(MLX_SRC_DIR),$(MLX))

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJSF 		= .cache_exists
INCLUDES 	= -I$(INC_DIR) -I$(LIBFT_PATH) $(MLX_INC)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR) CC=gcc CFLAGS="-O3 -std=gnu89 -I.."
	@echo "mlx compiled"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) all

all: $(MLX_LIB) ${NAME}

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX_LNK) $(LIBFT) -o $(NAME)
	@echo -e "$(GREEN)✓ Build OK: $(NAME)$(RESET)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)$(PARS_DIR)
	@mkdir -p $(OBJS_DIR)$(CLEANING_DIR)
	@mkdir -p $(OBJS_DIR)$(MLX_SRC_DIR)

clean:
	@$(RM) -rf $(OBJS_DIR)
	@$(RM) -f $(OBJSF)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo -e "$(RED)✗ Objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean 
	@$(MAKE) -C $(MLX_DIR) clean 
	@echo -e "$(RED)✗ $(NAME) removed$(RESET)"

re: fclean all

.PHONY : all clean fclean re valgrind
