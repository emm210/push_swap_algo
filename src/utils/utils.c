#include "push_swap.h"

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

