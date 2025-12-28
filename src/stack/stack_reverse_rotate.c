/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:57:18 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 20:58:16 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *SA)
{
	t_node	*old_top;
	t_node	*old_bottom;

	if (SA->size < 2)
		return ;
	old_top = SA->top;
	old_bottom = SA->bottom;
	SA->bottom = old_bottom->prev;
	SA->bottom->next = NULL;
	old_top->prev = old_bottom;
	old_bottom->next = old_top;
	old_bottom->prev = NULL;
	SA->top = old_bottom;
}

void	reverse_rotate_b(t_stack *SB)
{
	t_node	*old_top;
	t_node	*old_bottom;

	if (SB->size < 2)
		return ;
	old_top = SB->top;
	old_bottom = SB->bottom;
	SB->bottom = old_bottom->prev;
	SB->bottom->next = NULL;
	old_top->prev = old_bottom;
	old_bottom->next = old_top;
	old_bottom->prev = NULL;
	SB->top = old_bottom;
}
