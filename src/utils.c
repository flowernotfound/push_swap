/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:39:05 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/09 21:21:12 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_stack *ps)
{
	int	i;

	if (!ps || ps->size_a < 2)
		return (1);
	i = 0;
	while (i < ps->size_a - 1)
	{
		if (ps->stack_a[i] > ps->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	count_words(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
		}
	}
	return (count);
}

int	find_word_bounds(char *str, int *index, int *start, int *end)
{
	while (str[*index] && (str[*index] == ' ' || str[*index] == '\t'))
		(*index)++;
	*start = *index;
	while (str[*index] && str[*index] != ' ' && str[*index] != '\t')
		(*index)++;
	*end = *index;
	if (*start == *end)
		return (0);
	return (1);
}

char	*get_next_word(char *str, int *index)
{
	int		start;
	int		end;
	int		i;
	char	*word;

	if (!find_word_bounds(str, index, &start, &end))
		return (NULL);
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}
