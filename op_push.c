/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:53:30 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 20:55:10 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_stack *SA, t_stack *SB)
{
	t_node	*node;

	if (!SB || SB->size == 0)
		return ;
	node = pop(SB);
	if (!node)
		return ;
	push(SA, node);
}

void	op_pb(t_stack *SA, t_stack *SB)
{
	t_node	*node;

	if (!SA || SA->size == 0)
		return ;
	node = pop(SA);
	if (!node)
		return ;
	push(SB, node);
}

void	pa(t_stack *SA, t_stack *SB)
{
	op_pa(SA, SB);
	write(1, "pa\n", 3);
}

void	pb(t_stack *SA, t_stack *SB)
{
	op_pb(SA, SB);
	write(1, "pb\n", 3);
}
