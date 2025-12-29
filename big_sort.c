/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:43:16 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 21:43:27 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_max_pos(t_stack *sa)
{
	int		pos;
	int		max_pos;
	t_node	*current;
	int		max_rank;

	pos = 0;
	max_pos = 0;
	if (!sa || !sa->top)
		return (-1);
	current = sa->top;
	max_rank = current->rank;
	while (current)
	{
		if (current->rank > max_rank)
		{
			max_rank = current->rank;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

void	push_first_to_b(t_stack *a, t_stack *b, t_var var)
{
	while (a->top)
	{
		if (a->top->rank <= var.start)
		{
			pb(a, b);
			rb(b);
			var.start++;
			if (var.end < var.numbers - 1)
				var.end++;
		}
		else if (a->top->rank <= var.end)
		{
			pb(a, b);
			if (b->size > 1 && b->top->next
				&& b->top->next->rank > b->top->rank)
				sb(b);
			var.start++;
			if (var.end < var.numbers - 1)
				var.end++;
		}
		else
			ra(a);
	}
}

void	push_back_to_a(t_stack *b, t_stack *a)
{
	int	max_pos;
	int	moves;

	max_pos = 0;
	moves = 0;
	while (b->size > 0)
	{
		max_pos = find_max_pos(b);
		if (max_pos <= b->size / 2)
		{
			moves = max_pos;
			while (moves-- > 0)
				rb(b);
		}
		else
		{
			moves = b->size - max_pos;
			while (moves-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

void	big_sort(t_stack *a, t_stack *b)
{
	t_var	var;

	var.chunk_size = 0;
	var.numbers = a->size;
	if (var.numbers <= 100)
		var.chunk_size = var.numbers / 6;
	else if (var.numbers > 100)
		var.chunk_size = var.numbers / 14;
	var.start = 0;
	var.end = var.chunk_size - 1;
	push_first_to_b(a, b, var);
	push_back_to_a(b, a);
}
