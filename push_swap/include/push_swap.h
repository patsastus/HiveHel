/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:05:23 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/01 11:30:02 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>   
# include <libft.h>

# ifndef BUCKET_SIZE
#  define BUCKET_SIZE 40
# endif

//The allowed moves, correspond to integers 0 through 10
typedef enum e_move
{
	SWAPA,
	SWAPB,
	SS,
	PUSHA,
	PUSHB,
	ROTA,
	ROTB,
	RR,
	RROTA,
	RROTB,
	RRR
}	t_move;

typedef void	(*t_function)(void *);

typedef struct s_data
{
	t_list		*a;
	t_list		*b;
	int			stack_size;
	int			size_a;
	int			size_b;
	char		candidate;
	t_function	funcs[11];	
}	t_data;

//main.c
void		free_and_exit(t_list *ptr);

//init.c
void		parse_validate_input(t_data *data, int argc, char **argv);
t_list		*parse_input_argument(char *str);
int			atoi_check(int *ptr, char *str);
void		init_data(t_data *data);

//list.c
t_list		*make_list_node(int content);
void		rotate_list(t_list **list);
void		rev_rotate_list(t_list **list);
int			check_duplicate_in(t_data *data, t_list *candidates);
void		swap_top_two(t_list **list);

//list_utils.c
ssize_t		index_of(t_list *list, int value);
int			list_min(t_list *list);
int			list_max(t_list *list);
int			get_mean(t_list *list);
int			get_median(t_list *stack, int index, int num_medians);

//utils.c
int			is_sorted(t_data *data);
void		make_move(t_data *data, t_move m);
void		find_best_candidate(t_data *data);
void		choose_and_make_moves(t_data *data, long *array);

//sort.c
void		presort(t_data *data);
void		move_to_a(t_data *data, int a_i, int value_b);
void		small_sort(t_data *data);
long		largest_below(t_list *list, t_list *node, t_list *check);
long		smallest_above(t_list *list, t_list *node, t_list *check);

//sort_utils.c
int			calculate_cost(t_data *data, int a_i, int b_i);
void		move_rotate_both(t_data *data, int a_i, int b_i);
void		move_rev_rotate_both(t_data *data, int a_i, int b_i);
void		move_opposite_rotate_both(t_data *data, int a_i, int b_i);
void		final_rotate(t_data *data, int pivot);

//sort_bucket.c
void		sort_bucket(t_data *data);

//moves_push_swap.c
void		swap_a(void *ptr);
void		swap_b(void *ptr);
void		push_a(void *ptr);
void		push_b(void *ptr);

//moves_rotates.c 
void		rotate_a(void *ptr);
void		rotate_b(void *ptr);
void		rev_rotate_a(void *ptr);
void		rev_rotate_b(void *ptr);

//moves_doubles.c  
void		rotate_both(void *ptr);
void		rev_rotate_both(void *ptr);
void		swap_both(void *ptr);

#endif
