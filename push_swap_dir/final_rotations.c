/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:05:32 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/09 22:31:23 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			final_forward_steps(t_data *data)
{
	int		i_next;
	int		i_prev;
	t_arg	prev;
	t_arg	next;
	int		steps;

	i_next = 0;
	i_prev = data->size_a - 1;
	next = data->stack_a[i_next];
	prev = data->stack_a[i_prev];
	steps = 0;
	while (!(next.position == 0 && \
			prev.position == data->size_a + data->size_b - 1))
	{
		i_prev = i_next;
		i_next++;
		next = data->stack_a[i_next];
		prev = data->stack_a[i_prev];
		steps++;
	}
	return (steps);
}

int			final_reverse_steps(t_data *data)
{
	int		i_next;
	int		i_prev;
	t_arg	prev;
	t_arg	next;
	int		steps;

	i_next = 0;
	i_prev = data->size_a - 1;
	next = data->stack_a[i_next];
	prev = data->stack_a[i_prev];
	steps = 0;
	while (!(next.position == 0 && \
			prev.position == data->size_a + data->size_b - 1))
	{
		i_next = i_prev;
		i_prev--;
		next = data->stack_a[i_next];
		prev = data->stack_a[i_prev];
		steps++;
	}
	return (steps);
}

/*
**	This function rotates atack A if it needed
*/

int			final_rotations(t_data *data)
{
	int		forward;
	int		reverse;

	forward = final_forward_steps(data);
	reverse = final_reverse_steps(data);
	if (forward < reverse)
	{
		while (forward--)
			rotate_a(data);
	}
	else
	{
		while (reverse--)
			rev_rotate_a(data);
	}
	return (0);
}
