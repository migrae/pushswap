/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:46:32 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/10 09:40:56 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_2d(char **temp)
{
	int	i;

	i = 0;
	if (temp || *temp)
	{
		while (temp[i])
		{
			free(temp[i]);
			i++;
		}
		free(temp);
	}
}

void	shutdown(t_stacks *stacks, t_error type)
{
	free_stack(stacks->a);
	free_stack(stacks->b);
	free(stacks);
	if (type == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;

	temp = NULL;
	current = stack;
	while (current)
	{
		if (current->next)
			temp = current->next;
		else
			temp = NULL;
		free(current);
		current = temp;
	}
}
