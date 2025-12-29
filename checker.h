/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:53:10 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 20:53:12 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H
# include "get_next_line.h"
# include "push_swap.h"

void	check_sorted(t_stack *sa, t_stack *sb);
void	execute_op(int op, t_stack *SA, t_stack *SB);
int		ft_streq(const char *s1, const char *s2);
int		get_op_type(char *str);

#endif
