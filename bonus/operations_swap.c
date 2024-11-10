/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:50:33 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/10 03:16:45 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	sa(t_stack *ps)
{
	if (!ps || ps->size_a < 2)
		return ;
	swap(&ps->stack_a[0], &ps->stack_a[1]);
}

void	sb(t_stack *ps)
{
	if (!ps || ps->size_b < 2)
		return ;
	swap(&ps->stack_b[0], &ps->stack_b[1]);
}

void	ss(t_stack *ps)
{
	if (!ps)
		return ;
	if (ps->size_a >= 2)
		swap(&ps->stack_a[0], &ps->stack_a[1]);
	if (ps->size_b >= 2)
		swap(&ps->stack_b[0], &ps->stack_b[1]);
}
