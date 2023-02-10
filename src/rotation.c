/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:25:32 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/06 11:22:11 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*rotation(t_stack *stack, t_rotate type)
{
	t_stack	*temp;

	if (stack && stack->next)
	{
		temp = stack;
		stack = stack->next;
		temp->next = NULL;
		ft_num_node_add_back(&stack, temp);
		if (type == rotate_a)
			ft_printf("ra\n");
		else if (type == rotate_b)
			ft_printf("rb\n");
	}
	return (stack);
}

t_stack	*rev_rotation(t_stack *stack, t_rotate type)
{
	t_stack	*temp;

	temp = stack;
	stack = ft_stack_last(stack);
	stack->next = temp;
	while (temp->next != stack)
		temp = temp->next;
	temp->next = NULL;
	if (type == rotate_a)
		ft_printf("rra\n");
	else if (type == rotate_b)
		ft_printf("rrb\n");
	return (stack);
}

t_stacks	*rotate_both_stacks(t_stacks *stacks)
{
	rotation(stacks->a, rotate_both);
	rotation(stacks->b, rotate_both);
	ft_printf("rr\n");
	return (stacks);
}

t_stacks	*rev_rotate_both_stacks(t_stacks *stacks)
{
	rev_rotation(stacks->a, rotate_both);
	rev_rotation(stacks->b, rotate_both);
	ft_printf("rrr\n");
	return (stacks);
}
