# Standard
NAME	=	push_swap

# Directories
PRINTF	=	./ft_printf/ft_printf.a

# Compiler and CFlags
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

# Source files
SRCS	=	errors.c			\
			ft_split.c			\
			init_a_to_b.c		\
			init_b_to_a.c		\
			push_swap.c				\
			push.c				\
			rev_rotate.c		\
			rotate.c			\
			sort_stacks.c		\
			sort_three.c		\
			stack_init.c		\
			stack_utils.c		\
			swap.c				\
			resources_libft.c	\

# Object files
OBJS	=	$(SRCS:.c=.o)

# Build rules
start:
		@make all
	
$(PRINTF):
		@make -C ./ft_printf

all:	$(NAME)

$(NAME):	$(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

clean:
	rm -rf $(OBJS)
	@make clean -C ./ft_printf

fclean:		clean
	rm -rf $(NAME)
	@$(RM) %(PRINTF)

re:	clean all

.PHONY:	start all clean fclean re
