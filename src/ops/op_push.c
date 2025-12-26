#include "push_swap.h"

void    pa(t_stack *SA, t_stack *SB)
{
    t_node* node = pop (SB);
    if (!node)
        return ;
    push(SA, node);
    write(1, "pa\n", 3);
}

void    pb(t_stack *SA, t_stack *SB)
{
    t_node* node = pop (SA);
    if (!node)
        return ;
    push(SB, node);
    write(1, "pb\n", 3);
}
