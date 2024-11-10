/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:38:52 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/09 21:46:36 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_min_position(t_stack *ps)
{
	int	i;
	int	min_pos;
	int	min_val;

	if (!ps || ps->size_a < 1)
		return (-1);
	min_pos = 0;
	min_val = ps->stack_a[0];
	i = 1;
	while (i < ps->size_a)
	{
		if (ps->stack_a[i] < min_val)
		{
			min_val = ps->stack_a[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

void	move_min_to_b(t_stack *ps)
{
	int	pos;
	int	middle;

	pos = find_min_position(ps);
	if (pos == -1)
		return ;
	middle = ps->size_a / 2;
	if (pos <= middle)
	{
		while (pos-- > 0)
			ra(ps);
	}
	else
	{
		while (pos++ < ps->size_a)
			rra(ps);
	}
	pb(ps);
}

void	sort_small_stacks(t_stack *ps)
{
	int	original_size;

	if (ps->size_a == 2)
		sort_two(ps);
	else if (ps->size_a == 3)
		sort_three(ps);
	else if (ps->size_a == 4 || ps->size_a == 5)
	{
		original_size = ps->size_a;
		move_min_to_b(ps);
		if (original_size == 5)
			move_min_to_b(ps);
		sort_three(ps);
		while (ps->size_b > 0)
			pa(ps);
	}
}
