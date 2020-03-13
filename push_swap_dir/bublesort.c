/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bublesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 23:28:45 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/13 12:55:30 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stacks_sorted(t_data *data, t_arg *st_a, t_arg *st_b)
{
	int		i;
	int		length;

	if ((length = data->size_a) > 1)
	{
		i = -1;
		while (++i < length - 1)
		{
			if (st_a[i].arg >= st_a[i + 1].arg)
				return (0);
		}
	}
	if ((length = data->size_b) > 1)
	{
		i = -1;
		while (++i < length - 1)
		{
			if (st_b[i].arg <= st_b[i + 1].arg)
				return (0);
		}
	}
	return (1);
}

static int	sort_forward(t_data *data, t_arg *st_a, t_arg *st_b)
{
	while (data->size_a && !stacks_sorted(data, st_a, st_b))
	{
		if (data->size_b > 2 && st_b[0].arg < st_b[data->size_b - 1].arg && \
				data->size_a > 2 && st_a[0].arg > st_a[data->size_a - 1].arg)
			rotate_r(data);
		if (data->size_b > 2 && st_b[0].arg < st_b[data->size_b - 1].arg)
			rotate_b(data);
		if (data->size_a > 2 && st_a[0].arg > st_a[data->size_a - 1].arg)
			rotate_a(data);
		if (data->size_b > 1 && st_b[0].arg < st_b[1].arg && data->size_a > 1 \
				&& st_a[0].arg > st_a[1].arg)
			swap_s(data);
		if (data->size_b > 1 && st_b[0].arg < st_b[1].arg)
			swap_b(data);
		if (data->size_a > 1 && st_a[0].arg > st_a[1].arg)
			swap_a(data);
		push_b(data);
		print_stacks(data);
	}
	return (1);
}

static int	sort_back(t_data *data, t_arg *st_a, t_arg *st_b)
{
	while (data->size_b && !stacks_sorted(data, st_a, st_b))
	{
		if (data->size_b > 2 && st_b[0].arg < st_b[data->size_b - 1].arg && \
				data->size_a > 2 && st_a[0].arg > st_a[data->size_a - 1].arg)
			rotate_r(data);
		if (data->size_b > 2 && st_b[0].arg < st_b[data->size_b - 1].arg)
			rotate_b(data);
		if (data->size_a > 2 && st_a[0].arg > st_a[data->size_a - 1].arg)
			rotate_a(data);
		if (data->size_b > 1 && st_b[0].arg < st_b[1].arg && data->size_a > 1 \
				&& st_a[0].arg > st_a[1].arg)
			swap_s(data);
		if (data->size_b > 1 && st_b[0].arg < st_b[1].arg)
			swap_b(data);
		if (data->size_a > 1 && st_a[0].arg > st_a[1].arg)
			swap_a(data);
		push_a(data);
		print_stacks(data);
	}
	return (1);
}

/*
**	This is simple bublesort algorithm.
*/

int			bublesort(t_data *data)
{
	t_arg		*st_a;
	t_arg		*st_b;

	st_a = data->stack_a;
	st_b = data->stack_b;
	while (!stacks_sorted(data, st_a, st_b))
	{
		sort_forward(data, st_a, st_b);
		sort_back(data, st_a, st_b);
	}
	while (data->size_b)
	{
		push_a(data);
		print_stacks(data);
	}
	return (1);
}
