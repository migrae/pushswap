/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:13:13 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/09 16:06:17 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		ft_printf("NUMBER: %i | INDEX: %i\n", current->number, current->index);
		current = current->next;
	}
}

void	print_both_stacks(t_stacks *stacks)
{
	ft_printf("STACK A:\n");
	print_stack(stacks->a);
	ft_printf("STACK B:\n");
	print_stack(stacks->b);
}

int	stack_height(t_stack *stack)
{
	t_stack	*current;
	int		height;

	current = stack;
	height = 0;
	while (current)
	{
		height++;
		current = current->next;
	}
	return (height);
}

t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (!temp->next)
			return (temp);
		temp = temp->next;
	}
	return (0);
}
