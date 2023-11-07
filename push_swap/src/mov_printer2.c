/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_printer2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:29:56 by sergisan          #+#    #+#             */
/*   Updated: 2023/11/03 10:52:04 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) < 2 || ft_stacksize(*stack_b) < 2)
		return (-1);
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}

int	rrx(t_stack **stack_x, int option)
{
	if (ft_rev_rotate(stack_x) == -1)
		return (-1);
	if (option == 0)
		ft_putendl_fd("rra", 1);
	else
		ft_putendl_fd("rrb", 1);
	return (0);
}
