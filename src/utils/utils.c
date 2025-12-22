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

void bubble_sort(int* array, int size)
{
    int i = 0;
    while (i < size)
    {
        int j = i + 1;
        while (j < size - 1 - i){
            if (array[j] > array[j + 1])
                ft_swap(&array[j], array[j+1]);
            j++;
        }
        i++;
    }
}
void ft_swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int is_digit(char c){
    return ((c >='0' && c =< '9' ));
    }

int valid_number(char* str)
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