/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:09:16 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 16:28:16 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	error_print(t_data *data, char *message)
{
	if (data->flag & FLAG_EXTENDED_OUTPUT)
		fprint("\033[31m%s\033[m\n", message);
	return (-1);
}

int			checker_check_flags_combination(t_data *data)
{
	if (data->flag & FLAG_BRUTE_FORCE)
		return (error_print(data, "Invalid flag"));
	if (data->flag & FLAG_VISUALIZATION)
		return (error_print(data, "Invalid flag"));
	if (data->flag & FLAG_BUBLESORT)
		return (error_print(data, "Invalid flag"));
	return (0);
}

int			push_swap_check_flags_combination(t_data *data)
{
	if ((data->flag & FLAG_BRUTE_FORCE) && (data->flag & FLAG_BUBLESORT))
		return (error_print(data, "Conflict flags"));
	if ((data->flag & FLAG_BRUTE_FORCE) && (data->flag & FLAG_VERBOSE))
		data->flag &= ~(FLAG_VERBOSE);
	if ((data->flag & FLAG_BRUTE_FORCE) && (data->flag & FLAG_EXTENDED_OUTPUT))
		data->flag &= ~(FLAG_EXTENDED_OUTPUT);
	if ((data->flag & FLAG_VISUALIZATION) && (data->flag & FLAG_BRUTE_FORCE))
		data->flag &= ~(FLAG_VISUALIZATION);
	if ((data->flag & FLAG_VISUALIZATION) && \
			(data->flag & FLAG_EXTENDED_OUTPUT))
		data->flag &= ~(FLAG_EXTENDED_OUTPUT);
	return (0);
}

static int	extract_flags(t_data *data, char *line, int len)
{
	int			i;

	i = 0;
	while (++i < len)
	{
		if (line[i] == 'v' && !(data->flag & FLAG_VERBOSE))
			data->flag = data->flag | FLAG_VERBOSE;
		else if (line[i] == 'e' && !(data->flag & FLAG_EXTENDED_OUTPUT))
			data->flag = data->flag | FLAG_EXTENDED_OUTPUT;
		else if (line[i] == 'b' && !(data->flag & FLAG_BUBLESORT))
			data->flag = data->flag | FLAG_BUBLESORT;
		else if (line[i] == 'f' && !(data->flag & FLAG_BRUTE_FORCE))
			data->flag = data->flag | FLAG_BRUTE_FORCE;
		else if (line[i] == 'g' && !(data->flag & FLAG_VISUALIZATION))
			data->flag = data->flag | FLAG_VISUALIZATION;
		else if (line[i] == 'v' || line[i] == 'e' || line[i] == 'b' || \
				line[i] == 'f' || line[i] == 'g')
			return (error_print(data, "Double flag inclusion"));
		else
			return (error_print(data, "Invalid flag"));
	}
	return (0);
}

int			check_for_flags(t_data *data, char *line, int *count)
{
	int			start;
	int			len;
	int			ret;

	start = 0;
	while (line[start] && (line[start] == ' ' || line[start] == '\t'))
		start++;
	len = 0;
	while (line[start + len] && line[start + len] != ' ' && \
			line[start + len] != '\t')
		len++;
	if ((ret = is_int(line, start, start + len)) < 0 && len > 1)
		return (-1);
	if (ret == 1)
		return (0);
	if (len < 2 || line[start] != '-')
		return (0);
	(*count)--;
	ret = extract_flags(data, &(line[start]), len);
	ft_memset(&(line[start]), (int)(' '), len);
	return (ret);
}
