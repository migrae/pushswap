/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:39:15 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/13 09:42:30 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*swap_first_num(t_stack *stack, t_swap type)
{
	t_stack	*temp;

	if (stack)
	{
		temp = stack;
		stack = stack->next;
		temp->next = stack->next;
		stack->next = temp;
	}
	if (type == swap_a)
		ft_printf("sa\n");
	else if (type == swap_b)
		ft_printf("b\n");
	return (stack);
}

t_stacks	*swap_first_num_both(t_stacks *stacks)
{
	swap_first_num(stacks->a, swap_both);
	swap_first_num(stacks->b, swap_both);
	ft_printf("ss\n");
	return (stacks);
}

void	send_num_to_stack(t_stack **stack_from, t_stack **stack_to, t_push type)
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
	if (type == push_a)
		ft_printf("pb\n");
	else if (type == push_b)
		ft_printf("pa\n");
}
