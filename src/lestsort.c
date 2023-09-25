/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lestsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:12:13 by afelicia          #+#    #+#             */
/*   Updated: 2023/09/22 01:47:19 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maxval(t_stack *stack)
{
	int		max;
	t_stack	*current;

	max = stack->val;
	current = stack;
	while (current != NULL)
	{
		if (current->val > max)
			max = current->val;
		current = current->next;
	}
	return (max);
}

t_stack	*sort_three(t_stack *stack)
{
	int		max;
	t_stack	*current;

	max = maxval(stack);
	current = stack;
	if (current->val == max)
		rotate_a(&current);
	else if (current->next->val == max)
		reverse_rotate_a(&current);
	if (current->val > current->next->val)
		swap_a(current);
	return (current);
}

t_stack	*sort_five(t_stack	*stack_a, t_stack *stack_b)
{
	stack_a = minval(stack_a);
	if (issorted(stack_a))
		return (stack_a);
	pushb(&stack_a, &stack_b);
	stack_a = minval(stack_a);
	pushb(&stack_a, &stack_b);
	if (!issorted(stack_a))
		stack_a = sort_three(stack_a);
	pusha(&stack_a, &stack_b);
	pusha(&stack_a, &stack_b);
	return (stack_a);
}

t_stack	*sort_ten(t_stack	*stack_a, t_stack *stack_b, int len)
{
	int	i;

	i = 0;
	while (i < (len - 3))
	{
		stack_a = minval(stack_a);
		pushb(&stack_a, &stack_b);
		i++;
	}
	if (!issorted(stack_a))
		stack_a = sort_three(stack_a);
	while (i > 0)
	{
		pusha(&stack_a, &stack_b);
		--i;
	}
	return (stack_a);
}

t_stack	*sorted(t_stack	*stack_a, t_stack	*stack_b, int len, t_stack *dup)
{
	t_stack	*sstack;

	sstack = NULL;
	if (len == 3 || len == 2)
		sstack = sort_three(stack_a);
	else if (len == 5 || len == 4)
		sstack = sort_five(stack_a, stack_b);
	else if (len > 5 && len <= 11)
		sstack = sort_ten(stack_a, stack_b, len);
	else if (len > 11 && len <= 499)
		sstack = sort100(stack_a, stack_b, len, dup);
	else if (len > 499 && len <= 500)
		sstack = sort500(stack_a, stack_b, len, dup);
	else if (len > 500)
	{
		free_stack(&stack_a);
		ret_error("More than 500 numbers :c\n");
	}
	return (sstack);
}
