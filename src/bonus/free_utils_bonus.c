/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:46:32 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/09 17:16:14 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

void	free_2d_bonus(char **temp)
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

void	shutdown_bonus(t_stacks *stacks, t_error type)
{
	free_stack_bonus(stacks->a);
	free_stack_bonus(stacks->b);
	free(stacks);
	if (type)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}

void	free_stack_bonus(t_stack *stack)
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
