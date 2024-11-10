/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:38:38 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/09 21:16:59 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stack *ps)
{
	if (!ps || ps->size_a < 2)
		return ;
	rotate_stack(ps->stack_a, ps->size_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *ps)
{
	if (!ps || ps->size_b < 2)
		return ;
	rotate_stack(ps->stack_b, ps->size_b);
	write(1, "rb\n", 3);
}
