/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:09:54 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 17:14:42 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			queue_pushback(t_queue *node, t_queue **tail)
{
	if (!tail || !(*tail))
		return (-1);
	if (!node)
		return (0);
	(*tail)->next = node;
	*tail = node;
	return (1);
}

t_queue		*queue_popfront(t_queue *head)
{
	t_queue	*to_remove;

	to_remove = head;
	head = head->next;
	kill_queue_node(to_remove);
	return (head);
}

t_queue		*copy_node(t_queue *parent, char *operation)
{
	t_queue *dst;

	if (!parent || !operation)
		return (NULL);
	if (!(dst = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (NULL);
	if (!(dst->st_a = (t_arg *)malloc(sizeof(t_arg) * (parent->size_a + 1))) \
		|| !(dst->st_b = (t_arg *)malloc(sizeof(t_arg) * (parent->size_b + 1)))\
		|| !(dst->operations = ft_strjoin(parent->operations, operation)))
	{
		kill_queue_node(dst);
		return (NULL);
	}
	ft_memcpy(dst->st_a, parent->st_a, parent->size_a * sizeof(t_arg));
	ft_memcpy(dst->st_b, parent->st_b, parent->size_b * sizeof(t_arg));
	dst->size_a = parent->size_a;
	dst->size_b = parent->size_b;
	dst->deep = parent->deep + 1;
	return (dst);
}

t_queue		*create_first_node(t_data *data)
{
	t_queue *dst;

	if (!data)
		return (NULL);
	if (!(dst = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (NULL);
	if (!(dst->st_a = (t_arg *)malloc(sizeof(t_arg) * data->size_a)) || \
		!(dst->st_b = (t_arg *)malloc(sizeof(t_arg) * data->size_a)) || \
		!(dst->operations = ft_strnew(0)))
	{
		kill_queue_node(dst);
		return (NULL);
	}
	ft_memcpy(dst->st_a, data->stack_a, data->size_a * sizeof(t_arg));
	ft_memcpy(dst->st_b, data->stack_b, data->size_b * sizeof(t_arg));
	dst->size_a = data->size_a;
	dst->size_b = data->size_b;
	return (dst);
}
