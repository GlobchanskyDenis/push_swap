/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:13:24 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/13 12:54:42 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sorted(t_queue *node)
{
	int			i;

	if (node->size_b)
		return (0);
	i = -1;
	while (++i < node->size_a)
	{
		if (node->st_a[i].position != i)
			return (0);
	}
	return (1);
}

int			is_last_operation_equal(t_queue *parent, char *operation)
{
	size_t		len1;
	size_t		len2;

	if (!parent || !(parent->operations) || !operation)
		return (-1);
	len1 = ft_strlen(parent->operations);
	len2 = ft_strlen(operation);
	if (len1 == 0 || len1 < len2)
		return (0);
	if (ft_strcmp(&(parent->operations[len1 - len2]), operation))
		return (0);
	return (1);
}

int			add_new_operations_to_queue_1(t_queue *head, t_queue **tail)
{
	if ((queue_pushback(bf_swap_a(head), tail)) < 0)
		return (-1);
	if (is_sorted(*tail))
		return (1);
	if ((queue_pushback(bf_swap_b(head), tail)) < 0)
		return (-1);
	if (is_sorted(*tail))
		return (1);
	if ((queue_pushback(bf_swap_s(head), tail)) < 0)
		return (-1);
	if (is_sorted(*tail))
		return (1);
	if ((queue_pushback(bf_rev_rotate_a(head), tail)) < 0)
		return (-1);
	if (is_sorted(*tail))
		return (1);
	if ((queue_pushback(bf_rev_rotate_b(head), tail)) < 0)
		return (-1);
	if (is_sorted(*tail))
		return (1);
	if ((queue_pushback(bf_rev_rotate_r(head), tail)) < 0)
		return (-1);
	if (is_sorted(*tail))
		return (1);
	return (0);
}

int			add_new_operations_to_queue_2(t_queue *head, t_queue **tail)
{
	if ((queue_pushback(bf_push_a(head), tail)) < 0)
		return (-1);
	if (is_sorted(*tail))
		return (1);
	if ((queue_pushback(bf_push_b(head), tail)) < 0)
		return (-1);
	if (is_sorted(*tail))
		return (1);
	if ((queue_pushback(bf_rotate_a(head), tail)) < 0)
		return (-1);
	if (is_sorted(*tail))
		return (1);
	if ((queue_pushback(bf_rotate_b(head), tail)) < 0)
		return (-1);
	if (is_sorted(*tail))
		return (1);
	if ((queue_pushback(bf_rotate_r(head), tail)) < 0)
		return (-1);
	if (is_sorted(*tail))
		return (1);
	return (0);
}

/*
**	This is algorithm that itarates all operations, using queue, untill stack
**	will be sorted. It gives the best posible combination of operations for
**	each unsorted stack to sort it.
*/

int			bruteforce(t_data *data)
{
	t_queue		*head;
	t_queue		*tmp;
	t_queue		*tail;
	int			ret;

	if (!(head = create_first_node(data)))
		return (-1);
	tail = head;
	while (1)
	{
		if ((ret = add_new_operations_to_queue_1(head, &tail)) != 0)
			break ;
		if ((ret = add_new_operations_to_queue_2(head, &tail)) != 0)
			break ;
		if (!(head = queue_popfront(head)))
			break ;
	}
	if (!tail || !(tail->operations) || ret != 1)
		return (-1);
	fprint("%s", tail->operations);
	kill_queue_list(head);
	return (0);
}
