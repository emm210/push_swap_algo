NAME = push_swap
NAME_BONUS = checker 
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

SRC= ./op_push.c \
	 ./op_rev_rotate.c \
	 ./op_rotate.c \
	 ./op_swap.c \
	 ./parse_input.c \
	 ./big_sort.c \
	 ./small_sort.c \
	 ./stack_init.c \
	 ./stack_push_pop.c \
	 ./stack_reverse_rotate.c \
	 ./stack_rotate.c \
	 ./stack_swap.c \
	 ./ft_split.c \
	 ./utils.c \
	 ./utils2.c \
	 ./utils3.c \
	 ./utils4.c \
	 ./main.c

BONUS_SRC = ./checker.c \
		./op_push.c \
		./op_rev_rotate.c \
	 	./op_rotate.c \
	 	./op_swap.c \
	 	./parse_input.c \
	 	./stack_init.c \
	 	./stack_push_pop.c \
	 	./stack_reverse_rotate.c \
	 	./stack_rotate.c \
	 	./stack_swap.c \
	 	./ft_split.c \
	 	./utils.c \
	 	./utils2.c \
	 	./utils3.c \
		./utils4.c \
		./get_next_line.c \
		./get_next_line_utils.c

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJS) -o $(NAME) 

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all bonus

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -g3 $(BONUS_OBJS) -o $(NAME_BONUS)

.PHONY: all clean fclean re bonus