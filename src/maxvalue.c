/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxvalue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:59:26 by afelicia          #+#    #+#             */
/*   Updated: 2023/09/21 20:59:43 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fdire(t_stack *stack, int max_i, int i)
{
	if (max_i > i / 2)
	{
		while (max_i < i)
		{
			reverse_rotate_b(&stack);
			max_i++;
		}
	}
	else
	{
		while (max_i > 0)
		{	
			rotate_b(&stack);
			max_i--;
		}
	}
	return (stack);
}

t_stack	*maxvalue(t_stack *stack)
{
	int		maxval;
	t_stack	*current;
	int		i;
	int		max_i;

	max_i = -1;
	i = 0;
	current = stack;
	maxval = INT_MIN;
	while (current != NULL)
	{
		if (current->val > maxval)
		{
			maxval = current->val;
			max_i = i;
		}
		current = current->next;
		i++;
	}
	if (max_i == 0)
		return (stack);
	stack = fdire(stack, max_i, i);
	return (stack);
}
