# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/26 13:46:51 by amatthys     #+#   ##    ##    #+#        #
#    Updated: 2017/11/26 17:53:19 by amatthys    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #


NAME= fillit
CC= gcc
CFLAGS= -Wall -Wextra -Werror

INCLUDE_DIR=includes/

SRC_NAME = ft_inittab.c \
		   ft_optabl.c \
		   ft_readfile.c \
		   ft_solve.c \
		   ft_transfpiece.c \
		   main.c \
		   ft_putchar.c \
		   ft_putstr.c \
		   ft_memdel.c 

SRC_PATH = srcs/
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = objs/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: clean fclean all re

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) -c $^ $(CFLAGS) -o $@ -I $(INCLUDE_DIR)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
