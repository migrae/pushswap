/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:13:09 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/09 17:05:35 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

int	stack_is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		if (current->number > current->next->number)
			return (1);
		current = current->next;
	}
	return (0);
}

int	check_stacks(t_stacks *stacks)
{
	if (!stack_is_sorted(stacks->a) && !stacks->b)
		return (0);
	else
		return (1);
}

t_stacks	*process_input(char *line, t_stacks *stacks)
{
	if (!ft_strncmp(line, "sa\n", 3))
		stacks->a = swap_first_num_bonus(stacks->a);
	else if (!ft_strncmp(line, "sb\n", 3))
		stacks->b = swap_first_num_bonus(stacks->b);
	else if (!ft_strncmp(line, "ss\n", 3))
		stacks = swap_first_num_both_bonus(stacks);
	else if (!ft_strncmp(line, "pb\n", 3))
		send_num_to_stack_bonus(&stacks->a, &stacks->b);
	else if (!ft_strncmp(line, "pa\n", 3))
		send_num_to_stack_bonus(&stacks->b, &stacks->a);
	else if (!ft_strncmp(line, "ra\n", 3))
		stacks->a = rotation_bonus(stacks->a);
	else if (!ft_strncmp(line, "rb\n", 3))
		stacks->b = rotation_bonus(stacks->b);
	else if (!ft_strncmp(line, "rr\n", 3))
		stacks = rotate_both_stacks_bonus(stacks);
	else if (!ft_strncmp(line, "rra\n", 4))
		stacks->a = rev_rotation_bonus(stacks->a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		stacks->b = rev_rotation_bonus(stacks->b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		stacks = rev_rotate_both_stacks_bonus(stacks);
	else
		shutdown_bonus(stacks, error);
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*line;

	stacks = malloc(sizeof(t_stacks *));
	if (!stacks)
		shutdown_bonus(stacks, error);
	if (check_input_bonus(argc, argv, stacks))
		shutdown_bonus(stacks, error);
	if (load_stack_bonus(argc, argv, stacks) || !stacks->a)
		shutdown_bonus(stacks, error);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		stacks = process_input(line, stacks);
	}
	if (!check_stacks (stacks))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	shutdown_bonus(stacks, no_error);
	return (0);
}
