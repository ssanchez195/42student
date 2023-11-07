/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:04:53 by sergisan          #+#    #+#             */
/*   Updated: 2023/11/07 16:09:03 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_stack **stack)
{
	t_stack	*copy;

	copy = *stack;
	while (copy->next)
	{
		if (copy->value > copy->next->value)
			return (1);
		copy = copy->next;
	}
	return (0);
}

void	ft_upload_info(int number, t_stack **stack)
{
	t_stack	*aux;
	t_stack	*copy;

	aux = ft_calloc(sizeof(t_stack), (1));
	aux->value = number;
	aux->next = NULL;
	if (!(*stack))
		*stack = aux;
	else
	{
		copy = *stack;
		while (copy->next)
			copy = copy->next;
		copy->next = aux;
	}
}

void	ft_free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (*stack_a)
	{
		aux = *stack_a;
		while (*stack_a)
		{
			aux = (*stack_a)->next;
			free(*stack_a);
			*stack_a = aux;
		}
	}
	if (*stack_b)
	{
		aux = *stack_b;
		if (aux == NULL)
			return ;
		while (*stack_b)
		{
			aux = (*stack_b)->next;
			free(*stack_b);
			*stack_a = aux;
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (argc != 2)
			ft_checker_values(argv, &stack_a);
		else
			ft_checker_values2(argv, &stack_a);
		ft_put_indexes(&stack_a);
		if (!ft_is_sorted(&stack_a))
			return (0);
		ft_sort_chooser(&stack_a, &stack_b);
		ft_free_stacks(&stack_a, &stack_b);
	}
	return (0);
}

/*
void	printlist(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	b;

	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			a = stack_a->value;
			stack_a = stack_a->next;
		}
		else
			a = 0;
		if (stack_b)
		{
			b = stack_b->value;
			stack_b = stack_b->next;
		}
		else
			b = 0;
		printf(" %d	 %d \n", a, b);
	}
	printf(" ---------\n A	 B \n\n");
}*/
/*
atexit(ft_void);
void	ft_void(void)
{
	system("leaks -q push_swap");
}
*/