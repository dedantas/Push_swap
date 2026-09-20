/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedantas <dedantas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:30:29 by dedantas          #+#    #+#             */
/*   Updated: 2025/10/12 11:47:41 by dedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	error_exit(t_stack *a, t_stack *b, char *message)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (message)
		write(2, message, ft_strlen(message));
	exit(1);
}

void	parse_command(t_stack *a, t_stack *b, char *command)
{
	if (!ft_strncmp(command, "pa\n", 3))
		pa(a, b, true);
	else if (!ft_strncmp(command, "pb\n", 3))
		pb(a, b, true);
	else if (!ft_strncmp(command, "sa\n", 3))
		sa(a, true);
	else if (!ft_strncmp(command, "sb\n", 3))
		sb(b, true);
	else if (!ft_strncmp(command, "ss\n", 3))
		ss(a, b, true);
	else if (!ft_strncmp(command, "ra\n", 3))
		ra(a, true);
	else if (!ft_strncmp(command, "rb\n", 3))
		rb(b, true);
	else if (!ft_strncmp(command, "rr\n", 3))
		rr(a, b, true);
	else if (!ft_strncmp(command, "rra\n", 4))
		rra(a, true);
	else if (!ft_strncmp(command, "rrb\n", 4))
		rrb(b, true);
	else if (!ft_strncmp(command, "rrr\n", 4))
		rrr(a, b, true);
	else
		error_exit(a, b, "Error\n");
}

void	read_commands(t_stack *a, t_stack *b)
{
	char	*next_line;

	next_line = get_next_line(0);
	while (next_line)
	{
		parse_command(a, b, next_line);
		free(next_line);
		next_line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		initial_size;

	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	a = check_ac(ac, av);
	if (!a)
		error_exit(a, b, "Error\n");
	initial_size = a->size;
	b = create_stack();
	read_commands(a, b);
	if (stack_sorted(a) && a->size == initial_size && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	free_stack(b);
	return (0);
}
