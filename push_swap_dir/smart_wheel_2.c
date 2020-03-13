/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_wheel_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:05:32 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/09 22:31:23 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			forward_steps_for_element_in_b(t_data *data, int arg_b)
{
	int		i_next;
	int		i_prev;
	t_arg	prev;
	t_arg	next;
	int		steps;

	i_next = 0;
	i_prev = data->size_a - 1;
	next = data->stack_a[i_next];
	prev = data->stack_a[i_prev];
	steps = 0;
	while (!(next.arg > arg_b && \
			(prev.position == data->size_a + data->size_b - 1 || \
			prev.arg < arg_b)))
	{
		i_prev = i_next;
		i_next++;
		next = data->stack_a[i_next];
		prev = data->stack_a[i_prev];
		steps++;
		if (i_next == data->size_a)
			return ((data->size_a + data->size_b) * 2);
	}
	return (steps);
}

int			reverse_steps_for_element_in_b(t_data *data, int arg_b)
{
	int		i_next;
	int		i_prev;
	t_arg	prev;
	t_arg	next;
	int		steps;

	i_next = 0;
	i_prev = data->size_a - 1;
	next = data->stack_a[i_next];
	prev = data->stack_a[i_prev];
	steps = 0;
	while (!(next.arg > arg_b && \
			(prev.position == data->size_a + data->size_b - 1 || \
			prev.arg < arg_b)))
	{
		i_next = i_prev;
		i_prev--;
		next = data->stack_a[i_next];
		prev = data->stack_a[i_prev];
		steps++;
		if (i_prev == -1)
			return ((data->size_a + data->size_b) * 2);
	}
	return (steps);
}

int			prepare_table_and_find_element(t_data *data)
{
	int		i;
	int		min;
	int		forward;
	int		reverse;
	t_arg	*stack_b;

	stack_b = data->stack_b;
	min = 0;
	i = -1;
	while (++i < data->size_b)
	{
		stack_b[i].calculation = data->size_b - i;
		if (i < data->size_b - i)
			stack_b[i].calculation = i;
		forward = forward_steps_for_element_in_b(data, stack_b[i].arg);
		reverse = reverse_steps_for_element_in_b(data, stack_b[i].arg);
		stack_b[i].calculation += ft_mini(forward, reverse);
		if (stack_b[i].calculation < stack_b[min].calculation)
			min = i;
	}
	return (min);
}
