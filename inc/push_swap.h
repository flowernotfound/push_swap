/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:40:38 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/10 16:44:46 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_error
{
	ERR_NONE,
	ERR_MALLOC,
	ERR_INVALID_INPUT,
	ERR_DUPLICATE,
	ERR_OVERFLOW
}		t_error;

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	max_size;
}		t_stack;

t_stack	*init_program(int ac, char **av);
int		get_stack_size(int ac, char **av);
void	error_exit(t_stack *ps, t_error err);
void	free_stacks(t_stack *ps);
t_stack	*init_struct(int size);
t_stack	*init_stacks(t_stack *ps, int size);
int		*prepare_sorted_array(t_stack *ps);
void	bubble_sort_array(int *sorted, int size);
void	normalize_stack(t_stack *ps);
void	pa(t_stack *ps);
void	pb(t_stack *ps);
void	ra(t_stack *ps);
void	rb(t_stack *ps);
void	rr(t_stack *ps);
void	rra(t_stack *ps);
void	rrb(t_stack *ps);
void	rrr(t_stack *ps);
void	sa(t_stack *ps);
void	sb(t_stack *ps);
void	ss(t_stack *ps);
void	swap(int *a, int *b);
void	rotate_stack(int *stack, int size);
void	reverse_rotate_stack(int *stack, int size);
int		find_min_position(t_stack *ps);
void	move_min_to_b(t_stack *ps);
void	sort_small_stacks(t_stack *ps);
int		select_action(int first, int second, int third);
void	execute_sort(t_stack *ps, int action);
void	sort_three(t_stack *ps);
void	sort_two(t_stack *ps);
int		get_chunk_size(int size);
void	move_to_b(t_stack *ps);
int		find_max_pos(t_stack *ps);
void	move_to_a(t_stack *ps);
void	sort_stacks(t_stack *ps);
int		is_sorted(t_stack *ps);
int		count_words(char *str);
int		find_word_bounds(char *str, int *index, int *start, int *end);
char	*get_next_word(char *str, int *index);
t_error	check_duplicates(t_stack *ps, int num);
t_error	process_prefix(char *str, int *i, int *sign);
t_error	convert_to_number(char *str, int i, int sign, long long *val);
t_error	validate_input(char *str, int *num);
t_error	process_single_argument(t_stack *ps, char *arg);
t_error	process_one_arg(t_stack *ps, char *arg);
t_error	process_arguments(t_stack *ps, int ac, char **av);

#endif
