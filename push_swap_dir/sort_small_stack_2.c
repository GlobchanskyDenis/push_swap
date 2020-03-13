/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:15:49 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 17:16:04 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sort_2_args_stack_a(t_data *data)
{
	if (data->size_a > 2)
		return (-1);
	if (data->size_a == 1 || data->stack_a[0].arg < data->stack_a[1].arg)
		return (0);
	swap_a(data);
	return (1);
}

int			sort_3_args_stack_a(t_data *data)
{
	int			a1;
	int			a2;
	int			a3;

	if (data->size_a > 3)
		return (-1);
	if (data->size_a == 2)
		return (sort_2_args_stack_a(data));
	a1 = data->stack_a[0].arg;
	a2 = data->stack_a[1].arg;
	a3 = data->stack_a[2].arg;
	if (a1 > a2 && a1 > a3 && a2 > a3 && swap_a(data))
		rev_rotate_a(data);
	else if (a1 < a2 && a1 < a3 && a2 > a3 && rev_rotate_a(data))
		swap_a(data);
	else if (a1 > a2 && a1 < a3 && a2 < a3)
		swap_a(data);
	else if (a1 < a2 && a1 > a3 && a2 > a3 && rotate_a(data))
		rotate_a(data);
	else if (a1 > a2 && a1 > a3 && a2 < a3)
		rotate_a(data);
	else if (a1 < a3 && a2 < a3 && a1 < a3)
		return (0);
	return (1);
}
