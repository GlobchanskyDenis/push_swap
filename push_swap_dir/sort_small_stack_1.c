/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:05:32 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 17:14:10 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sort_2_args_stack_b(t_data *data)
{
	if (data->size_b > 2)
		return (-1);
	if (data->size_b == 1 || data->stack_b[0].arg > data->stack_b[1].arg)
		return (0);
	swap_b(data);
	return (1);
}

int			sort_3_args_stack_b(t_data *data)
{
	int			b1;
	int			b2;
	int			b3;

	if (data->size_b > 3)
		return (-1);
	if (data->size_b == 2)
		return (sort_2_args_stack_b(data));
	b1 = data->stack_b[0].arg;
	b2 = data->stack_b[1].arg;
	b3 = data->stack_b[2].arg;
	if (b1 < b2 && b1 < b3 && b2 < b3 && swap_b(data))
		rev_rotate_b(data);
	else if (b1 > b2 && b1 > b3 && b2 < b3 && rev_rotate_b(data))
		swap_b(data);
	else if (b1 < b2 && b1 > b3 && b2 > b3)
		swap_b(data);
	else if (b1 > b2 && b1 < b3 && b2 < b3 && rotate_b(data))
		rotate_b(data);
	else if (b1 < b2 && b1 < b3 && b2 > b3)
		rotate_b(data);
	else if (b1 > b3 && b2 > b3 && b1 > b3)
		return (0);
	return (1);
}

int			midian_6_args(t_data *data, t_arg *stack, int size)
{
	int			*sorted;
	int			ret;

	quicksort(data, stack, size);
	sorted = data->sorted;
	ret = sorted[size - 3];
	return (ret);
}

int			is_forward(t_data *data, int midian)
{
	int			forward;
	int			reverse;

	forward = 0;
	while (forward < data->size_a && data->stack_a[forward].arg >= midian)
		forward++;
	reverse = data->size_a - 1;
	while (reverse >= 0 && data->stack_a[reverse].arg >= midian)
		reverse--;
	if (forward < data->size_a - reverse)
		return (1);
	return (0);
}

int			sort_6_args(t_data *data)
{
	int		midiana;

	if (data->size_a > 6)
		return (-1);
	if (data->size_a < 4)
		return (sort_3_args_stack_a(data));
	midiana = midian_6_args(data, data->stack_a, data->size_a);
	while (data->size_a > 3)
	{
		if (data->stack_a[0].arg < midiana)
			push_b(data);
		else if (is_forward(data, midiana))
			rotate_a(data);
		else
			rev_rotate_a(data);
	}
	sort_3_args_stack_a(data);
	sort_3_args_stack_b(data);
	while (data->size_b)
		push_a(data);
	return (1);
}
