/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:31:32 by sergisan          #+#    #+#             */
/*   Updated: 2023/10/24 18:13:52 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stacksize(t_stack *lst)
{
	int		cont;

	cont = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		cont++;
		lst = lst->next;
	}
	return (cont);
}

int	ft_error(char *error)
{
	int	i;

	i = 0;
	while (error[i])
	{
		write(1, &error[i], 1);
		i++;
	}
	write (1, "\n", 1);
	exit(0);
}

int	ft_finder(long number, char **argument, int i)
{
	while (argument[i])
	{
		if (number == ft_atoi(argument[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_checker_values(char **argv, t_stack **a_stack)
{
	int		i;
	long	temp;
	char	**argument;

	i = 1;
	argument = argv;
	while (argument[i])
	{
		temp = ft_atoi(argument[i]);
		if ((temp < -2147483648 || temp > 2147483647)
			|| (ft_finder(temp, argument, (i + 1)) == 1))
			ft_error("Error");
		i++;
	}
	i = 1;
	while (argument[i])
		ft_upload_info(ft_atoi(argument[i++]), a_stack);
}