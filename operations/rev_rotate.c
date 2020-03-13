/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:17:20 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 16:54:38 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common/common.h"

static int		shift_down(t_arg *stack, int len)
{
	int		i;
	t_arg	arg;

	i = len;
	arg = stack[len - 1];
	while (--i > 0)
		stack[i] = stack[i - 1];
	stack[0] = arg;
	return (1);
}

int				rev_rotate_a(t_data *data)
{
	t_arg	arg;

	if (data->size_a < 2)
		return (0);
	if (data->flag & FLAG_PUSH_SWAP && !(data->flag & FLAG_VISUALIZATION))
		fprint("rra\n");
	arg = data->stack_a[0];
	shift_down(data->stack_a, data->size_a);
	visualization(data, "rra");
	return (1);
}

int				rev_rotate_b(t_data *data)
{
	t_arg	arg;

	if (data->size_b < 2)
		return (0);
	if (data->flag & FLAG_PUSH_SWAP && !(data->flag & FLAG_VISUALIZATION))
		fprint("rrb\n");
	arg = data->stack_b[0];
	shift_down(data->stack_b, data->size_b);
	visualization(data, "rrb");
	return (1);
}

int				rev_rotate_r(t_data *data)
{
	t_arg	arg;

	if (data->size_a < 2 && data->size_b < 2)
		return (0);
	if (data->flag & FLAG_PUSH_SWAP && !(data->flag & FLAG_VISUALIZATION))
		fprint("rrr\n");
	if (data->size_a > 1)
	{
		arg = data->stack_a[0];
		shift_down(data->stack_a, data->size_a);
	}
	if (data->size_b > 1)
	{
		arg = data->stack_b[0];
		shift_down(data->stack_b, data->size_b);
	}
	visualization(data, "rrr");
	return (1);
}
