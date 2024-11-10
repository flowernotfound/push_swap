/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:36:43 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/10 03:12:05 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*init_stacks(t_stack *ps, int size)
{
	ps->stack_a = (int *)malloc(sizeof(int) * size);
	if (!ps->stack_a)
	{
		free(ps);
		return (NULL);
	}
	ps->stack_b = (int *)malloc(sizeof(int) * size);
	if (!ps->stack_b)
	{
		free(ps->stack_a);
		free(ps);
		return (NULL);
	}
	return (ps);
}

t_stack	*init_struct(int size)
{
	t_stack	*ps;
	t_stack	*result;

	if (size <= 0)
		return (NULL);
	ps = (t_stack *)malloc(sizeof(t_stack));
	if (!ps)
		return (NULL);
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->size_a = 0;
	ps->size_b = 0;
	ps->max_size = size;
	result = init_stacks(ps, size);
	return (result);
}

void	free_stacks(t_stack *ps)
{
	if (!ps)
		return ;
	if (ps->stack_a)
		free(ps->stack_a);
	if (ps->stack_b)
		free(ps->stack_b);
	free(ps);
}

int	get_stack_size(int ac, char **av)
{
	int	size;

	if (ac == 2)
		size = count_words(av[1]);
	else
		size = ac - 1;
	if (size < 1)
		return (0);
	return (size);
}

t_stack	*init_program(int ac, char **av)
{
	t_stack	*ps;
	t_error	err;
	int		size;

	err = validate_mixed_input(ac, av);
	if (err != ERR_NONE)
		error_exit(NULL, err);
	size = get_stack_size(ac, av);
	if (size == 0)
		return (NULL);
	ps = init_struct(size);
	if (!ps)
		error_exit(NULL, ERR_MALLOC);
	return (ps);
}
