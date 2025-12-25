#include "push_swap.h"
int find_max_pos(t_stack *A) { 
    int current_pos = 1; 
    int max_pos = 0; 
    t_node *max_node = A->top; 
    t_node *current_node = A-> top->next; 
    while(current_node) 
    { 
        if (current_node -> rank > max_node->rank) 
        {
            max_node = current_node; 
            max_pos = current_pos;
        }
        current_node = current_node -> next;
        current_pos++; 
    }
    return (max_pos); 
}
void big_sort(t_stack* SA, t_stack* SB, int argc)
{
    int chunk_size = 0;
    int numbers = argc - 1 ;
    int max_rank = numbers -1 ;
    if (numbers <= 100)
        chunk_size = 20;
    int start = 0;
    int count_rotation= 0;
    int end = chunk_size - 1;
    while (SA->top)
    {
        if(SA->top->rank >= start && SA->top->rank <= end)
        {
            pb(SA, SB);
            count_rotation = 0;
            int mid = (end-start)/2;
            if(SB->top->rank >= start && SB->top->rank <= start + mid)
                rb(SB);
        }
        else
        {
                ra(SA);
                count_rotation++;
        }
        if( SA-> size == count_rotation)
        {
            start += chunk_size;
            end += chunk_size;
            if (end > max_rank)
                end = max_rank;
            count_rotation = 0;
        }
    }
    while (SB->top)
    {
        while(SB->top->rank != max_rank)
        {
        int max_pos = find_max_pos(SB);
        if (max_pos <= SB -> size / 2)
                rb(SB);
        else
            rrb(SB);
        }
        pa(SA, SB);
        max_rank--;
    }

}