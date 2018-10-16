# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/16 16:16:29 by vsteyaer     #+#   ##    ##    #+#        #
#    Updated: 2018/06/23 11:05:05 by vsteyaer    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fdf
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
INC_MLX = -L ./minilibx/ -l mlx -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
LIBMLX = ./minilibx/libmlx.a
PATH_OFDF = ./srcs/
PATH_SFDF = ./srcs/
PATH_IFDF = ./include/
FILESFDF = main ft_init ft_free ft_init_fdf ft_draw ft_deal_key
ILIBFT = $(addprefix $(PATH_ILIBFT), libft.h)
SFDF = $(addprefix $(PATH_SFDF), $(addsuffix .c, $(FILESFDF)))
OFDF = $(addprefix $(PATH_OFDF), $(addsuffix .o, $(FILESFDF)))
IFDF = $(addprefix $(PATH_IFDF), fdf.h)

all : $(NAME)

$(NAME) : $(LIBFT) $(LIBMLX) $(OFDF)
	@$(CC) $(CC_FLAGS) $(INC_MLX) -L ./libft -l ft $(OFDF) -o $(NAME)
	@echo "\n 💎 💎 💎  EXECUTABLE CREATED 💎 💎 💎  \n"

$(LIBFT):
	@printf "Compilation of \033[1m$@\033[0m ... ⌛️ "
	@make -C libft
	@echo "\n 💯 💯 💯  LIBFT COMPILED 💯 💯 💯  \n"

$(LIBMLX):
	@printf "Compilation of \033[1m$@\033[0m ...⌛️ \n"
	@make -C minilibx
	@echo "\n 💰 💰 💰  MINILIBX COMPILED 💰 💰 💰  \n"

$(PATH_OFDF)%.o : $(PATH_SFDF)%.c $(IFDF)
	@printf "Compilation of \033[1m$@\033[0m ... ⌛️ \n"
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_IFDF) -I minilibx

clean :
	@make clean -C libft
	@make clean -C minilibx
	@rm -f $(OFDF)

fclean : clean
	@make fclean -C libft
	@make clean -C minilibx
	@rm -f $(NAME)

re : fclean all
