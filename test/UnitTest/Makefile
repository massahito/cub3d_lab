NAME		=	UnitTest
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I ../../includes/
LIB			=	-lcunit
SRCS		=	main.c \
				../../srcs/file_name.c \
				file_name_test.c \

OBJS		=	${SRCS:.c=.o}

all: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${LIB} -o ${NAME}

${OBJS}: %.o:%.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@ 
clean: ${OBJS}
	rm -rf ${OBJS}
fclean: clean
	rm -f $(NAME)
re:	fclean all

.PHONY:
	all clean fclean re
