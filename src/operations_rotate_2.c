/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:38:42 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/09 21:17:05 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rr(t_stack *ps)
{
	if (!ps)
		return ;
	if (ps->size_a >= 2)
		rotate_stack(ps->stack_a, ps->size_a);
	if (ps->size_b >= 2)
		rotate_stack(ps->stack_b, ps->size_b);
	write(1, "rr\n", 3);
}

void	rra(t_stack *ps)
{
	if (!ps || ps->size_a < 2)
		return ;
	reverse_rotate_stack(ps->stack_a, ps->size_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *ps)
{
	if (!ps || ps->size_b < 2)
		return ;
	reverse_rotate_stack(ps->stack_b, ps->size_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *ps)
{
	if (!ps)
		return ;
	if (ps->size_a >= 2)
		reverse_rotate_stack(ps->stack_a, ps->size_a);
	if (ps->size_b >= 2)
		reverse_rotate_stack(ps->stack_b, ps->size_b);
	write(1, "rrr\n", 4);
}
