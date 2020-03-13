/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:22:00 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 16:44:52 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H

# define COMMON_H
# define FLAG_VERBOSE				1
# define FLAG_EXTENDED_OUTPUT		2
# define FLAG_BUBLESORT				4
# define FLAG_BRUTE_FORCE			8
# define FLAG_VISUALIZATION			16
# define FLAG_PUSH_SWAP				32
# define VISUALIZATION_DELAY		300000000

# include "../libft/libft.h"

typedef struct	s_arg
{
	int				arg;
	int				position;
	int				calculation;
}				t_arg;

typedef struct	s_data
{
	t_arg			*stack_a;
	t_arg			*stack_b;
	int				size_a;
	int				size_b;
	int				min;
	int				max;
	int				flag;
	int				*sorted;
	char			*line;
}				t_data;

/*
**	OPERATIONS
*/

int				push_a(t_data *data);
int				push_b(t_data *data);
int				swap_a(t_data *data);
int				swap_b(t_data *data);
int				swap_s(t_data *data);
int				rev_rotate_a(t_data *data);
int				rev_rotate_b(t_data *data);
int				rev_rotate_r(t_data *data);
int				rotate_a(t_data *data);
int				rotate_b(t_data *data);
int				rotate_r(t_data *data);

/*
**	COMMON
*/

void			*free_data(t_data *data, char *message, char *color);
t_data			*read_and_create_stack(int ac, char **av, int count);
int				check_for_flags(t_data *data, char *line, int *count);
int				count_args(int ac, char **av);
int				check_data(t_data *data);
int				is_int(char *src, int start, int end);
void			print_stacks(t_data *data);
void			quicksort(t_data *data, t_arg *stack, int size);
int				check_arg_repeating(t_data *data);
int				checker_check_flags_combination(t_data *data);
int				push_swap_check_flags_combination(t_data *data);

void			visualization(t_data *data, char *operation);

#endif
