/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:28:50 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 16:55:37 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	shift_down(t_arg *stack, int len)
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

t_queue		*bf_rev_rotate_a(t_queue *parent)
{
	t_arg	arg;
	t_queue	*dst;

	if (parent->size_a < 3)
		return (NULL);
	if (is_last_operation_equal(parent, "ra\n"))
		return (NULL);
	if (!(dst = copy_node(parent, "rra\n")))
		return (NULL);
	arg = dst->st_a[0];
	shift_down(dst->st_a, dst->size_a);
	return (dst);
}

t_queue		*bf_rev_rotate_b(t_queue *parent)
{
	t_arg	arg;
	t_queue	*dst;

	if (parent->size_b < 3)
		return (NULL);
	if (is_last_operation_equal(parent, "rb\n"))
		return (NULL);
	if (!(dst = copy_node(parent, "rrb\n")))
		return (NULL);
	arg = dst->st_b[0];
	shift_down(dst->st_b, dst->size_b);
	return (dst);
}

t_queue		*bf_rev_rotate_r(t_queue *parent)
{
	t_arg	arg;
	t_queue	*dst;

	if (parent->size_a < 3 || parent->size_b < 3)
		return (NULL);
	if (is_last_operation_equal(parent, "rr\n"))
		return (NULL);
	if (!(dst = copy_node(parent, "rrr\n")))
		return (NULL);
	arg = dst->st_a[0];
	shift_down(dst->st_a, dst->size_a);
	arg = dst->st_b[0];
	shift_down(dst->st_b, dst->size_b);
	return (dst);
}
