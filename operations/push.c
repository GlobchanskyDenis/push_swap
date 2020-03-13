/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:16:25 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 14:43:27 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common/common.h"

static int	shift_up(t_arg *stack, int *len, t_arg *ret)
{
	int		i;
	int		length;

	if (*len <= 0)
		return (0);
	*ret = stack[0];
	i = -1;
	length = *len;
	while (++i < length - 1)
		stack[i] = stack[i + 1];
	(*len)--;
	return (1);
}

static int	shift_down(t_arg *stack, int *len, t_arg new_arg)
{
	int		i;

	(*len)++;
	i = *len;
	while (--i)
		stack[i] = stack[i - 1];
	stack[0] = new_arg;
	return (1);
}

int			push_a(t_data *data)
{
	t_arg		arg;

	if (data->size_b <= 0)
		return (0);
	if (data->flag & FLAG_PUSH_SWAP && !(data->flag & FLAG_VISUALIZATION))
		fprint("pa\n");
	if (shift_up(data->stack_b, &(data->size_b), &arg))
		shift_down(data->stack_a, &(data->size_a), arg);
	visualization(data, "pa");
	return (1);
}

int			push_b(t_data *data)
{
	t_arg		arg;

	if (data->size_a <= 0)
		return (0);
	if (data->flag & FLAG_PUSH_SWAP && !(data->flag & FLAG_VISUALIZATION))
		fprint("pb\n");
	if (shift_up(data->stack_a, &(data->size_a), &arg))
		shift_down(data->stack_b, &(data->size_b), arg);
	visualization(data, "pb");
	return (1);
}
