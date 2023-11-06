/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:00:39 by sergisan          #+#    #+#             */
/*   Updated: 2023/10/24 15:02:31 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sx(t_stack **stack_x, int option)
{
	if (ft_swap(stack_x) == -1)
		return (-1);
	if (option == 0)
		ft_putendl_fd("sa", 1);
	else
		ft_putendl_fd("sb", 1);
	return (0);
}

int	px(t_stack **stack_x1, t_stack **stack_x2, int option)
{
	if (option == 0 && (ft_push(stack_x1, stack_x2) == -1))
		return (-1);
	else
	{
		if (option == 1 && (ft_push(stack_x2, stack_x1) == -1))
			return (-1);
	}
	if (option == 0)
		ft_putendl_fd("pa", 1);
	else
		ft_putendl_fd("pb", 1);
	return (0);
}

int	rx(t_stack **stack_x, int option)
{
	if (ft_rotate(stack_x) == -1)
		return (-1);
	if (option == 0)
		ft_putendl_fd("ra", 1);
	else
		ft_putendl_fd("rb", 1);
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) < 2 || ft_stacksize(*stack_b) < 2)
		return (-1);
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) < 2 || ft_stacksize(*stack_b) < 2)
		return (-1);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}