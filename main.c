/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:52:14 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 20:52:37 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *SA, t_stack *SB, int size)
{
	if (size == 2)
	{
		if (SA->top->rank > SA->top->next->rank)
			sa(SA);
	}
	else if (size == 3)
		sort_3(SA);
	else if (size == 4)
		sort_4(SA, SB);
	else
		sort_5(SA, SB);
}

int	main(int argc, char *argv[])
{
	t_stack	sa;
	t_stack	sb;

	if (argc < 2)
		return (0);
	init_stack(&sa);
	init_stack(&sb);
	parse_input(argc, argv, &sa);
	if (is_sorted(&sa))
	{
		free_stack(&sa);
		return (0);
	}
	if (sa.size <= 5)
		sort_small(&sa, &sb, sa.size);
	else
		big_sort(&sa, &sb);
	free_stack(&sa);
	free_stack(&sb);
	return (0);
}
