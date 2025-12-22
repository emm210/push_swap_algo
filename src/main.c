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
t_node *new_node(int value, int rank )
{
    t_node *node = malloc(sizeof(t_node));

    if(!node)
        return (NULL);

    node->value = value;
    node->rank = rank;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

void init_stack(t_stack *stack)
{
    stack->size = 0;
    stack->top = NULL;
    stack->bottom = NULL;
}

int main(int argc, char* argv[])
{
    t_stack SA;
    //t_stack SB;
    if(argc < 2)
        return (0);
    init_stack(&SA);
    if (!parse_input(argc, argv, &SA))
        return (1);
    // if (is_sorted(&SA))
    //     do_exit();
    // if (SA.size <= 5)
    //     sort_small(&SA);
    // else
    //     sort_chunk(&SA);
    // free_all(&SA, &SB);
    print_stack(&SA, 'A');
return (0);
}