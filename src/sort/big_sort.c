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

void	big_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	numbers;
	int	start;
	int	end;
	int	max_pos;
	int moves;

	chunk_size = 0;
	numbers = a->size;
	if (numbers <= 100)
		chunk_size = numbers / 6;
	else if (numbers > 100)
		chunk_size = numbers / 14;
	start = 0;
	end = chunk_size - 1;
	while (a->top)
	{
		if (a->top->rank <= start)
		{
			pb(a, b);
			rb(b);
			start++;
			if (end < numbers - 1)
				end++;
		}
		else if (a->top->rank <= end)
		{
			pb(a, b);
			if (b->size > 1 && b->top->next
				&& b->top->next->rank > b->top->rank)
				sb(b);
			start++;
			if (end < numbers - 1)
				end++;
		}
		else
			ra(a);
	}
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
