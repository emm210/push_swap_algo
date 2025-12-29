/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:53:48 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 20:53:50 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *SA)
{
	reverse_rotate_a(SA);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *SB)
{
	reverse_rotate_b(SB);
	write(1, "rrb\n", 4);
}

void	op_rrr(t_stack *SA, t_stack *SB)
{
	reverse_rotate_a(SA);
	reverse_rotate_a(SB);
}

void	rrr(t_stack *SA, t_stack *SB)
{
	op_rrr(SA, SB);
	write(1, "rrr\n", 3);
}
