#include "push_swap.h"
// int cheapest_direction(t_stack* A, int start , int end)
// {
//     int dist_top = 0;
//     int dist_bottom = 0;
//     t_node* current = A->top;
//     t_node* current_b = A->bottom;
//     while(current && current_b)
//     {
//         if ((current->rank >= start && current->rank <= end) || 
//             (current_b->rank >= start && current_b->rank <= end))
//             break;     
//         current = current->next;
//         dist_top++;
//         current_b = current_b->prev;
//         dist_bottom++;
//     }
//     if(dist_top <= dist_bottom)
//         return (1);
//     else
//         return (0);
// }
int cheapest_direction(t_stack *A, int start, int end)
{
    t_node *top = A->top;
    t_node *bot = A->bottom;
    int dist_top = 0;
    int dist_bot = 0;
    int half = A->size / 2;

    while (dist_top <= half || dist_bot <= half)
    {
        if (top && top->rank >= start && top->rank <= end)
            return (1); 

        if (bot && bot->rank >= start && bot->rank <= end)
            return (0); 

        if (top)
        {
            top = top->next;
            dist_top++;
        }
        if (bot)
        {
            bot = bot->prev;
            dist_bot++;
        }
    }
    return (1);
}


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
    else if(numbers > 100)
        chunk_size = 40;
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
            if (cheapest_direction(SA, start , end)){
                ra(SA);
                count_rotation++;
            }
            else
            {
                rra(SA);
                count_rotation++;
            }
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