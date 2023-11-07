/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:29:04 by sergisan          #+#    #+#             */
/*   Updated: 2023/11/07 11:25:26 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if ((ft_stacksize(*stack)) < 2)
		return (-1);
	first = *stack;
	second = first->next;
	*stack = second;
	first->next = second->next;
	second->next = first;
	return (0);
}

int	ft_push(t_stack **stack_dst, t_stack **stack_src)
{
	t_stack	*aux;
	t_stack	*first_elem_src;
	t_stack	*first_elem_dst;

	if (ft_stacksize(*stack_src) == 0)
		return (-1);
	first_elem_src = *stack_src;
	first_elem_dst = *stack_dst;
	aux = first_elem_src;
	first_elem_src = first_elem_src->next;
	*stack_src = first_elem_src;
	if (first_elem_dst)
	{
		aux->next = first_elem_dst;
		*stack_dst = aux;
	}
	else
	{
		first_elem_dst = aux;
		first_elem_dst->next = NULL;
		*stack_dst = first_elem_dst;
	}
	return (0);
}

int	ft_rotate(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*necesary;

	if (ft_stacksize(*stack) == 0)
		return (-1);
	necesary = *stack;
	*stack = (*stack)->next;
	necesary->next = NULL;
	aux = *stack;
	aux = ft_stacklast(aux);
	aux->next = necesary;
	return (0);
}

int	ft_rev_rotate(t_stack **stack)
{
	t_stack	*copy;
	t_stack	*aux;

	if (ft_stacksize(*stack) < 2)
		return (-1);
	copy = *stack;
	aux = ft_stacklast(copy);
	while (copy)
	{
		if (copy->next->next == NULL)
		{
			copy->next = NULL;
			aux->next = *stack;
			*stack = aux;
			return (0);
		}
		copy = copy->next;
	}
	aux->next = *stack;
	*stack = aux;
	return (0);
}
