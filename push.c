/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedantas <dedantas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:56:41 by dedantas          #+#    #+#             */
/*   Updated: 2025/10/07 20:57:06 by dedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *src, t_stack *dst)
{
	t_node	*tmp;

	if (!src || src->size == 0)
		return ;
	tmp = src->top;
	src->top = src->top->next;
	src->size--;
	tmp->next = dst->top;
	dst->top = tmp;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pb\n", 3);
}
