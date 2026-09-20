/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedantas <dedantas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 22:02:20 by dedantas          #+#    #+#             */
/*   Updated: 2025/10/12 12:53:51 by dedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// Parsing and initialization
t_stack	*check_ac(int ac, char **av);
t_stack	*create_stack(void);
t_stack	*init_stack(char **av, char **split);
void	assign_index(t_stack *stack);
void	free_split(char **arr);
void	free_error(t_stack *stack, char **av);
void	free_stack(t_stack *stack);

// Error checking
bool	error_syntax(char *s);
bool	error_duplicate(t_node *a, int n);
bool	stack_sorted(t_stack *stack);

// Operations
void	sa(t_stack *a, bool checker);
void	sb(t_stack *b, bool checker);
void	ss(t_stack *a, t_stack *b, bool checker);
void	pa(t_stack *a, t_stack *b, bool checker);
void	pb(t_stack *a, t_stack *b, bool checker);
void	ra(t_stack *a, bool checker);
void	rb(t_stack *b, bool checker);
void	rr(t_stack *a, t_stack *b, bool checker);
void	rra(t_stack *a, bool checker);
void	rrb(t_stack *b, bool checker);
void	rrr(t_stack *a, t_stack *b, bool checker);

// Sorting algorithms
void	sort_three(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);
void	push_chunks_to_b(t_stack *a, t_stack *b);
void	push_back_to_a(t_stack *a, t_stack *b);
void	final_rotate(t_stack *a);

// Utils
int		find_min_value(t_stack *stack);
int		find_max_value(t_stack *stack);
int		find_position(t_stack *stack, int value);
void	rotate_to_top(t_stack *stack, int position, char stack_name);

#endif
