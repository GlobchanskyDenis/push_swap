/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:19:26 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 14:44:35 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common/common.h"

int		swap_a(t_data *data)
{
	t_arg	*stack;
	t_arg	tmp;

	if (data->size_a < 2)
		return (0);
	if (data->flag & FLAG_PUSH_SWAP && !(data->flag & FLAG_VISUALIZATION))
		fprint("sa\n");
	stack = data->stack_a;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	visualization(data, "sa");
	return (1);
}

int		swap_b(t_data *data)
{
	t_arg	*stack;
	t_arg	tmp;

	if (data->size_b < 2)
		return (0);
	if (data->flag & FLAG_PUSH_SWAP && !(data->flag & FLAG_VISUALIZATION))
		fprint("sb\n");
	stack = data->stack_b;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	visualization(data, "sb");
	return (1);
}

int		swap_s(t_data *data)
{
	t_arg	*stack;
	t_arg	tmp;

	if (data->size_a < 2 && data->size_b < 2)
		return (0);
	if (data->flag & FLAG_PUSH_SWAP && !(data->flag & FLAG_VISUALIZATION))
		fprint("ss\n");
	if (data->size_a >= 2)
	{
		stack = data->stack_a;
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
	if (data->size_b >= 2)
	{
		stack = data->stack_b;
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
	visualization(data, "ss");
	return (1);
}
