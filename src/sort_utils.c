/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedantas <dedantas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:54:32 by dedantas          #+#    #+#             */
/*   Updated: 2025/10/07 20:55:55 by dedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_value(t_stack *stack)
{
	t_node	*curr;
	int		min;

	if (!stack || !stack->top)
		return (INT_MAX);
	curr = stack->top;
	min = curr->value;
	while (curr)
	{
		if (curr->value < min)
			min = curr->value;
		curr = curr->next;
	}
	return (min);
}

int	find_max_value(t_stack *stack)
{
	t_node	*curr;
	int		max;

	if (!stack || !stack->top)
		return (INT_MIN);
	curr = stack->top;
	max = curr->value;
	while (curr)
	{
		if (curr->value > max)
			max = curr->value;
		curr = curr->next;
	}
	return (max);
}

int	find_position(t_stack *stack, int value)
{
	t_node	*curr;
	int		position;

	curr = stack->top;
	position = 0;
	while (curr)
	{
		if (curr->value == value)
			return (position);
		position++;
		curr = curr->next;
	}
	return (-1);
}

void	rotate_to_top(t_stack *stack, int position, char stack_name)
{
	if (position <= stack->size / 2)
	{
		while (position-- > 0)
		{
			if (stack_name == 'a')
				ra(stack, false);
			else
				rb(stack, false);
		}
	}
	else
	{
		while (position++ < stack->size)
		{
			if (stack_name == 'a')
				rra(stack, false);
			else
				rrb(stack, false);
		}
	}
}
