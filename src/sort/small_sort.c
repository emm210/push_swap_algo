#include "push_swap.h"
// int find_min_pos(t_stack *A) { 
//     int current_pos = 1; 
//     int min_pos = 0; 
//     t_node *min_node = A->top; 
//     t_node *current_node = A-> top->next; 

//     while(current_node) 
//     { 
//         if (current_node -> rank < min_node->rank) 
//         {
//             min_node = current_node; 
//             min_pos = current_pos;
//         }
//         current_node = current_node -> next;
//         current_pos++; 
//     }
//     return (min_pos); 
// }

int find_min_pos(t_stack *A)
{
    int pos = 0;
    int min_pos = 0;
    t_node *current;
    int min_rank;

    if (!A || !A->top)
        return (-1);

    current = A->top;
    min_rank = current->rank;

    while (current)
    {
        if (current->rank < min_rank)
        {
            min_rank = current->rank;
            min_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return (min_pos);
}

void sort_3(t_stack *A)
{
    int a = A->top->rank;
    int b = A->top->next->rank;
    int c = A->top->next->next->rank;
    if (a > b && b < c && a < c)        
        sa(A);
    else if (a > b && b > c)            
    {
        sa(A);
        rra(A);
    }
    else if (a > b && b < c && a > c) 
        ra(A);
    else if (a < b && b > c && a < c)   
    {
        sa(A);
        ra(A);
    }
    else if (a < b && b > c && a > c) 
        rra(A);
}

void sort_4(t_stack *A, t_stack* B)
{
    int min_pos = find_min_pos(A);
    while(A->top->rank != 0 )
    {
        if (min_pos <= A -> size / 2)
            ra(A);
        else
            rra(A);

    }
    pb(A, B);
    sort_3(A);
    pa(A,B);
}

void sort_5(t_stack *A, t_stack* B)
{
    int min_pos = find_min_pos(A);
    while(A->top->rank != 0)
    {
        min_pos = find_min_pos(A);
        if (min_pos <= A -> size / 2)
            ra(A);
        else
            rra(A);
    }
    pb(A, B);
    while(A->top->rank != 1)
    {
        min_pos = find_min_pos(A);
        if (min_pos <= A -> size / 2)
            ra(A);
        else
            rra(A);
    }
    pb(A, B);
    if(B->top->rank < B->top->next->rank)
        sb(B);
    sort_3(A);
    pa(A,B);
    pa(A,B);
}

