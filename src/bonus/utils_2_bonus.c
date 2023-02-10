/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:33:42 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/06 17:01:56 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

t_stack	*find_lowest_number(t_stack *stack)
{
	t_stack	*lowest;
	t_stack	*temp;

	temp = stack;
	lowest = stack;
	while (temp)
	{
		if (get_index(temp, stack) == 1)
			return (temp);
		temp = temp->next;
	}
	return (stack);
}

t_stack	*find_highest_number(t_stack *stack)
{
	t_stack	*highest;
	t_stack	*temp;

	temp = stack;
	highest = stack;
	while (temp)
	{
		if (get_index(temp, stack) == stack_height(stack))
			return (temp);
		temp = temp->next;
	}
	return (stack);
}

void	index_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;

	current = stack;
	while (current)
	{
		temp = stack;
		while (temp)
		{
			if (current->number >= temp->number)
				current->index += 1;
			temp = temp->next;
		}
		current = current->next;
	}
}

int	get_index(t_stack *current, t_stack *stack)
{
	t_stack	*temp;
	int		index;

	index = 0;
	temp = stack;
	while (temp)
	{
		if (current->number >= temp->number)
			index += 1;
		temp = temp->next;
	}
	return (index);
}

int	get_stack_pos(t_stack *current, t_stack *stack)
{
	t_stack	*temp;
	int		pos;

	pos = 0;
	temp = current;
	while (temp->next)
	{
		temp = temp->next;
		pos++;
	}
	pos = stack_height(stack) - pos;
	return (pos);
}
