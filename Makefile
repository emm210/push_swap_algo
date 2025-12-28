NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
SRC= src/ops/op_push.c \
	 src/ops/op_rev_rotate.c \
	 src/ops/op_rotate.c \
	 src/ops/op_swap.c \
	 src/parse/parse_input.c \
	 src/sort/big_sort.c \
	 src/sort/small_sort.c \
	 src/stack/stack_init.c \
	 src/stack/stack_push_pop.c \
	 src/stack/stack_reverse_rotate.c \
	 src/stack/stack_rotate.c \
	 src/stack/stack_swap.c \
	 src/utils/ft_split.c \
	 src/utils/utils.c \
	 src/utils/utils2.c \
	 src/utils/utils3.c \
	 src/main.c

OBJS = $(SRC:.c=.o)
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJS) -o $(NAME) 
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) 

re : fclean all
	