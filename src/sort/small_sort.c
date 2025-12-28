/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:47:21 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 21:47:25 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_min_pos(t_stack *A)
{
	int		pos;
	int		min_pos;
	t_node	*current;
	int		min_rank;

	pos = 0;
	min_pos = 0;
	if (!A || !A->top)
		return (-1);
	current = A->top;
	min_rank = current->rank;
	while (current)
	{
		if (current->rank < min_rank)
		{
			min_rank = current->rank;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	sort_3(t_stack *A)
{
	int	a;
	int	b;
	int	c;

	a = A->top->rank;
	b = A->top->next->rank;
	c = A->top->next->next->rank;
	if (a > b && b < c && a < c)
		sa(A);
	else if (a > b && b > c)
	{
		sa(A);
		rra(A);
	}
	else if (a > b && b < c && a > c)
		ra(A);
	else if (a < b && b > c && a < c)
	{
		sa(A);
		ra(A);
	}
	else if (a < b && b > c && a > c)
		rra(A);
}

void	sort_4(t_stack *A, t_stack *B)
{
	int	min_pos;

	min_pos = find_min_pos(A);
	while (A->top->rank != 0)
	{
		if (min_pos <= A->size / 2)
			ra(A);
		else
			rra(A);
	}
	pb(A, B);
	sort_3(A);
	pa(A, B);
}

void	sort_5(t_stack *A, t_stack *B)
{
	int	min_pos;

	min_pos = find_min_pos(A);
	while (A->top->rank != 0)
	{
		min_pos = find_min_pos(A);
		if (min_pos <= A->size / 2)
			ra(A);
		else
			rra(A);
	}
	pb(A, B);
	while (A->top->rank != 1)
	{
		min_pos = find_min_pos(A);
		if (min_pos <= A->size / 2)
			ra(A);
		else
			rra(A);
	}
	pb(A, B);
	if (B->top->rank < B->top->next->rank)
		sb(B);
	sort_3(A);
	pa(A, B);
	pa(A, B);
}
