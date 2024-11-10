/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:39:08 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/09 22:59:53 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_error	validate_mixed_input(int argc, char **argv)
{
	int	i;
	int	quote_count;

	i = 1;
	quote_count = 0;
	while (i < argc)
	{
		if (argv[i][0] == '"')
			quote_count++;
		i++;
	}
	if (quote_count > 0)
		return (ERR_INVALID_INPUT);
	return (ERR_NONE);
}
