NAME		=	UnitTest
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I ../../minilibx-linux/ -I ../../includes/ -I ~/.brew/Cellar/cunit/2.1-3/include/
LIB			=	-L ~/.brew/Cellar/cunit/2.1-3/lib -lcunit
SRCS		=	main.c \
				srcs/file_name.c \
				file_name_test.c \
				check_texture_exist.c \

OBJDIR		=	./obj
OBJS		=	${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.o}}}
VPATH		=	../../srcs/:srcs/
all: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${LIB} -o ${NAME}
${OBJDIR}/%.o: %.c
	mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<
clean:
	rm -rf ${OBJDIR}
fclean: clean
	rm -f $(NAME)
re:	fclean all
.PHONY:
	all clean fclean re
