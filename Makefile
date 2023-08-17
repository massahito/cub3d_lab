NAME		=	cub3D
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror #-g -fsanitize=leak
INCLUDE		=	-I ./minilibx-linux/ -I ./includes/
LIBMACDIR	=	-L/usr/local/lib -L/usr/lib -L/usr/X11R6/lib
LIBLNXDIR	=	-L/usr/local/lib -L/usr/lib -L./minilibx-linux
LIBMAC		=	-lmlx -framework OpenGL -framework Appkit
LIBLNX		=	-lmlx -lX11 -lXext -lm -lz
MLXLIB		=	./minilibx-linux/libmlx.a
SRCS		=	srcs/calculation/calc.c \
				srcs/calculation/dda.c \
				srcs/calculation/drawing.c \
				srcs/check/file_check.c \
				srcs/check/map_check.c \
				srcs/check/map_check2.c \
				srcs/check/map_check3.c \
				srcs/error/error.c \
				srcs/main.c \
				srcs/map/map_list.c \
				srcs/map/map_list2.c \
				srcs/map/map_utils.c \
				srcs/mlx/mlx_utils.c \
				srcs/operation/front_back_operation.c \
				srcs/operation/right_left_operation.c \
				srcs/operation/rot_operation.c \
				srcs/read/read_azimuths_floor_ceil.c \
				srcs/read/read_azimuths_floor_ceil2.c \
				srcs/read/read_file.c \
				srcs/read/read_file2.c \
				srcs/read/read_map.c \
				srcs/utils/add_vars.c \
				srcs/utils/delete.c \
				srcs/utils/rgb.c \
				srcs/utils/rgb2.c
OBJDIR		=	obj
OBJS		=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
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

minilibx:
	if ! [ -d minilibx-linux ]; then\
		git clone https://github.com/42Paris/minilibx-linux;\
	fi

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

