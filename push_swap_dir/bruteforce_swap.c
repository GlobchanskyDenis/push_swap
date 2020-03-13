/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:08:23 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 16:55:53 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_queue		*bf_swap_a(t_queue *parent)
{
	t_arg	*stack;
	t_arg	tmp;
	t_queue	*dst;

	if (parent->size_a < 2)
		return (NULL);
	if (is_last_operation_equal(parent, "sa\n"))
		return (NULL);
	if (!(dst = copy_node(parent, "sa\n")))
		return (NULL);
	stack = dst->st_a;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	return (dst);
}

t_queue		*bf_swap_b(t_queue *parent)
{
	t_arg	*stack;
	t_arg	tmp;
	t_queue	*dst;

	if (parent->size_b < 2)
		return (NULL);
	if (is_last_operation_equal(parent, "sb\n"))
		return (NULL);
	if (!(dst = copy_node(parent, "sb\n")))
		return (NULL);
	stack = dst->st_b;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	return (dst);
}

t_queue		*bf_swap_s(t_queue *parent)
{
	t_arg	*stack;
	t_arg	tmp;
	t_queue	*dst;

	if (parent->size_a < 2 || parent->size_b < 2)
		return (NULL);
	if (is_last_operation_equal(parent, "ss\n"))
		return (NULL);
	if (!(dst = copy_node(parent, "ss\n")))
		return (NULL);
	stack = dst->st_a;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	stack = dst->st_b;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	return (dst);
}
