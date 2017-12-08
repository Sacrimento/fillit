# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 14:27:58 by abouvero          #+#    #+#              #
#    Updated: 2017/12/08 13:56:50 by abouvero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
	  parser.c \
      file_checker.c \
	  combination.c \
	  eraseblock.c \
	  placeblock.c \
	  placenext.c \
	  alphablock.c \
	  tabcreator.c \
	  print_grid.c \
	  controller.c \
	  struct_checks.c \
	  chk_limit.c \
	  parsing_exce.c

FLAGS = -Wall -Werror -Wextra
LIBDIR = ./libft/
LIBFT = ./libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	gcc -o $@ -c $< $(FLAGS)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	make -C $(LIBDIR)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
