/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:51:23 by afelicia          #+#    #+#             */
/*   Updated: 2023/09/21 19:51:25 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	searchkey(t_stack *srted, int pos)
{
	t_stack	*findk;
	int		i;
	int		key_nbr;

	key_nbr = 0;
	findk = srted;
	i = 1;
	while (i < pos)
	{
		findk = findk->next;
		i++;
	}
	key_nbr = findk->val;
	return (key_nbr);
}

t_stack	*fdir(t_stack *stack_a, int iatkey, int i, int stacklen)
{
	if (iatkey > stacklen / 2)
	{
		while (iatkey < i)
		{
			reverse_rotate_a(&stack_a);
			iatkey++;
		}
	}
	else
	{
		while (iatkey > 0)
		{
			rotate_a(&stack_a);
			iatkey--;
		}
	}
	return (stack_a);
}

t_stack	*finding_key_nbr(t_stack *stack_a, int key_nbr, int stacklen)
{
	int		iatkey;
	t_stack	*search_a;
	int		i;

	iatkey = 0;
	i = 0;
	search_a = stack_a;
	while (search_a != NULL)
	{
		i++;
		if (search_a->val <= key_nbr)
			break ;
		iatkey++;
		search_a = search_a->next;
	}
	if (iatkey == 0)
		return (stack_a);
	stack_a = fdir(stack_a, iatkey, i, stacklen);
	return (stack_a);
}

void	lstq(t_stack **sa, t_stack **sb)
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

t_stack	*sort100(t_stack *stack_a, t_stack *stack_b, int len, t_stack *dup)
{
	int		keynbr;
	int		pos;
	t_stack	*sorted;
	int		size;
	int		pushed;

	pos = len / 4;
	size = len / 4;
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
	lstq(&stack_a, &stack_b);
	free_stack(&dup);
	return (stack_a);
}
