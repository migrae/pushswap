/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:45:42 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/09 17:15:53 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

int	check_dubs(t_stacks *stacks, int number)
{
	t_stack	*current;

	current = stacks->a;
	while (current)
	{
		if (current->number == number)
			return (1);
		current = current->next;
	}
	return (0);
}

int	check_input_bonus(int argc, char **argv, t_stacks *stacks)
{
	int	i;

	i = 1;
	if (!argv[1])
	{
		free(stacks);
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			shutdown_bonus(stacks, error);
		i++;
	}
	return (0);
}

int	check_split_bonus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i])
			return (1);
	}
	return (0);
}
