/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergisan <sergisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:55:07 by sergisan          #+#    #+#             */
/*   Updated: 2023/11/07 12:27:03 by sergisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;

	struct s_stack	*next;
}	t_stack;

//checker_functions.c
int		ft_stacksize(t_stack *lst);
int		ft_error(char *error);
int		ft_finder(long number, char **argument, int i);
void	ft_checker_values(char **argv, t_stack **a_list);
void	ft_checker_values2(char **argv, t_stack **a_stack);

//main.c
int		ft_is_sorted(t_stack **stack);
void	ft_upload_info(int number, t_stack **stack);
void	ft_free_stacks(t_stack **stack_a, t_stack **stack_b);

//mov_printer.c
int		sx(t_stack **stack_x, int option);
int		px(t_stack **stack_x1, t_stack **stack_x2, int option);
int		rx(t_stack **stack_x, int option);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);

//mov_printer2.c
int		rrr(t_stack **stack_a, t_stack **stack_b);
int		rrx(t_stack **stack_x, int option);

//mov_types.c
int		ft_swap(t_stack **stack);
int		ft_push(t_stack **stack_dst, t_stack **stack_src);
int		ft_rotate(t_stack **stack);
int		ft_rev_rotate(t_stack **stack);

//sorter_max5.c
void	ft_sort_chooser(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_3_values(t_stack **stack);
void	ft_sort_4_values(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_5_values(t_stack **stack_a, t_stack **stack_b);
void	ft_radix(t_stack **stack_a, t_stack **stack_b);

//utils.c
t_stack	*ft_stacklast(t_stack *stack);
int		ft_get_distance(t_stack **stack, int min_value);
int		ft_get_min_value(t_stack **stack, int aux_index);
void	ft_put_indexes(t_stack **stack);

#endif