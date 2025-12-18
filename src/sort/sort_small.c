#include "push_swap.h"

void sort_3(t_stack *A)
{
    t_node* a = A->top;
    t_node* b = a -> next;
    t_node* c = b -> next;
    if(a-> rank < b-> rank && b-> rank < c-> rank)
        return ;
    else if (a->rank < c->rank && c->rank < b->rank)
    {
        sa(A);
        ra(A);
    }
    else if (b->rank < a->rank && a->rank < c->rank)
    {
        sa(A);
    }
    else if (b->rank < c->rank && c->rank < a->rank)
    {
        rra(A);
    }
    else if (c->rank < a->rank && a->rank < b->rank)
    {
        ra(A);
    }
    else if (c->rank < b->rank && b->rank< a->rank)
    {
        sa(A);
        rra(A);
    }

}

int find_min_pos(t_stack *A) { 
    int current_pos = 1; 
    int min_pos = 0; 
    t_node *min_node = A->top; 
    t_node *current_node = A-> top->next; 
    while(current_node) 
    { 
        if (current_node -> rank < min_node->rank) 
        {
            min_node = current_node; 
            min_pos = current_pos;
        }
        current_node = current_node -> next;
        current_pos++; 
    }
    return (min_pos); 
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
        if (min_pos <= A -> size / 2)
            ra(A);
        else
            rra(A);

    }
    pb(A, B);
    min_pos = find_min_pos(A);
    while(A->top->rank != 1)
    {
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