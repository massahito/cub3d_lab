# NAME 				=	cub3D
# CC					=	cc
# CFLAGS				=	-Wall -Wextra -Werror
# INCLUDE				=	-I ./include/ 

# GNLDIR		=	get_next_line
# GNLNAME		=	$(GNLDIR)/gnl.a
# GNL			=	$(GNLNAME)

# CFLAGS_DEBUG		=	-g -fsanitize=address

# SRCS				=	$(shell find ./srcs/ -name "*.c")

# OBJDIR   			= 	obj
# OBJS  				= 	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# $(OBJDIR)/%.o: %.c
# 	@mkdir -p $$(dirname $@)
# 	make -C get_next_line
# 	$(CC) $(GNLNAME) $(INCLUDE) $(CFLAGS) -o $@ -c $<

# all: $(NAME)

# $(NAME):$(OBJS)
# 	$(CC) $^ $(CFLAGS) $(GNLNAME) -o $@
NAME 				=	cub3D
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
INCLUDE				=	-I ./include/ 

GNLDIR		=	get_next_line
GNLNAME		=	$(GNLDIR)/gnl.a
GNL			=	$(GNLNAME)

CFLAGS_DEBUG		=	-g -fsanitize=address

SRCS				=	$(shell find srcs/ -name "*.c")
VPATH				=	./srcs

OBJDIR   			= 	obj
OBJS  				= 	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS) $(GNLNAME)
	$(CC) $^ $(CFLAGS) -o $@

$(GNLNAME):
	make -C $(GNLDIR)

clean:
	$(RM) -r $(OBJDIR)
	make clean -C get_next_line

fclean: clean 
	$(RM) $(NAME)
	make fclean -C get_next_line
	rm -f result

re : fclean all

debug:	CFLAGS += $(CFLAGS_DEBUG)
debug:	re


.PHONY:
	all lib clean fclean re debug
