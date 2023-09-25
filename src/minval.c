/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minval.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:49:12 by afelicia          #+#    #+#             */
/*   Updated: 2023/09/21 19:49:16 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*dir(t_stack *stack, int min_i, int i)
{
	if (min_i > i / 2)
	{
		while (min_i < i)
		{
			reverse_rotate_a(&stack);
			min_i++;
		}
	}
	else
	{
		while (min_i > 0)
		{	
			rotate_a(&stack);
			min_i--;
		}
	}
	return (stack);
}

t_stack	*minval(t_stack *stack)
{
	int		minval;
	t_stack	*current;
	int		i;
	int		min_i;

	min_i = -1;
	i = 0;
	current = stack;
	minval = INT_MAX;
	while (current != NULL)
	{
		if (current->val < minval)
		{
			minval = current->val;
			min_i = i;
		}
		current = current->next;
		i++;
	}
	if (min_i == 0)
		return (stack);
	stack = dir(stack, min_i, i);
	return (stack);
}
