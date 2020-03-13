/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:54:27 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/10 23:00:44 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			print_usage(t_data *data, char *message)
{
	if (data && (data->flag & FLAG_EXTENDED_OUTPUT) && message)
		fprint("\033[31m%s\033[m\n", message);
	fprint("\033[32mUsage: ./push_swap [-flags] arg1 arg2 ...\n\tFlags:\n");
	fprint("-e:\textended output\n");
	fprint("-v:\tverbose mode (display stack's status)\n\033[m");
	if (data)
		free_data(data, NULL, NULL);
	return (-1);
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
	if (checker_check_flags_combination(data))
		return ((int)free_data(data, "Error", "red"));
	if (data->size_a < 1)
		return (print_usage(data, "No arguments was found"));
	if (check_arg_repeating(data) < 0 || command_reader(data) < 0)
		return ((int)free_data(data, "Error", "red"));
	if (check_data(data) < 0)
		return ((int)free_data(data, "KO", "red"));
	free_data(data, "OK", "green");
	return (0);
}
