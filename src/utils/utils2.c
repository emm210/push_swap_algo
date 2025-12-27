#include "push_swap.h"

// int check_is_sorted(t_stack* A, int size)
// {
//     int i = 0;
//     int j = 0;


// }

void free_stack(t_stack *stack)
{
    t_node *cur;
    t_node *next;

    cur = stack->top;
    while (cur)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}