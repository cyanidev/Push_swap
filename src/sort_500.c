/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:51:29 by afelicia          #+#    #+#             */
/*   Updated: 2023/09/21 19:51:34 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lastquarter(t_stack **sa, t_stack **sb)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = *sa;
	stack_b = *sb;
	while (stack_a != NULL)
	{
		stack_a = minval(stack_a);
		pushb(&stack_a, &stack_b);
	}
	while (stack_b != NULL)
	{
		stack_b = maxvalue(stack_b);
		pusha(&stack_a, &stack_b);
	}
	*sa = stack_a;
	*sb = stack_b;
}

t_stack	*sort500(t_stack *stack_a, t_stack *stack_b, int len, t_stack *dup)
{
	int		keynbr;
	int		pos;
	t_stack	*sorted;
	int		size;
	int		pushed;

	pos = len / 10;
	size = len / 10;
	pushed = 0;
	sorted = merge_sort(&dup);
	while (pos < len - size + 1)
	{
		keynbr = searchkey(sorted, pos);
		while (pushed < size)
		{
			stack_a = finding_key_nbr(stack_a, keynbr, len);
			pushb(&stack_a, &stack_b);
			pushed++;
		}
		pushed = 0;
		pos = pos + size;
	}
	lastquarter(&stack_a, &stack_b);
	free_stack(&dup);
	return (stack_a);
}
