# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcresce <dcresce@student.42lausanne.c    	+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 16:33:55 by dcresce           #+#    #+#              #
#    Updated: 2026/10/05 22:04:58 by dcresce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
RESET	= \033[0m

#Standard

NAME		= cub
INC_DIR		= inc
SRCS_DIR 	= ./
OBJS_DIR 	= obj/
CC 			= gcc
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror -g -fsanitize=address

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
PARS = get_config store_map

CLEANING_DIR = src/cleaning/
CLEANING = clean_exit

SRC_FILES += $(MAIN)
SRC_FILES += $(addprefix $(PARS_DIR),$(PARS))
SRC_FILES += $(addprefix $(CLEANING_DIR),$(CLEANING))

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJSF 		= .cache_exists
INCLUDES 	= -I$(INC_DIR) -I$(LIBFT_PATH)

$(MLX_LIB):
	@make -C $(MLX_DIR) CC=gcc CFLAGS="-O3 -std=gnu89 -I.."
	@echo "mlx compiled"

$(LIBFT):
	@make -C $(LIBFT_PATH) all

all: $(MLX_LIB) ${NAME}

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX_LNK) $(LIBFT) -o $(NAME)
	@echo -e "$(GREEN)✓ Build OK: $(NAME)$(RESET)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)$(PARS_DIR)
	@mkdir -p $(OBJS_DIR)$(CLEANING_DIR)

clean:
	@$(RM) -rf $(OBJS_DIR)
	@$(RM) -f $(OBJSF)
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_DIR) clean
	@echo -e "$(RED)✗ Objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MLX_DIR) clean
	@echo -e "$(RED)✗ $(NAME) removed$(RESET)"

re: fclean all

.PHONY : all clean fclean re valgrind
