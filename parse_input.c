/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:55:29 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 20:55:31 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i] != NULL)
		i++;
	return (i);
}

void	parse_input(int argc, char **argv, t_stack *SA)
{
	char	**numbers;
	int		*values;
	int		count;

	numbers = get_numbers(argc, argv);
	if (!numbers)
		error_exit();
	count = count_numbers(numbers);
	if (count == 0)
		error_exit();
	values = malloc(sizeof(int) * count);
	if (!values)
		error_exit();
	fill_values(numbers, values, count);
	if (has_duplicate(values, count))
		error_exit();
	build_stack(SA, values, count);
	free(values);
	free_split(numbers);
}
// void parse_input(int argc, char** argv, t_stack *SA)
// {
//     char** numbers;
//     int* values = NULL;
//     int count;
//     int* temp = NULL;
//     int need_free = 0;
//     int i = 0;
//     numbers = get_numbers(argc, argv + 1, SA);
//     count = count_numbers(numbers);
//     values = malloc(sizeof(int) * count);
//     if (!values) {
//         if (need_free)
//             free_split(numbers);
//         error_exit();
//     }
//     i = 0;
//     while (i < count)
//     {
//         long x;

//         if (!is_valid_number(numbers[i])) {
//             free(values);
//             if (need_free)
//                 free_split(numbers);
//             error_exit();
//         }

//         x = atol(numbers[i]);
//         if (x < INT_MIN || x > INT_MAX) {
//             free(values);
//             if (need_free)
//                 free_split(numbers);
//             error_exit();
//         }

//         values[i] = (int)x;
//         i++;
//     }
//     if (has_duplicate(values, count)) {
//         free(values);
//         if (need_free)
//             free_split(numbers);
//         error_exit();
//     }
//     temp = malloc(sizeof(int) * count);
//     if (!temp) {
//         free(values);
//         if (need_free)
//             free_split(numbers);
//         error_exit();
//     }
//     copyArray(values, temp, count);
//     bubble_sort(temp, count);
//     create_stack(SA, temp, values, count);
//     free(temp);
//     free(values);
//     if (need_free)
//         free_split(numbers);
//     return (1);
// }
