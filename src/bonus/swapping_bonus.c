/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:39:15 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/13 09:44:56 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

t_stack	*swap_first_num_bonus(t_stack *stack)
{
	t_stack	*temp;

	if (stack)
	{
		temp = stack;
		stack = stack->next;
		temp->next = stack->next;
		stack->next = temp;
	}
	return (stack);
}

t_stacks	*swap_first_num_both_bonus(t_stacks *stacks)
{
	swap_first_num_bonus(stacks->a);
	swap_first_num_bonus(stacks->b);
	return (stacks);
}

void	send_num_to_stack_bonus(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*temp;

	if (!*stack_to)
	{
		temp = *stack_from;
		*stack_from = temp->next;
		temp->next = NULL;
		*stack_to = temp;
	}
	else if (*stack_from && *stack_to)
	{
		temp = *stack_from;
		*stack_from = temp->next;
		temp->next = *stack_to;
		*stack_to = temp;
	}
}
