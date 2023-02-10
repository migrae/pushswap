/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:45:42 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/09 17:10:28 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (str[i] <= '0' || str[i] >= '9')
			return (0);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i])
			return (0);
	}
	return (1);
}

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

int	check_input(int argc, char **argv, t_stacks *stacks)
{
	int	i;

	i = 1;
	if (!argv[1])
		return (free(stacks), exit(EXIT_FAILURE), 1);
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	check_split(char *str)
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

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks *));
	if (!stacks)
		shutdown(stacks, error);
	if (check_input(argc, argv, stacks))
		shutdown(stacks, error);
	if (load_stack(argc, argv, stacks) || !stacks->a)
		shutdown(stacks, error);
	stacks = solve(stacks);
	shutdown(stacks, no_error);
	return (0);
}
