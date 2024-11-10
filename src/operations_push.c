/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:38:35 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/09 21:16:54 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_stack *ps)
{
	int	i;

	if (!ps || ps->size_b < 1 || ps->size_a >= ps->max_size)
		return ;
	i = ps->size_a;
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = ps->stack_b[0];
	ps->size_a++;
	i = 0;
	while (i < ps->size_b - 1)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->size_b--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *ps)
{
	int	i;

	if (!ps || ps->size_a < 1 || ps->size_b >= ps->max_size)
		return ;
	i = ps->size_b;
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = ps->stack_a[0];
	ps->size_b++;
	i = 0;
	while (i < ps->size_a - 1)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->size_a--;
	write(1, "pb\n", 3);
}
