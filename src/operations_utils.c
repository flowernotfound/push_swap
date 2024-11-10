/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:38:49 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/09 20:38:49 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	rotate_stack(int *stack, int size)
{
	int	temp;
	int	i;

	if (size < 2)
		return ;
	temp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = temp;
}

void	reverse_rotate_stack(int *stack, int size)
{
	int	temp;
	int	i;

	if (size < 2)
		return ;
	temp = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
}
