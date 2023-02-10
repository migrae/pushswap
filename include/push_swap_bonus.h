/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:56:41 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/09 17:06:15 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				chunk_size;
	int				divider;
	int				chunk_part;
	int				start_size;
}					t_stacks;

typedef enum e_rotate
{
	rotate_a,
	rotate_b,
	rotate_both,
}	t_rotate;

typedef enum e_swap
{
	swap_a,
	swap_b,
	swap_both,
}	t_swap;

typedef enum e_push
{
	push_a,
	push_b,
}	t_push;

typedef enum e_error
{
	no_error,
	error,
}	t_error;

//Checker
int			main(int argc, char **argv);
int			check_input_bonus(int argc, char **argv, t_stacks *stacks);
int			check_split_bonus(char *str);
int			check_dubs(t_stacks *stacks, int number);

//Utils
void		print_stack(t_stack *stack);
void		print_both_stacks(t_stacks *stacks);
int			stack_height(t_stack *stack);
t_stack		*ft_stack_last(t_stack *stack);

//Utils_2
t_stack		*find_lowest_number(t_stack *stack);
t_stack		*find_highest_number(t_stack *stack);
void		index_stack(t_stack *stack);
int			get_index(t_stack *current, t_stack *stack);
int			get_stack_pos(t_stack *current, t_stack *stack);

//Load Stack
int			load_stack_bonus(int argc, char **argv, t_stacks *stacks);
t_stack		*ft_new_num_node(int number);
t_stack		*ft_num_node_last(t_stack *lst);
void		ft_num_node_add_back(t_stack **stack, t_stack *new);
int			init_num_node(t_stacks *stacks, char *str);

//Rotation
t_stack		*rotation_bonus(t_stack *stack);
t_stack		*rev_rotation_bonus(t_stack *stack);
t_stacks	*rotate_both_stacks_bonus(t_stacks *stacks);
t_stacks	*rev_rotate_both_stacks_bonus(t_stacks *stacks);

//Swapping & Pushing
t_stack		*swap_first_num_bonus(t_stack *stack);
t_stacks	*swap_first_num_both_bonus(t_stacks *stacks);
void		send_num_to_stack_bonus(t_stack **stack_from, t_stack **stack_to);

//Movement
t_stacks	*lowest_to_b(t_stacks *stacks);
t_stacks	*highest_to_top_b(t_stacks *stacks);
t_stacks	*chunk_to_b(t_stacks *stacks);
t_stacks	*one_chunknum_to_b_bonus(t_stacks *stacks, t_stack *temp);
t_stacks	*lowest_a_to_b(t_stacks *stacks);

//Free
void		free_2d_bonus(char **temp);
void		free_stack_bonus(t_stack *stack);
void		shutdown_bonus(t_stacks *stacks, t_error type);

//Solve
t_stacks	*solve(t_stacks *stacks);
t_stack		*solve_3(t_stack *stack);
t_stacks	*solve_12_and_more(t_stacks *stacks);

#endif
