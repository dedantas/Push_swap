/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedantas <dedantas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:11:55 by dedantas          #+#    #+#             */
/*   Updated: 2025/10/20 21:41:57 by dedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, false);
	else if (first > second && second > third)
	{
		sa(a, false);
		rra(a, false);
	}
	else if (first > second && second < third && first > third)
		ra(a, false);
	else if (first < second && second > third && first < third)
	{
		sa(a, false);
		ra(a, false);
	}
	else if (first < second && second > third && first > third)
		rra(a, false);
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	min;
	int	position;

	while (a->size > 3)
	{
		min = find_min_value(a);
		position = find_position(a, min);
		rotate_to_top(a, position, 'a');
		pb(a, b, false);
	}
	if (a->size == 3)
		sort_three(a);
	else
		sa(a, false);
	while (b->size > 0)
		pa(a, b, false);
}
