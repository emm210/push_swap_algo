#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_node {
    struct s_node *next;
    struct s_node *prev;
    int value;
    int rank;
} t_node ;

typedef struct s_stack {
   t_node *top ;
   t_node *bottom ;
   int size;
} t_stack;



void    init_stack(t_stack *stack);

t_node  *new_node(int value, int rank);
int     is_empty(t_stack *stack);

void    push(t_stack *stack, t_node *node);
t_node  *pop(t_stack *stack);

void    swap_a(t_stack *stack);
void    swap_b(t_stack *stack);

void    rotate_a(t_stack *stack);
void    rotate_b(t_stack *stack);

void    reverse_rotate_a(t_stack *stack);
void    reverse_rotate_b(t_stack *stack);

/* push operations */
void    pa(t_stack *SA, t_stack *SB);
void    pb(t_stack *SA, t_stack *SB);

void op_pa(t_stack *SA, t_stack *SB);
void op_pb(t_stack *SA, t_stack *SB);

/* swap operations */
void    sa(t_stack *SA);
void    sb(t_stack *SB);
void    ss(t_stack *SA, t_stack *SB);
void    op_ss(t_stack *SA, t_stack *SB);

/* rotate operations */
void    ra(t_stack *SA);
void    rb(t_stack *SB);
void    rr(t_stack *SA, t_stack *SB);
void    op_rr(t_stack *SA, t_stack *SB);

/* reverse rotate operations */
void    rra(t_stack *SA);
void    rrb(t_stack *SB);
void    rrr(t_stack *SA, t_stack *SB);
void    op_rrr(t_stack *SA, t_stack *SB);

void sort_3(t_stack *A);
void sort_4(t_stack *A, t_stack* B);
void sort_5(t_stack *A, t_stack* B);

void parse_input(int argc , char** argv, t_stack *SA);
void create_stack(t_stack *SA,int* temp, int* values,int count);
int is_valid_number(char* str);
void bubble_sort(int* array, int size);
int has_duplicate(int* values,int count);
void copyArray(int source[], int dest[], int size);
void error_exit();
char	**ft_split(char const *s, char c);
void create_stack(t_stack *SA,int* temp, int* values,int count);
t_node *new_node(int value, int rank );
void  free_split(char** numbers);
void sort_small(t_stack* SA,t_stack* SB ,int size);
int find_min_pos(t_stack *A);
void big_sort(t_stack* SA, t_stack* SB);
void free_stack(t_stack *stack);
char** get_numbers(int argc, char** argv ,int *need_free);
void fill_values(char **numbers, int *values, int count);
void build_stack(t_stack *SA, int *values, int count);
int is_sorted(t_stack *stack);
long ft_atol(const char *str);
#endif