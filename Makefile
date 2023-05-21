NAME		=	cub3d
CC			=	cc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I /usr/include/ -I /usr/local/include/ -I ./minilibx-linux/ -I ./includes/
LIBDIR	=	-L/usr/local/lib -L/usr/lib
LIB		=	-lXext -lX11 -lm -lz
MLXLIB	=	./minilibx-linux/libmlx.a
SRCS	=	$(shell find srcs/ -name "*.c")
OBJDIR	=	obj
OBJS	=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))


all: $(NAME)
$(NAME):$(OBJS) $(LIBFT) $(MLXLIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLXLIB) $(LIBDIR) $(LIB) -o $(NAME)

$(MLXLIB):
	@make -C ./minilibx-linux

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<

UnitTest:
	make -C test/UnitTest
	./test/UnitTest/UnitTest
clean:
	rm -rf $(OBJDIR)
	make clean -C ./test/UnitTest/
fclean: clean
	rm -f $(NAME)
	make fclean -C ./test/UnitTest/
re:	fclean all

.PHONY:
	all clean fclean re

