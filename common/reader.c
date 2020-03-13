/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:58:06 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/13 13:01:15 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int			is_int(char *src, int start, int end)
{
	long long	number;
	int			i;

	if (end <= start || (src[start] == '-' && end <= start + 1) || \
			end - start > 11 || (src[start] == '-' && end - start > 12))
		return (-1);
	i = start;
	if (src[i] == '-')
		i++;
	while (i < end && ft_isdigit(src[i]))
		i++;
	if (i != end)
		return (0);
	if (src[end] && src[end] != ' ' && src[end] != '\t')
		return (-1);
	number = ft_atoll(&(src[start]));
	if (number <= 2147483647 && number >= -2147483648)
		return (1);
	return (0);
}

static int	extract_arguments(t_arg *dst, char *src)
{
	int			i;
	int			start;
	int			end;

	i = 0;
	start = 0;
	end = 0;
	while (src[start])
	{
		while (src[start] && (src[start] == ' ' || src[start] == '\t'))
			start++;
		end = (src[start] != '-') ? start : start + 1;
		while (src[end] && ft_isdigit(src[end]))
			end++;
		if ((is_int(src, start, end)) > 0)
			dst[i++].arg = ft_atoll(&(src[start]));
		else if (src[end])
			return (-1);
		start = end;
	}
	return (i);
}

static int	extract_data(t_data *data, int ac, char **av, int count)
{
	int			ret;
	int			sum;
	int			i;

	sum = 0;
	i = 0;
	while (++i < ac)
	{
		ret = extract_arguments(&(data->stack_a[sum]), av[i]);
		if (ret < 0)
		{
			if (data->flag & FLAG_EXTENDED_OUTPUT)
				fprint("\033[31mwrong argument was found!\033[m\n");
			return (-1);
		}
		sum += ret;
	}
	if (sum != count)
	{
		if (data->flag & FLAG_EXTENDED_OUTPUT)
			fprint("\033[31mToo large argument was found\033[m\n");
		return (-1);
	}
	return (0);
}

t_data		*read_and_create_stack(int ac, char **av, int count)
{
	t_data		*data;
	int			i;

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		return (NULL);
	if (!(data->stack_a = (t_arg *)ft_memalloc(sizeof(t_arg) * count)) || \
			!(data->stack_b = (t_arg *)ft_memalloc(sizeof(t_arg) * count)) || \
			!(data->sorted = (int *)malloc(sizeof(int) * count)))
		return (free_data(data, "Error", "red"));
	i = 1;
	while (i < ac && !ft_strchr(av[i], '-'))
		i++;
	if (i == ac)
		i = 1;
	if (check_for_flags(data, av[i], &count) < 0)
		return (free_data(data, "Error", "red"));
	if (extract_data(data, ac, av, count) < 0)
		return (free_data(data, "Error", "red"));
	data->size_a = count;
	return (data);
}
