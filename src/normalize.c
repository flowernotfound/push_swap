/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:55:21 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/09 21:20:32 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*prepare_sorted_array(t_stack *ps)
{
	int	*sorted;
	int	i;

	if (!ps || ps->size_a < 1)
		error_exit(ps, ERR_MALLOC);
	sorted = malloc(sizeof(int) * ps->size_a);
	if (!sorted)
		error_exit(ps, ERR_MALLOC);
	i = 0;
	while (i < ps->size_a)
	{
		sorted[i] = ps->stack_a[i];
		i++;
	}
	return (sorted);
}

void	bubble_sort_array(int *sorted, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (sorted[j] > sorted[j + 1])
			{
				temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	normalize_stack(t_stack *ps)
{
	int	*sorted;
	int	i;
	int	rank;

	sorted = prepare_sorted_array(ps);
	bubble_sort_array(sorted, ps->size_a);
	i = 0;
	while (i < ps->size_a)
	{
		rank = 0;
		while (rank < ps->size_a && sorted[rank] != ps->stack_a[i])
			rank++;
		ps->stack_a[i] = rank;
		i++;
	}
	free(sorted);
}
