/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:55:46 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 12:43:53 by bsabre-c         ###   ########.fr       */
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

t_queue		*bf_rotate_a(t_queue *parent)
{
	t_arg	ret;
	t_queue	*dst;

	if (parent->size_a < 3)
		return (NULL);
	if (is_last_operation_equal(parent, "rra\n"))
		return (NULL);
	ft_bzero(&ret, sizeof(t_arg));
	if (!(dst = copy_node(parent, "ra\n")))
		return (NULL);
	if (shift_up(dst->st_a, &(dst->size_a), &ret))
	{
		dst->size_a++;
		dst->st_a[dst->size_a - 1] = ret;
	}
	return (dst);
}

t_queue		*bf_rotate_b(t_queue *parent)
{
	t_arg	ret;
	t_queue	*dst;

	if (parent->size_b < 3)
		return (NULL);
	if (is_last_operation_equal(parent, "rrb\n"))
		return (NULL);
	ft_bzero(&ret, sizeof(t_arg));
	if (!(dst = copy_node(parent, "rb\n")))
		return (NULL);
	if (shift_up(dst->st_b, &(dst->size_b), &ret))
	{
		dst->size_b++;
		dst->st_b[dst->size_b - 1] = ret;
	}
	return (dst);
}

t_queue		*bf_rotate_r(t_queue *parent)
{
	t_arg	ret;
	t_queue	*dst;

	if (parent->size_a < 3 || parent->size_b < 3)
		return (NULL);
	if (is_last_operation_equal(parent, "rrr\n"))
		return (NULL);
	ft_bzero(&ret, sizeof(t_arg));
	if (!(dst = copy_node(parent, "rr\n")))
		return (NULL);
	if (shift_up(dst->st_a, &(dst->size_a), &ret))
	{
		dst->size_a++;
		dst->st_a[dst->size_a - 1] = ret;
	}
	if (shift_up(dst->st_b, &(dst->size_b), &ret))
	{
		dst->size_b++;
		dst->st_b[dst->size_b - 1] = ret;
	}
	return (dst);
}
