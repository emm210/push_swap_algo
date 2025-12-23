#include "push_swap.h"
int is_in(int count , int rank, int start , int end)
{
    int i = 0;
    while (i < count)
    {
        if (rank >= start && rank <= end)
            return (1);
        i++;
    }
return (0);
}

void big_sort(t_stack* SA, t_stack* SB, int argc)
{
    int chunk_size;
    int numbers = argc - 1 ;
    if (numbers <= 100)
        chunk_size = 20;
    int start = 0;
    int end = chunk_size - 1;
    while(end != numbers)
    {
        int j = 0;
        while (j < chunk_size)
        {
            if(is_in(argc, SA->top->rank , start , end ))
            {
                while(SA->top->rank )
                {
                    ra(SA);
                    pb(SA, SB);
                }
            }
            SA->top->next;
            j++;
        }
    start +=chunk_size;
    end += chunk_size;
    }
}