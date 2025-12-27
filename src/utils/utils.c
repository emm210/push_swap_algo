#include "push_swap.h"

int has_duplicate(int* values,int count)
{
    int i = 0;
    while(i < count)
    {
        int j = i + 1;
        while(j < count)
        {
            if (values[i] == values[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

void ft_swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* array, int size)
{
    int i = 0;
    while (i < size - 1)
    {
        int j = 0;
        while (j < size - 1 - i){
            if (array[j] > array[j + 1])
                ft_swap(&array[j], &array[j+1]);
            j++;
        }
        i++;
    }
}

int is_digit(char c){
    return ((c >= '0' && c <= '9' ));
    }

int is_valid_number(char* str)
{
    int i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    if(str[i] == '\0')
        return (0);
    while (str[i])
    {
        if(!is_digit(str[i]))
            return (0);
        i++;
    }
    return (1);
}
// int is_empty(t_stack *stack )
// {
//      if (stack->top == NULL )
//         return(1);
//      return(0);
// }


// void push(t_stack *stack, t_node* node)
// {
//     if (is_empty(stack))
//     {
//         stack->top = node;
//         stack->bottom = node;
//         node -> prev = NULL;
//         node -> next = NULL;
//     }
//     else
//     {
//         node->next = stack->top;
//         stack->top->prev = node;
//         node -> prev = NULL;
//         stack->top = node;
//     }
//      stack->size++;
// }

void create_stack(t_stack *SA,int* temp, int* values,int count)
{
    int i = count-1;
    while (i >= 0)
    {
        int j = 0;
        int rank = -1;
        while (j < count)
        {
            if (values[i] == temp[j]){
                rank = j;
                break;
            }
            j++;
        }
         if (rank == -1)
            error_exit();
        push(SA,new_node(values[i], rank));
        i--;
    }
}

void error_exit()
{
    write(2, "Error\n", 6);
    exit(1);
}

 void  free_split(char** str){
    int i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
 }