#include "push_swap.h"
// void print_stack_debug(t_stack *S, char name)
// {
//     t_node *cur = S->top;

//     printf("Stack %c (size = %d): ", name, S->size);
//     while (cur)
//     {
//         printf("%d(%d) ", cur->value, cur->rank);
//         cur = cur->next;
//     }
//     printf("\n");
// }
void sort_small(t_stack* SA, t_stack* SB,int size)
{
    if(size == 2)
    {
        if (SA->top->rank > SA->top->next->rank)
            sa(SA);
    }
    else if(size == 3)
        sort_3(SA);
    else if (size == 4)
        sort_4(SA, SB);
    else 
        sort_5(SA, SB);

}

int main(int argc, char* argv[])
{
    t_stack SA;
    t_stack SB;

    if(argc < 2)
        return (0);

    init_stack(&SA);
    init_stack(&SB);

    parse_input(argc, argv, &SA);
    if (is_sorted(&SA))
    {
        free_stack(&SA);
        return (0);
    }
    if(SA.size <= 5)
        sort_small(&SA,&SB ,SA.size);
    else
        big_sort(&SA, &SB);
    //print_stack_debug(&SA, 'A');
    free_stack(&SA);
    free_stack(&SB);
return (0);
}
