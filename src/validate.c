/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:39:12 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/10 16:06:47 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_error	process_single_argument(t_stack *ps, char *arg)
{
	int		word_count;
	char	*word;
	int		str_index;
	t_error	err;

	word_count = count_words(arg);
	if (word_count == 0)
		return (ERR_INVALID_INPUT);
	str_index = 0;
	word = get_next_word(arg, &str_index);
	while (word)
	{
		err = process_one_arg(ps, word);
		free(word);
		if (err != ERR_NONE)
			return (err);
		word = get_next_word(arg, &str_index);
	}
	return (ERR_NONE);
}

t_error	process_one_arg(t_stack *ps, char *arg)
{
	int		num;
	t_error	err;

	err = validate_input(arg, &num);
	if (err != ERR_NONE)
		return (err);
	err = check_duplicates(ps, num);
	if (err != ERR_NONE)
		return (err);
	ps->stack_a[ps->size_a++] = num;
	return (ERR_NONE);
}

t_error	process_arguments(t_stack *ps, int ac, char **av)
{
	t_error	err;
	int		i;

	if (ac == 2)
		return (process_single_argument(ps, av[1]));
	i = 1;
	while (i < ac)
	{
		err = process_one_arg(ps, av[i]);
		if (err != ERR_NONE)
			return (err);
		i++;
	}
	return (ERR_NONE);
}
