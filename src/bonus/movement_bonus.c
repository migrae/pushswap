/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:22:42 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/06 17:12:26 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

t_stacks	*lowest_a_to_b_bonus(t_stacks *stacks)
{
	int		middle;
	t_stack	*lowest;

	lowest = find_lowest_number(stacks->a);
	middle = stack_height(stacks->a) / 2;
	if (middle > get_stack_pos(lowest, stacks->a))
	{
		while (get_stack_pos(lowest, stacks->a) != 1)
			stacks->a = rotation_bonus(stacks->a);
	}
	else
		while (get_stack_pos(lowest, stacks->a) != 1)
			stacks->a = rev_rotation_bonus(stacks->a);
	send_num_to_stack_bonus(&stacks->a, &stacks->b);
	return (stacks);
}

t_stacks	*lowest_to_b_bonus(t_stacks *stacks)
{
	int		middle;
	t_stack	*lowest;

	lowest = find_lowest_number(stacks->a);
	middle = stack_height(stacks->a) / 2;
	if (middle > get_stack_pos(lowest, stacks->a))
	{
		while (get_stack_pos(lowest, stacks->a) != 1)
			stacks->a = rotation_bonus(stacks->a);
	}
	else
		while (get_stack_pos(lowest, stacks->a) != 1)
			stacks->a = rev_rotation_bonus(stacks->a);
	send_num_to_stack_bonus(&stacks->a, &stacks->b);
	return (stacks);
}

t_stacks	*highest_to_top_b_bonus(t_stacks *stacks)
{
	int		middle;
	t_stack	*highest;

	highest = find_highest_number(stacks->b);
	middle = stack_height(stacks->b) / 2;
	if (middle > get_stack_pos(highest, stacks->b))
	{
		while (get_stack_pos(highest, stacks->b) != 1)
			stacks->b = rotation_bonus(stacks->b);
	}
	else
		while (get_stack_pos(highest, stacks->b) != 1)
			stacks->b = rev_rotation_bonus(stacks->b);
	return (stacks);
}

t_stacks	*chunk_to_b(t_stacks *stacks)
{
	t_stack	*temp;
	int		middle;
	int		i;

	i = 0;
	temp = stacks->a;
	while (i < stacks->chunk_size && temp)
	{
		middle = stack_height(stacks->a) / 2;
		if (temp->index <= stacks->chunk_size)
		{
			stacks = one_chunknum_to_b_bonus(stacks, temp);
			i++;
			temp = stacks->a;
		}
		else
			temp = temp->next;
	}
	return (stacks);
}

t_stacks	*one_chunknum_to_b_bonus(t_stacks *stacks, t_stack *temp)
{
	int	middle;

	middle = stack_height(stacks->a) / 2;
	if (middle > get_stack_pos(temp, stacks->a))
		while (get_stack_pos(temp, stacks->a) != 1)
					stacks->a = rotation_bonus(stacks->a);
	else
		while (get_stack_pos(temp, stacks->a) != 1)
			stacks->a = rev_rotation_bonus(stacks->a);
	send_num_to_stack_bonus(&stacks->a, &stacks->b);
	if (stacks->b->index >= (stacks->chunk_size - (stacks->chunk_part / 2)))
		stacks->b = rotation_bonus(stacks->b);
	return (stacks);
}
