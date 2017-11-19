# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouvero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 14:27:58 by abouvero          #+#    #+#              #
#    Updated: 2017/11/18 11:51:56 by abouvero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = libft/libft.a \
	  main.c \
	  fillit.c \
	  parser.c \
      file_checker.c \

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJ) $^

%.o: %.c
	    $(CC) -o $@ -c $< $(FLAGS) 

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	
re: fclean all

norme:
	norminette

run:
	./$(NAME)
