NAME = libftprintf.a

SRCS_UTILS = utils_snd.c utils_convert.c

SRCS = ft_printf.c ${SRCS_UTILS}

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

LIB = ar rcs

OBJ = ${SRCS:.c=.o}

CC = gcc

all : ${NAME}

${NAME} : ${OBJ}
	${LIB} ${NAME} ${OBJ}

%.o : %.c Makefile ft_printf.h
	${CC} ${CFLAGS} -I. -c $< -o $@

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : clean fclean all re