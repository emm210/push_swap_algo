/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:00:49 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 21:00:51 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_copy_array(int src[], int dest[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
				ft_swap(&array[j], &array[j + 1]);
			j++;
		}
		i++;
	}
}

void	create_stack(t_stack *SA, int *temp, int *values, int count)
{
	int	i;
	int	j;
	int	rank;

	i = count - 1;
	while (i >= 0)
	{
		j = 0;
		rank = -1;
		while (j < count)
		{
			if (values[i] == temp[j])
			{
				rank = j;
				break ;
			}
			j++;
		}
		if (rank == -1)
			error_exit();
		push(SA, new_node(values[i], rank));
		i--;
	}
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
