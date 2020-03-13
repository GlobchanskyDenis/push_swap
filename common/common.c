/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:53:25 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/13 12:58:41 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void		*free_data(t_data *data, char *message, char *color)
{
	if (data)
	{
		if (data->stack_a)
			free(data->stack_a);
		if (data->stack_b)
			free(data->stack_b);
		if (data->line)
			free(data->line);
		if (data->sorted)
			free(data->sorted);
		free(data);
	}
	if (message && !ft_strcmp(message, "Error"))
		fprint_fd(2, "\033[31m%s\033[m\n", message);
	if (message && color && !ft_strcmp("red", color))
		fprint("\033[31m%s\033[m\n", message);
	if (message && color && !ft_strcmp("green", color))
		fprint("\033[32m%s\033[m\n", message);
	fgnl_free();
	return (NULL);
}

int			count_args(int ac, char **av)
{
	int			count;
	int			i;
	int			j;

	if (ac < 2)
		return (0);
	count = 0;
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ' || av[i][j] == '\t')
				j++;
			if (av[i][j])
				count++;
			while (av[i][j] && av[i][j] != ' ' && av[i][j] != '\t')
				j++;
		}
	}
	return (count);
}

int			check_data(t_data *data)
{
	t_arg	*stack;
	int		i;
	int		length;

	if (data->size_b || !(data->size_a))
	{
		if (data->flag & FLAG_EXTENDED_OUTPUT)
			fprint("\033[31mstack B isnt empty\033[m\n");
		return (-1);
	}
	stack = data->stack_a;
	length = data->size_a;
	i = -1;
	while (++i < length - 1)
	{
		if (stack[i].arg >= stack[i + 1].arg)
		{
			if (data->flag & FLAG_EXTENDED_OUTPUT)
				fprint("\033[31mArray is not sorted :(\033[m\n");
			return (-1);
		}
	}
	return (1);
}

void		print_stacks(t_data *data)
{
	int			i;

	if (!(data->flag & FLAG_VERBOSE) || (data->flag & FLAG_VISUALIZATION))
		return ;
	fprint("stack A\t\tstack B\n");
	i = 0;
	while (i < data->size_a || i < data->size_b)
	{
		if (i < data->size_a)
			fprint("%d", data->stack_a[i].arg);
		fprint("\t\t");
		if (i < data->size_b)
			fprint("%d", data->stack_b[i].arg);
		fprint("\n");
		i++;
	}
	fprint("\n");
}

int			check_arg_repeating(t_data *data)
{
	int			i;
	int			j;

	quicksort(data, data->stack_a, data->size_a);
	data->min = data->sorted[0];
	data->max = data->sorted[data->size_a - 1];
	i = data->size_a;
	while (--i >= 0)
	{
		j = 0;
		while (j < data->size_a && data->stack_a[j].arg != data->sorted[i])
			j++;
		if ((i && data->sorted[i] == data->sorted[i - 1]) || j > data->size_a)
		{
			if (data->flag & FLAG_EXTENDED_OUTPUT)
				fprint("\033[31mSome of arguments are repeating\033[m\n");
			return (-1);
		}
		data->stack_a[j].position = i;
	}
	return (0);
}
