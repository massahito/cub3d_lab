NAME		=	cub3D
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror #-g -fsanitize=leak
# CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I ./minilibx-linux/ -I ./includes/
LIBMACDIR	=	-L/usr/local/lib -L/usr/lib -L/usr/X11R6/lib
LIBLNXDIR	=	-L/usr/local/lib -L/usr/lib -L./minilibx-linux
LIBMAC		=	-lmlx -framework OpenGL -framework Appkit
LIBLNX		=	-lmlx -lX11 -lXext -lm -lz
MLXLIB		=	./minilibx-linux/libmlx.a
SRCS		=	$(shell find ./srcs/ -name "*.c")
OBJDIR		=	obj
OBJS		=	$(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
VPATH		=	./srcs/

MAKE		= make --no-print-directory

GNLDIR		=	get_next_line
GNLNAME		=	$(GNLDIR)/gnl.a
GNL			=	$(GNLNAME)

LIBFTDIR 	= libft
LIBFTNAME 	= $(LIBFTDIR)/libft.a
LIBFT 		= $(LIBFTNAME)

all: $(NAME)
$(NAME):$(OBJS) $(MLXLIB) $(LIBFTNAME) $(GNLNAME)
ifeq ($(shell uname -s),Linux)
	$(CC) $(CFLAGS) $^ $(LIBLNXDIR) $(LIBLNX) $(MLXLIB) -o $(NAME)
else
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTNAME) $(GNLNAME) $(LIBMACDIR) $(LIBMAC) $(MLXLIB) -o $(NAME)
endif

$(MLXLIB):
	@$(MAKE) -C ./minilibx-linux

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<

$(LIBFTNAME):
	$(MAKE) --no-print-directory -C $(LIBFTDIR)

$(GNLNAME):
	$(MAKE) --no-print-directory -C $(GNLDIR)

UnitTest:
	$(MAKE) -C test/UnitTest
	./test/UnitTest/UnitTest
clean:
	rm -rf $(OBJDIR)
	$(MAKE) clean -C ./test/UnitTest/
	$(MAKE) --no-print-directory -C libft clean
	$(MAKE) --no-print-directory -C get_next_line clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./test/UnitTest/
	$(MAKE) --no-print-directory -C libft fclean
	$(MAKE) --no-print-directory -C get_next_line fclean
re:	fclean all

.PHONY:
	all clean fclean re Libft UnitTest

