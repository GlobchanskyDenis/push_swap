/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:13:23 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 17:16:12 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		kill_queue_node(t_queue *node)
{
	if (node->st_a)
		free(node->st_a);
	if (node->st_b)
		free(node->st_b);
	if (node->operations)
		free(node->operations);
	free(node);
}

void		kill_queue_list(t_queue *head)
{
	t_queue	*tmp;

	if (!head)
		return ;
	while (head)
	{
		tmp = head;
		head = head->next;
		kill_queue_node(tmp);
	}
}
