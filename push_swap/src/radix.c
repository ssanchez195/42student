/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:46:29 by sergisan          #+#    #+#             */
/*   Updated: 2023/10/24 17:36:27 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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