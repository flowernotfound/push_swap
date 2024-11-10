/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:38:46 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/09 21:17:11 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack *ps)
{
	if (!ps || ps->size_a < 2)
		return ;
	swap(&ps->stack_a[0], &ps->stack_a[1]);
	write(1, "sa\n", 3);
}

void	sb(t_stack *ps)
{
	if (!ps || ps->size_b < 2)
		return ;
	swap(&ps->stack_b[0], &ps->stack_b[1]);
	write(1, "sb\n", 3);
}

void	ss(t_stack *ps)
{
	if (!ps)
		return ;
	if (ps->size_a >= 2)
		swap(&ps->stack_a[0], &ps->stack_a[1]);
	if (ps->size_b >= 2)
		swap(&ps->stack_b[0], &ps->stack_b[1]);
	write(1, "ss\n", 3);
}
