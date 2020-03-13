/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_wheel_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:05:32 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 17:12:07 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			optimization_function(t_data *data, int *element)
{
	int		forward;
	int		reverse;

	forward = forward_steps_for_element_in_b(data, data->stack_b[*element].arg);
	reverse = reverse_steps_for_element_in_b(data, data->stack_b[*element].arg);
	if (*element < data->size_b - *element && forward <= reverse)
	{
		while (*element && forward)
		{
			rotate_r(data);
			(*element)--;
			forward--;
		}
	}
	else if (*element >= data->size_b - *element && forward > reverse)
	{
		while (*element < data->size_b && reverse)
		{
			rev_rotate_r(data);
			(*element)++;
			reverse--;
		}
	}
	return (0);
}

int			rotate_wheel_b(t_data *data, int element)
{
	if (element < data->size_b - element)
	{
		while (element--)
			rotate_b(data);
	}
	else
	{
		while (element++ < data->size_b)
			rev_rotate_b(data);
	}
	return (0);
}

int			rotate_wheel_a(t_data *data)
{
	int		forward;
	int		reverse;

	forward = forward_steps_for_element_in_b(data, data->stack_b[0].arg);
	reverse = reverse_steps_for_element_in_b(data, data->stack_b[0].arg);
	if (forward <= reverse)
	{
		while (forward--)
			rotate_a(data);
	}
	else
	{
		while (reverse--)
			rev_rotate_a(data);
	}
	return (0);
}

int			smart_wheel_move_b_to_a(t_data *data)
{
	int		element;

	while (data->size_b)
	{
		element = prepare_table_and_find_element(data);
		optimization_function(data, &element);
		rotate_wheel_b(data, element);
		rotate_wheel_a(data);
		push_a(data);
	}
	return (0);
}

int			smart_wheel_algorithm(t_data *data)
{
	if (data->size_a <= 6)
		return (sort_6_args(data));
	if (data->flag & FLAG_EXTENDED_OUTPUT)
		full_print_stacks(data);
	recursion_move_a_to_b(data);
	if (data->flag & FLAG_EXTENDED_OUTPUT)
		full_print_stacks(data);
	smart_wheel_move_b_to_a(data);
	final_rotations(data);
	return (0);
}
