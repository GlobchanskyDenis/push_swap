/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:54:25 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/14 16:43:33 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	skip_stack(void)
{
	int			len;
	int			print;

	len = 200 / 5 + 10;
	print = 0;
	while (print < len)
	{
		fprint(" ");
		print++;
	}
}

void	print_arg(int arg)
{
	int			len;
	int			cpy_arg;

	cpy_arg = arg;
	len = 1;
	if (arg < 0)
	{
		arg = -arg;
		len++;
	}
	while (arg > 9)
	{
		arg = arg / 10;
		len++;
	}
	while (len < 8)
	{
		fprint(" ");
		len++;
	}
	fprint("\033[32m%d \033[m", cpy_arg);
}

void	visualize_stack(t_data *data, int arg)
{
	int			len;
	int			print;

	len = (arg - data->min) * 200 / \
			(data->max - data->min) / 5 + 1;
	print_arg(arg);
	fprint("\033[41m");
	print = 0;
	while (print < len)
	{
		fprint(" ");
		print++;
	}
	fprint("\033[m");
	len = 200 / 5 + 1;
	while (print < len)
	{
		fprint(" ");
		print++;
	}
}

void	visualize_stacks(t_data *data, int i)
{
	int			count;

	if (i < data->size_a)
		visualize_stack(data, data->stack_a[i].arg);
	else
		skip_stack();
	count = 0;
	while (++count < 10)
		fprint(" ");
	if (i < data->size_b)
		visualize_stack(data, data->stack_b[i].arg);
	else
		skip_stack();
	fprint("\n");
}

void	visualization(t_data *data, char *message)
{
	int			i;

	if (!(data->flag & FLAG_VISUALIZATION))
		return ;
	i = 0;
	fprint("\033[35m\t%s\n\033[m", message);
	while (i < data->size_a || i < data->size_b)
	{
		visualize_stacks(data, i);
		i++;
	}
	if (!(data->flag & FLAG_VERBOSE))
	{
		i = 0;
		while (i < VISUALIZATION_DELAY)
			i++;
	}
	else
	{
		ft_strdel(&(data->line));
		fprint("press enter..");
		fgnl(0, &(data->line));
	}
	fprint("\n");
	fgnl_free();
}
