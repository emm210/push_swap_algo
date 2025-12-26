#include "push_swap.h"
void    rra(t_stack *SA)
{
    
    reverse_rotate_a(SA);
    write(1, "rra\n", 4);
}

void    rrb(t_stack *SB)
{
    reverse_rotate_b(SB);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *SA, t_stack *SB)
{
    reverse_rotate_a(SA);
    reverse_rotate_b(SB);
    write(1, "rrr\n", 4);
}