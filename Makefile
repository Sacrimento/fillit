# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 14:27:58 by abouvero          #+#    #+#              #
#    Updated: 2017/11/30 15:18:01 by mfonteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
	  parser.c \
      file_checker.c \
	  ft_combination.c \
	  ft_eraseblock.c \
	  ft_placeblock.c \
	  ft_placenext.c \
	  ft_alphablock.c \
	  ft_tabcreator.c \
	  ft_print_grid.c \
	  ft_controller.c \
	  ft_gridsize.c \
	  ft_struct_checker.c

FLAGS = -Wall -Werror -Wextra
LIBDIR = ./libft/
LIBFT = ./libft/libft.a
OBJDIR = ./obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(OBJDIR) $(LIBFT) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:%.c
	gcc -o $@ -c $< $(FLAGS)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	make -C $(LIBDIR)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
