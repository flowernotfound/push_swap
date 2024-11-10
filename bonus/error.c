/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:35:12 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/09 23:00:15 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error_exit(t_stack *ps, t_error err)
{
	int	flag;

	if (ps)
		free_stacks(ps);
	if (err != ERR_NONE)
		write(2, "Error\n", 6);
	if (err != ERR_NONE)
		flag = 1;
	else
		flag = 0;
	exit(flag);
}
