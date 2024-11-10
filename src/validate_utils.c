/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:39:12 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/09 21:21:22 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_error	check_duplicates(t_stack *ps, int num)
{
	int	i;

	i = 0;
	while (i < ps->size_a)
	{
		if (ps->stack_a[i] == num)
			return (ERR_DUPLICATE);
		i++;
	}
	return (ERR_NONE);
}

t_error	process_prefix(char *str, int *i, int *sign)
{
	if (!str || !*str)
		return (ERR_INVALID_INPUT);
	*i = 0;
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		(*i)++;
	if (!str[*i])
		return (ERR_INVALID_INPUT);
	*sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (!str[*i])
		return (ERR_INVALID_INPUT);
	return (ERR_NONE);
}

t_error	convert_to_number(char *str, int i, int sign, long long *val)
{
	*val = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (ERR_INVALID_INPUT);
		*val = *val * 10 + (str[i] - '0');
		if ((sign == 1 && *val > INT_MAX) || (sign == -1 && *val
				* sign < INT_MIN))
			return (ERR_OVERFLOW);
		i++;
	}
	return (ERR_NONE);
}

t_error	validate_input(char *str, int *num)
{
	long long	val;
	int			i;
	int			sign;
	t_error		err;

	err = process_prefix(str, &i, &sign);
	if (err != ERR_NONE)
		return (err);
	err = convert_to_number(str, i, sign, &val);
	if (err != ERR_NONE)
		return (err);
	*num = (int)(val * sign);
	return (ERR_NONE);
}
