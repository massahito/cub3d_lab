NAME		=	cub3d
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I ./minilibx-linux/ -I ./includes/
LIBMACDIR	=	-L/usr/local/lib -L/usr/lib -L/usr/X11R6/lib
LIBMAC		=	-lmlx -framework OpenGL -framework Appkit
MLXLIB		=	./minilibx-linux/libmlx.a
SRCS		=	$(shell find ./srcs/ -name "*.c")
OBJDIR		=	obj
OBJS		=	$(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
VPATH		=	./srcs/

all: $(NAME)
$(NAME):$(OBJS) $(LIBFT) $(MLXLIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDIR) $(LIBMAC) $(MLXLIB) -o $(NAME)

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

