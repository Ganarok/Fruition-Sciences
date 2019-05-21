##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## generic Makefile
##

SRC	=	main.c	\
		src/movement.c \
		src/my_getnbr.c \
		src/fullstruct.c	\
		src/my_str_to_word_array.c \

CC	=	gcc -g3

NAME	=	aspirateur

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
