#include "push_swap.h"

void print_stack(t_stack *stack, char name)
{
    t_node *current;

    printf("Stack %c (size = %d): ", name, stack->size);

    current = stack->top;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}


// void sort_5(t_stack *A, t_stack *B)
// {
//     int min_pos;
//     while (A->top->rank != 0)
//     {
//         min_pos = find_min_pos(A);
//         if (min_pos <= A->size / 2)
//             ra(A);
//         else
//             rra(A);
//     }
//     pb(A, B);
//     while (A->top->rank != 1)
//     {
//         min_pos = find_min_pos(A);
//         if (min_pos <= A->size / 2)
//             ra(A);
//         else
//             rra(A);
//     }
//     pb(A, B);
//     if (B->top->rank < B->top->next->rank)
//         sb(B);
//     sort_3(A);
//     printf("After sort_3, Stack A: ");
//     print_stack(A, 'A');
//     pa(A, B);
//     pa(A, B);
// }

// void sort_3(t_stack *A)
// {
//     t_node* a = A->top;
//     t_node* b = a -> next;
//     t_node* c = b -> next;
//     if (a -> rank > b -> rank && a -> rank > c -> rank)
//     {
//         ra(A);
//     }
//     else if (b -> rank > a -> rank  && b -> rank > c -> rank)
//     {
//         rra(A);
//     }
//     a = A->top;
//     b = a -> next;
//     if(a -> rank > b ->rank )
//     {
//         sa(A);
//     }
// void sort_5(t_stack *A, t_stack *B)
// {
//     int min_pos;
//     while (A->top->rank != 0)
//     {
//         min_pos = find_min_pos(A);
//         if (min_pos <= A->size / 2)
//             ra(A);
//         else
//             rra(A);
//     }
//     pb(A, B);
//     while (A->top->rank != 1)
//     {
//         min_pos = find_min_pos(A);
//         if (min_pos <= A->size / 2)
//             ra(A);
//         else
//             rra(A);
//     }
//     pb(A, B);
//     if (B->top->rank < B->top->next->rank)
//         sb(B);
//     sort_3(A);
//     printf("After sort_3, Stack A: ");
//     print_stack(A, 'A');
//     pa(A, B);
// void sort_5(t_stack *A, t_stack *B)
// {
//     int min_pos;
//     while (A->top->rank != 0)
//     {
//         min_pos = find_min_pos(A);
//         if (min_pos <= A->size / 2)
//             ra(A);
//         else
//             rra(A);
//     }
//     pb(A, B);
//     while (A->top->rank != 1)
//     {
//         min_pos = find_min_pos(A);
//         if (min_pos <= A->size / 2)
//             ra(A);
//         else
//             rra(A);
//     }
//     pb(A, B);
//     if (B->top->rank < B->top->next->rank)
//         sb(B);
//     sort_3(A);
//     printf("After sort_3, Stack A: ");
//     print_stack(A, 'A');
//     pa(A, B);
//     pa(A, B);
// }
//     pa(A, B);
// }
// }

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

// void sort_4(t_stack *A, t_stack* B)
// {
//     int min_pos = find_min_pos(A);
//     while(A->top->rank != 0 )
//     {
//         if (min_pos <= A -> size / 2)
//             ra(A);
//         else
//             rra(A);

//     }
//     pb(A, B);
//     sort_3(A);
//     pa(A,B);
// }

// void sort_5(t_stack *A, t_stack* B)
// {
//     int min_pos = find_min_pos(A);
//     while(A->top->rank != 0)
//     {
//         if (min_pos <= A -> size / 2)
//             ra(A);
//         elseprint_stack(&A, 'A');
//             rra(A);

//     }
//     pb(A, B);
//     min_pos = find_min_pos(A);
//     while(A->top->rank != 1)
//     {
//         if (min_pos <= A -> size / 2)
//             ra(A);
//         else
//             rra(A);

//     }print_stack(&A, 'A');
//     pb(A, B);
//     if(B->top->rank < B->top->next->rank)
//         sb(B);
//     sort_3(A);
//     pa(A,B);
//     pa(A,B);
// }

int main(void)
{
    t_stack A;

    init_stack(&A);
    t_stack B;

    init_stack(&B);
    push(&A, new_node(1, 0));
    push(&A, new_node(2, 1));
    push(&A, new_node(3, 2));
    push(&A, new_node(4, 3));
    push(&A, new_node(5, 4));

    print_stack(&A, 'A');
    sort_5(&A, &B);
    print_stack(&A, 'A');
}


