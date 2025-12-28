/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:54:44 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 20:54:48 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *SA)
{
	swap_a(SA);
	write(1, "sa\n", 3);
}

void	sb(t_stack *SB)
{
	swap_a(SB);
	write(1, "sb\n", 3);
}

void	op_ss(t_stack *SA, t_stack *SB)
{
	swap_a(SA);
	swap_b(SB);
}

void	ss(t_stack *SA, t_stack *SB)
{
	op_ss(SA, SB);
	write(1, "ss\n", 3);
}
