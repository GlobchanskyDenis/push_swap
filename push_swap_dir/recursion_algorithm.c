/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:05:32 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/09 22:31:23 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			midian(t_data *data, t_arg *stack, int size)
{
	int			*sorted;
	int			ret;

	quicksort(data, stack, size);
	sorted = data->sorted;
	ret = sorted[size / 2];
	return (ret);
}

/*
**	This function find minimal amount of steps to sort all elements, that
**	less than midian value, in stack B. This function optimizing algorithm
*/

int			find_steps_optimization(t_arg *stack, int size, int midian)
{
	int			i;
	int			steps_forward;

	i = -1;
	while (++i < size)
	{
		if (stack[i].arg < midian)
			steps_forward = i + 1;
	}
	return (steps_forward);
}

/*
**	This function move all elements, that less than midian value, from
**	stack A to stack B.
*/

void		move_a_to_b(t_data *data)
{
	int			steps;
	int			midiana;

	midiana = midian(data, data->stack_a, data->size_a);
	steps = find_steps_optimization(data->stack_a, data->size_a, midiana);
	while (steps-- > 0)
	{
		if (data->stack_a[0].arg < midiana)
			push_b(data);
		else
			rotate_a(data);
	}
}

/*
**	This function recursively sends almost all elements from stack A to
**	stack B (only the largest values will remain).
**	This is actually pre-sorting.
*/

void		recursion_move_a_to_b(t_data *data)
{
	if (data->size_a < 4)
	{
		sort_3_args_stack_a(data);
		return ;
	}
	move_a_to_b(data);
	if (data->flag & FLAG_EXTENDED_OUTPUT)
		full_print_stacks(data);
	recursion_move_a_to_b(data);
}
