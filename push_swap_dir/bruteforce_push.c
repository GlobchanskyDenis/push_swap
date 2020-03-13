/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:30:07 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 16:55:27 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_queue		*bf_push_a(t_queue *parent)
{
	t_arg		arg;
	t_queue		*dst;

	if (parent->size_b == 0)
		return (NULL);
	if (is_last_operation_equal(parent, "pb\n"))
		return (NULL);
	if (!(dst = copy_node(parent, "pa\n")))
		return (NULL);
	if (shift_up(dst->st_b, &(dst->size_b), &arg))
		shift_down(dst->st_a, &(dst->size_a), arg);
	return (dst);
}

t_queue		*bf_push_b(t_queue *parent)
{
	t_arg		arg;
	t_queue		*dst;

	if (parent->size_a == 0)
		return (NULL);
	if (is_last_operation_equal(parent, "pa\n"))
		return (NULL);
	if (!(dst = copy_node(parent, "pb\n")))
		return (NULL);
	if (shift_up(dst->st_a, &(dst->size_a), &arg))
		shift_down(dst->st_b, &(dst->size_b), arg);
	return (dst);
}
