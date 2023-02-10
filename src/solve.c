/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:25:22 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/10 14:43:59 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

t_stack	*solve_3(t_stack *stack)
{	
	if (get_index(stack, stack) == 3 && get_index(stack->next, stack) == 2)
	{
		stack = swap_first_num(stack, swap_a);
		stack = rev_rotation(stack, rotate_a);
	}
	else if (get_index(stack, stack) == 2 && get_index(stack->next, stack) == 1)
		stack = swap_first_num(stack, swap_a);
	else if (get_index(stack, stack) == 3 && get_index(stack->next, stack) == 1)
		stack = rotation(stack, rotate_a);
	else if (get_index(stack, stack) == 1 && get_index(stack->next, stack) == 3)
	{
		stack = swap_first_num(stack, swap_a);
		stack = rotation(stack, rotate_a);
	}
	else if (get_index(stack, stack) == 2 && get_index(stack->next, stack) == 3)
		stack = rev_rotation(stack, rotate_a);
	return (stack);
}

t_stacks	*solve_under_12(t_stacks *stacks)
{
	while (stack_height(stacks->a) > 3)
		stacks = lowest_a_to_b(stacks);
	stacks->a = solve_3(stacks->a);
	while (stack_height(stacks->b))
		send_num_to_stack(&stacks->b, &stacks->a, push_b);
	return (stacks);
}

t_stacks	*solve_12_and_more(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->chunk_size = stack_height(stacks->a) / stacks->divider;
	stacks->start_size = stack_height(stacks->a);
	stacks->chunk_part = stacks->start_size / stacks->divider;
	while (i < (stacks->divider - 1))
	{
		stacks = chunk_to_b(stacks);
		stacks->chunk_size = stacks->chunk_size
			+ (stacks->start_size / stacks->divider);
		i++;
	}
	while (stack_height(stacks->a))
	{
		stacks = lowest_a_to_b(stacks);
		if (stacks->b->index >= (stacks->start_size - (stacks->chunk_part / 2)))
			stacks->b = rotation(stacks->b, rotate_b);
	}
	while (stack_height(stacks->b))
	{
		stacks = highest_to_top_b(stacks);
		send_num_to_stack(&stacks->b, &stacks->a, push_b);
	}
	return (stacks);
}

t_stacks	*solve(t_stacks *stacks)
{
	index_stack(stacks->a);
	if (!stack_is_sorted(stacks->a))
		return (stacks);
	if (stack_height(stacks->a) <= 12)
	{
		while (stack_height(stacks->a) > 5)
			stacks = lowest_to_b(stacks);
		stacks = solve_under_12(stacks);
	}
	else if (stack_height(stacks->a) > 12 && stack_height(stacks->a) <= 200)
	{
		stacks->divider = 4;
		stacks = solve_12_and_more(stacks);
	}
	else if (stack_height(stacks->a) > 200)
	{
		stacks->divider = 8;
		stacks = solve_12_and_more(stacks);
	}
	return (stacks);
}
