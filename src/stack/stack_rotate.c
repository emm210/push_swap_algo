/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:58:38 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 20:58:44 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *SA)
{
	t_node	*old_top;
	t_node	*old_bottom;

	if (SA->size < 2)
		return ;
	old_top = SA->top;
	old_bottom = SA->bottom;
	SA->top = SA->top->next;
	SA->top->prev = NULL;
	old_bottom->next = old_top;
	old_top->prev = old_bottom;
	old_top->next = NULL;
	SA->bottom = old_top;
}

void	rotate_b(t_stack *SB)
{
	t_node	*old_top;
	t_node	*old_bottom;

	if (SB->size < 2)
		return ;
	old_top = SB->top;
	old_bottom = SB->bottom;
	SB->top = old_top->next;
	SB->top->prev = NULL;
	old_bottom->next = old_top;
	old_top->prev = old_bottom;
	old_top->next = NULL;
	SB->bottom = old_top;
}
