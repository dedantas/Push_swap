/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedantas <dedantas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 22:04:15 by dedantas          #+#    #+#             */
/*   Updated: 2025/10/07 22:41:51 by dedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 4
# include "push_swap.h"
# include "libft.h"

void	error_exit(t_stack *a, t_stack *b, char *message);
void	parse_command(t_stack *a, t_stack *b, char *command);
int		stack_size(t_stack *stack);

#endif
