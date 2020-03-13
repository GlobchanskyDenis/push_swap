/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 23:18:45 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/03/12 17:08:32 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../common/common.h"

typedef struct	s_queue
{
	t_arg			*st_a;
	t_arg			*st_b;
	int				size_a;
	int				size_b;
	int				deep;
	char			*operations;
	struct s_queue	*next;
}				t_queue;

/*
**	bublesort.c
*/

int				bublesort(t_data *data);

/*
**	main.c
*/

int				full_print_stacks(t_data *data);

/*
**	sort_small_stack.c
*/

int				sort_6_args(t_data *data);
int				sort_3_args_stack_a(t_data *data);

/*
**	recursion_algorithm.c
*/

int				midian(t_data *data, t_arg *stack, int size);
void			recursion_move_a_to_b(t_data *data);

/*
**	final_rotations.c
*/

int				final_rotations(t_data *data);

/*
**	smart_wheel_1.c
**	smart_wheel_2.c
*/

int				smart_wheel_algorithm(t_data *data);
int				forward_steps_for_element_in_b(t_data *data, int arg_b);
int				reverse_steps_for_element_in_b(t_data *data, int arg_b);
int				prepare_table_and_find_element(t_data *data);

/*
**	queue.c
*/

t_queue			*copy_node(t_queue *parent, char *operation);
int				queue_pushback(t_queue *node, t_queue **tail);
t_queue			*queue_popfront(t_queue *head);
void			kill_queue_list(t_queue *head);
void			kill_queue_node(t_queue *node);
t_queue			*create_first_node(t_data *data);

t_queue			*bf_push_a(t_queue *parent);
t_queue			*bf_push_b(t_queue *parent);
t_queue			*bf_rotate_a(t_queue *parent);
t_queue			*bf_rotate_b(t_queue *parent);
t_queue			*bf_rotate_r(t_queue *parent);
t_queue			*bf_swap_a(t_queue *parent);
t_queue			*bf_swap_b(t_queue *parent);
t_queue			*bf_swap_s(t_queue *parent);
t_queue			*bf_rev_rotate_a(t_queue *parent);
t_queue			*bf_rev_rotate_b(t_queue *parent);
t_queue			*bf_rev_rotate_r(t_queue *parent);

int				bruteforce(t_data *data);
int				is_last_operation_equal(t_queue *parent, char *operation);

#endif
