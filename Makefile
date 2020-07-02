##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	visualizer

CC	=	gcc

SRC	=	src/main.c \
		src/color.c \
		src/init.c \
		src/shuffle.c \
		src/selection_sort.c \
		src/bubble_sort.c \
		src/insertion_sort.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra
CFLAGS	+=	-I./include -g3 -O3
FFLAGS	+=	-l csfml-system
FFLAGS	+=	-l csfml-graphics
FFLAGS	+=	-l csfml-audio
FFLAGS	+=	-l csfml-window
FFLAGS  +=	-lm

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(FFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
