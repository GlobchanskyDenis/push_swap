/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 20:54:20 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 16:53:55 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

inline static void	qs_swap(int *arr, int *left, int *right)
{
	int		tmp;

	tmp = arr[*left];
	arr[*left] = arr[*right];
	arr[*right] = tmp;
	(*left)++;
	(*right)--;
}

static int			qs(int *arr, int first, int last)
{
	int		left;
	int		right;
	int		middle;

	left = first;
	right = last;
	middle = arr[(left + right) / 2];
	while (left <= right)
	{
		while (arr[left] < middle)
			left++;
		while (arr[right] > middle)
			right--;
		if (left <= right)
			qs_swap(arr, &left, &right);
		qs(arr, first, right);
		qs(arr, left, last);
	}
	return (1);
}

void				quicksort(t_data *data, t_arg *stack, int size)
{
	int		i;
	int		*sorted;

	sorted = data->sorted;
	i = -1;
	while (++i < size)
		sorted[i] = stack[i].arg;
	qs(sorted, 0, size - 1);
}
