/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedantas <dedantas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:10:43 by dedantas          #+#    #+#             */
/*   Updated: 2025/10/12 12:56:59 by dedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	a = check_ac(ac, av);
	b = create_stack();
	if (!stack_sorted(a))
	{
		if (a->size <= 5)
			sort_small(a, b);
		else
			sort_large(a, b);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
