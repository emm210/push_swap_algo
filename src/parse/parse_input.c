#include "push_swap.h"
int parse_input(int argc , char** argv, t_stack *SA)
{
    char** numbers;
    int* values;
    int count;
    int* temp;
    int need_free = 0;
    int i = 0;
    if (argc == 2 ){
        numbers = ft_split(argv[1],' ');
        need_free = 1;
    }
    else 
        numbers = argv + 1;
    while (numbers[i] != NULL)
        i++;
    count = i;
    values = malloc(sizeof(int) * count);
    if(!values)
        return (0);
    i = 0;
    while (i < count)
    {
        long x;

        if (!is_valid_number(numbers[i]))
            error_exit();
        x = atol(numbers[i]);
        if (x < INT_MIN || x > INT_MAX)
            error_exit();
        values[i] = (int)x;
        i++;
    }

    if (has_duplicate(values, count))
        error_exit();
    temp = malloc(sizeof(int) * count);
    if(!temp)
        error_exit();
    copyArray(values, temp, count);
    bubble_sort(temp, count);
    create_stack(SA, temp, values, count);
    free(temp);
    free(values);
    // if (need_free)
    //     free_split(numbers);
    
    return (1);
}