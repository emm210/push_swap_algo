#ifndef CHECKER_H
# define CHECKER_H
# include "get_next_line.h"
# include "push_swap.h"

int	ft_streq(const char *s1, const char *s2);
void execute_op(int op,t_stack *SA, t_stack *SB);
int	get_op_type(char *str);

#endif