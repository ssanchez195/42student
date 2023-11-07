/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:47:11 by sergisan          #+#    #+#             */
/*   Updated: 2023/11/07 11:13:08 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_chooser(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = ft_stacksize(*stack_a);
	if (count <= 5)
	{
		if (count == 1)
			return ;
		if (count == 2)
			sx(stack_a, 0);
		else if (count == 3)
			ft_sort_3_values(stack_a);
		else if (count == 4)
			ft_sort_4_values(stack_a, stack_b);
		else
			ft_sort_5_values(stack_a, stack_b);
	}
	else
		ft_radix(stack_a, stack_b);
}

void	ft_sort_3_values(t_stack **stack)
{
	int		min_value;
	int		next_min;

	min_value = ft_get_min_value(stack, -1);
	next_min = ft_get_min_value(stack, min_value);
	if (ft_is_sorted(stack) == 0)
		return ;
	if ((*stack)->index == min_value && (*stack)->next->index != next_min)
	{
		rx(stack, 0);
		sx(stack, 0);
		rrx(stack, 0);
	}
	else if ((*stack)->index == next_min && (*stack)->next->index != min_value)
		rrx(stack, 0);
	else if ((*stack)->index == next_min && (*stack)->next->index == min_value)
		sx(stack, 0);
	else if ((*stack)->next->index == min_value)
		rx(stack, 0);
	else
	{
		sx(stack, 0);
		rrx(stack, 0);
	}
}

void	ft_sort_4_values(t_stack **stack_a, t_stack **stack_b)
{
	int	sort_min;

	sort_min = ft_get_distance(stack_a, ft_get_min_value(stack_a, 0));
	if (ft_is_sorted(stack_a) == 0)
		return ;
	if (sort_min == 1 || sort_min == 2)
	{
		rx(stack_a, 0);
		if (sort_min == 2)
			rx(stack_a, 0);
	}
	if (sort_min == 3)
		rrx(stack_a, 0);
	if (ft_is_sorted(stack_a) == 0)
		return ;
	px(stack_a, stack_b, 1);
	ft_sort_3_values(stack_a);
	px(stack_a, stack_b, 0);
}

void	ft_sort_5_values(t_stack **stack_a, t_stack **stack_b)
{
	int	sort_min;

	sort_min = ft_get_distance(stack_a, ft_get_min_value(stack_a, 0));
	if (ft_is_sorted(stack_a) == 0)
		return ;
	if (sort_min == 1 || sort_min == 2)
	{
		rx(stack_a, 0);
		if (sort_min == 2)
			rx(stack_a, 0);
	}
	else if (sort_min == 3 || sort_min == 4)
	{
		rrx(stack_a, 0);
		if (sort_min == 3)
			rrx(stack_a, 0);
	}
	if (ft_is_sorted(stack_a) == 0)
		return ;
	px(stack_a, stack_b, 1);
	ft_sort_4_values(stack_a, stack_b);
	px(stack_a, stack_b, 0);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*copy;
	int		i;
	int		j;
	int		count;

	copy = *stack_a;
	i = 0;
	count = ft_stacksize(copy);
	while (ft_is_sorted(stack_a) && ft_stacksize(*stack_b) == 0)
	{
		j = 0;
		while (j++ < count)
		{
			copy = *stack_a;
			if (((copy->index >> i) & 1) == 1)
				rx(stack_a, 0);
			else
				px(stack_a, stack_b, 1);
		}
		while (ft_stacksize(*stack_b) != 0)
			px(stack_a, stack_b, 0);
		i++;
	}
}
