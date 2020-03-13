/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:17:53 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 14:44:13 by bsabre-c         ###   ########.fr       */
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

int			rotate_a(t_data *data)
{
	t_arg	ret;

	ft_bzero(&ret, sizeof(t_arg));
	if (data->size_a < 2)
		return (0);
	if (data->flag & FLAG_PUSH_SWAP && !(data->flag & FLAG_VISUALIZATION))
		fprint("ra\n");
	if (shift_up(data->stack_a, &(data->size_a), &ret))
	{
		data->size_a++;
		data->stack_a[data->size_a - 1] = ret;
	}
	visualization(data, "ra");
	return (1);
}

int			rotate_b(t_data *data)
{
	t_arg	ret;

	ft_bzero(&ret, sizeof(t_arg));
	if (data->size_b < 2)
		return (0);
	if (data->flag & FLAG_PUSH_SWAP && !(data->flag & FLAG_VISUALIZATION))
		fprint("rb\n");
	if (shift_up(data->stack_b, &(data->size_b), &ret))
	{
		data->size_b++;
		data->stack_b[data->size_b - 1] = ret;
	}
	visualization(data, "rb");
	return (1);
}

int			rotate_r(t_data *data)
{
	t_arg	ret;

	ft_bzero(&ret, sizeof(t_arg));
	if (data->size_b < 2 && data->size_b < 2)
		return (0);
	if (data->flag & FLAG_PUSH_SWAP && !(data->flag & FLAG_VISUALIZATION))
		fprint("rr\n");
	if (shift_up(data->stack_a, &(data->size_a), &ret))
	{
		data->size_a++;
		data->stack_a[data->size_a - 1] = ret;
	}
	if (shift_up(data->stack_b, &(data->size_b), &ret))
	{
		data->size_b++;
		data->stack_b[data->size_b - 1] = ret;
	}
	visualization(data, "rr");
	return (1);
}
