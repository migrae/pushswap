/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:25:32 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/06 17:06:41 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

t_stack	*rotation_bonus(t_stack *stack)
{
	t_stack	*temp;

	if (stack && stack->next)
	{
		temp = stack;
		stack = stack->next;
		temp->next = NULL;
		ft_num_node_add_back(&stack, temp);
	}
	return (stack);
}

t_stack	*rev_rotation_bonus(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	stack = ft_stack_last(stack);
	stack->next = temp;
	while (temp->next != stack)
		temp = temp->next;
	temp->next = NULL;
	return (stack);
}

t_stacks	*rotate_both_stacks_bonus(t_stacks *stacks)
{
	rotation_bonus(stacks->a);
	rotation_bonus(stacks->b);
	return (stacks);
}

t_stacks	*rev_rotate_both_stacks_bonus(t_stacks *stacks)
{
	rev_rotation_bonus(stacks->a);
	rev_rotation_bonus(stacks->b);
	return (stacks);
}
