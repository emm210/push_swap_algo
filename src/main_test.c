#include "push_swap.h"
void sort_3(t_stack *A)
{
    t_node* a = A->top;
    t_node* b = a -> next;
    t_node* c = b -> next;
    if (a -> rank > b -> rank && a -> rank > c -> rank)
    {
        ra(A);
    }
    else if (b -> rank > a -> rank  && b -> rank > c -> rank)
    {
        rra(A);
    }
    a = A->top;
    b = a -> next;
    if(a -> rank > b ->rank )
    {
        sa(A);
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


int main(void)
{
    t_stack SA;
    t_stack SB;

    init_stack(&SA);
    init_stack(&SB);

    t_node *node1 = new_node(23, 1);
    t_node *node2 = new_node(12, 0);
    t_node *node3 = new_node(89, 4);
    t_node *node4 = new_node(43, 3);
     t_node *node5 = new_node(30, 2);
    push(&SA, node1);
    push(&SA, node2);
    push(&SA, node4);
     push(&SA, node5);
    push(&SA, node3);
    print_stack(&SA, 'A');

    sort_5(&SA, &SB);
    write(1, "\n", 1);
    print_stack(&SA, 'A');
    print_stack(&SB, 'B');

    return (0);
}
