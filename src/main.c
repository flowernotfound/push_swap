/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:38:30 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/10 15:21:00 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*ps;
	t_error	err;

	if (ac < 2)
		return (0);
	ps = init_program(ac, av);
	if (!ps)
		return (0);
	err = process_arguments(ps, ac, av);
	if (err != ERR_NONE)
		error_exit(ps, err);
	if (!is_sorted(ps))
		sort_stacks(ps);
	free_stacks(ps);
	return (0);
}
