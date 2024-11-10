/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_commands_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:39:06 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/10 04:11:09 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	print_result(t_stack *ps, t_error err)
{
	if (err != ERR_NONE)
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (is_sorted(ps) && ps->size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

t_error	execute_commands(t_stack *ps)
{
	char	*cmd;
	t_error	err;

	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		err = process_command(ps, cmd);
		free(cmd);
		if (err != ERR_NONE)
			return (err);
	}
	return (ERR_NONE);
}
