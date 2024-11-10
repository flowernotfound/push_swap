/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:50:33 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/10 03:18:45 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	rrr(t_stack *ps)
{
	if (!ps)
		return ;
	if (ps->size_a >= 2)
		reverse_rotate_stack(ps->stack_a, ps->size_a);
	if (ps->size_b >= 2)
		reverse_rotate_stack(ps->stack_b, ps->size_b);
}
