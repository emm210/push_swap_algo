NAME = push_swap
NAME_BONUS = checker 
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

BONUS_SRC = src/checker/checker.c \
		src/ops/op_push.c \
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
		src/get_next_line/get_next_line.c \
		src/get_next_line/get_next_line_utils.c

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJS) -o $(NAME) 

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

bonus : fclean $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -g3 $(BONUS_OBJS) -o $(NAME_BONUS)

.PHONY: all clean fclean re bonus