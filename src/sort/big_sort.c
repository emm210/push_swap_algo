#include "push_swap.h"

int find_max_pos(t_stack *A)
{
    int pos = 0;
    int max_pos = 0;
    t_node *current;
    int max_rank;

    if (!A || !A->top)
        return (-1);

    current = A->top;
    max_rank = current->rank;

    while (current)
    {
        if (current->rank > max_rank)
        {
            max_rank = current->rank;
            max_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return (max_pos);
}


void big_sort(t_stack* SA, t_stack* SB)
{
    int chunk_size = 0;
    int numbers = SA->size;
    if (numbers <= 100)
        chunk_size = numbers / 6;
    else if(numbers > 100)
        chunk_size = numbers / 14;
    int start = 0;
    int end = chunk_size - 1;
    while (SA->top)
    {
        if (SA->top->rank <= start)
        {
            pb(SA,SB);
            rb(SB);
            start++;
            if (end < numbers - 1)
                end++;
        }
        else if (SA->top->rank <= end)
        {
            pb(SA, SB);
            if (SB->size > 1 && SB->top->next && SB->top->next->rank > SB->top->rank)
                sb(SB);
            start++;
            if (end < numbers - 1)
                end++;
        }
        else
            ra(SA);
    }

    // while (SB->top)
    // {
    //     int max_pos = find_max_pos(SB);
    //     if (max_pos <= SB->size / 2)
    //     {
    //         while (max_pos-- > 0)
    //             rb(SB);
    //     }
    //     else
    //     {
    //         while (max_pos++ < SB->size)
    //             rrb(SB);
    //     }
    //     pa(SA, SB);
    // }
    while (SB->size > 0)
{
    int max_pos = find_max_pos(SB);

    if (max_pos <= SB->size / 2)
    {
        int moves = max_pos;
        while (moves-- > 0)
            rb(SB);
    }
    else
    {
        int moves = SB->size - max_pos;
        while (moves-- > 0)
            rrb(SB);
    }
    pa(SA, SB);
}


}