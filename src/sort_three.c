/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:38:55 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/09 21:20:59 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	select_action(int first, int second, int third)
{
	if (first > second && second < third && first < third)
		return (1);
	else if (first > second && second > third)
		return (2);
	else if (first > second && second < third && first > third)
		return (3);
	else if (first < second && second > third && first < third)
		return (4);
	else if (first < second && second > third && first > third)
		return (5);
	return (0);
}

void	execute_sort(t_stack *ps, int action)
{
	if (action == 1)
		sa(ps);
	else if (action == 2)
	{
		sa(ps);
		rra(ps);
	}
	else if (action == 3)
		ra(ps);
	else if (action == 4)
	{
		sa(ps);
		ra(ps);
	}
	else if (action == 5)
		rra(ps);
}

void	sort_three(t_stack *ps)
{
	int	first;
	int	second;
	int	third;
	int	action;

	if (!ps || ps->size_a != 3)
		return ;
	first = ps->stack_a[0];
	second = ps->stack_a[1];
	third = ps->stack_a[2];
	action = select_action(first, second, third);
	execute_sort(ps, action);
}
