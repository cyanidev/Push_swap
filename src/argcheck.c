/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 23:49:25 by afelicia          #+#    #+#             */
/*   Updated: 2023/09/22 02:02:01 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sign(int c)
{
	if (c == '-')
		return (1);
	else
		return (0);
}

int	ft_stacklen(t_stack *stack)
{
	unsigned int	len;

	len = 0;
	if (stack != NULL)
	{
		while (stack != NULL)
		{
			stack = stack->next;
			len++;
		}
		return (len);
	}
	return (0);
}

int	isok(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (is_sign(argv[j][i]) && argv[j][i + 1] == '0')
				return (0);
			if (is_sign(argv[j][i]) || ft_isdigit(argv[j][i]))
				i++;
			else
				return (0);
		}
		j++;
	}
	if (j == 2)
		return (0);
	return (1);
}

int	finddups(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{	
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	issorted(t_stack	*stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL && current->next != NULL)
	{
		if (current->val > current->next->val)
			return (0);
		current = current->next;
	}
	return (1);
}
