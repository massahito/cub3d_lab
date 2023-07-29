NAME	= 	gnl.a

# CC 		= 	gcc
CC 		= 	clang

INCLUDE = -I ../include

# CFLAGS	=	-Wall -Wextra
CFLAGS	=	-Wall -Werror -Wextra -D BUFFER_SIZE=42
# CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined -fsanitize=integer
# CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined -fsanitize=integer -D BUFFER_SIZE=42

SRCS		= 	get_next_line.c	\
				get_next_line_utils.c

SRCS_BONUS	=	get_next_line_bonus.c	\
				get_next_line_utils_bonus.c

OBJDIR		= obj/
OBJS  = $(addprefix $(OBJDIR), $(SRCS:.c=.o))
OBJS_BONUS	= $(addprefix $(OBJDIR), $(SRCS_BONUS:.c=.o))

ifdef WITH_BONUS
OBJS += $(OBJS_BONUS)
endif

all 	: 	$(NAME)

$(NAME)	:	$(OBJS)
	ar rcs $(NAME) $^

$(OBJDIR)%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<

bonus :
	@$(MAKE) --no-print-directory all WITH_BONUS=1

clean	:
	$(RM) -r $(OBJDIR)

fclean	:	 clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY 	: 	all clean fclean re bonus

