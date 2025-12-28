#include "push_swap.h"
void    ra(t_stack *SA)
{
    rotate_a(SA);
    write(1, "ra\n", 3);
}

void    rb(t_stack *SB)
{
    rotate_b(SB);
    write(1, "rb\n", 3);
}

void    op_rr(t_stack *SA, t_stack *SB)
{
    rotate_a(SA);
    rotate_b(SB);
}

void    rr(t_stack *SA, t_stack *SB)
{
    op_rr(SA, SB);
    write(1, "rr\n", 3);
}