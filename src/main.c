#include "push_swap.h"
void print_stack_debug(t_stack *S, char name)
{
    t_node *cur = S->top;

    printf("Stack %c (size = %d): ", name, S->size);
    while (cur)
    {
        printf("%d(%d) ", cur->value, cur->rank);
        cur = cur->next;
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    t_stack SA;
    t_stack SB;
    if(argc < 2)
        return (0);
    init_stack(&SA);
    init_stack(&SB);
    if (!parse_input(argc, argv, &SA))
        return (1);
    // if (is_sorted(&SA))
    //     do_exit();
    // if (SA.size <= 5)
    //     sort_small(&SA);
    // else
    //     sort_chunk(&SA);
    // free_all(&SA, &SB);
    if(SA.size <= 5)
        sort_small(&SA,&SB ,SA.size);
    else
        big_sort(&SA, &SB, argc);
    print_stack_debug(&SA, 'A');
return (0);
}