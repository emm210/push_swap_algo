/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:52:58 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 20:53:01 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	ft_streq(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	execute_op(int op, t_stack *SA, t_stack *SB)
{
	if (op == 1)
		swap_a(SA);
	else if (op == 2)
		swap_b(SB);
	else if (op == 3)
		op_ss(SA, SB);
	else if (op == 4)
		op_pa(SA, SB);
	else if (op == 5)
		op_pb(SA, SB);
	else if (op == 6)
		rotate_a(SA);
	else if (op == 7)
		rotate_b(SB);
	else if (op == 8)
		op_rr(SA, SB);
	else if (op == 9)
		reverse_rotate_a(SA);
	else if (op == 10)
		reverse_rotate_b(SB);
	else if (op == 11)
		op_rrr(SA, SB);
}

int	get_op_type(char *str)
{
	if (ft_streq("sa\n", str))
		return (1);
	else if (ft_streq("sb\n", str))
		return (2);
	else if (ft_streq("ss\n", str))
		return (3);
	else if (ft_streq("pa\n", str))
		return (4);
	else if (ft_streq("pb\n", str))
		return (5);
	else if (ft_streq("ra\n", str))
		return (6);
	else if (ft_streq("rb\n", str))
		return (7);
	else if (ft_streq("rr\n", str))
		return (8);
	else if (ft_streq("rra\n", str))
		return (9);
	else if (ft_streq("rrb\n", str))
		return (10);
	else if (ft_streq("rrr\n", str))
		return (11);
	else
		return (-1);
}

void	check_sorted(t_stack *sa, t_stack *sb)
{
	if (is_sorted(sa) && is_empty(sb))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	t_stack	sa;
	t_stack	sb;
	char	*str;
	int		op;

	if (argc < 2)
		return (0);
	init_stack(&sa);
	init_stack(&sb);
	parse_input(argc, argv, &sa);
	str = get_next_line(0);
	while (str && str[0] != '\0')
	{
		op = get_op_type(str);
		if (op == -1)
			error_exit();
		execute_op(op, &sa, &sb);
		free(str);
		str = get_next_line(0);
	}
	check_sorted(&sa, &sb);
	free_stack(&sa);
	free_stack(&sb);
	return (0);
}
