#include "push_swap.h"

void free_stack(t_stack *stack)
{
    t_node *cur;
    t_node *next;

    cur = stack->top;
    while (cur)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}

char **get_numbers(int argc, char **argv, int *need_free)
{
    if (argc == 2)
    {
        *need_free = 1;
        return (ft_split(argv[1], ' '));
    }
    *need_free = 0;
    return (argv + 1);
}

void fill_values(char **numbers, int *values, int count)
{
    int i;
    long x;

    i = 0;
    while (i < count)
    {
        if (!is_valid_number(numbers[i]))
            error_exit();
        x = ft_atol(numbers[i]);
        if (x < INT_MIN || x > INT_MAX)
            error_exit();
        values[i] = (int)x;
        i++;
    }
}

void build_stack(t_stack *SA, int *values, int count)
{
    int *temp;

    temp = malloc(sizeof(int) * count);
    if (!temp)
        error_exit();
    copyArray(values, temp, count);
    bubble_sort(temp, count);
    create_stack(SA, temp, values, count);
    free(temp);
}

int is_sorted(t_stack *stack)
{
    t_node *cur;

    if (!stack || stack->size < 2)
        return (1);

    cur = stack->top;
    while (cur->next)
    {
        if (cur->rank > cur->next->rank)
            return (0);
        cur = cur->next;
    }
    return (1);
}




