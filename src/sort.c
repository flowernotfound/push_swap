/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:39:02 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/09 21:46:22 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_chunk_size(int size)
{
	int	chunk_count;
	int	div_num;

	if (size <= 100)
	{
		chunk_count = 5;
		div_num = size / chunk_count;
	}
	else
	{
		chunk_count = 11;
		div_num = size / chunk_count;
	}
	return (div_num);
}

void	move_to_b(t_stack *ps)
{
	int	max_div;
	int	i;

	max_div = get_chunk_size(ps->size_a);
	i = 0;
	while (ps->size_a > 0)
	{
		if (ps->stack_a[0] <= i)
		{
			pb(ps);
			rb(ps);
			i++;
		}
		else if (ps->stack_a[0] <= i + max_div)
		{
			pb(ps);
			i++;
		}
		else
			ra(ps);
	}
}

int	find_max_pos(t_stack *ps)
{
	int	i;
	int	max;
	int	max_pos;

	if (ps->size_b == 0)
		return (-1);
	max = ps->stack_b[0];
	max_pos = 0;
	i = 1;
	while (i < ps->size_b)
	{
		if (ps->stack_b[i] > max)
		{
			max = ps->stack_b[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

void	move_to_a(t_stack *ps)
{
	int	pos;

	while (ps->size_b > 0)
	{
		pos = find_max_pos(ps);
		if (pos <= ps->size_b / 2)
		{
			while (pos-- > 0)
				rb(ps);
		}
		else
		{
			while (pos++ < ps->size_b)
				rrb(ps);
		}
		pa(ps);
	}
}

void	sort_stacks(t_stack *ps)
{
	if (!ps || is_sorted(ps))
		return ;
	if (ps->size_a <= 5)
		sort_small_stacks(ps);
	else
	{
		normalize_stack(ps);
		move_to_b(ps);
		move_to_a(ps);
	}
}
