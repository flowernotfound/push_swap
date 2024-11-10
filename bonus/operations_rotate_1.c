/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:50:33 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/10 03:18:36 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	ra(t_stack *ps)
{
	if (!ps || ps->size_a < 2)
		return ;
	rotate_stack(ps->stack_a, ps->size_a);
}

void	rb(t_stack *ps)
{
	if (!ps || ps->size_b < 2)
		return ;
	rotate_stack(ps->stack_b, ps->size_b);
}

void	rr(t_stack *ps)
{
	if (!ps)
		return ;
	if (ps->size_a >= 2)
		rotate_stack(ps->stack_a, ps->size_a);
	if (ps->size_b >= 2)
		rotate_stack(ps->stack_b, ps->size_b);
}

void	rra(t_stack *ps)
{
	if (!ps || ps->size_a < 2)
		return ;
	reverse_rotate_stack(ps->stack_a, ps->size_a);
}

void	rrb(t_stack *ps)
{
	if (!ps || ps->size_b < 2)
		return ;
	reverse_rotate_stack(ps->stack_b, ps->size_b);
}
