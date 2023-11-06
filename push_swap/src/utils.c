/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:38:50 by sergisan          #+#    #+#             */
/*   Updated: 2023/10/24 14:46:11 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_distance(t_stack **stack, int min_value)
{
	t_stack	*aux;
	int		count;

	aux = *stack;
	count = 0;
	while (aux)
	{
		if (aux->index == min_value)
			return (count);
		aux = aux->next;
		count++;
	}
	return (count);
}

int	ft_get_min_value(t_stack **stack, int aux_index)
{
	t_stack	*aux;
	int		min_index;

	aux = *stack;
	min_index = (*stack)->index;
	while (aux->next)
	{
		aux = aux->next;
		if (aux->index < min_index && aux->index != aux_index)
			min_index = aux->index;
	}
	return (min_index);
}

void	ft_put_indexes(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*copy;
	int		count_index;

	aux = *stack;
	while (aux)
	{
		count_index = 1;
		copy = *stack;
		while (copy)
		{
			if (aux->value > copy->value)
				count_index++;
			copy = copy->next;
		}
		aux->index = count_index;
		aux = aux->next;
	}
}
/*
//String
void	ft_checkStringArgs()
{
	int	i;

	i = 0;


	i = 0;
}
//Argumentos muchos
void	ft_checkAllArgs()
{
	int	i;

	i = 1;


	i = 1;
	while (argument[i])
		ft_upload_info(ft_atoi(argument[i++]), stack_a)
}*/