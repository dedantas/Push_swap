/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedantas <dedantas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:11:19 by dedantas          #+#    #+#             */
/*   Updated: 2025/10/12 13:00:56 by dedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*check_ac(int ac, char **av)
{
	char	**split;
	t_stack	*a;

	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		a = init_stack(split, split);
		free_split(split);
		return (a);
	}
	else
	{
		return (init_stack(av + 1, NULL));
	}
}

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	append_node(t_stack *stack, int n)
{
	t_node	*new;
	t_node	*curr;

	new = malloc(sizeof(t_node));
	if (!new)
		free_error(stack, NULL);
	new->value = n;
	new->index = -1;
	new->next = NULL;
	if (!stack->top)
		stack->top = new;
	else
	{
		curr = stack->top;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	stack->size++;
}

t_stack	*init_stack(char **av, char **split)
{
	t_stack	*stack;
	long	n;
	int		i;

	stack = create_stack();
	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_error(stack, split);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(stack, split);
		if (error_duplicate(stack->top, (int)n))
			free_error(stack, split);
		append_node(stack, (int)n);
		i++;
	}
	return (stack);
}
