NAME	= 	gnl.a
CC 		= 	gcc
INCLUDE = -I ../includes/

CFLAGS	=	-Wall -Werror -Wextra -D BUFFER_SIZE=42
# CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined -fsanitize=integer -D BUFFER_SIZE=42

SRCS		= 	get_next_line.c	\
				get_next_line_utils.c

OBJDIR		= obj/
OBJS  = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

all 	: 	$(NAME)

$(NAME)	:	$(OBJS)
	ar rcs $(NAME) $^

$(OBJDIR)%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<

clean	:
	$(RM) -r $(OBJDIR)

fclean	:	 clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY 	: 	all clean fclean re bonus

