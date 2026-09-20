/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedantas <dedantas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:06:03 by dedantas          #+#    #+#             */
/*   Updated: 2025/10/09 18:56:50 by dedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	error_syntax(char *s)
{
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
		return (1);
	if ((*s == '+' || *s == '-') && !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	while (*++s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (1);
	}
	return (0);
}

bool	error_duplicate(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*curr;

	if (!stack)
		return ;
	curr = stack->top;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	free(stack);
}

void	free_error(t_stack *a, char **split)
{
	free_stack(a);
	if (split)
		free_split(split);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		free(a[i++]);
	free(a);
}
