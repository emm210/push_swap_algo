/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:59:00 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 20:59:05 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *SA)
{
	t_node	*first;
	t_node	*second;
	t_node	*rest;

	if (SA->size < 2)
		return ;
	first = SA->top;
	second = SA->top->next;
	rest = second->next;
	SA->top = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = rest;
	if (rest)
		rest->prev = first;
}

void	swap_b(t_stack *SB)
{
	t_node	*first;
	t_node	*second;
	t_node	*rest;

	if (SB->size < 2)
		return ;
	first = SB->top;
	second = SB->top->next;
	rest = second->next;
	SB->top = second;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = rest;
	if (rest)
		rest->prev = first;
}
