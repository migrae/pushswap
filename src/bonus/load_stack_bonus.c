/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:38:45 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/13 14:49:37 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

t_stack	*ft_num_node_last(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (!tmp->next)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_num_node_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!*stack || !stack)
		*stack = new;
	else
	{
		tmp = ft_num_node_last(*stack);
		if (tmp)
			tmp->next = new;
	}
}

t_stack	*ft_new_num_node(int number)
{
	t_stack	*newstack;

	newstack = (t_stack *) malloc(sizeof(t_stack));
	if (newstack == 0)
		return (0);
	newstack->number = number;
	newstack->index = 0;
	newstack->next = NULL;
	return (newstack);
}

int	load_stack_bonus(int argc, char **argv, t_stacks *stacks)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		argv[i] = ft_strtrim(argv[i], " \n\f\r\t\v");
		if (ft_strlen(argv[i]) < 1)
			shutdown(stacks, error);
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			if (check_split_bonus(split[j]) || init_num_node(stacks, split[j]))
				return (free_2d_bonus(split), 1);
			j++;
		}
		free_2d_bonus(split);
		i++;
	}
	if (!stacks->a->next)
		shutdown_bonus(stacks, mute);
	return (0);
}

int	init_num_node(t_stacks *stacks, char *str)
{
	t_stack	*temp;

	if (check_dubs(stacks, ft_atoi(str)) || ft_atol(str) > INT_MAX
		|| ft_atol(str) < INT_MIN)
		return (1);
	temp = ft_new_num_node(ft_atoi(str));
	if (!temp)
		return (1);
	ft_num_node_add_back(&stacks->a, temp);
	return (0);
}
