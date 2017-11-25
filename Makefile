# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 14:27:58 by abouvero          #+#    #+#              #
#    Updated: 2017/11/25 17:38:51 by abouvero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
	  parser.c \
      file_checker.c \

FLAGS = -Wall -Werror -Wextra
LIBDIR = ./libft/
LIBFT = ./libft/libft.a
OBJDIR = ./obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: wow $(OBJDIR) $(LIBFT) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:%.c
	@gcc -o $@ -c $< $(FLAGS)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	@make -C $(LIBDIR)

wow:
	@echo "  _____.__.__  .__  .__  __                                .__.__  .__                 "
	@echo "_/ ____\__|  | |  | |__|/  |_    ____  ____   _____ ______ |__|  | |__| ____    ____   "
	@echo "\   __\|  |  | |  | |  \   __\ _/ ___\/  _ \ /     \\____ \|  |  | |  |/    \  / ___\  "
	@echo " |  |  |  |  |_|  |_|  ||  |   \  \__(  <_> )  Y Y  \  |_> >  |  |_|  |   |  \/ /_/  > "
	@echo " |__|  |__|____/____/__||__|    \___  >____/|__|_|  /   __/|__|____/__|___|  /\___  /  "
	@echo "                                    \/            \/|__|                   \//_____/   "
	@echo ""

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
