/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedantas <dedantas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:13:58 by dedantas          #+#    #+#             */
/*   Updated: 2025/10/07 21:15:49 by dedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate(t_stack *a)
{
	int	min;
	int	position;

	min = find_min_value(a);
	position = find_position(a, min);
	rotate_to_top(a, position, 'a');
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

bool	stack_sorted(t_stack *stack)
{
	t_node	*curr;

	if (!stack || !stack->top)
		return (true);
	curr = stack->top;
	while (curr && curr->next)
	{
		if (curr->value > curr->next->value)
			return (false);
		curr = curr->next;
	}
	return (true);
}

void	assign_index(t_stack *stack)
{
	t_node	*curr;
	t_node	*cmp;
	int		count;

	if (!stack || !stack->top)
		return ;
	curr = stack->top;
	while (curr)
	{
		count = 0;
		cmp = stack->top;
		while (cmp)
		{
			if (cmp->value < curr->value)
				count++;
			cmp = cmp->next;
		}
		curr->index = count;
		curr = curr->next;
	}
}
