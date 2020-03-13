/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 23:17:33 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 17:08:01 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			print_usage(t_data *data, char *message)
{
	if (data && (data->flag & FLAG_EXTENDED_OUTPUT) && message)
		fprint("\033[31m%s\033[m\n", message);
	fprint("\033[32mUsage: ./push_swap [-flags] arg1 arg2 ...\n\tFlags:\n");
	fprint("-e:\textended output (does not work with visualization ");
	fprint("and bruteforce mode)\n");
	fprint("-v:\tverbose mode (does not work with bruteforce mode)\n");
	fprint("-b:\ttype of sorting - bublesort\n");
	fprint("-f:\ttype of sorting - bruteforce\n");
	fprint("-g:\tvisualization mode (does not work with bruteforce mode)\n");
	fprint("\033[m");
	if (data)
		free_data(data, NULL, NULL);
	return (-1);
}

void		print_stacks_arguments_by_index(t_data *data, int i)
{
	if (i < data->size_a)
	{
		fprint("%d %d %d\t\t", data->stack_a[i].arg, \
				data->stack_a[i].position, data->stack_a[i].calculation);
	}
	else
		fprint("\t\t");
	if (i < data->size_b)
	{
		fprint("%d %d %d\n", data->stack_b[i].arg, \
				data->stack_b[i].position, data->stack_b[i].calculation);
	}
	else
		fprint("\n");
}

int			full_print_stacks(t_data *data)
{
	t_arg	*st_a;
	t_arg	*st_b;
	int		len_a;
	int		len_b;
	int		i;

	fprint("--------------------------------\n");
	fprint("- STACK A ---------- STACK B ---\n");
	st_a = data->stack_a;
	st_b = data->stack_b;
	len_a = data->size_a;
	len_b = data->size_b;
	i = 0;
	while (i < len_a || i < len_b)
	{
		print_stacks_arguments_by_index(data, i);
		i++;
	}
	fprint("--------------------------------\n");
	return (0);
}

static void	solver(t_data *data)
{
	if (data->flag & FLAG_BUBLESORT)
		bublesort(data);
	else if (data->flag & FLAG_BRUTE_FORCE)
		bruteforce(data);
	else
		smart_wheel_algorithm(data);
}

int			main(int ac, char **av)
{
	int			count;
	t_data		*data;
	char		*line;

	if ((count = count_args(ac, av)) < 1)
		return (print_usage(NULL, NULL));
	if (!(data = read_and_create_stack(ac, av, count)))
		return (-1);
	if (data->size_a < 1)
		return (print_usage(data, "No arguments was found"));
	if (check_arg_repeating(data) < 0)
		return ((int)free_data(data, "KO", "red"));
	if (push_swap_check_flags_combination(data))
		return ((int)free_data(data, "KO", "red"));
	data->flag = data->flag | FLAG_PUSH_SWAP;
	if (check_data(data) < 0)
		solver(data);
	if ((data->flag & FLAG_VERBOSE) && !(data->flag & FLAG_VISUALIZATION))
		full_print_stacks(data);
	if (check_data(data) < 0 && (data->flag & FLAG_EXTENDED_OUTPUT))
		return ((int)free_data(data, "KO", "red"));
	else if (check_data(data) > 0 && (data->flag & FLAG_EXTENDED_OUTPUT))
		return ((int)free_data(data, "OK", "green"));
	free_data(data, NULL, NULL);
	return (0);
}
