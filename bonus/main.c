/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:38:11 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/10 03:12:01 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

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
	err = execute_commands(ps);
	print_result(ps, err);
	free_stacks(ps);
	return (0);
}
