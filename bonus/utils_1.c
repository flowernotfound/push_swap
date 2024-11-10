/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:45:06 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/10 03:39:55 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i + 1 < n)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = 0;
	while (s2[c])
		str[i++] = s2[c++];
	str[i] = '\0';
	free(s1);
	return (str);
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
