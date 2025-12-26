#include "push_swap.h"
// int parse_input(int argc , char** argv, t_stack *SA)
// {
//     char** numbers;
//     int* values;
//     int count;
//     int* temp;
//     int need_free = 0;
//     int i = 0;
//     if (argc == 2 ){
//         numbers = ft_split(argv[1],' ');
//         need_free = 1;
//     }
//     else 
//         numbers = argv + 1;
//     while (numbers[i] != NULL)
//         i++;
//     count = i;
//     values = malloc(sizeof(int) * count);
//     if(!values)
//         return (0);
//     i = 0;
//     while (i < count)
//     {
//         long x;

//         if (!is_valid_number(numbers[i]))
//             error_exit();
//         x = atol(numbers[i]);
//         if (x < INT_MIN || x > INT_MAX)
//             error_exit();
//         values[i] = (int)x;
//         i++;
//     }

//     if (has_duplicate(values, count))
//         error_exit();
//     temp = malloc(sizeof(int) * count);
//     if(!temp)
//         error_exit();
//     copyArray(values, temp, count);
//     bubble_sort(temp, count);
//     create_stack(SA, temp, values, count);
//     free(temp);
//     free(values);
//     if (need_free)
//         free_split(numbers);
//     return (1);
// }

int parse_input(int argc, char** argv, t_stack *SA)
{
    char** numbers;
    int* values = NULL;
    int count;
    int* temp = NULL;
    int need_free = 0;
    int i = 0;

    // Parse input
    if (argc == 2) {
        numbers = ft_split(argv[1], ' ');
        if (!numbers)
            error_exit();
        need_free = 1;
    }
    else 
        numbers = argv + 1;

    // Count elements
    while (numbers[i] != NULL)
        i++;
    count = i;

    // Allocate values array
    values = malloc(sizeof(int) * count);
    if (!values) {
        if (need_free)
            free_split(numbers);
        error_exit();
    }

    // Parse and validate numbers
    i = 0;
    while (i < count)
    {
        long x;

        if (!is_valid_number(numbers[i])) {
            free(values);
            if (need_free)
                free_split(numbers);
            error_exit();
        }

        x = atol(numbers[i]);
        if (x < INT_MIN || x > INT_MAX) {
            free(values);
            if (need_free)
                free_split(numbers);
            error_exit();
        }

        values[i] = (int)x;
        i++;
    }

    // Check duplicates
    if (has_duplicate(values, count)) {
        free(values);
        if (need_free)
            free_split(numbers);
        error_exit();
    }

    // Create temp array for ranking
    temp = malloc(sizeof(int) * count);
    if (!temp) {
        free(values);
        if (need_free)
            free_split(numbers);
        error_exit();
    }

    // Create stack
    copyArray(values, temp, count);
    bubble_sort(temp, count);
    create_stack(SA, temp, values, count);

    // Cleanup
    free(temp);
    free(values);
    if (need_free)
        free_split(numbers);

    return (1);
}