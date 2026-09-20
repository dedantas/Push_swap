/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedantas <dedantas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:00:20 by dedantas          #+#    #+#             */
/*   Updated: 2025/10/20 18:50:01 by dedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int stack_size)
{
	if (stack_size <= 100)
		return (20);
	else
		return (50);
}

void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	current_chunk;
	int	pushed;
	int	chunk_mid;

	chunk_size = get_chunk_size(a->size);
	current_chunk = 1;
	while (a->size > 0)
	{
		pushed = 0;
		chunk_mid = (current_chunk * chunk_size) - (chunk_size / 2);
		while (pushed < chunk_size && a->size > 0 /*&& a->size * 2*/)
		{
			if (a->top->index <= current_chunk * chunk_size)
			{
				pb(a, b, false);
				pushed++;
				if (b->size > 1 && b->top->index < chunk_mid)
					rb(b, false);
			}
			else
				ra(a, false);
		}
		current_chunk++;
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max;
	int	position;

	while (b->size > 0)
	{
		max = find_max_value(b);
		position = find_position(b, max);
		if (position <= b->size / 2)
		{
			while (b->top->value != max)
				rb(b, false);
		}
		else
		{
			while (b->top->value != max)
				rrb(b, false);
		}
		pa(a, b, false);
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	assign_index(a);
	push_chunks_to_b(a, b);
	push_back_to_a(a, b);
	final_rotate(a);
}
