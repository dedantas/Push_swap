/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedantas <dedantas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:36:16 by dedantas          #+#    #+#             */
/*   Updated: 2025/10/07 22:31:18 by dedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *a)
{
	int		max_index;
	int		max_bits;
	t_node	*tmp;

	max_index = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;
	int	num;

	i = 0;
	size = a->size;
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = a->top->index;
			if (((num >> i) & 1) == 0)
				pb(a, b, false);
			else
				ra(a, false);
			j++;
		}
		while (b->size > 0)
			pa(a, b, false);
		i++;
	}
}
