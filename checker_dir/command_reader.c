/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 22:29:22 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/02/20 22:28:55 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	push_commands(t_data *data, char *line)
{
	if (!strcmp(line, "pa"))
	{
		push_a(data);
		return (1);
	}
	else if (!strcmp(line, "pb"))
	{
		push_b(data);
		return (1);
	}
	return (0);
}

static int	swap_commands(t_data *data, char *line)
{
	if (!strcmp(line, "sa"))
	{
		swap_a(data);
		return (1);
	}
	else if (!strcmp(line, "sb"))
	{
		swap_b(data);
		return (1);
	}
	else if (!strcmp(line, "ss"))
	{
		swap_s(data);
		return (1);
	}
	return (0);
}

static int	rotate_commands(t_data *data, char *line)
{
	if (!strcmp(line, "ra"))
	{
		rotate_a(data);
		return (1);
	}
	else if (!strcmp(line, "rb"))
	{
		rotate_b(data);
		return (1);
	}
	else if (!strcmp(line, "rr"))
	{
		rotate_r(data);
		return (1);
	}
	return (0);
}

static int	rev_rotate_commands(t_data *data, char *line)
{
	if (!strcmp(line, "rra"))
	{
		rev_rotate_a(data);
		return (1);
	}
	else if (!strcmp(line, "rrb"))
	{
		rev_rotate_b(data);
		return (1);
	}
	else if (!strcmp(line, "rrr"))
	{
		rev_rotate_r(data);
		return (1);
	}
	return (0);
}

int			command_reader(t_data *data)
{
	if ((data->flag & FLAG_VERBOSE) && (data->flag & FLAG_EXTENDED_OUTPUT))
	{
		fprint("\033[32mType commands to sort stack. Commands:\n");
		fprint("sa sb ss pa pb ra rb rr rra rrb rrr\033[m\n");
	}
	while (fgnl(0, &(data->line)) > 0)
	{
		if (rotate_commands(data, data->line) || \
				rev_rotate_commands(data, data->line) || \
				push_commands(data, data->line) || \
				swap_commands(data, data->line))
		{
			print_stacks(data);
			ft_strdel(&(data->line));
		}
		else
		{
			ft_strdel(&(data->line));
			if (data->flag & FLAG_EXTENDED_OUTPUT)
				fprint("\033[31mUnknown command\033[m\n");
			return (-1);
		}
	}
	return (0);
}
