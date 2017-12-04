# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 14:27:58 by abouvero          #+#    #+#              #
#    Updated: 2017/12/04 15:30:29 by mfonteni         ###   ########.fr        #
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
	  gridsize.c \
	  struct_checks.c \
	  get_limit.c

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
