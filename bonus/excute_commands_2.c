/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_commands_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:39:06 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/11 00:25:42 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	execute_swap_push(t_stack *ps, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa(ps);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sb(ps);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(ps);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa(ps);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pb(ps);
}

void	execute_rotate(t_stack *ps, char *cmd)
{
	if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra(ps);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rb(ps);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(ps);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rra(ps);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrb(ps);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(ps);
}

t_error	validate_command(char *cmd)
{
	const char	*valid_commands[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", NULL};
	int			i;
	size_t		cmd_len;
	size_t		valid_cmd_len;
	int			is_match;

	i = 0;
	cmd_len = ft_strlen(cmd);
	while (valid_commands[i])
	{
		valid_cmd_len = ft_strlen(valid_commands[i]);
		is_match = (cmd_len == valid_cmd_len && ft_strncmp(cmd,
					valid_commands[i], valid_cmd_len) == 0);
		if (is_match)
			return (ERR_NONE);
		i++;
	}
	return (ERR_INVALID_COMMAND);
}

t_error	process_command(t_stack *ps, char *cmd)
{
	t_error	err;

	err = validate_command(cmd);
	if (err != ERR_NONE)
		return (err);
	execute_swap_push(ps, cmd);
	execute_rotate(ps, cmd);
	return (ERR_NONE);
}
